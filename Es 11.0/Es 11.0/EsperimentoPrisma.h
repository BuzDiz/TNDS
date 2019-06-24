#ifndef __EsperimentoPrisma_h__
#define __EsperimentoPrisma_h__

#include "RandomGen.h"
#include "Vettore.h"
#include <fstream>
#include <iostream>

using namespace std;

class EsperimentoPrisma
{
private:
	RandomGen m_random;
	double m_lambda1, m_lambda2, m_alpha, m_sigmat;

	double m_A_in, m_A_out;
	double m_B_in, m_B_out;
	double m_n1_in, m_n1_out;
	double m_n2_in, m_n2_out;
	double m_t0_in, m_t0_out;
	double m_t1_in, m_t1_out;
	double m_t2_in, m_t2_out;
	double m_dm1_in, m_dm2_in;

	Vettore saved_t0_out, saved_t1_out, saved_t2_out;
	Vettore saved_n1_out, saved_n2_out;
	Vettore saved_A_out, saved_B_out;
	Vettore saved_dm1_out, saved_dm2_out;

	ofstream stampa;

	public:

		EsperimentoPrisma();
		~EsperimentoPrisma();

		void Esegui(unsigned int n);
		void Analizza(int n);

		void StampaGraficoDistribuzione(char* nome_istogramma, Vettore dati, double ext_sx, double ext_dx);
		void StampaGraficoCorrelazione(char* nome_istogramma, Vettore x, Vettore y, unsigned int n_valori);

};



#endif
