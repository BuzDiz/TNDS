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

Eulero::Eulero() {};

Eulero::~Eulero() {};

VettoreLineare Eulero::Passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase* f) const {
		VettoreLineare derivata(inizio.getIndex());
		derivata = inizio + (f->eval(t, inizio)) * h;

return derivata;
}
