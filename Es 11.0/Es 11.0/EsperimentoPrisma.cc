#include "EsperimentoPrisma.h"
#include "RandomGen.h"
#include "Gauss.h"
#include "Vettore.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include "TCanvas.h"
#include "TApplication.h"
#include "TH1F.h"
#include "TH2F.h"

using namespace std;



EsperimentoPrisma::EsperimentoPrisma():
	m_random(3),
	m_lambda1(579.1E-9),		//giallo
	m_lambda2(404.7E-9),		//viola
	m_alpha(60.*M_PI/180.),		//60. : x = 180. : M_PI
	m_sigmat(0.3E-3),
	m_A_in(2.7),
	m_B_in(60000E-18)

 {
	 stampa.open("Analisi.txt");

		m_n1_in = sqrt(m_A_in + m_B_in/pow(m_lambda1, 2));		//legge di Cauchy
		m_n2_in = sqrt(m_A_in + m_B_in/pow(m_lambda2, 2));

		m_t0_in = M_PI/2.;

 		m_dm1_in = 2. * asin(m_n1_in * sin(0.5 * m_alpha)) - m_alpha;
		m_t1_in = m_t0_in + m_dm1_in;

		m_dm2_in = 2. * asin(m_n2_in * sin(0.5 * m_alpha)) - m_alpha;
		m_t2_in = m_t0_in + m_dm2_in;

 }

EsperimentoPrisma::~EsperimentoPrisma() {}

void EsperimentoPrisma::Esegui(unsigned int n)
{
	cout << "Eseguo " << n << " iterazioni dell'esperimento." << endl;
	cout << "Stampo gli istogrammi relativi alle distribuzioni dei valori misurati degli angoli di rifrazione e di deviazione minima, degli indici di rifrazione ottenuti e dei parametri A e B del materiale. Si effettua un'analisi sull'errore ottenuto tramite l'esperimento e quello ottenuto con propagazione, oltre a un'analisi dei coefficienti di correlazione tra valori misurati e attesi." << endl;

	Vettore a(n);

	saved_t0_out = a;
	saved_t1_out = a;
	saved_t2_out = a;
	a.~Vettore();

	Gauss* t0 = new Gauss(m_t0_in, m_sigmat);
	Gauss* t1 = new Gauss(m_t1_in, m_sigmat);
	Gauss* t2 = new Gauss(m_t2_in, m_sigmat);

  for(int i = 0; i < n; i++)
	{
		m_t0_out = m_random.GausAR(t0, m_t0_in - 3*m_sigmat, m_t0_in + 3*m_sigmat);
		m_t1_out = m_random.GausAR(t1, m_t1_in - 3*m_sigmat, m_t1_in + 3*m_sigmat);
		m_t2_out = m_random.GausAR(t2, m_t2_in - 3*m_sigmat, m_t2_in + 3*m_sigmat);

		saved_t0_out.setValue(i, m_t0_out);
		saved_t1_out.setValue(i, m_t1_out);
		saved_t2_out.setValue(i, m_t2_out);
	}

	StampaGraficoDistribuzione((char*)"Distribuzione theta0", saved_t0_out, m_t0_in - 3*m_sigmat, m_t0_in + 3*m_sigmat);
	StampaGraficoDistribuzione((char*)"Distribuzione theta1", saved_t1_out, m_t1_in - 3*m_sigmat, m_t1_in + 3*m_sigmat);
	StampaGraficoDistribuzione((char*)"Distribuzione theta2", saved_t2_out, m_t2_in - 3*m_sigmat, m_t2_in + 3*m_sigmat);

	stampa << endl;
	stampa << "ANALISI DATI:" << endl;

	stampa << "Analisi valor medio angoli misurati: " << endl << endl;

	stampa << "        " << "Valor medio misurato" << "        " << "Valore atteso" << endl << endl;

	stampa << "theta0: " << setw(15) << saved_t0_out.getMean() << setw (25) << m_t0_in << endl;
	stampa << "theta1: " << setw(15) << saved_t1_out.getMean() << setw (25) << m_t1_in  << endl;
	stampa << "theta2: " << setw(15) << saved_t1_out.getMean() << setw (25) << m_t2_in  << endl << endl;

	stampa << "Deviazione standard angoli: " << endl << endl;

  stampa << "RMS theta0: " << saved_t0_out.getRMS() << endl;
	stampa << "RMS theta1: " << saved_t1_out.getRMS() << endl;
	stampa << "RMS theta2: " << saved_t2_out.getRMS() << endl;


	delete t0;

}


