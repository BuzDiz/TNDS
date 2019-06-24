#ifndef __CampoVettoriale_h__
#define __CampoVettoriale_h__
#include "Posizione.h"

class CampoVettoriale: public Posizione
{
  double m_Fx, m_Fy, m_Fz;

public:
  CampoVettoriale(const Posizione& );
  CampoVettoriale(const Posizione& , double Fx, double Fy, double Fz);
  CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz);
  ~CampoVettoriale();

  CampoVettoriale & operator+=(const CampoVettoriale& );
  CampoVettoriale operator+(const CampoVettoriale& ) const;

  void setFx(double fx) { m_Fx = fx; }
  void setFy(double fy) { m_Fy = fy; }
  void setFz(double fz) { m_Fz = fz; }

  double getFx() const { return m_Fx; }
  double getFy() const { return m_Fy; }
  double getFz() const { return m_Fz; }

  double modulo_c() { return sqrt(pow(m_Fx, 2) + pow(m_Fy, 2) + pow(m_Fz, 2)); };
};

#endif
