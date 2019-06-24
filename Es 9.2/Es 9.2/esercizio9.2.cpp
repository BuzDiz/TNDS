#include "VettoreLineare.h"
#include "EquazioniDifferenziali.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
#include <TGaxis.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#define pi 3.141592653589793

using namespace std;

int main(int argc, char ** argv)
{
  if(argc != 2)
  {
    cerr << "Utilizzo: " << argv[0] << " < h >" << endl;
    return -1;
  }

  RungeKutta myKutta;
  OscillatoreArmonico *osc = new OscillatoreArmonico(1.);		// omega == 1

  double tmax = 70.;
  double h = atof(argv[1]);

  VettoreLineare x(2);
  x.setValue(0, 0.);
  x.setValue(1, 1.);		//Condizioni iniziali: x = 0, v = 1;

    TGraph *errore = new TGraph();
    int i = 0;

    do
    {
      TGraph *kut = new TGraph();
      x.setValue(0, 0.);		//ripristino condizioni iniziali
      x.setValue(1, 1.);
      double t = 0.;
      int n_step = int(tmax/h + 0.5);

    for(int step = 0; step < n_step; step++)
      {
        kut->SetPoint(step, t, x.getValue(0));
        x = myKutta.Passo(t, x, h, osc);
        t += h;

      }
      errore->SetPoint(i, h, abs((kut->Eval(22.*pi)) - sin(22.*pi)));

      kut->GetXaxis()->SetTitle("t [s]");
      kut->GetYaxis()->SetTitle("x [m]");

      i++;
      h = h/10.;

      //Disegno Runge-kutta
        TCanvas* c1 = new TCanvas("Runge", "Grafico");
        c1->cd();
        kut->Draw("ALP");
        c1->Print("R-K.pdf");
        delete c1;

      }
      while(h >= 0.00001);

      TCanvas* c = new TCanvas("errore a 70s", "c");
  		c->cd();
  		c->SetLogx();
  		c->SetLogy();

  		errore->GetXaxis()->SetTitle("passo [s]");
  		errore->GetYaxis()->SetTitle("errore a 70s [m]");

  		errore->Draw("AL*");
  		c->Print("Errore a 70s.jpg");

  return 0;
}
