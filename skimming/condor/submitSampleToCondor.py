# /usr/bin/python

#Author: Matt Joyce
#Date: February 7, 2019
#Purpose: Script to submit condor jobs for SUSY analysis

import os,sys, argparse

# *** 0. setup parser for command line
parser = argparse.ArgumentParser()
parser.add_argument("--inputDir", help="input directory for root files to be scanned.  Should be in format of year/samplename/ (ie 2016/ZGGtonunuGG)")
parser.add_argument("--outputDir", help="output directory for processed rootfiles (ZGGtonunuGG_2016 for example)")
parser.add_argument("--inputTXTfile", help=".txt file containing list of input files for a given sample")
parser.add_argument("--weightfile", help="Path to weight file")
parser.add_argument("--year", help="The year of the dataset")
args = parser.parse_args()

if (len(vars(args)) != 5): # 3 --> three: one for each options
    os.system('python submitSampleToCondor.py -h')
    quit()

# ** A. Test output directory existence and create if DNE
if(args.outputDir is None):
    print "#### Need to specify output directory using --outputDir <desired output directory> ####\nEXITING"
    quit()

else:
    if ( not os.path.exists(args.outputDir) ): # Checking if the output directory exists locally (not on eos) and making it if it does not exist.
        print "Specified input file ({0}) DNE.\nCREATING NOW".format(args.inputTXTfile)
        os.system("mkdir {0}".format(args.outputDir))
    # Making directories for condor logs, errors, output, etc
    if ( not os.path.exists( (args.outputDir + '/condor_logs/') ) ):
        os.system("mkdir {0}".format( (args.outputDir + '/condor_logs/')) )
    if ( not os.path.exists( (args.outputDir + '/condor_err/') ) ):
        os.system("mkdir {0}".format( (args.outputDir + '/condor_err/')) )
    if ( not os.path.exists( (args.outputDir + '/condor_out/') ) ):
        os.system("mkdir {0}".format( (args.outputDir + '/condor_out/')) )

    print '-- Setting outputDir = {0}'.format(args.outputDir)

wfile = "TMVAClassification_BDT.weights.xml"
# ** B. Test input .txt file and exit if DNE
if(args.inputTXTfile is None):
    print "#### Need to specify input .txt file using --inputTXTfile <address to .txt file> ####\nEXITING"
    quit()
else:
    if ( not os.path.exists(args.inputTXTfile) ):
        print "#### Specified input file ({0}) DNE ####.\nEXITING".format(args.inputTXTfile)
        quit()
    else:
        print '-- Setting inputTXTfile = {0}'.format(args.inputTXTfile)

if(args.weightfile is None):
    print "### Need to specify .xml weight file using --weightfile <address to .xml file> ####\nExiting"
    quit()

else:
    if (not os.path.exists(args.weightfile) ):
        print "### Specified weight file ({0}) DNE ###.\nEXITING".format(args.weightfile)
        quit()
    else: 
        print '-- Setting weightfile = {0}'.format(args.weightfile)
        os.system("cp {0} .".format(args.weightfile))
        if (os.path.exists(wfile)):
            print 'BDT weight file is copied into local directory'


# ** C. Test isMC flag and exit if not sensible



# ** D. Exit if no grid proxy
if ( not os.path.exists(os.path.expandvars("$X509_USER_PROXY")) ):
    print "#### No GRID PROXY detected. Please do voms-proxy-init -voms cms before submitting Condor jobs ####.\nEXITING"
    quit()


# *** 1. Create .tar of directory and store in personal EOS
print "##########     Tarring workdir     ##########"
tarball_name = "{0}.tar.gz".format(args.outputDir)
os.system("tar -cvzf {0} ./ --exclude 'dpg*' --exclude '.git' --exclude 'test*' --exclude 'submitOneFile_' --exclude '*.tar.gz' --exclude '*.h' --exclude '*.C' --exclude '*.cpp' --exclude 'single*' --exclude '*.err' --exclude '*.log' --exclude '*.out' --exclude '*.root' --exclude 'quick*' --exclude '*.*~' --exclude 'fileLists*'".format(tarball_name))
if ( not os.path.exists("/eos/uscms/store/user/mjoyce/SUSY/{0}/".format(args.outputDir)) ): # Checking if a directory in eos exists with same name as local directory and creating it if it doesn't exist
    os.system("mkdir /eos/uscms/store/user/mjoyce/SUSY/{0}".format(args.outputDir))
#os.system("xrdfs root://cmseos.fnal.gov rm /store/user/mjoyce/SUSY/{0}/{1}".format(args.outputDir, tarball_name))
os.system("xrdcp {0} root://cmseos.fnal.gov//store/user/mjoyce/SUSY/{1}/".format(tarball_name, args.outputDir))


# *** 2. Create temporary .pdl file for condor submission
print "\n##########     Submitting Condor jobs     ##########\n"
txtfile = open(args.inputTXTfile, 'r')

for line in txtfile:
    number = (line.rsplit('_',2))[1] # get number of file
    infile = line.split('\n')[0]
    #inputDir = infile.split('ggtree')[0]
    
    print number, infile, args.inputDir
    jdl_filename = "submitOneFile_{0}_{1}.jdl".format(args.outputDir, number)
    print "jdl filename is {0}".format(jdl_filename)
    os.system("touch {0}".format(jdl_filename))
    os.system("echo universe = vanilla > {0}".format(jdl_filename))
    os.system("echo Executable = runOneFile.csh >> {0}".format(jdl_filename))
    os.system("echo Should_Transfer_Files = YES >> {0}".format(jdl_filename))
    os.system("echo WhenToTransferOutput = ON_EXIT >> {0}".format(jdl_filename))
    os.system("echo Transfer_Input_Files = runOneFile.csh, {0} >> {1}".format(tarball_name, jdl_filename))
    os.system("echo Output = {0}/condor_out/outfile_{1}.out  >> {2}".format(args.outputDir, number, jdl_filename))
    os.system("echo Error = {0}/condor_err/outfile_{1}.err >> {2}".format(args.outputDir, number, jdl_filename))
    os.system("echo Log = {0}/condor_logs/outfile_{1}.log >> {2}".format(args.outputDir, number, jdl_filename))
    os.system("echo x509userproxy = ${{X509_USER_PROXY}} >> {0}".format(jdl_filename))
    os.system("echo Arguments = {0} {1} {2} {3} {4} {5} {6} >> {7}".format(infile, args.inputDir, args.outputDir, number, tarball_name, wfile, args.year, jdl_filename))
    os.system("echo Queue 1 >> {0}".format(jdl_filename))   

    
    os.system("condor_submit {0}".format(jdl_filename))


# *** 3. Cleanup submission directory
print "\n##########     Cleanup submission directory     ##########\n"
os.system("rm *.jdl")
#os.system("rm {0}".format(tarball_name))
#os.system("xrdfs root://cmseos.fnal.gov rm /store/user/mjoyce/SUSY/{0}/{1}".format(args.outputDir, tarball_name))
#os.system("mv {0} {1}/".format(tarball_name, args.outputDir) )
