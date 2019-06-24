#include "Vettore.h"
#include <iostream>
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
