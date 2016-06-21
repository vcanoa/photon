#include "PhotonEvent.h"
#include "CNTE.h"
#include "CNTDE.h"
#include "EMCC.h"

#include <vector>

using namespace std;

ClassImp(PhotonEvent)

PhotonEvent::PhotonEvent() {
  fBBCcharge  = -999;
  fZVertex    = -999;
  fCentrality = -999;
  fPsi_BBC    = -999;
  fPsi_BBCN   = -999;
  fPsi_BBCS   = -999;
  fSvxz       = -999;
  fRun        = -999;
};

void PhotonEvent::ClearEvent() {
  fP.clear();
  fN.clear();
  fDE.clear();
  fEMCC.clear();
}
