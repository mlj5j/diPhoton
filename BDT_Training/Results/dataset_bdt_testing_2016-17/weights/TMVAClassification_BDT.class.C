// Class: ReadBDT
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================

#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-

Method         : BDT::BDT
TMVA Release   : 4.2.1         [262657]
ROOT Release   : 6.12/07       [396295]
Creator        : mjoyce
Date           : Fri Aug 28 10:48:18 2020
Host           : Linux cmsbuild06.cern.ch 3.10.0-1062.9.1.el7.x86_64 #1 SMP Fri Dec 6 15:49:49 UTC 2019 x86_64 x86_64 x86_64 GNU/Linux
Dir            : /uscms_data/d3/mjoyce/SUSY/CMSSW_10_2_21/src/diPhoton/BDT_Training/condor
Training events: 7415
Analysis type  : [Classification]


#OPT -*-*-*-*-*-*-*-*-*-*-*-*- options -*-*-*-*-*-*-*-*-*-*-*-*-

# Set by User:
NTrees: "20" [Number of trees in the forest]
MaxDepth: "8" [Max depth of the decision tree allowed]
# Default:
V: "False" [Verbose output (short form of "VerbosityLevel" below - overrides the latter one)]
VerbosityLevel: "Default" [Verbosity level]
VarTransform: "None" [List of variable transformations performed before training, e.g., "D_Background,P_Signal,G,N_AllClasses" for: "Decorrelation, PCA-transformation, Gaussianisation, Normalisation, each for the given class of events ('AllClasses' denotes all events of all classes, if no class indication is given, 'All' is assumed)"]
H: "False" [Print method-specific help message]
CreateMVAPdfs: "False" [Create PDFs for classifier outputs (signal and background)]
IgnoreNegWeightsInTraining: "False" [Events with negative weights are ignored in the training (but are included for testing and performance evaluation)]
MinNodeSize: "5%" [Minimum percentage of training events required in a leaf node (default: Classification: 5%, Regression: 0.2%)]
nCuts: "20" [Number of grid points in variable range used in finding optimal cut in node splitting]
BoostType: "AdaBoost" [Boosting type for the trees in the forest (note: AdaCost is still experimental)]
AdaBoostR2Loss: "quadratic" [Type of Loss function in AdaBoostR2]
UseBaggedBoost: "False" [Use only a random subsample of all events for growing the trees in each boost iteration.]
Shrinkage: "1.000000e+00" [Learning rate for GradBoost algorithm]
AdaBoostBeta: "5.000000e-01" [Learning rate  for AdaBoost algorithm]
UseRandomisedTrees: "False" [Determine at each node splitting the cut variable only as the best out of a random subset of variables (like in RandomForests)]
UseNvars: "3" [Size of the subset of variables used with RandomisedTree option]
UsePoissonNvars: "True" [Interpret "UseNvars" not as fixed number but as mean of a Poisson distribution in each split with RandomisedTree option]
BaggedSampleFraction: "6.000000e-01" [Relative size of bagged event sample to original size of the data sample (used whenever bagging is used (i.e. UseBaggedBoost, Bagging,)]
UseYesNoLeaf: "True" [Use Sig or Bkg categories, or the purity=S/(S+B) as classification of the leaf node -> Real-AdaBoost]
NegWeightTreatment: "inverseboostnegweights" [How to treat events with negative weights in the BDT training (particular the boosting) : IgnoreInTraining;  Boost With inverse boostweight; Pair events with negative and positive weights in training sample and *annihilate* them (experimental!)]
Css: "1.000000e+00" [AdaCost: cost of true signal selected signal]
Cts_sb: "1.000000e+00" [AdaCost: cost of true signal selected bkg]
Ctb_ss: "1.000000e+00" [AdaCost: cost of true bkg    selected signal]
Cbb: "1.000000e+00" [AdaCost: cost of true bkg    selected bkg ]
NodePurityLimit: "5.000000e-01" [In boosting/pruning, nodes with purity > NodePurityLimit are signal; background otherwise.]
SeparationType: "giniindex" [Separation criterion for node splitting]
RegressionLossFunctionBDTG: "huber" [Loss function for BDTG regression.]
HuberQuantile: "7.000000e-01" [In the Huber loss function this is the quantile that separates the core from the tails in the residuals distribution.]
DoBoostMonitor: "False" [Create control plot with ROC integral vs tree number]
UseFisherCuts: "False" [Use multivariate splits using the Fisher criterion]
MinLinCorrForFisher: "8.000000e-01" [The minimum linear correlation between two variables demanded for use in Fisher criterion in node splitting]
UseExclusiveVars: "False" [Variables already used in fisher criterion are not anymore analysed individually for node splitting]
DoPreselection: "False" [and and apply automatic pre-selection for 100% efficient signal (bkg) cuts prior to training]
SigToBkgFraction: "1.000000e+00" [Sig to Bkg ratio used in Training (similar to NodePurityLimit, which cannot be used in real adaboost]
PruneMethod: "nopruning" [Note: for BDTs use small trees (e.g.MaxDepth=3) and NoPruning:  Pruning: Method used for pruning (removal) of statistically insignificant branches ]
PruneStrength: "0.000000e+00" [Pruning strength]
PruningValFraction: "5.000000e-01" [Fraction of events to use for optimizing automatic pruning.]
SkipNormalization: "False" [Skip normalization at initialization, to keep expectation value of BDT output according to the fraction of events]
nEventsMin: "0" [deprecated: Use MinNodeSize (in % of training events) instead]
UseBaggedGrad: "False" [deprecated: Use *UseBaggedBoost* instead:  Use only a random subsample of all events for growing the trees in each iteration.]
GradBaggingFraction: "6.000000e-01" [deprecated: Use *BaggedSampleFraction* instead: Defines the fraction of events to be used in each iteration, e.g. when UseBaggedGrad=kTRUE. ]
UseNTrainEvents: "0" [deprecated: Use *BaggedSampleFraction* instead: Number of randomly picked training events used in randomised (and bagged) trees]
NNodesMax: "0" [deprecated: Use MaxDepth instead to limit the tree size]
##


#VAR -*-*-*-*-*-*-*-*-*-*-*-* variables *-*-*-*-*-*-*-*-*-*-*-*-

NVar 10
mva_ST                        mva_ST                        mva_ST                        mva_ST                                                          'F'    [152.908981323,3650.04101562]
mva_Pt_jets                   mva_Pt_jets                   mva_Pt_jets                   mva_Pt_jets                                                     'F'    [0,1569.38757324]
mva_dPhi_GG                   mva_dPhi_GG                   mva_dPhi_GG                   mva_dPhi_GG                                                     'F'    [-3.14152336121,3.13939261436]
mva_Photons0Et                mva_Photons0Et                mva_Photons0Et                mva_Photons0Et                                                  'F'    [75.3722991943,1275.85412598]
mva_Photons1Et                mva_Photons1Et                mva_Photons1Et                mva_Photons1Et                                                  'F'    [75.0455322266,565.674255371]
mva_HardMET                   mva_HardMET                   mva_HardMET                   mva_HardMET                                                     'F'    [110.000480652,708.448303223]
mva_Pt_GG                     mva_Pt_GG                     mva_Pt_GG                     mva_Pt_GG                                                       'F'    [1.89664292336,1389.22680664]
mva_ST_jets                   mva_ST_jets                   mva_ST_jets                   mva_ST_jets                                                     'F'    [0,3222.6015625]
mva_min_dPhi                  mva_min_dPhi                  mva_min_dPhi                  mva_min_dPhi                                                    'F'    [0.000116848066682,3.13644599915]
mva_dPhi_GGHardMET            mva_dPhi_GGHardMET            mva_dPhi_GGHardMET            mva_dPhi_GGHardMET                                              'F'    [-3.14159274101,3.14159274101]
NSpec 0


============================================================================ */

#include <array>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#define NN new BDTNode
   
#ifndef BDTNode__def
#define BDTNode__def
   
class BDTNode {
   
public:
   
   // constructor of an essentially "empty" node floating in space
   BDTNode ( BDTNode* left,BDTNode* right,
                          int selector, double cutValue, bool cutType, 
                          int nodeType, double purity, double response ) :
   fLeft         ( left         ),
   fRight        ( right        ),
   fSelector     ( selector     ),
   fCutValue     ( cutValue     ),
   fCutType      ( cutType      ),
   fNodeType     ( nodeType     ),
   fPurity       ( purity       ),
   fResponse     ( response     ){
   }

   virtual ~BDTNode();

   // test event if it descends the tree at this node to the right
   virtual bool GoesRight( const std::vector<double>& inputValues ) const;
   BDTNode* GetRight( void )  {return fRight; };

   // test event if it descends the tree at this node to the left 
   virtual bool GoesLeft ( const std::vector<double>& inputValues ) const;
   BDTNode* GetLeft( void ) { return fLeft; };   

   // return  S/(S+B) (purity) at this node (from  training)

   double GetPurity( void ) const { return fPurity; } 
   // return the node type
   int    GetNodeType( void ) const { return fNodeType; }
   double GetResponse(void) const {return fResponse;}

private:

   BDTNode*   fLeft;     // pointer to the left daughter node
   BDTNode*   fRight;    // pointer to the right daughter node
   int                     fSelector; // index of variable used in node selection (decision tree)   
   double                  fCutValue; // cut value applied on this node to discriminate bkg against sig
   bool                    fCutType;  // true: if event variable > cutValue ==> signal , false otherwise
   int                     fNodeType; // Type of node: -1 == Bkg-leaf, 1 == Signal-leaf, 0 = internal 
   double                  fPurity;   // Purity of node from training
   double                  fResponse; // Regression response value of node
}; 
   
//_______________________________________________________________________
   BDTNode::~BDTNode()
{
   if (fLeft  != NULL) delete fLeft;
   if (fRight != NULL) delete fRight;
}; 
   
//_______________________________________________________________________
bool BDTNode::GoesRight( const std::vector<double>& inputValues ) const
{
   // test event if it descends the tree at this node to the right
   bool result;
     result = (inputValues[fSelector] > fCutValue );
   if (fCutType == true) return result; //the cuts are selecting Signal ;
   else return !result;
}
   
//_______________________________________________________________________
bool BDTNode::GoesLeft( const std::vector<double>& inputValues ) const
{
   // test event if it descends the tree at this node to the left
   if (!this->GoesRight(inputValues)) return true;
   else return false;
}
   
#endif
   
#ifndef IClassifierReader__def
#define IClassifierReader__def

class IClassifierReader {

 public:

   // constructor
   IClassifierReader() : fStatusIsClean( true ) {}
   virtual ~IClassifierReader() {}

   // return classifier response
   virtual double GetMvaValue( const std::vector<double>& inputValues ) const = 0;

   // returns classifier status
   bool IsStatusClean() const { return fStatusIsClean; }

 protected:

   bool fStatusIsClean;
};

#endif

class ReadBDT : public IClassifierReader {

 public:

   // constructor
   ReadBDT( std::vector<std::string>& theInputVars ) 
      : IClassifierReader(),
        fClassName( "ReadBDT" ),
        fNvars( 10 ),
        fIsNormalised( false )
   {      
      // the training input variables
      const char* inputVars[] = { "mva_ST", "mva_Pt_jets", "mva_dPhi_GG", "mva_Photons0Et", "mva_Photons1Et", "mva_HardMET", "mva_Pt_GG", "mva_ST_jets", "mva_min_dPhi", "mva_dPhi_GGHardMET" };

      // sanity checks
      if (theInputVars.size() <= 0) {
         std::cout << "Problem in class \"" << fClassName << "\": empty input vector" << std::endl;
         fStatusIsClean = false;
      }

      if (theInputVars.size() != fNvars) {
         std::cout << "Problem in class \"" << fClassName << "\": mismatch in number of input values: "
                   << theInputVars.size() << " != " << fNvars << std::endl;
         fStatusIsClean = false;
      }

      // validate input variables
      for (size_t ivar = 0; ivar < theInputVars.size(); ivar++) {
         if (theInputVars[ivar] != inputVars[ivar]) {
            std::cout << "Problem in class \"" << fClassName << "\": mismatch in input variable names" << std::endl
                      << " for variable [" << ivar << "]: " << theInputVars[ivar].c_str() << " != " << inputVars[ivar] << std::endl;
            fStatusIsClean = false;
         }
      }

      // initialize min and max vectors (for normalisation)
      fVmin[0] = 0;
      fVmax[0] = 0;
      fVmin[1] = 0;
      fVmax[1] = 0;
      fVmin[2] = 0;
      fVmax[2] = 0;
      fVmin[3] = 0;
      fVmax[3] = 0;
      fVmin[4] = 0;
      fVmax[4] = 0;
      fVmin[5] = 0;
      fVmax[5] = 0;
      fVmin[6] = 0;
      fVmax[6] = 0;
      fVmin[7] = 0;
      fVmax[7] = 0;
      fVmin[8] = 0;
      fVmax[8] = 0;
      fVmin[9] = 0;
      fVmax[9] = 0;

      // initialize input variable types
      fType[0] = 'F';
      fType[1] = 'F';
      fType[2] = 'F';
      fType[3] = 'F';
      fType[4] = 'F';
      fType[5] = 'F';
      fType[6] = 'F';
      fType[7] = 'F';
      fType[8] = 'F';
      fType[9] = 'F';

      // initialize constants
      Initialize();

   }

   // destructor
   virtual ~ReadBDT() {
      Clear(); // method-specific
   }

   // the classifier response
   // "inputValues" is a vector of input values in the same order as the 
   // variables given to the constructor
   double GetMvaValue( const std::vector<double>& inputValues ) const;

 private:

   // method-specific destructor
   void Clear();

   // common member variables
   const char* fClassName;

   const size_t fNvars;
   size_t GetNvar()           const { return fNvars; }
   char   GetType( int ivar ) const { return fType[ivar]; }

   // normalisation of input variables
   const bool fIsNormalised;
   bool IsNormalised() const { return fIsNormalised; }
   double fVmin[10];
   double fVmax[10];
   double NormVariable( double x, double xmin, double xmax ) const {
      // normalise to output range: [-1, 1]
      return 2*(x - xmin)/(xmax - xmin) - 1.0;
   }

   // type of input variable: 'F' or 'I'
   char   fType[10];

   // initialize internal variables
   void Initialize();
   double GetMvaValue__( const std::vector<double>& inputValues ) const;

   // private members (method specific)
   std::vector<BDTNode*> fForest;       // i.e. root nodes of decision trees
   std::vector<double>                fBoostWeights; // the weights applied in the individual boosts
};

double ReadBDT::GetMvaValue__( const std::vector<double>& inputValues ) const
{
   double myMVA = 0;
   double norm  = 0;
   for (unsigned int itree=0; itree<fForest.size(); itree++){
      BDTNode *current = fForest[itree];
      while (current->GetNodeType() == 0) { //intermediate node
         if (current->GoesRight(inputValues)) current=(BDTNode*)current->GetRight();
         else current=(BDTNode*)current->GetLeft();
      }
      myMVA += fBoostWeights[itree] *  current->GetNodeType();
      norm  += fBoostWeights[itree];
   }
   return myMVA /= norm;
};

void ReadBDT::Initialize()
{
  // itree = 0
  fBoostWeights.push_back(0.884863981605529);
  fForest.push_back( 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.933141,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.779211,-99) , 
NN(
0, 
0, 
-1, 113.328, 0, -1, 0.327408,-99) , 
8, 0.673256, 0, 0, 0.538796,-99) , 
5, 135.967, 0, 0, 0.77187,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.510168,-99) , 
NN(
0, 
0, 
-1, 446.003, 1, -1, 0.046007,-99) , 
5, 166.996, 0, 0, 0.139836,-99) , 
7, 306.914, 1, 0, 0.5,-99)    );
  // itree = 1
  fBoostWeights.push_back(0.757478);
  fForest.push_back( 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.927827,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.757102,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.633994,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.411393,-99) , 
