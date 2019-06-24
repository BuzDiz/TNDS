#include "Integral.h"
#include "RandomGen.h"
#include "FunzioneBase.h"

#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>


using namespace std;

Integral::Integral(double a, double b, const FunzioneBase* f)
{
  I_a = min(a, b);
  I_b = max(a, b);
  F_integrand = f;
  if(a > b) I_sign = -1;
  else I_sign = 1;
}


// double Integral::EvaluateMax() {
//
// 	double z = _integrand->Eval(_a);
// 	double max;
//
// 		for(double delta = (_b - _a)/pow(10, 6); delta <= _b; delta += delta) {		//calcolo massimo della funzione per la valutazione dell'area del rettangolo
//
// 			if( z < _integrand->Eval(delta))
//
// 				max = _integrand->Eval(delta);
//
// 				z = _integrand->Eval(delta);
//
// 		}
//
//
//  return max;
//
//
// }

double Integral::mid_point(int n_step)
{
  I_sum = 0.;
  F_integral = 0.;
  I_h = (I_b - I_a)/n_step;

  for(unsigned int i = 0; i < n_step; i++)
  {
    I_sum += F_integrand->eval(I_a + (i + 0.5) * I_h);
  }
F_integral = I_sign * I_sum * I_h;
return F_integral;
}

double Integral::Simpson(int n_step)
{
  if(n_step%2 != 0)
  {
    cout << "Serve un numero pari di passi." << endl;
    return -1;
  }

	I_sum = 0.;
  F_integral = 0.;
	I_h = (I_b - I_a)/n_step;

  for(int k = 1; k < n_step; k = k + 2)
  {
    I_sum += 4./3. * (F_integrand->eval(I_a + k * I_h)) + 2./3. * (F_integrand->eval(I_a + (k + 1) * I_h));
  }

  I_sum = I_sum + 1./3. * (F_integrand->eval(I_a) + F_integrand->eval(I_b));
  F_integral = I_sign * I_sum * I_h;
  return F_integral;
}

int Integral::S_Error(double prec)
{
  int n2 = 2;
  int n = 0;
  double errore = 0.;

	do
  {
    n2 = n2 * 2;
    n = n2/2;

  	errore = (Simpson(n2) - Simpson(n))*16./(15*pow(n2, 4) );

  } while(errore*n2 > prec);
  return n;
}

double Integral::Trapezi(int n_step)
{
  I_sum = 0.;
  I_h = (I_b - I_a)/n_step;
  I_sum = (F_integrand->eval(I_b) + F_integrand->eval(I_a))* I_h/2;

  for(int i = 1; i < n_step - 1; i++)
  {
    I_sum += F_integrand->eval(I_a + (i * I_h));
	}

	F_integral = I_sign * I_sum * I_h;
	return F_integral;
}

int Integral::T_Error(double prec)
{
  int n2 = 2;
  int n = 1;
	long double errore = 0.;
  do
  {
		n2 = n2 + 2;
		n = n2/2;
    errore = (4./3.) * (fabs(Trapezi(n2) - Trapezi(n)));
  }
  while(errore > prec);
  return n2;
}

//MONTECARLO

//Media
double Integral::IntegraleAVG(int punti)
{
  double sum = 0.;
	double sum2 = 0.;
	RandomGen r(3);
	for(int i = 0; i < punti; i++)
  {
		double sample = r.LCG() * (I_b - I_a) + I_a;
		sum += F_integrand->eval(sample);
		sum2 += pow(F_integrand->eval(sample), 2);
	}

	double mean = ((I_b - I_a) * sum/punti)/(I_b - I_a);		// mean = ((I_b - I_a)*sum/punti)/(I_b - I_a)
	double meansquared = (I_b - I_a) * sum2/punti/(I_b - I_a);

	m_MeanMethodRMS = (I_b - I_a) * sqrt(meansquared - pow(mean, 2)) / sqrt(punti);		   //calcolo varianza alla fine del metodo

 return (I_b - I_a)*sum/punti;

}

int Integral::MeanStep(double prec)
{
	double sum = 0.;
	RandomGen r(3);
	double integral1, integral2;
	int punti = 1;

	do
  {
		integral1 = (I_b - I_a)*sum/punti;
		punti++;
		sum = 0.;

		for(int i = 0; i < punti; i++)
    {
			double sample = r.LCG() * (I_b - I_a) + I_a;
			sum += F_integrand->eval(sample);
		}

    integral2 = (I_b - I_a)*sum/punti;
	} while(abs(integral2 - integral1) > prec);

 return punti;

}



//Hit or Miss
double Integral::IntegraleHOM(int punti)
{
  double z = F_integrand->eval(I_a);
	double fmax;

	for(double delta = (I_b - I_a)/pow(10, 6); delta <= I_b; delta += delta)
  {
		if(F_integrand->eval(delta) > z)
    {
			fmax = F_integrand->eval(delta);
			z = F_integrand->eval(delta);
		}
	}

double area = (I_b - I_a)*fmax;
int n = 0;
RandomGen r(n + 1);

for(int i = 0; i < punti; i++)
  {
    double s = r.LCG();
    double t = r.LCG();
    double x = I_a + (I_b - I_a)*s;
    double y = fmax*t;
    if(F_integrand->eval(x) >= y)
    {
      n++;
    }
  }
  double p = (area*n/punti)/area;			//Calcolo dev std. Probabilità = n/punti
  m_HitRMS = area*sqrt(p*(1-p)/punti);

return area*n/punti;

}

int Integral::HOMStep(double prec)
{
  double z = F_integrand->eval(I_a);
  double fmax;

  for(double delta = (I_b - I_a)/pow(10, 6); delta <= I_b; delta += delta)
  {
    if(F_integrand->eval(delta) > z)
    {
      fmax = F_integrand->eval(delta);
      z = F_integrand->eval(delta);
    }
  }

  double area = (I_b - I_a)*fmax;
  int n = 0;
  RandomGen r(n + 1);
  double integral1, integral2;
  int punti = 1;

  do
  {
    integral1 = area*n/punti;
    punti++;
    n = 0;

    for(int i = 0; i < punti; i++)
    {
      double s = r.LCG();
      double t = r.LCG();
      double x = I_a + (I_b - I_a)*s;
      double y = fmax*t;
      if(F_integrand->eval(x) >= y)
      {
        n++;
      }
    }
    integral2 = area*n/punti;
  }
  while(abs(integral2 - integral1) > prec);

return punti;

}
