// $Id: SvxGeoTrack.h,v 1.1 2014/05/02 17:00:11 adare Exp $

#ifndef __SVXGEOTRACK_H__
#define __SVXGEOTRACK_H__

#include <vector>
#include <Rtypes.h>

class TGeoNode;

class SvxGeoHit
{
public:
  SvxGeoHit();
  ~SvxGeoHit() {};
  void Print();

  // This can differ from member x,y,z if geometry is changed after assignment.
  void GetCurrentXYZ(double &x, double &y, double &z);

  // These variables are "dumb", i.e. not synced to detector geometry.
  int layer,ladder,sensor,component,tile;
  double x,y,z;    // Global position.
  double xs,ys,zs; // Position on sensor wrt center point
  double ds,dz;    // Residuals to projected track position (s = Rdphi)
  double xsigma;   // Cluster size/resolution in x ~ s coord (cm)
  double zsigma;   // Cluster size/resolution in z coord (cm)
  int status;      // 0 bad, 1+ good.
  long trkid;      // Use to associate hit to a track
  float livefrac;  // Fraction of channels in tile that are good

  // This allows querying hit position in current geometry.
  TGeoNode *node;

  ClassDef(SvxGeoHit,1)
};

class SvxGeoTrack
{
public:
  SvxGeoTrack();
  ~SvxGeoTrack() {};
  SvxGeoHit GetHit(int i);
  void Print();

  int nhits;
  int charge;
  double vx,vy,vz;
  double mom, phi0, the0;
  double bfield;
  std::vector<SvxGeoHit> hits;

  ClassDef(SvxGeoTrack,1)
};


#endif // __SVXGEOTRACK_H__