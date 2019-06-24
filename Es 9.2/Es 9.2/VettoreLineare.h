#ifndef __VettoreLineare_h__
#define __VettoreLineare_h__
#include "Vettore.h"

class VettoreLineare: public Vettore
{
public:
  VettoreLineare(const VettoreLineare &);
  VettoreLineare(unsigned int);
  ~VettoreLineare();

  VettoreLineare operator+ (const VettoreLineare &) const; //Somma di vettori
  double operator* (const VettoreLineare &) const; //Prodotto tra vettori
  VettoreLineare operator* (const double) const; //Prodotto per uno scalare
};



#endif
