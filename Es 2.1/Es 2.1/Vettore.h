#ifndef __Vettore_h__
#define __Vettore_h__

class Vettore
{
  double *value;
  int index;

public:
  Vettore();
  Vettore(int a);

  int getIndex() const;
  void addValue(double vec);
  double getValue(int a);
  void scambia(int a, int b);
};

#endif
