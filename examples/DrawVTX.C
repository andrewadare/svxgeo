#include "SvxTGeo.C"

#include <TCanvas.h>
#include <TGeoManager.h>
#include <TGeoVolume.h>

void DrawVTX()
{
  SvxTGeo *geo = new SvxTGeo;
  geo->ReadParFile("parfiles/svxPISA.par");

  // Make an empty 100x100x100 cm^3 space in the experiment hall.
  geo->MakeTopVolume(200/2, 200/2, 200/2);

  // Place VTX sensors in the volume.
  geo->AddSensors();

  // Get handles for further manipulation
  TGeoManager *mgr = geo->GeoManager();
  TGeoVolume *top = mgr->GetTopVolume();

  // Done building model.
  // Close geometry to check for problems (overlapping boundaries)
  mgr->CloseGeometry();

  // Press j,k to zoom; u,i to look up/down; h,l to look left, right.
  TCanvas *c = new TCanvas("c", "svx model", 1400, 1000);
  c->SetFillColor(kBlack);
  top->Draw();

  return;
}