void EsperimentoPrisma::Analizza(int n)
{
	Vettore a(n);
	saved_dm1_out = a;
	saved_dm2_out = a;
	saved_n1_out = a;
	saved_n2_out = a;
	saved_A_out = a;
	saved_B_out = a;
	a.~Vettore();

	for(int i = 0; i < n; i++)
	{
		saved_dm1_out.setValue(i, saved_t1_out.getValue(i) - saved_t0_out.getValue(i) );
		saved_dm2_out.setValue(i, saved_t2_out.getValue(i) - saved_t0_out.getValue(i) );

		saved_n1_out.setValue(i, sin( (saved_dm1_out.getValue(i) + m_alpha)/2. )/sin(m_alpha/2.) );
		saved_n2_out.setValue(i, sin( (saved_dm2_out.getValue(i) + m_alpha)/2. )/sin(m_alpha/2.) );

		m_A_out = (pow(m_lambda2, 2)*pow(saved_n2_out.getValue(i), 2) - pow(m_lambda1, 2)*pow(saved_n1_out.getValue(i), 2))/(pow(m_lambda2, 2) - pow(m_lambda1, 2.));
		m_B_out = (pow(saved_n2_out.getValue(i), 2) - pow(saved_n1_out.getValue(i), 2))/(1/pow(m_lambda2, 2) - 1/pow(m_lambda1, 2));

		saved_A_out.setValue(i, m_A_out );
		saved_B_out.setValue(i, m_B_out );
	}

//calcolo coefficienti di correlazione
	stampa << endl;
	stampa << "Valutazione dei coefficienti di correlazione: " << endl << endl;

	stampa << "Tra n(lambda1) e n(lambda2): " << saved_n1_out.getCorrelazione(saved_n2_out) << "%" << endl << endl;

	stampa << "Tra dm1 e dm2: " << saved_dm1_out.getCorrelazione(saved_dm2_out) << "%" << endl << endl;

	stampa << "Tra A e B: " << saved_A_out.getCorrelazione(saved_B_out) << "%" << endl << endl;

//Grafici
	StampaGraficoDistribuzione((char*)"Distribuzione dm1", saved_dm1_out, m_dm1_in - 3*saved_dm1_out.getRMS(), m_dm1_in + 3*saved_dm1_out.getRMS());
	StampaGraficoDistribuzione((char*)"Distribuzione dm2", saved_dm2_out, m_dm2_in - 3*saved_dm2_out.getRMS(), m_dm2_in + 3*saved_dm2_out.getRMS());

	StampaGraficoDistribuzione((char*)"Distribuzione n1", saved_n1_out, m_n1_in - 3*saved_n1_out.getRMS(), m_n1_in + 3*saved_n1_out.getRMS());
	StampaGraficoDistribuzione((char*)"Distribuzione n2", saved_n2_out, m_n2_in - 3*saved_n2_out.getRMS(), m_n2_in + 3*saved_n2_out.getRMS());

	StampaGraficoDistribuzione((char*)"Distribuzione A", saved_A_out, m_A_in - 3*saved_A_out.getRMS(), m_A_in + 3*saved_A_out.getRMS());
	StampaGraficoDistribuzione((char*)"Distribuzione B", saved_B_out, m_B_in - 3*saved_B_out.getRMS(), m_B_in + 3*saved_B_out.getRMS());

//istogrammi bidimensionali

	StampaGraficoCorrelazione((char*)"Correlazione dm1 e dm2", saved_dm1_out, saved_dm2_out, n);
	StampaGraficoCorrelazione((char*)"Correlazione n1 e n2",saved_n1_out, saved_n2_out, n);
	StampaGraficoCorrelazione((char*)"Correlazione A e B", saved_A_out, saved_B_out, n);

//differenze di errore tra sperimentali e propagazione errori

	double sigma_dm1_propagata = sqrt( pow(saved_t1_out.getRMS(), 2) + pow(saved_t0_out.getRMS(), 2));
	double sigma_dm2_propagata = sqrt( pow(saved_t2_out.getRMS(), 2) + pow(saved_t0_out.getRMS(), 2));

	double sigma_n1_propagata = sqrt(pow(cos((saved_dm1_out.getMean() + m_alpha)/2.)/(2*sin(m_alpha/2.)), 2) )*saved_dm1_out.getRMS();
	double sigma_n2_propagata = sqrt(pow(cos((saved_dm2_out.getMean() + m_alpha)/2.)/(2*sin(m_alpha/2.)), 2) )*saved_dm2_out.getRMS();

	stampa << endl;

	stampa << "Confronto tra errori misurati e propagati: " << endl;

	stampa << setw(18) << "RMS Empirica:" << setw(28) << "RMS Propagata:" << endl << endl;

	stampa << "dm1: " << setw(15) << saved_dm1_out.getRMS() << setw (25) << sigma_dm1_propagata << endl;
	stampa << "dm2: "<< setw(15) << saved_dm2_out.getRMS() << setw (25) << sigma_dm2_propagata  << endl << endl;

	stampa << "n1: " << setw(16) << saved_n1_out.getRMS() << setw (25) << sigma_n1_propagata  << endl;
	stampa << "n2: " << setw(16) << saved_n2_out.getRMS() << setw (25) << sigma_n2_propagata  << endl;

	stampa.close();

}

void EsperimentoPrisma::StampaGraficoDistribuzione(char* nome_istogramma, Vettore dati, double ext_sx, double ext_dx)
{
	TH1F h("Analisi", nome_istogramma, 100, ext_sx, ext_dx );

	for(int i = 0; i < dati.getIndex(); i++) h.Fill( dati.getValue(i) );

	TCanvas* c1 = new TCanvas(nome_istogramma, "Distribuzione");
	c1->cd();
	h.Draw();

	int a = string(nome_istogramma).length() + 5;

	char* stampa = new char[a];
	strcpy( stampa, nome_istogramma);

	c1->Print( strncat( stampa, ".pdf", 4 ) );

}


void EsperimentoPrisma::StampaGraficoCorrelazione(char* nome_istogramma, Vettore x, Vettore y, unsigned int n_valori)
{
	TH2F h("Correlazione", nome_istogramma, n_valori, x.getMin(), x.getMax(), n_valori, y.getMin(), y.getMax() );

	for(int i = 0; i < n_valori; i++) h.Fill( x.getValue(i), y.getValue(i) );

	TCanvas* c1 = new TCanvas(nome_istogramma, "Distribuzione");
	c1->cd();
	h.Draw();

	int a = string(nome_istogramma).length() + 5;

	char* stampa = new char[a];
	strcpy( stampa, nome_istogramma);

	c1->Print( strncat( stampa, ".pdf", 4 ) );

}
