#include "Posizione.h"
#include "Particella.h"
#include <cmath>
#include <iostream>
#include <cstring>
#define G 6.67E-11

using namespace std;

Posizione::Posizione()
{
	m_x=0.;
	m_y=0.;
	m_z=0.;
}

Posizione::Posizione(double x, double y, double z)
{
	m_x=x;
	m_y=y;
	m_z=z;
}

Posizione::~Posizione() { }

//Cartesiane

double Posizione::X() const
{
	return m_x;
}

double Posizione::Y() const
{
	return m_y;
}

double Posizione::Z() const
{
	return m_z;
}

//Sferiche

double Posizione::R() const
{
	return sqrt(m_x * m_y * m_z);
}

double Posizione::Phi() const
{
	return atan2(m_y , m_x);
}

double Posizione::Theta() const
{
	return acos(m_z / R());
}


//Raggio cilindrico

double Posizione::Rho() const
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

double Posizione::Distanza(const Posizione& pos) const
{
	return sqrt(pow(X() - pos.X(), 2) + pow(Y() - pos.Y(), 2) + pow(Z() - pos.Z(), 2));
}

double Posizione::Distanza(const Posizione* pos) const
{
	return sqrt(pow(X() - pos->X(), 2) + pow(Y() - pos->Y(), 2) + pow(Z() - pos->Z(), 2));
}
