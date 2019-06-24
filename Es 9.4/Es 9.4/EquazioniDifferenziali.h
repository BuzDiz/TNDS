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

class OscillatoreArmonicoSmorzato: public FunzioneVettorialeBase
{
private:

  double m_omega_0;
  double m_alpha;
  double m_forzante;

public:
	OscillatoreArmonicoSmorzato(double omega_0, double alpha, double forzante) { m_omega_0 = omega_0; m_alpha = alpha; m_forzante = forzante; }
	~OscillatoreArmonicoSmorzato();

	void setOmega_0(double omega_0) { m_omega_0 = omega_0; }
	double getOmega_0() { return m_omega_0; }

	void setForzante(double forzante) { m_forzante = forzante; }
	double getForzante() { return m_forzante; }

	void setAlpha(double alpha) { m_alpha = alpha; }
	double getAlpha() { return m_alpha; }

	virtual VettoreLineare eval(double t, const VettoreLineare& x) const;


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

class RungeKutta: public EquazioneDifferenzialeBase
{
public:
  RungeKutta();
  ~RungeKutta();

  virtual VettoreLineare Passo(double t, const VettoreLineare & inizio, double h, FunzioneVettorialeBase * f) const;
};

class Pendolo: public FunzioneVettorialeBase
{
public:
	Pendolo(double l) { m_l = l; }
	~Pendolo();
	double GetL() { return m_l; }

	virtual VettoreLineare eval(double t, const VettoreLineare& x) const;

private:
	double m_l;
};



#endif