5, 122.203, 0, 0, 0.534939,-99) , 
NN(
0, 
0, 
-1, 1.71696, 0, -1, 0.306793,-99) , 
8, 0.430898, 0, 0, 0.434497,-99) , 
9, -2.84239, 1, 0, 0.544549,-99) , 
5, 161.919, 0, 0, 0.678005,-99) , 
NN(
0, 
0, 
-1, 166.996, 0, -1, 0.0788477,-99) , 
7, 460.372, 1, 0, 0.480675,-99)    );
  // itree = 2
  fBoostWeights.push_back(0.601371);
  fForest.push_back( 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.857699,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.716984,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.56583,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.237223,-99) , 
9, 0.146665, 0, 0, 0.425767,-99) , 
7, 153.33, 1, 0, 0.606143,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.536102,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.229439,-99) , 
2, -1.94366, 1, 0, 0.361374,-99) , 
6, 110.144, 0, 0, 0.53232,-99) , 
5, 161.919, 0, 0, 0.629547,-99) , 
NN(
0, 
0, 
-1, 166.996, 0, -1, 0.154383,-99) , 
7, 460.372, 1, 0, 0.487977,-99)    );
  // itree = 3
  fBoostWeights.push_back(0.466933);
  fForest.push_back( 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.879563,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.549545,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.461387,-99) , 
