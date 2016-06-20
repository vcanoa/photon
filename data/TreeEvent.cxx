#include "CNTrack.h"
#include "CNTrackPair.h"
#include "EMCCluster.h"

#include <vector>

using namespace std;

ClassImp(TreeEvent)

TreeEvent::TreeEvent() {
  fBBCcharge  = -999;
  fZVertex    = -999;
  fCentrality = -999;
  fPsi_BBC    = -999;
  fPsi_BBCN   = -999;
  fPsi_BBCS   = -999;
  fSvxz       = -999;
  fRun        = -999;
};

void TreeEvent::ClearEvent() {
  fP.clear();
  fN.clear();
  fDL.clear();
  fEMCC.clear();
}

void TreeEvent::Clear() {
  fBBCcharge  = -999;
  fZVertex    = -999;
  fCentrality = -999;
  fPsi_BBC    = -999;
  fPsi_BBCN   = -999;
  fPsi_BBCS   = -999;
  fSvxz       = -999;
  fRun        = -999;
}
