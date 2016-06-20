#ifndef __TREEEVENT_H__
#define __TREEEVENT_H__ 1

#include "CNTrack.h"
#include "CNTrackPair.h"
#include "EMCCluster.h"

#include <vector>

using namespace std;

class TreeEvent : public TObject  {
 private:
  float fBBCcharge;
  float fZVertex;
  float fCentrality;
  float fPsi_BBC;
  float fPsi_BBCN;
  float fPsi_BBCS;
  float fSvxz;
  float fRun;
  vector<CNTrack> fP;
  vector<CNTrack> fN;
  vector<CNTrackPair> fDL;
  vector<EMCCluster> fEMCC;

 public:
  TreeEvent();
  virtual ~TreeEvent() {};
  
  void ClearEvent();
  
  void SetRunNumber(int val)    { fRun = val; };
  void SetBBCcharge(float val)  { fBBCcharge = val; };
  void SetVtxZ(float val)       { fZVertex = val; }
  void SetCentrality(float val) { centrality = val; };
  void SetPsiBBC(float val)     { fPsi_BBC = val; };
  void SetPsiBBCN(float val)    { fPsi_BBCN = val; };
  void SetPsiBBCS(float val)    { fPsi_BBCS = val; };
  void SetSvxZ(float val)       { fSvxz = val; };

  int   GetRunNumber()  { return fRun; }
  float GetBBCcharge()  { return fBBCcharge; };
  float GetVtxZ()       { return fZVertex; }
  float GetCentrality() { return fCentrality; };
  float GetPsiBBC()     { return fPsi_BBC; };
  float GetPsiBBCN()    { return fPsi_BBCN; };
  float GetPsiBBCS()    { return fPsi_BBCS; };
  float GetSvxZ()       { return fSvxz; };
  
  void AddPTrack(CNTTrack val)    { fP.push_back(val); };
  void AddNTrack(CNTTrack val)    { fN.push_back(val); };
  void AddPair(CNTTrackPair val)  { fDL.push_back(val); };
  void AddCluster(EMCCluster val) { fEMCC.push_back(val); };
  
  int GetNPtracks()  { return fP.size(); };
  int GetNEtracks()  { return fE.size(); };
  int GetNpairs()    { return fDL.size(); };
  int GetNclusters() { return fEMCC.size(); };
  
  CNTrack&     GetPtrack(int i)  { return fP[i]; };
  CNTrack&     GetNtrack(int i)  { return fN[i]; };
  EMCCC&       GetCluster(int i) { return fEMCC[i]; };
  CNTrackPair& GetPair(int i)    { return fDL[i]; };
  
  vector<CNTrack>      GetPTracks()  { return fP; };
  vector<CNTrack>      GetNTracks()  { return fN; };
  vector<EMCC>         GetClusters() { return fEMCC; };
  vector<CNTTrackPair> GetPairs()    { return fDL; };
  
  ClassDef(TreeEvent,1)
    };

#endif

ClassImp(TreeEvent)

void MyEvent::ClearEvent() {
  fBBCcharge  = -999;
  fZVertex    = -999;
  fCentrality = -999;
  fPsi_BBC    = -999;
  fPsi_BBCN   = -999;
  fPsi_BBCS   = -999;
  fSvxz       = -999;
  fRun        = -999;
};

void MyEvent::ClearEvent() {
  fP.clear();
  fN.clear();
  fDL.clear();
  fEMCC.clear();
}