1, 146.272, 1, 0, 0.51979,-99) , 
5, 138.508, 0, 0, 0.710573,-99) , 
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.605223,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.506188,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.167625,-99) , 
7, 44.5251, 0, 0, 0.358662,-99) , 
6, 126.07, 0, 0, 0.493629,-99) , 
NN(
0, 
0, 
-1, 171.17, 0, -1, 0.303838,-99) , 
7, 233.803, 1, 0, 0.41448,-99) , 
NN(
0, 
0, 
-1, 375.911, 0, -1, 0.112691,-99) , 
7, 613.829, 1, 0, 0.335724,-99) , 
8, 0.746862, 0, 0, 0.464371,-99)    );
  // itree = 4
  fBoostWeights.push_back(0.473753);
  fForest.push_back( 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.826006,-99) , 
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.667355,-99) , 
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.58779,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.519421,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.368385,-99) , 
3, 153.665, 1, 0, 0.452849,-99) , 
6, 182.861, 0, 0, 0.495246,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.34778,-99) , 
7, 391.38, 1, 0, 0.467619,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.246713,-99) , 
8, 0.0931804, 0, 0, 0.442787,-99) , 
7, 29.2254, 1, 0, 0.487522,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.193406,-99) , 
2, -2.84066, 0, 0, 0.439268,-99) , 
NN(
0, 
0, 
-1, 862.628, 1, -1, 0.0674563,-99) , 
7, 613.829, 1, 0, 0.376595,-99) , 
5, 195.493, 0, 0, 0.456351,-99)    );
  // itree = 5
  fBoostWeights.push_back(0.401657);
  fForest.push_back( 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.747218,-99) , 
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.603918,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.449753,-99) , 
7, 115.816, 1, 0, 0.537739,-99) , 
NN(
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.597504,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.349676,-99) , 
6, 127.224, 0, 0, 0.492102,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.336748,-99) , 
6, 225.496, 1, 0, 0.448631,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.257244,-99) , 
3, 109.856, 0, 0, 0.413217,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.242325,-99) , 
2, -2.83836, 0, 0, 0.379036,-99) , 
8, 0.746862, 0, 0, 0.43385,-99) , 
NN(
0, 
0, 
-1, 248.948, 0, -1, 0.104081,-99) , 
7, 613.829, 1, 0, 0.384945,-99) , 
5, 195.493, 0, 0, 0.445726,-99)    );
  // itree = 6
  fBoostWeights.push_back(0.352047);
  fForest.push_back( 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.672329,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.620119,-99) , 
