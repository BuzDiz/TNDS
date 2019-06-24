#include "Posizione.h"
#include "Particella.h"
#include <iostream>
#include <cstring>
#define G 6.67E-11
using namespace std;

Particella::Particella(double massa, double carica){
	m_massa = massa;
	m_carica = carica;
}

Particella::~Particella() { };

void Particella::Print() const
{
	cout << "Massa della particella: " << m_massa << endl;
	cout << "Carica della particella: " << m_carica << endl;
}


Corpoceleste::Corpoceleste(string nome, double massa, double raggio, double x, double y, double z): Posizione(x, y, z)
{
	m_nome = nome;
	m_massa = massa;
	m_raggio = raggio;
}

Corpoceleste::~Corpoceleste() { };

void Corpoceleste::Print() const {
	cout << m_nome << ": " << endl;
	cout << "Massa: " << m_massa << " kg " << endl;
	cout << "Raggio: " << m_raggio << " m " << endl;
}

double Corpoceleste::Getg(Posizione& pos)
{
	return (G * GetMassa()) / (pow(Distanza(pos), 2));
}

double Corpoceleste::Getg(Posizione* pos)
{
	return (G * GetMassa()) / (pow(Distanza(pos), 2));
}

double Corpoceleste::GetPotenziale(const Posizione& dist) const{
	return ((-G * GetMassa()) / Distanza(dist));
}

double Corpoceleste::GetPotenziale(const Posizione* dist) const{
	return ((-G * GetMassa()) / Distanza(dist));
}
