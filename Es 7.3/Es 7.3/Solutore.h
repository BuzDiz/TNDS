#ifndef __Solutore_h__
#define __Solutore_h__
#include "FunzioneBase.h"

int sign(double x);

class Solutore
{
protected:
  double s_a, s_b;
  double f_prec;
  const FunzioneBase* F;

public:
  virtual double cercaZeri(const FunzioneBase* f) = 0;
  // void sets_a(double x) { s_a = x; }
  // double gets_a() { return s_a; }
  // void sets_b(double x) { s_b = x; }
  // double gets_b() { return s_b; }

	void setPrecision(double epsilon) { f_prec = epsilon; }
	double getPrecision() { return f_prec; }
};

class Valuta: public Solutore
{
public:
	Valuta();
	Valuta(double a, double b, double prec);
	~Valuta();

	double cercaZeri(const FunzioneBase* f);
	void Print();
};

#endif