NN(
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.575124,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.365421,-99) , 
1, 221.888, 1, 0, 0.517805,-99) , 
NN(
0, 
0, 
-1, 325.631, 0, -1, 0.361893,-99) , 
2, 1.71641, 1, 0, 0.453232,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.289134,-99) , 
2, -2.84066, 0, 0, 0.431695,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.239431,-99) , 
0, 727.329, 1, 0, 0.409778,-99) , 
3, 319.824, 0, 0, 0.436108,-99) , 
5, 166.996, 0, 0, 0.491711,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.0887417,-99) , 
7, 920.743, 1, 0, 0.455716,-99)    );
  // itree = 7
  fBoostWeights.push_back(0.337152);
  fForest.push_back( 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.702579,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.64632,-99) , 
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.622873,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.525409,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.392549,-99) , 
1, 114.142, 0, 0, 0.472628,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.314412,-99) , 
8, 0.128097, 0, 0, 0.444173,-99) , 
2, 2.24238, 0, 0, 0.481831,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.277579,-99) , 
0, 308.876, 0, 0, 0.447931,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.138819,-99) , 
7, 525.999, 1, 0, 0.422384,-99) , 
1, 399.912, 0, 0, 0.44695,-99) , 
8, 1.34426, 0, 0, 0.482041,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.121634,-99) , 
7, 920.743, 1, 0, 0.452735,-99)    );
  // itree = 8
  fBoostWeights.push_back(0.291986);
  fForest.push_back( 
NN(
NN(
NN(
NN(
0, 
0, 
-1, 110.636, 0, 1, 0.691397,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.52779,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.344763,-99) , 
6, 116.002, 0, 0, 0.437523,-99) , 
6, 172.996, 0, 0, 0.539589,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.549959,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.45088,-99) , 
9, -2.84241, 1, 0, 0.494098,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.540104,-99) , 
NN(
0, 
0, 
-1, -2.36047, 1, -1, 0.321538,-99) , 
1, 325.97, 0, 0, 0.408398,-99) , 
NN(
0, 
0, 
-1, 1.4267, 0, -1, 0.21685,-99) , 
2, 0.141271, 1, 0, 0.338666,-99) , 
7, 175.333, 1, 0, 0.40863,-99) , 
8, 0.597513, 0, 0, 0.466223,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.162479,-99) , 
7, 920.743, 1, 0, 0.443408,-99)    );
  // itree = 9
  fBoostWeights.push_back(0.250192);
  fForest.push_back( 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.624155,-99) , 
