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
  int S_Error(double x);
  double Trapezi(int n_step);
  int T_Error(double x);

//metodi numerici casuali (Montecarlo)
  double IntegraleAVG(int punti);
  double IntegraleHOM(int punti);

  int HOMStep(double prec);

  int MeanStep(double prec);

  double getHitRMS() { return m_HitRMS; }
  double getMeanRMS() { return m_MeanMethodRMS; }

protected:
  int I_sign;
  double I_a, I_b;
  double I_sum;
  double I_h;
  double F_integral;

  const FunzioneBase * F_integrand;

  double m_MeanMethodRMS;
  double m_HitRMS;

};

#endif
