from ROOT import TChain, TFile, TLorentzVector, TMath, TMVA, AddressOf
import numpy as np
import sys
import argparse



def find_deltaR(v1, vList):
    min_deltaR = 999.9
    for i in vList:
        deltaR = v1.DeltaR(i)
        if deltaR< min_deltaR:
            min_deltaR = deltaR
    return min_deltaR

def check_iso(v1 , vList):
    incJets = 0
    nearJets = 0
    isIso = False
    for i in vList:
        dR = v1.DeltaR(i)
        if dR <= 0.3:
            incJets+=1
        if dR > 0.3 and dR < 0.6:
            nearJets+=1
    if incJets==1 and nearJets==0:
        isIso = True
    return isIso


parser = argparse.ArgumentParser(description='Parses file paths and other options skimming root files')
parser.add_argument('-f', dest='fin', help='Name of file to be skimmed')
parser.add_argument('-b', dest='bpath', default='root:://cmsxrootd.fnal.gov//', help='This is the base path for the file.  On EOS this should not be changed from the default')
parser.add_argument('-p', dest='fpath', help='This is the path to the parent directory of the skimmed file (ie store/group/lpcsusyphotons/TreeMaker/2018/GJets/).')
parser.add_argument('-o', dest='opath', default='test_skim.root', help='name and path of output file')
parser.add_argument('-w', dest='weightfile')
#parser.add_argument('-s', type=bool, dest='is_mc', action='store_true', help='flag for MC samples')


args = parser.parse_args()

ch = TChain("PreSelection")
print (args.bpath + args.fpath + args.fin)
ch.Add(args.bpath + args.fpath + args.fin)

fout = TFile.Open(args.opath,"RECREATE")
print "Output file made"
tree = ch.CloneTree(0)
print "Tree cloned"
entries = ch.GetEntries()
print "scanning total of {0} entries".format(entries)
i_trig = -1


reader = TMVA.Reader()

##--------------Initializing user-defined variables (mostly kinematic)----------------
min_dR = np.zeros(1,dtype=float)

ST = np.zeros(1,dtype=np.float32)
ST_jets = np.zeros(1,dtype=np.float32)
Pt_jets = np.zeros(1,dtype=np.float32)
Pt_GG = np.zeros(1,dtype=np.float32)
HardMETPt = np.zeros(1,dtype=np.float32)
HardMETPhi = np.zeros(1,dtype=np.float32)
DPhiGG = np.zeros(1,dtype=np.float32)
#min_dPhi = np.zeros(1,dtype=float)
DPhiHardMetGG = np.zeros(1,dtype=np.float32)
mass_GG = np.zeros(1,dtype=np.float32)
MinDPhiHardMetJets = np.zeros(1,dtype=np.float32)
#Pho1_hadTowOverEM = np.zeros(1,dtype=float)
#Pho2_hadTowOverEM = np.zeros(1,dtype=float)
Photons0Et = np.zeros(1,dtype=np.float32)
Photons1Et = np.zeros(1,dtype=np.float32)
MinDPhiJetPt = np.zeros(1,dtype=np.float32)
print "ST Address: {0}".format(AddressOf(ST))

reader.AddVariable('mva_ST', ST)
reader.AddVariable('mva_Pt_jets', Pt_jets)
reader.AddVariable('mva_dPhi_GG', DPhiGG)
reader.AddVariable('mva_Photons0Et', Photons0Et)
reader.AddVariable('mva_Photons1Et', Photons1Et)
reader.AddVariable('mva_HardMET', HardMETPt)
reader.AddVariable('mva_Pt_GG', Pt_GG)
reader.AddVariable('mva_ST_jets', ST_jets)
reader.AddVariable('mva_min_dPhi', MinDPhiHardMetJets)
reader.AddVariable('mva_dPhi_GGHardMET', DPhiHardMetGG)


BDTscore = np.zeros(1,dtype=float)
##--------------Adding branches for possible use in BDT---------------
b_ST = tree.Branch('ST', ST, 'ST/F')
b_ST_jets = tree.Branch('ST_jets', ST_jets, 'ST_jets/F')
b_Pt_jets = tree.Branch('Pt_jets', Pt_jets, 'Pt_jets/F')
b_Pt_GG = tree.Branch('Pt_GG', Pt_GG, 'Pt_GG/F')
b_HardMETPt = tree.Branch('HardMETPt', HardMETPt, 'HardMETPt/F')
b_HardMETPhi = tree.Branch('HardMETPhi', HardMETPhi, 'HardMETPhi/F')
b_DPhiGG = tree.Branch('DPhiGG', DPhiGG, 'DPhiGG/F')
#b_min_dPhi = tree.Branch('min_dPhi', min_dPhi, 'min_dPhi/D')
b_MinDPhiHardMetJets = tree.Branch('MinDPhiHardMetJets', MinDPhiHardMetJets, 'MinDPhiHardMetJets/F')
b_DPhiHardMetGG = tree.Branch('DPhiHardMetGG', DPhiHardMetGG, 'DPhiHardMetGG/F')
b_mass_GG = tree.Branch('mass_GG', mass_GG, 'mass_GG/F')
#b_Pho1_hadTowOverEM = tree.Branch('Pho1_hadTowOverEM', Pho1_hadTowOverEM, 'Pho1_hadTowOverEM/D')
#b_Pho2_hadTowOverEM = tree.Branch('Pho2_hadTowOverEM', Pho2_hadTowOverEM, 'Pho2_hadTowOverEM/D')
b_Photons0Et = tree.Branch('Photons0Et', Photons0Et, 'Photons0Et/F')
b_Photons1Et = tree.Branch('Photons1Et', Photons1Et, 'Photons1Et/F')
b_MinDPhiJetPt = tree.Branch('MinDPhiJetPt', MinDPhiJetPt, 'MinDPhiJetPt/F')

