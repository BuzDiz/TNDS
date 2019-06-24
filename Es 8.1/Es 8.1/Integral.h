#ifndef __Integral_h__
#define __Integral_h__
#include "FunzioneBase.h"

using namespace std;

class Integral
{
public:
  Integral(double a, double b, const FunzioneBase* f);
  double mid_point(int n_step);

  double Simpson(int n_step);
  int S_Error(double prec);

  double Trapezi(int n_step);
  int T_Error(double prec);
  
  double getA() { return I_a; }
  double getB() { return I_b; }

protected:
  int I_sign;

  double I_a, I_b;
  double I_sum;
  double I_h;
  double F_integral;

  const FunzioneBase * F_integrand;

};

#endif
