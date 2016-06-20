#include "stdlib.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include "getClass.h"
#include "PHCompositeNode.h"
#include "RunHeader.h" 
#include "Fun4AllReturnCodes.h"
#include "Fun4AllServer.h"

#include "recoConsts.h"
#include "PHTimeStamp.h"

#include "phSubsysReco.h"

#include "TH1F.h"

using namespace std;
using namespace findNode;

//====================================================
phSubsysReco::phSubsysReco( const char* name ) : 
  SubsysReco( name ),
  fDebug(NULL),
  fQA(0)
{
  printf("mcReco::CTOR\n");
}
//====================================================
int phSubsysReco::End(PHCompositeNode *topNode) {
  return EVENT_OK;
}
//====================================================
phSubsysReco::~phSubsysReco() {
}
//====================================================
int phSubsysReco::Init(PHCompositeNode* top_node) {
  printf("phSubsysReco::Init\n");
  Fun4AllServer *se = Fun4AllServer::instance();

  fEvents = new TH1F("phSubsysReco_EVENTS","phSubsysReco_EVENTS",10,-0.5,9.5);
  se->registerHisto(fEvents);

  switch(fQA) {
  case(1):
    break;
  }
  return EVENT_OK;
}
//====================================================
int phSubsysReco::InitRun(PHCompositeNode* top_node) {
  printf("phSubsysReco::InitRun\n");
  RunHeader *runhead = getClass<RunHeader> (top_node, "RunHeader");
  if(!runhead) { cout<<PHWHERE<<" exiting."<<endl; exit(1); }
  int runno = runhead->get_RunNumber();

  if(fDebug) printf("phSubsysReco::InitRun || Run number %d\n",runno);

  return EVENT_OK; 
}
//====================================================
bool phSubsysReco::PassEventCuts(PHCompositeNode* top_node) {
  fEvents->Fill(0);

  // Triger
  TrigLvl1 *lvl1 = getClass<TrigLvl1>(top_node,"TrigLvl1");
  if(!lvl1) return false;
  int trigger = lvl1->get_level1_trigscaled_bit( fTRIGGER_BIT );
  if(!trigger) return false;

  // Multiplicity
  PHCentralTrack *cnt = getClass<PHCentralTrack> (top_node,"PHCentralTrack");
  if(!cnt) return false;
  fE.clear();
  fP.clear();
  for(int i=0; i!=int(cnt->get_npart()); ++i) {
    int   quality = cnt->get_quality(i);
    float zed     = cnt->get_zed(i);
    float emcdz   = cnt->get_emcdz(i);
    float emcdphi = cnt->get_emcdphi(i);
    float n0      = cnt->get_n0(i);
    float disp    = cnt->get_disp(i);
    float chi2    = cnt->get_chi2(i);
    float npe0    = cnt->get_npe0(i);
    float prob    = cnt->get_prob(i);
    float dep     = cnt->get_dep(i);
    // cuts
    if(cnt->get_charge(i)==-1) fP.push_back(i);
    if(cnt->get_charge(i)==+1) fE.push_back(i);
  }
  if(fP.size()<1||fE.size()<1) return false;

  return true;
}
//====================================================
int phSubsysReco::process_event(PHCompositeNode* top_node) {
  if(!PassEventCuts(top_node)) return ABORTEVENT;

  return EVENT_OK;
}