b_BDTscore = tree.Branch('BDTscore', BDTscore, 'BDTscore/D')

reader.BookMVA('BDT', args.weightfile)


for j_entry in range(entries):

    i_entry = ch.LoadTree(j_entry)
    if i_entry < 0:
        break
    nb = ch.GetEntry(j_entry)
    if nb <= 0:
        continue
    if j_entry % 5000 ==0:
        print 'Processing signal entry ' + str(j_entry)
    if j_entry ==0:
        if ch.TriggerPass[21]!=-1:
            i_trig = 21

        if ch.TriggerPass[21]==-1:
            i_trig = 22

        print ('Trigger name element is {0}').format(i_trig)
        print 'Using Trigger ' + str(ch.TriggerVersion[i_trig])
    
    #----Initializing variables--------------

    ST[0] = 0.0
    ST_jets[0] = 0.0
    HardMETPt[0] = -1.0
    HardMETPhi[0] = -99
    Pt_GG[0] = 0.0
    Photons0Et[0] = 0.0
    Photons1Et[0] = 0.0
    MinDPhiJetPt[0] = 0.0
    MinDPhiHardMetJets[0] = 99.9
    
    vGG = TLorentzVector(0.0, 0.0, 0.0, 0.0)
    vJets = TLorentzVector(0.0, 0.0, 0.0, 0.0)
    vHardMET = TLorentzVector(0.0, 0.0, 0.0, 0.0)


        
    if ch.TriggerPass[i_trig]==1:

        #-----Photon loop---------
        #print "#photons = {0}".format(min(2,ch.Photons.size()))
        for i_photon in range(0,min(2,ch.Photons.size())):
    
#print "phtons id is {0}".format(bool(ch.Photons_fullID[i_photon]))
            if bool(ch.Photons_fullID[i_photon]) and bool(check_iso(ch.Photons[i_photon],ch.Jets)):
                #print "made it to photons"
                
                ST[0] += ch.Photons[i_photon].Pt()
                vHardMET -= ch.Photons[i_photon]
                vGG += ch.Photons[i_photon]
                if i_photon==0:
                    Photons0Et[0]=ch.Photons[0].Et()
                if i_photon==1:
                    Photons1Et[0]=ch.Photons[1].Et()
                    DPhiGG[0] = abs(ch.Photons[0].DeltaPhi(ch.Photons[1]))


        #-----Jet loops------------
    
        for i_jet in range(0,ch.Jets.size()):
            min_dR[0] = find_deltaR(ch.Jets[i_jet], ch.Photons)
            if (ch.Jets[i_jet].Pt()>30) and (abs(ch.Jets[i_jet].Eta())<2.4) and (min_dR[0]>0.4):
                ST[0] += ch.Jets[i_jet].Pt()
                ST_jets[0] += ch.Jets[i_jet].Pt()
                vJets += ch.Jets[i_jet]
                vHardMET -= ch.Jets[i_jet]

        for i_jet in range(0,ch.Jets.size()):
            if ch.Jets[i_jet].Pt()>30 and abs(ch.Jets[i_jet].Eta())<2.4 and min_dR[0]>0.4:
                DPhiHardMetJets = abs(ch.Jets[i_jet].DeltaPhi(vHardMET))
#                print "Made it into jet thingy"
                
                if DPhiHardMetJets < MinDPhiHardMetJets[0]:
                    MinDPhiHardMetJets[0] = DPhiHardMetJets
                    MinDPhiJetPt[0] = ch.Jets[i_jet].Pt()
#                    print "MindPhi = {0}".format(MinDPhiHardMetJets[0])
#                else:
#                    MinDPhiHardMetJets[0] = DPhiHardMetJets
#                    MinDPhiJetPt[0] = ch.Jets[i_jet].Pt()

        #print "Final ST is {0}".format(ST[0])
#        print "MindPhi = {0}".format(MinDPhiHardMetJets[0])
        mass_GG[0] = vGG.M()
        Pt_GG[0] = vGG.Pt()
        Pt_jets[0] = vJets.Pt()
        HardMETPt[0] = vHardMET.Pt()
        HardMETPhi[0] = vHardMET.Phi()
        DPhiHardMetGG[0] = abs(vHardMET.DeltaPhi(vGG))
        BDTscore[0] = reader.EvaluateMVA("BDT")
        tree.Fill()

fout.Write()

sys.stdin.readline()
