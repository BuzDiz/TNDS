#include "Vettore.h"
#include <iostream>
#include <cmath>
using namespace std;

Vettore::Vettore()
{
  value = NULL;
  index = 0;
}

Vettore::Vettore(unsigned int n)
{
  index = n;
  value = new double[index];
  for(unsigned int i = 0; i < index; i++)
    value[i] = 0.;
}

Vettore::Vettore(const Vettore& vec)
{
	index = vec.index;
	value = new double[index];
	for(unsigned int i = 0; i < index; i++)
		value[i] = vec.value[i];
}

Vettore::~Vettore() {}

int Vettore::getIndex() const
{
  return index;
}

double Vettore::getValue(unsigned int a) const
{
  return value[a];
}


void  Vettore::addValue(double x)
{
  value[index++] = x;
}

void Vettore::scambia(unsigned int a, unsigned int b) const
{
  double c = value[a];
  value[a] = value[b];
  value[b] = c;
}

void Vettore::setValue(unsigned int n, double x)
{
  value[n] = x;
  index = n + 1;
}

Vettore& Vettore::operator=(const Vettore& vec)
{
	index = vec.index;
	if ( value ) delete[] value;
	value = new double[index];
	for(unsigned int i = 0; i < index; i++)
		value[i] = vec.value[i];

	return *this;
}

//metodi per EsperimentoPrisma


double Vettore::getMean() {

	double mean = 0.;

		for(int i = 0; i < index; i++)

			mean += getValue(i);


	m_mean = mean/index;

 return m_mean;

}


double Vettore::getRMS() {

	double x2 = 0.;
	double mean = getMean();

	for(int i = 0; i < index; i++)

		x2 += pow(getValue(i), 2);

	x2 = x2/index;


 return sqrt(x2 - pow(mean, 2));

}

double Vettore::getCorrelazione(Vettore a) {

	double x = 0.;

		for(int i = 0; i < index; i++) {

			x += getValue(i)*a.getValue(i);


		}

 return 100*(x/index - getMean()*a.getMean() )/( getRMS()*a.getRMS() );

}


double Vettore::getMax() {

	double max = 0.;

		for(int i = 0; i < index; i++) {

			double a = getValue(i);

				if( a > max)

					max = a;

		}


 return max;

}


double Vettore::getMin() {

	double min = getValue(0);

		for(int i = 1; i < index; i++) {


			double a = getValue(i);

				if(min > a)

					min = a;


		}

 return min;

}
