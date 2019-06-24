#include "RandomGen.h"
#include "Gauss.h"
#include <cmath>
#include <iostream>
using namespace std;

RandomGen::RandomGen(int a)
{
	m_seed = a;
	m_a = 1664525;
	m_c = 1013904223;
	m_m = pow(2,31);
};

RandomGen::RandomGen() {};

double RandomGen::LCG(double x_min, double x_max) //LCG con intervallo
{
	unsigned int test = (m_a * m_seed + m_c) % m_m;
	m_seed = test;

	return x_min + (x_max - x_min)*double(test)/(2*double(m_m - 1));
}

double RandomGen::LCG() //LCG tra 0 e 1
{
	unsigned int test = (m_a * m_seed + m_c) % m_m;
	m_seed = test;

	return double(test)/(2*double(m_m - 1));
}


double RandomGen::Exp()
{
	double k = this->LCG();
	double result = -(log(1 - k))/m_r;

	return result;
}

double RandomGen::GausBM(double mean, double sigma)
{
	double s = LCG();
	double t = LCG();
	double x = sqrt(-2.*log(s)) * cos(2.*M_PI*t);

	return mean + sigma * x;
}

double RandomGen::GausAR(Gauss *g, double a, double b)
{
	start:
	//Faccio GausBM (Va bene qualsiasi altra funzione, l'esercizio richiedeva questa)
	double max = g->GetMax();
	double s = LCG();
	double t = LCG();
	double x = a + (b - a)*s;
	double y = max*t;									//max = 1 perchè la gaussiana è normalizzata.
if(g->eval(x) >= y) return x;
else goto start;

}
