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

int main()
{


  RungeKutta myKutta;
  Pendolo *p = new Pendolo(10.);
  double A = 3.1;
  double t;
  double h = 0.01;
  int i = 0;
  double tmax = 70.;
  int n_step = int(tmax/h + 0.5);

  VettoreLineare x(2);
  x.setValue(0, -A);
  x.setValue(1, 0.);



  do
      {
        TGraph *periodo = new TGraph();
        x.setValue(0, 0.);		//ripristino condizioni iniziali
        x.setValue(1, 1.);
        double t = 0.;
        int n_step = int(tmax/h + 0.5);

      for(int step = 0; step < n_step; step++)
        {
          periodo->SetPoint(step, t, x.getValue(0));
          x = myKutta.Passo(t, x, h, p);
          t += h;

        }


        //Disegno Runge-kutta
        periodo->GetXaxis()->SetTitle("t [s]");
        periodo->GetYaxis()->SetTitle("x [m]");
        TCanvas* c = new TCanvas("Runge", "Grafico");
        c->cd();
        periodo->Draw("ALP");
        c->Print("Periodo.pdf");

        h = h/10.;
        delete c;
        }
        while(h >= 0.0001);



//Andamento del periodo
    TGraph *t1 = new TGraph();
    t = 0.;
    // double v;
    x.setValue(0, -A);
    x.setValue(1, 0.);

    for(int j = 1; j < 32; j++)
    {
      x.setValue(0, -A + (0.1*(j - 1)));
      x.setValue(1, 0.);

      while(x.getValue(0) <= 0.) //Kutta tra -pi e pi.
      {
        // v = x.getValue(1);
        x = myKutta.Passo(t, x, h, p);
        t += h;
      }

      t1->SetPoint(j - 1, (A - 0.1*(j - 1)), 2*t); //2*t = periodo, t è semiperiodo!
      // t1->SetPoint(32, 0, 2*(t - (v * h )/ (x.getValue(1) - v))); <-- numeri assurdi!! non posso interpolare lo zero
      t = 0.;
    }

  TCanvas *c1 = new TCanvas("hhh", "c");
  c1->cd();
  t1->Draw("AC*");
  c1->Print("errore.jpg");

delete c1;

delete t1;
delete p;


  return 0;
}