NN(
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.641289,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.456682,-99) , 
8, 0.288804, 1, 0, 0.522461,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.517084,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.515525,-99) , 
NN(
0, 
0, 
-1, 226.645, 1, -1, 0.359682,-99) , 
7, 379.931, 0, 0, 0.388546,-99) , 
1, 47.1474, 1, 0, 0.425948,-99) , 
9, 1.0472, 0, 0, 0.460314,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.284617,-99) , 
0, 875.878, 1, 0, 0.44718,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.137976,-99) , 
7, 613.829, 1, 0, 0.414935,-99) , 
5, 195.493, 0, 0, 0.446945,-99)    );
  // itree = 10
  fBoostWeights.push_back(0.302702);
  fForest.push_back( 
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.696805,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.637678,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.381112,-99) , 
0, 329.799, 0, 0, 0.528577,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.531678,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.291091,-99) , 
6, 231.586, 0, 0, 0.394467,-99) , 
6, 159.519, 1, 0, 0.473695,-99) , 
5, 161.919, 0, 0, 0.520375,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.542951,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.383978,-99) , 
4, 105.563, 1, 0, 0.481887,-99) , 
NN(
0, 
0, 
-1, 524.216, 1, -1, 0.33688,-99) , 
9, -0.149909, 0, 0, 0.415643,-99) , 
8, 0.298815, 0, 0, 0.482998,-99) , 
NN(
0, 
0, 
-1, 0.359913, 0, -1, 0.266501,-99) , 
7, 613.829, 1, 0, 0.453884,-99)    );
  // itree = 11
  fBoostWeights.push_back(0.299614);
  fForest.push_back( 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.60583,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.596964,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.406941,-99) , 
