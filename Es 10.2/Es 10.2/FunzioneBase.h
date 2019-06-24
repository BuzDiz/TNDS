#ifndef __FunzioneBase_h__
#define __FunzioneBase_h__
#include <cmath>

class FunzioneBase
{
  public:
  virtual double eval(double x) const = 0;
};

class Parabola: public FunzioneBase
{
protected:
  double m_a, m_b, m_c;
public:
  Parabola(double a, double c, double d);
  ~Parabola();

  virtual double eval(double x) const;
  // void setA(double a) { m_a = a; }
  // double getA() const {return m_a; }
  // void setB(double b) { m_b = b; }
  // double getB() const {return m_b; }
  // void setC(double c) { m_c = c; }
  // double getC() const {return m_c; }
};

class Sinusoide: public FunzioneBase
{
public:
  virtual double eval(double x) const;
};

class Seno: public FunzioneBase
{
public:
  virtual double eval(double) const;
};

#endif
