#ifndef __Particella_h__
#define __Particella_h__
#include "Posizione.h"
#include <string>
#include <cmath>

class Particella
{
  double m_massa;
  double m_carica;

  public:
    Particella(double massa, double carica);
    ~Particella();

    double GetMassa() const { return m_massa; }
    double GetCarica() const { return m_carica; }

    void Print() const;
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
    double GetPotenziale(const Posizione*) const;
		// double GetPotenziale(const Posizione) const;

		void Print() const;

};
#endif
