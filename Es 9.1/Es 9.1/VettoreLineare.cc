#include "VettoreLineare.h"
#include "Vettore.h"
#include <iostream>
using namespace std;

VettoreLineare::VettoreLineare(unsigned int n): Vettore(n) {}

VettoreLineare::VettoreLineare(const VettoreLineare& vec)
{
	index = vec.index;
	value = new double[vec.index];
	for(unsigned int i=0; i < vec.index; i++)
		value[i] = vec.value[i];
}

VettoreLineare:: ~VettoreLineare() {}

VettoreLineare VettoreLineare::operator+(const VettoreLineare & b) const
{
  VettoreLineare r(index);

  if(index != b.index)
  {
  cerr << "Errore! Vettori di dimensione " << index << " e " << b.index << endl;
  exit(-2);
  }

  for(unsigned int i = 0; i < index; i++) r.setValue(i, value[i] + b.value[i]);
  return r;
}


double VettoreLineare::operator* (const VettoreLineare & b) const
{
  double prod = 0;
  for(unsigned int i = 0; i < index; i++) prod = value[i] * (b.value[i]);
  return prod;
}

VettoreLineare VettoreLineare::operator* (const double x) const
{
  VettoreLineare r(index);
  for(unsigned int i = 0; i < index; i++) r.setValue(i, x * value[i]);
  return r;
}
