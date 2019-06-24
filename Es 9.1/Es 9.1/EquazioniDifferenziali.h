#ifndef __EquazioniDifferenziali_h__
#define __EquazioniDifferenziali_h__
#include "VettoreLineare.h"

class FunzioneVettorialeBase
{
public:
  virtual VettoreLineare eval(double t, const VettoreLineare & v) const = 0; // = 0: virtuale puro
};

class OscillatoreArmonico: public FunzioneVettorialeBase
{
  double m_omega_0;

public:
  OscillatoreArmonico(double omega_0) { m_omega_0 = omega_0; }
  ~OscillatoreArmonico();

  virtual VettoreLineare eval(double t, const VettoreLineare & v) const;
};

class EquazioneDifferenzialeBase
{
  virtual VettoreLineare Passo(double t, const VettoreLineare & inizio, double h, FunzioneVettorialeBase * f) const = 0;
};

class Eulero: public EquazioneDifferenzialeBase
{
public:
  Eulero();
  ~Eulero();
  
  virtual VettoreLineare Passo(double t, const VettoreLineare & inizio, double h, FunzioneVettorialeBase * f) const;
};





#endif
