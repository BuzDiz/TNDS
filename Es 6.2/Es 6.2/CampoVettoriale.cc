#include "CampoVettoriale.h"
#include "Posizione.h"


CampoVettoriale::CampoVettoriale(const Posizione& pos): Posizione(pos)
{
	m_Fx = 0;
	m_Fy = 0;
	m_Fz = 0;
}
CampoVettoriale::CampoVettoriale(const Posizione& pos, double Fx, double Fy, double Fz): Posizione(pos)
{
	setFx(Fx);
	setFy(Fy);
	setFz(Fz);
}
CampoVettoriale::CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz): Posizione(x, y, z)
{
	setFx(Fx);
	setFy(Fy);
	setFz(Fz);
}

CampoVettoriale::~CampoVettoriale() {};

CampoVettoriale & CampoVettoriale::operator+=(const CampoVettoriale& c)
{
	return (*this) = (*this) + c;
}

CampoVettoriale CampoVettoriale::operator+(const CampoVettoriale& c) const
{
	CampoVettoriale somma(c);
	somma.m_Fx += getFx();
	somma.m_Fy += getFy();
	somma.m_Fz += getFz();
	return somma;
}
