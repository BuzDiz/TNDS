#ifndef __PuntoMateriale_h__
#define __PuntoMateriale_h__

#include "Posizione.h"
#include "Particella.h"
#include "CampoVettoriale.h"
using namespace std;

class PuntoMateriale: public Particella, Posizione
{
public:
  PuntoMateriale(double massa, double carica, const Posizione& );
  PuntoMateriale(double massa, double carica, double x, double y, double z);
  ~PuntoMateriale();

  CampoVettoriale CampoElettrico(const Posizione& ) const;
  CampoVettoriale CampoGravitazionale(const Posizione& ) const;
};

#endif
