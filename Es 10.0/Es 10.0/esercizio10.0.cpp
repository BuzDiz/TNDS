#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "Gauss.h"
#include "TAttFill.h"
#include "TAxis.h"
#include <iostream>
#include "RandomGen.h"

using namespace std;
int main()
{
  TApplication myApp("app", 0, 0);
  int nmax = 10000;
  RandomGen myGen(5);

//LCG (a, b)
  TH1F *h = new TH1F("LCG", "LCG", 500, 4, 11); // 100 = numero bin

  for(int i = 0; i < nmax; i++)
  {
    h->Fill(myGen.LCG(5., 10.));
  }

  TCanvas *c = new TCanvas("LCG", "LCG");
  c->cd();
  h->GetXaxis()->SetTitle("x [AU]");
  h->GetYaxis()->SetTitle("Ripetizioni");
  h->Draw();
  h->Print();

//EXP
  TH1F *h1 = new TH1F("Exp", "Exp", 500, 0, 100); // 500 = numero bin
  myGen.SetExpRate(0.1);

  for(int i = 0; i < nmax; i++)
  {
    h1->Fill(myGen.Exp());
  }

  TCanvas *c1 = new TCanvas("Exp", "Exp");
  c1->cd();
  h1->GetXaxis()->SetTitle("x [AU]");
  h1->GetYaxis()->SetTitle("Ripetizioni");
  h1->Draw();
  h1->Print();

//Gaussiana B-M
  TH1F *h2 = new TH1F("GausBM", "GausBM", 500, -1, 3); // 100 = numero bin

	for(int i = 0; i < nmax; i++)
  {
		h2->Fill(myGen.GausBM(1., 1.));
	}

  TCanvas *c2 = new TCanvas("GausBM", "GausBM");
  c2->cd();
  h2->GetXaxis()->SetTitle("x [AU]");
  h2->GetYaxis()->SetTitle("Ripetizioni");
  h2->Draw();
  h2->Print();

//Gaussiana A-R
  TH1F *h3 = new TH1F("GausAR", "GausAR", 500, -1, 3); // 100 = numero bin

  Gauss *g = new Gauss(1., 1.);

  for(int i = 0; i < nmax*0.68; i++) //68%
  {
    h3->Fill(myGen.GausAR(g, 0., 2.));
  }

  TCanvas *c3 = new TCanvas("GausAR", "GausAR");
  c3->cd();
  h3->GetXaxis()->SetTitle("x [AU]");
  h3->GetYaxis()->SetTitle("Ripetizioni");
  h3->Draw();
  h3->Print();

  // h2.SetFillColor(2); colore
  // h2.SetFillStyle(4050); stile

  myApp.Run();
  delete c;
  delete c1;
  delete c2;
  delete c3;
  delete h;
  delete h1;
  delete h2;
  delete h3;
  delete g;
  return 0;
}
