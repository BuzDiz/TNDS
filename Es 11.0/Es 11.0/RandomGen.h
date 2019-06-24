#ifndef __Random_h__
#define __Random_h__
#include "Gauss.h"

class RandomGen
{
private:

	int m_a, m_c, m_m;
	int m_seed;
	double m_r;


public:
	RandomGen(int);
	RandomGen();

	void SetA(unsigned int a) { m_a = a; }
	void SetC(unsigned int c) { m_c = c; }
	void SetM(unsigned int m) { m_m = m; }
	void SetSeed(unsigned int seed) { m_seed = seed; }
	void SetExpRate(double r) { m_r = r; }

	double LCG(double, double);
	double LCG(); 														//Linear Congruential Generator (Distribuzione uniforme)
	double Exp();															//Distribuzione esponenziale
	double GausBM(double, double);						//Distribuzione gaussiana (Box-Muller)
	double GausAR(Gauss *, double, double);						//Distribuzione gaussiana (A-R)
};




#endif
