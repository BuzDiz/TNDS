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
  double alpha = 1./30.;
  double omega_0 = 10.;
  double forzante = 5.;
  double h = 0.1;
	OscillatoreArmonicoSmorzato* osc = new OscillatoreArmonicoSmorzato(0., 0., 0.);


	double tmax = 30.;
	int n_step = int(tmax/h + 0.5);

	VettoreLineare x(2);
	x.setValue(0, 0.);
	x.setValue(1, 0.);

// Primo caso:
  osc->setForzante(forzante);
  osc->setAlpha(alpha);
  osc->setOmega_0(omega_0);

  do
  {
    TGraph *posizione = new TGraph();
    x.setValue(0, 0.);
    x.setValue(1, 0.);
    double t = 0.;
    int n_step = int(tmax/h + 0.5);

  for(int step = 0; step < n_step; step++)
    {
      posizione->SetPoint(step, t, x.getValue(0));
      x = myKutta.Passo(t, x, h, osc);
      t += h;

    }
    posizione->GetXaxis()->SetTitle("t [s]");
    posizione->GetYaxis()->SetTitle("x [m]");


    h = h/10.;

    //Disegno Runge-kutta
      TCanvas* c1 = new TCanvas("Runge", "Grafico");
      c1->cd();
      posizione->Draw("AL");
      c1->Print("R-K.pdf");
      delete c1;
      delete posizione;

    }
    while(h >= 0.001);

    //Secondo caso:
      osc->setForzante(forzante + 5);
      osc->setAlpha(alpha);
      osc->setOmega_0(omega_0);

      do
      {
        TGraph *posizione2 = new TGraph();
        x.setValue(0, 0.);
        x.setValue(1, 0.);
        double t = 0.;
        int n_step = int(tmax/h + 0.5);

      for(int step = 0; step < n_step; step++)
        {
          posizione2->SetPoint(step, t, x.getValue(0));
          x = myKutta.Passo(t, x, h, osc);
          t += h;

        }
        posizione2->GetXaxis()->SetTitle("t [s]");
        posizione2->GetYaxis()->SetTitle("x [m]");


        h = h/10.;

        //Disegno Runge-kutta
          TCanvas* c1 = new TCanvas("Runge", "Grafico");
          c1->cd();
          posizione2->Draw("AL");
          c1->Print("R-K2.pdf");
          delete c1;
          delete posizione2;

        }
        while(h >= 0.001);

        //Terzo caso:
          osc->setForzante(forzante + 10);
          osc->setAlpha(alpha);
          osc->setOmega_0(omega_0);

          do
          {
            TGraph *posizione3 = new TGraph();
            x.setValue(0, 0.);
            x.setValue(1, 0.);
            double t = 0.;
            int n_step = int(tmax/h + 0.5);

          for(int step = 0; step < n_step; step++)
            {
              posizione3->SetPoint(step, t, x.getValue(0));
              x = myKutta.Passo(t, x, h, osc);
              t += h;

            }
            posizione3->GetXaxis()->SetTitle("t [s]");
            posizione3->GetYaxis()->SetTitle("x [m]");


            h = h/10.;

            //Disegno Runge-kutta
              TCanvas* c1 = new TCanvas("Runge", "Grafico");
              c1->cd();
              posizione3->Draw("AL");
              c1->Print("R-K3.pdf");
              delete c1;
              delete posizione3;

            }
            while(h >= 0.001);


//Risonanza

	osc->setAlpha(alpha);
	osc->setOmega_0(omega_0);

	double t = 0.;
  tmax = 10./osc->getAlpha();
	double v = 0;
	TGraph *t1 = new TGraph();
	TGraph *posizione = new TGraph();
	forzante = 9. - 0.05;
	h = 0.02;
	int i = 0;
	do
	{
		x.setValue(0, 0.);
		x.setValue(1, 0.);

		forzante = forzante + 0.05;
		osc->setForzante(forzante);

	  double t = 0.;
	  int n_step = int(tmax/h + 30);

	for(int step = 0; step < n_step; step++)
	  {
			posizione->SetPoint(step, t, x.getValue(0));
			v = x.getValue(1);
	    x = myKutta.Passo(t, x, h, osc);

			if(t > tmax && v*(x.getValue(1)) <= 0.)
			{
				t1->SetPoint(i, forzante, abs(posizione->Eval(t)));
	    	t += h;
			}
			if(t >= tmax + 1./osc->getAlpha()) break;

		else t += h;
	}
		i++;
	} while(forzante <= 11.);

	  t1->GetXaxis()->SetTitle("Pulsazione [rad/s]");
	  t1->GetYaxis()->SetTitle("Ampiezza");




	  //Disegno Runge-kutta
	    TCanvas* c1 = new TCanvas("Runge", "Grafico");
	    c1->cd();
	    t1->Draw("AC*");
	    c1->Print("errore.pdf");

delete posizione;
delete c1;
delete t1;
return 0;
}
