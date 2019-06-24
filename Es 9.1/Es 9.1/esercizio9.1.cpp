#include "VettoreLineare.h"
#include "EquazioniDifferenziali.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

int main(int argc, char ** argv)
{
  if(argc != 2)
  {
    cerr << "Utilizzo: " << argv[0] << " < h >" << endl;
    return -1;
  }

  TApplication myApp("myApp", 0, 0);
  Eulero myEuler;
  OscillatoreArmonico *osc = new OscillatoreArmonico(1.);		// omega == 1
  double tmax = 70.;
  double h = atof(argv[1]);

  // TGraph *errore = new TGraph();
  VettoreLineare x(2);		//Condizioni iniziali: x = 0, v = 1;
  double t = 0;
  x.setValue(0, 0.);
  x.setValue(1, 1.);
  TGraph *g1 = new TGraph();

  int n_step = int(tmax/h + 0.5);
  for(int step = 0; step < n_step; step++)
  {
    g1->SetPoint(step, t, x.getValue(0));
    x = myEuler.Passo(t, x, h, osc);
    t += h;
  }

  cout << setprecision(10) << "Precisione: "<< h << " Tempo: " << t << " Posizione: " << x.getValue(0) << " Velocità: " << x.getValue(1) << endl;
  TCanvas *c = new TCanvas();
  g1->SetLineColor(2);
  g1->SetTitle("Oscillatore armonico");
  g1->GetXaxis()->SetTitle("t");
  g1->GetYaxis()->SetTitle("x");
  g1->Draw("AL");
  myApp.Run();

  return 0;
}
