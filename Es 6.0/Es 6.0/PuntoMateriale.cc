#include "PuntoMateriale.h"
#include "Posizione.h"
#include "Particella.h"
#include "CampoVettoriale.h"
#include <iostream>
#include <cmath>
#define k 8.99E9
#define G 6.67E-11

using namespace std;

PuntoMateriale::PuntoMateriale(double massa, double carica, double x, double y, double z): Particella(massa, carica), Posizione(x, y, z) { }


PuntoMateriale::~PuntoMateriale() {}

CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& pos) const
{
	CampoVettoriale e(pos);
	e.setFx(k * GetCarica() * X() / pow(Distanza(pos), 2));
	e.setFy(k * GetCarica() * Y() / pow(Distanza(pos), 2));
	e.setFz(k * GetCarica() * Z() / pow(Distanza(pos), 2));
	return e;
}

CampoVettoriale PuntoMateriale::CampoGravitazionale (const Posizione& pos) const
{
	CampoVettoriale g(pos);
	g.setFx(G * GetMassa() * X() / pow(Distanza(pos), 2));
	g.setFy(G * GetMassa() * Y() / pow(Distanza(pos), 2));
	g.setFz(G * GetMassa() * Z() / pow(Distanza(pos), 2));
	return g;
}
