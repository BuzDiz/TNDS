#ifndef __Posizione_h__
#define __Posizione_h__
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

class Posizione{
		double m_x, m_y, m_z;
public:
	Posizione();
	Posizione(double x, double y, double z);
	~Posizione();

	double X() const;
	double Y() const;
	double Z() const;
	double R() const;
	double Phi() const;
	double Theta() const;
	double Rho() const;
	double Distanza(const Posizione&) const;
};

class Corpoceleste: public Posizione
{
	double m_massa, m_raggio;
	string m_nome;

	public:
		Corpoceleste(string nome, double massa, double raggio, double x, double y, double z);
		~Corpoceleste();

		void SetNome(string nome) { m_nome = nome; }
		void SetMassa(double massa) { m_massa = massa; }
		void SetRaggio(double raggio) { m_raggio = raggio; }
		string GetNome() const { return m_nome; }
		double GetRaggio() const { return m_raggio; }

		double GetPosizione() { return sqrt(pow(X(), 2) + pow(Y(), 2) + pow(Z(), 2)); }
		double GetPotenziale(const Posizione&) const;
		// double GetPotenziale(const Posizione) const;

		void Print() const;

};

#endif
