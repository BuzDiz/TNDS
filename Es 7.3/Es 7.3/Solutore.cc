#include "Solutore.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

Valuta::Valuta()
{
	s_a = 0;
	s_b = 0;
	f_prec = 0;
}

Valuta::Valuta(double a, double b, double prec)
{
	s_a = a;
	s_b = b;
	f_prec = prec;
}

Valuta::~Valuta() {}

int sign(double x)
{
	int a = 0;
	if(x < 0)
		a = -1;
	if(x > 0)
		a = 1;
	if(x == 0.)
		a = 0;
	return a;

}

double c = 0;

double Valuta::cercaZeri(const FunzioneBase* f)
{
	if(sign(f->eval(s_a)) == 0)
	{
		c = s_a;
	}

	else if(sign(f->eval(s_b)) == 0)
	{
		c = s_b;
	}

	else
	{
		while(fabs(s_b - s_a) > f_prec)
		{
			c = (s_b + s_a)/2;
			if(sign(f->eval(s_a)) * sign(f->eval(c)) < 0)
				s_b = c;

			else if(sign(f->eval(s_b)) * sign(f->eval(c)) < 0)
				s_a = c;

			else
				return c;
		}
	return c;
	}
}

	// (sign(f->eval(s_a)) * sign(f->eval(s_b)) < 0)
	// {
	//
	// 	while(fabs(s_b - s_a) > f_prec)
	// 	{


void Valuta::Print()
{
	cout << fixed;
	cout << "Lo zero si trova in x = " << setprecision(int(-log10(f_prec))) << c << endl;
}