7, 50.9628, 0, 0, 0.485381,-99) , 
6, 144.048, 0, 0, 0.533322,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.653263,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.518427,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.319035,-99) , 
1, 143.073, 0, 0, 0.421404,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.24924,-99) , 
1, 243.843, 1, 0, 0.369706,-99) , 
6, 260.973, 0, 0, 0.474777,-99) , 
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.574079,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.315031,-99) , 
9, -0.000320974, 0, 0, 0.442993,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.225701,-99) , 
9, 1.94013, 1, 0, 0.388686,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.0625163,-99) , 
7, 738.247, 1, 0, 0.322316,-99) , 
8, 0.392863, 0, 0, 0.400102,-99) , 
7, 153.457, 1, 0, 0.460137,-99)    );
  // itree = 12
  fBoostWeights.push_back(0.241949);
  fForest.push_back( 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.60329,-99) , 
NN(
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.554962,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.607548,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.462461,-99) , 
1, 76.1027, 0, 0, 0.531987,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.367418,-99) , 
8, 0.512372, 1, 0, 0.458046,-99) , 
5, 130.444, 0, 0, 0.498099,-99) , 
NN(
0, 
0, 
-1, 0.381914, 0, -1, 0.359165,-99) , 
7, 306.833, 1, 0, 0.470314,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.576097,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.393923,-99) , 
9, -0.156846, 1, 0, 0.473213,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.242834,-99) , 
3, 203.804, 0, 0, 0.37226,-99) , 
1, 266.608, 1, 0, 0.445185,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.249887,-99) , 
7, 920.743, 1, 0, 0.431714,-99) , 
8, 1.34426, 0, 0, 0.45243,-99)    );
  // itree = 13
  fBoostWeights.push_back(0.237384);
  fForest.push_back( 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.5836,-99) , 
