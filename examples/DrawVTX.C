
void DrawVTX()
{
  SvxTGeo *geo = new SvxTGeo;
  geo->ReadParFile("parfiles/svxPISA.par");

  // Make an empty 100x100x100 cm^3 space (x,y,z dimensions are optional args)
  geo->MakeTopVolume();

  // Place VTX sensors in the volume.
  geo->AddSensors();
  geo->SetSensorColors(kAzure+6, 50); // 2nd arg is alpha as a percentage

  // Get handles for further manipulation
  TGeoManager *mgr = geo->GeoManager();
  TGeoVolume *top = mgr->GetTopVolume();

  // Done building model.
  // Close geometry to check for problems (overlapping boundaries)
  mgr->CloseGeometry();

  // Perform a few nonsensical manipulations for obvious demonstration.
  // enum EW {EAST=0, WEST=1};
  // geo->RotateArm(WEST, 0, 0, TMath::PiOver2());
  // geo->TranslateArm(WEST, 20., 0., 0);
  // geo->TranslateHalfLayer(3, 1, 10., 0., 0);
  // geo->RotateHalfLayer(3, 1, TMath::Pi()/4, 0., 0);

  // Press j,k to zoom; u,i to look up/down; h,l to look left, right.
  TCanvas *c = new TCanvas("c", "svx model", 1400, 1000);
  c->SetFillColor(kBlack);  
  top->Draw("ogl");

  top->SetVisibility(false);

  // top->Raytrace();
  gPad->GetView()->ShowAxis();

  return;
}
