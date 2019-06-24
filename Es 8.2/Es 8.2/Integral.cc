#include "Integral.h"
#include "FunzioneBase.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

Integral::Integral(double a, double b, const FunzioneBase* f)
{
  I_a = min(a, b);
  I_b = max(a, b);
  F_integrand = f;
  if(a > b) I_sign = -1;
  else I_sign = 1;
}

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
