#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>
using namespace std;

template <typename T> class Vettore
{
  T *value;
  int index;

public:
  Vettore() { value = new T[0];}
  Vettore(unsigned int n)
  {
    value = new T[n];
    index = 0;
  }
  Vettore(const Vettore & V)
  {
    value = V.value;
    index = V.index;
  }
  ~Vettore() { delete[] value; }

  Vettore& operator=(const Vettore& vec) {
  	index = vec.index;
  	if ( value ) delete[] value;
  	value = new double[index];
  	for(unsigned int i=0; i < index; i++)
  		value[i] = vec.value[i];

  	return *this;
  }

  int getIndex() const { return index; }
  void setValue(unsigned int n, T x) { value[n] = x; }
  void addVec(T x) { value[index++] = x; }
  T getValue(unsigned int a) const { return value[a]; }
  void scambia(int a, int b)
  {
    T c = value[a];
    value[a] = value[b];
    value[b] = c;
  }


};


#endif