NN(
NN(
NN(
NN(
NN(
0, 
0, 
-1, 130.493, 1, 1, 0.552888,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.337792,-99) , 
6, 89.6038, 0, 0, 0.512352,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.611053,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.400916,-99) , 
9, 0.146714, 0, 0, 0.522555,-99) , 
NN(
0, 
0, 
-1, 100.648, 1, -1, 0.352477,-99) , 
5, 122.138, 1, 0, 0.421713,-99) , 
7, 116.902, 1, 0, 0.465544,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.293964,-99) , 
0, 875.878, 1, 0, 0.453027,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.25571,-99) , 
7, 613.829, 1, 0, 0.435927,-99) , 
5, 195.493, 0, 0, 0.457383,-99)    );
  // itree = 14
  fBoostWeights.push_back(0.276679);
  fForest.push_back( 
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.663767,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.37421,-99) , 
3, 424.777, 1, 0, 0.53926,-99) , 
NN(
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.638901,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.453023,-99) , 
7, 219.166, 1, 0, 0.580657,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.584646,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.373512,-99) , 
7, 218.957, 1, 0, 0.513697,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.365011,-99) , 
0, 316.394, 0, 0, 0.454998,-99) , 
6, 124.913, 0, 0, 0.508556,-99) , 
NN(
0, 
0, 
-1, 95.3199, 1, -1, 0.357553,-99) , 
1, 220.832, 1, 0, 0.474238,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.341267,-99) , 
3, 230.22, 1, 0, 0.449495,-99) , 
3, 292.238, 0, 0, 0.464575,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.279376,-99) , 
7, 920.743, 1, 0, 0.454067,-99)    );
  // itree = 15
  fBoostWeights.push_back(0.272613);
  fForest.push_back( 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.650835,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.634912,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.507442,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.397341,-99) , 
9, -0.448799, 0, 0, 0.447768,-99) , 
2, -0.15233, 1, 0, 0.520727,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.345985,-99) , 
3, 198.783, 1, 0, 0.472356,-99) , 
6, 259.65, 0, 0, 0.512441,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.675627,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.610631,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.411606,-99) , 
2, 1.34379, 0, 0, 0.481763,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.257623,-99) , 
6, 84.85, 0, 0, 0.438543,-99) , 
0, 695.508, 0, 0, 0.476029,-99) , 
NN(
0, 
0, 
-1, 399.235, 0, -1, 0.28986,-99) , 
0, 852.442, 1, 0, 0.431141,-99) , 
8, 0.448164, 0, 0, 0.473913,-99)    );
  // itree = 16
  fBoostWeights.push_back(0.229111);
  fForest.push_back( 
NN(
NN(
0, 
0, 
-1, -0.1496, 1, 1, 0.593804,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.638496,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.450387,-99) , 
2, -1.64293, 1, 0, 0.565747,-99) , 
NN(
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.61421,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.591779,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.491767,-99) , 
8, 0.287304, 1, 0, 0.531294,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.336027,-99) , 
3, 154.76, 1, 0, 0.475104,-99) , 
4, 91.1028, 0, 0, 0.520541,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.506665,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.219767,-99) , 
8, 0.447947, 0, 0, 0.414219,-99) , 
4, 103.075, 1, 0, 0.487246,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.297423,-99) , 
0, 804.951, 1, 0, 0.467878,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.267824,-99) , 
3, 228.032, 1, 0, 0.445109,-99) , 
3, 264.043, 0, 0, 0.465211,-99) , 
6, 398.277, 0, 0, 0.478752,-99)    );
  // itree = 17
  fBoostWeights.push_back(0.191516);
  fForest.push_back( 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.559338,-99) , 
