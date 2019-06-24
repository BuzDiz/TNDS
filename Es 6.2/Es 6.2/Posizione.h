#ifndef __Posizione_h__
#define __Posizione_h__
#include <cmath>
#include <string>
using namespace std;

class Posizione{
		double m_x, m_y, m_z;
public:
	Posizione();
	Posizione(double x, double y, double z);
	~Posizione();

	double X() const;
	double Y() const;
	double Z() const;
	double R() const;
	double Phi() const;
	double Theta() const;
	double Rho() const;
	double Distanza(const Posizione&) const;
	double Distanza(const Posizione*) const;
	double modulo_pos() { return sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2)); }
};




#endif
