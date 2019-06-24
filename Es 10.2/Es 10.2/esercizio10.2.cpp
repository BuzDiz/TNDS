#include "Integral.h"
#include "FunzioneBase.h"
#include "RandomGen.h"
#include "Gauss.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"

using namespace std;

int main()
{
	TGraph* m = new TGraph();
	TGraph* h = new TGraph();
	FunzioneBase* s = new Seno;

	Integral *p = new Integral(0., M_PI, s);

	for(int i = 100; i <= 100000; i += 100)
	{
		p->IntegraleAVG(i);
		m->SetPoint(i, double(i), p->getMeanRMS());
	}
	double prec = 0;
	cout << "Inserire la precisione richiesta, ne calcolerò i punti necessari a ottenerla col metodo della media. " << endl;
	cin >> prec;
	cout << "Per avere una precisione di " << prec << " sono necessari " << p->MeanStep(prec) << " punti." << endl;

	TCanvas *b = new TCanvas("Metodo Media", "Metodo Media");
	b->cd();
	m->GetXaxis()->SetTitle("Passi");
	m->GetYaxis()->SetTitle("Precisione");
	m->Draw("AP");
	b->Print("Metodo Media.pdf");







//Hit or Miss

for(int i = 100; i <= 100000; i += 100)
{
	p->IntegraleHOM(i);
	h->SetPoint(i, double(i), p->getHitRMS());
}
double prec1 = 0;
cout << "Inserire la precisione richiesta, ne calcolerò i punti necessari a ottenerla col metodo Hit or Miss. " << endl;
cin >> prec1;
cout << "Per avere una precisione di" << prec1 << " sono necessari " << p->HOMStep(prec1) << " punti." << endl;



TCanvas *c = new TCanvas("Metodo HOM", "Metodo HOM");
c->cd();
h->GetXaxis()->SetTitle("Passi");
h->GetYaxis()->SetTitle("Precisione");
h->Draw("AP");
c->Print("Metodo HOM.pdf");
	return 0;

}
