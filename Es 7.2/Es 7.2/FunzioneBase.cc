#include "FunzioneBase.h"
#include <cmath>

Parabola::Parabola(double a, double b, double c)
{
	m_a = a;
	m_b = b;
	m_c = c;
}

Parabola::~Parabola() {}

double Parabola::eval(double x) const
{
	return (m_a * pow(x, 2) + m_b * x + m_c);
}
