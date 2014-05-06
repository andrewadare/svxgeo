
void AddLadder()
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

  // Add a ladder just like B1L9. It will be labeled B1L20.
  double xyz[3] = {0};
  geo->GetSensorXYZ(1, 9, 0, xyz);
  double phitilt = geo->GetLadderPhiTilt(1,9);
  geo->AddLadder(1, 20, xyz[0], xyz[1], 0., phitilt);
  
  // Now rotate B1L20 by angular difference between B1L9 and B1L8.
  double dphi = geo->SensorPhi(1,9,0) - geo->SensorPhi(1,8,0);
  geo->RotateLadder(1, 20, 0., 0., 180./TMath::Pi()*dphi);

  // Done building model.
  // Close geometry to check for problems (overlapping boundaries)
  mgr->CloseGeometry();

  // Press j,k to zoom; u,i to look up/down; h,l to look left, right.
  TCanvas *c = new TCanvas("c", "svx model", 1400, 1000);
  c->SetFillColor(kBlack);
  top->Draw();

  return;
}
