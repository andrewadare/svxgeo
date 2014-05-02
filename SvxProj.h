// $Id: SvxProj.h,v 1.2 2014/05/02 17:53:54 adare Exp $

#ifndef __SVXPROJ_H__
#define __SVXPROJ_H__

#ifndef __SVXTGEO_H__
#include "SvxTGeo.h"
#endif

#ifndef __SVXGEOTRACK_H__
#include "SvxGeoTrack.h"
#endif

class SvxProj
{
public:
  SvxProj();
  ~SvxProj();

  double BendDelta(const double r,  // Straight-line proj. distance [cm]
                   const double pt, // p_{T} of particle [GeV/c]
                   const int Z,     // Charge/e (so usually +/- 1)
                   const double B); // B-field [T]. Sign = polarity.
  double BendDPhi(const double r,
                  const double pt,
                  const int Z,
                  const double B);

  void SensorAddress(TGeoNode *node, SvxGeoHit &hit);

  void FindHitsFromVertex(SvxGeoTrack &track, SvxTGeo *tgeo);

  void SetVerbosity(int v)
  {
    fVerbosity = v;
  }
protected:
  int fVerbosity;

  ClassDef(SvxProj,1)
};

#endif