#Do relevent imports
from ROOT import TChain, gROOT, TFile, TCut, TMVA, TLorentzVector
import numpy as np
import sys
import argparse


parser = argparse.ArgumentParser(description="Training BDT to separate real and fake MET")
parser.add_argument('-s', '--signal', dest='sig_name', help='This is the sample used for signal, ie ZGGtonunuGG or ZGGtonunuGG_RandS')
parser.add_argument('-y1', dest='year1', help='This is the year (obviously)')
parser.add_argument('-y2', dest='year2', default='0', help='This is the second year to include.')
parser.add_argument('-y3', dest='year3', default='0', help='This is the third year to include.')
parser.add_argument('-b', '--background', dest='back_name', help='This is the sample used for the backbaround, ie GJets or QCD_RandS')
parser.add_argument('-m', '--mode', dest='mode', default='v4', help='If training on RandS samples, you should put RandS here.  Otherwise do not put anything.')
parser.add_argument('-n', '--name', dest='name', default='test', help='This is a string appended to the output file name to serve as an identifier')

args = parser.parse_args()


#Read file lists to make TChains.  There should be one TChain for signal and one for background
if args.mode=='RandS':
     print "Rebalance and smear has been selected"
     sig = TChain("TreeMaker2/PreSelection")
     bkg = TChain("TreeMaker2/PreSelection")
else:
     sig = TChain("PreSelection")
     bkg = TChain('PreSelection')
years = []
years.append(args.year1)
years.append(args.year2)
years.append(args.year3)
for year in years:
     if year !='0':
          fsiglist = open(('filelists/{0}_{1}.txt').format(args.sig_name, year),'r')
          print "loading {0} files from {1}".format(args.sig_name, year)
          fbkglist = open(('filelists/{0}_{1}.txt').format(args.back_name, year),'r')
          print "loading {0} files from {1}".format(args.back_name, year)

          for line in fsiglist:                                                                                                                             
               sig.Add(('root://cmseos.fnal.gov/{0}').format(line.strip()))
               print "Added {0} to to TChain".format(line.strip())
          for line in fbkglist:                                                                                                                          
               bkg.Add(('root://cmseos.fnal.gov/{0}').format(line.strip()))
          fsiglist.close()
          fbkglist.close()

fout = TFile.Open("../Results/BDT_output_{0}.root".format(args.name),"RECREATE")

TMVA.Tools.Instance()

factory = TMVA.Factory("TMVAClassification", fout, "V:!Silent:Color:Transformations=I:DrawProgressBar:AnalysisType=Classification")


loader = TMVA.DataLoader("dataset_bdt_{0}".format(args.name))

#Add TChains to factory
loader.AddSignalTree(sig, 1.0)
loader.AddBackgroundTree(bkg, 1.0)

if args.mode == 'RandS':
#     loader.AddVariable('mva_Ngoodjets','I')
     loader.AddVariable('mva_ST','F')
     loader.AddVariable('mva_Pt_jets','F')
     loader.AddVariable('mva_dPhi_GG','F')
#     loader.AddVariable('mva_Photons0Et','F')
#     loader.AddVariable('mva_Photons1Et','F')
     loader.AddVariable('mva_HardMET','F')
     loader.AddVariable('mva_Pt_GG','F')
     loader.AddVariable('mva_ST_jets','F')
     #loader.AddVariable('mva_min_dPhi','F')
     loader.AddVariable('HardMetMinusMet','F')
     loader.AddVariable('MinDPhiHardMetJets','F')
     loader.AddVariable('mva_dPhi_GGHardMET','F')
     loader.AddVariable('mass_GG','F')

else:
#Add variables and spectators to factory
     loader.AddVariable('Ngoodjets','I')
     loader.AddVariable('ST','F')
     loader.AddVariable('Pt_jets','F')
     loader.AddVariable('dPhi_GG','F')

#basic attempt
     loader.AddVariable('Photons[0].Et()','F')
     loader.AddVariable('Photons[1].Et()','F')
     loader.AddVariable('HardMET','F')
     loader.AddVariable('Pt_GG','F')
     loader.AddVariable('ST_jets','F')

#--Some deltaPhi variables:
     loader.AddVariable('min_dPhi','F')
     loader.AddVariable('dPhi_GGHardMET','F')

#Define cuts to be applied
sigcuts = TCut('min_dPhi>-1 && min_dPhi<10 && Photons_isEB[0]==1 && Photons_isEB[1]==1 && Photons[0].Et()>80 && Photons[1].Et()>80') 
bkgcuts = TCut('min_dPhi>-1 && min_dPhi<10 && Photons_isEB[0]==1 && Photons_isEB[1]==1 && Photons[0].Et()>80 && Photons[1].Et()>80')

sigcuts_RandS = TCut('IsRandS==0 && HardMETPt>110 && Photons_isEB[0]==1 && Photons_isEB[1]==1')
bkgcuts_RandS = TCut('IsRandS==1 && HardMETPt>110 && Photons_isEB[0]==1 && Photons_isEB[1]==1')


#Prepare trees for training and testing (I think this just applies the cuts)
if args.mode == 'RandS':
     loader.PrepareTrainingAndTestTree(sigcuts_RandS, bkgcuts_RandS, "SplitMode=random:!V")

else:
     loader.PrepareTrainingAndTestTree(sigcuts, bkgcuts, "SplitMode=random:!V")
#Uset BookMethod to specify BDT
#factory.BookMethod(loader, TMVA.Types.kBDT, 'BDT_otherthing', '!H:!V:NTrees=200:MaxDepth=4:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex')
factory.BookMethod(loader, TMVA.Types.kBDT, 'BDT', "NTrees=20:MaxDepth=8")
#factory.BookMethod(loader, TMVA.Types.kBDT, 'BDT_15D', "NTrees=200:MaxDepth=15")
#Train, test, and evaluate
factory.TrainAllMethods()
factory.TestAllMethods()
factory.EvaluateAllMethods()
#close output file
fout.Close()
#Open output file in TMVAGUI (must be in batch mode I think)
print 'TMVA Classification is done!'

#gROOT.ProcessLine(fout)
c = factory.GetROCCurve(loader)
c.Draw()
sys.stdin.readline()


