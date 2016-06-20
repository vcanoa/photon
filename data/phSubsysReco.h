#ifndef __phSubsysReco_HH__
#define __phSubsysReco_HH__

#include "SubsysReco.h"
#include <vector>

class PHCompositeNode;
class TH1F;

using namespace std;

class phSubsysReco: public SubsysReco {
 public:
  phSubsysReco( const char* name = "phSubsysReco" );
  virtual ~phSubsysReco();

  virtual int Init(PHCompositeNode*);
  virtual int InitRun(PHCompositeNode*);
  virtual int process_event(PHCompositeNode*);
  virtual int End(PHCompositeNode *topNode);
  void QA(int level) {fQA=level;}
  void Debug() {fDebug=true;}

 protected:
  bool PassEventCuts(PHCompositeNode*);
  bool fDebug;
  int fQA;
  int fTRIGGER_BIT;
  vector<int> fE;
  vector<int> fP;

  TH1F *fEvents;
};

#endif /* __phSubsysReco_H__ */ 
