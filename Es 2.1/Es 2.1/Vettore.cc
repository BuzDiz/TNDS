#include "Vettore.h"
#include <iostream>
using namespace std;

Vettore::Vettore()
{
  value = new double[0];
}

Vettore::Vettore(int x)
{
  value = new double[x];
  index = 0;
}

int Vettore::getIndex() const
{
  return index;
}

double Vettore::getValue(int a)
{
  return value[a];
}


void  Vettore::addValue(double vec)
{
  value[index++] = vec;
}

void Vettore::scambia(int a, int b)
{
  double c = value[a];
  value[a] = value[b];
  value[b] = c;
}
