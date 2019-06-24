#ifndef __Gauss_h__
#define __Gauss_h__

class Gauss
{
protected:

	double m_mean;
	double m_sigma;

public:
	Gauss(double, double);

	void SetMean(double mean) { m_mean = mean; }
	void SetSigma(double sigma) { m_sigma = sigma; }

	double eval(double);
	double GetMax();

};

#endif
