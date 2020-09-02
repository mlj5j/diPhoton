#!/bin/bash
source /cvmfs/sft.cern.ch/lcg/views/LCG_89/x86_64-slc6-gcc62-opt/setup.sh
cd ${_CONDOR_SCRATCH_DIR}
xrdcp -s root://cmseos.fnal.gov//store/user/mjoyce/SUSY/${3}/${5} .
tar -xf $5
rm $5
echo python TreeSkimmer_HLT.py -f ${1} -o ${3}_${4}.root -p store/group/lpcsusyphotons/TreeMaker/${2}/ -w ${6} 
python TreeSkimmer_HLT.py -f ${1} -o ${3}_${4}.root -p store/group/lpcsusyphotons/TreeMaker/${2}/ -w ${6}

### Now that the run is over, there is one or more root files created
echo "List all root files = "
#xrdfs root://cmseos.fnal.gov ls /store/group/lpcsusyphotons/TreeMaker/${2}/
echo "List all files"
ls
echo "*******************************************"
OUTDIR=root://cmseos.fnal.gov//store/group/lpcsusyphotons/TreeMaker/${7}/Data/${3}
echo "xrdcp output for condor"
#for FILE in ${3}/*.root
#do
#  echo "xrdcp -f ${FILE} ${OUTDIR}/${FILE}"
#  xrdcp -f ${FILE} ${OUTDIR}/${FILE} 2>&1
xrdcp -f ${3}_${4}.root ${OUTDIR}/${3}_${4}.root 2>&1
XRDEXIT=$?
if [[ $XRDEXIT -ne 0 ]]; then
    rm *.root
    echo "exit code $XRDEXIT, failure in xrdcp"
    exit $XRDEXIT
fi
#rm ${FILE}
rm ${3}_${4}.root
#done
