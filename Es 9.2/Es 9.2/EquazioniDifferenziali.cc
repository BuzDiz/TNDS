#include "EquazioniDifferenziali.h"
#include "VettoreLineare.h"
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

OscillatoreArmonico::~OscillatoreArmonico() {}

VettoreLineare OscillatoreArmonico::eval(double t, const VettoreLineare & v) const
{
  VettoreLineare sol(2);
  sol.setValue(0, v.getValue(1));
  sol.setValue(1, -pow(m_omega_0, 2) * v.getValue(0));
return sol;
}

Eulero::Eulero() {}

Eulero::~Eulero() {}

VettoreLineare Eulero::Passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase* f) const
{
		VettoreLineare derivata(inizio.getIndex());
		derivata = inizio + (f->eval(t, inizio)) * h;
return derivata;
}

RungeKutta::RungeKutta() {}
RungeKutta::~RungeKutta() {}

VettoreLineare RungeKutta::Passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase* f) const
{
	VettoreLineare final(inizio.getIndex());
	VettoreLineare k1(inizio.getIndex()), k2(inizio.getIndex()), k3(inizio.getIndex()), k4(inizio.getIndex());
	k1 = f->eval(t, inizio);
	k2 = f->eval(t + h/2., inizio + (k1 * h)*0.5 );
	k3 = f->eval(t + h/2., inizio + (k2 * h)*0.5 );
	k4 = f->eval(t + h, inizio + (k3 * h));
	final = inizio + (k1 + k2 * 2 + k3 * 2 + k4) * (h/6.);

return final;
}
