#include "Gauss.h"
#include <cmath>

Gauss::Gauss(double mean, double sigma)
{
	m_mean = mean;
	m_sigma = sigma;
}


double Gauss::eval(double x)
{
	return exp(-pow(x-m_mean,2)/(2*pow(m_sigma,2)))/(m_sigma*sqrt(2*M_PI));
}


double Gauss::GetMax()
{
	return eval(m_mean);
}