NN(
NN(
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.635833,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.458156,-99) , 
2, -2.71271, 0, 0, 0.567878,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.563177,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.443916,-99) , 
1, 70.8466, 0, 0, 0.493295,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.337914,-99) , 
1, 165.632, 1, 0, 0.458239,-99) , 
2, -0.149639, 1, 0, 0.509023,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.419908,-99) , 
3, 239.92, 1, 0, 0.493059,-99) , 
NN(
0, 
0, 
-1, 287.063, 0, -1, 0.382924,-99) , 
6, 211.98, 1, 0, 0.471111,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.322729,-99) , 
7, 613.829, 1, 0, 0.459496,-99) , 
5, 195.493, 0, 0, 0.474326,-99)    );
  // itree = 18
  fBoostWeights.push_back(0.227764);
  fForest.push_back( 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.606344,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.406993,-99) , 
9, -2.97066, 1, 0, 0.560939,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.669962,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.569832,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.57015,-99) , 
NN(
0, 
0, 
-1, -0.447709, 1, -1, 0.347469,-99) , 
5, 117.396, 1, 0, 0.421938,-99) , 
5, 161.919, 0, 0, 0.480024,-99) , 
6, 153.732, 1, 0, 0.527413,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.529221,-99) , 
NN(
0, 
0, 
-1, -0.149726, 1, -1, 0.377248,-99) , 
4, 85.3265, 1, 0, 0.437675,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.210513,-99) , 
0, 709.409, 1, 0, 0.410253,-99) , 
3, 189.704, 0, 0, 0.462429,-99) , 
9, -2.84239, 1, 0, 0.485047,-99)    );
  // itree = 19
  fBoostWeights.push_back(0.245919);
  fForest.push_back( 
NN(
NN(
NN(
0, 
0, 
-1, -1.0472, 1, 1, 0.596372,-99) , 
NN(
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.637331,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.362115,-99) , 
4, 88.1796, 0, 0, 0.5419,-99) , 
NN(
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.574509,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.533443,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.313782,-99) , 
1, 302.088, 0, 0, 0.433388,-99) , 
1, 157.737, 1, 0, 0.488163,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.315648,-99) , 
2, -1.01712, 0, 0, 0.434739,-99) , 
6, 140.791, 1, 0, 0.475293,-99) , 
NN(
NN(
0, 
0, 
-1, 0, 1, 1, 0.500396,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.234578,-99) , 
9, -1.04648, 0, 0, 0.392342,-99) , 
6, 88.28, 0, 0, 0.458703,-99) , 
3, 264.043, 0, 0, 0.486193,-99) , 
NN(
0, 
0, 
-1, 0, 1, -1, 0.33916,-99) , 
6, 464.34, 1, 0, 0.477011,-99)    );
   return;
};
 
// Clean up
inline void ReadBDT::Clear() 
{
   for (unsigned int itree=0; itree<fForest.size(); itree++) { 
      delete fForest[itree]; 
   }
}
   inline double ReadBDT::GetMvaValue( const std::vector<double>& inputValues ) const
   {
      // classifier response value
      double retval = 0;

      // classifier response, sanity check first
      if (!IsStatusClean()) {
         std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
                   << " because status is dirty" << std::endl;
         retval = 0;
      }
      else {
         if (IsNormalised()) {
            // normalise variables
            std::vector<double> iV;
            iV.reserve(inputValues.size());
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(NormVariable( *varIt, fVmin[ivar], fVmax[ivar] ));
            }
            retval = GetMvaValue__( iV );
         }
         else {
            retval = GetMvaValue__( inputValues );
         }
      }

      return retval;
   }
