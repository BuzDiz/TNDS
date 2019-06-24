#include "Integral.h"
#include "FunzioneBase.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TF1.h"
#include "TAxis.h"
#include "TLegend.h"
#include "TROOT.h"
#include <iostream>
#define pi 3.141592653589

using namespace std;

int main(int argc, char** argv)
{
  if (argc != 2)
    {
    cout << "Errore, digita: " << argv[0] << " <numero passi>" << endl;
    return -1;
  }
  TApplication myApp("app", 0, 0);
  TGraph field;

  int passi = atoi(argv[1]);
  int n;
  Double_t x_graph[passi];
  FunzioneBase* s = new Seno;
  cout << "Programma per valutare l'integrale della funzione sin(x) in [ 0, pi ]." << endl;
  cout << "Che metodo di integrazione vuoi utilizzare?\n[1] - Mid-point.\n[2] - Simpson." << endl;
  cin >> n;

  if(n == 1) //Mid-point
  {
    Integral* integrale = new Integral(0, pi, s);
    cout << "L'integrale vale " << integrale->mid_point(passi) << endl;

    //Valutazione errore
    Double_t int_parz[passi];
    for(Int_t i = 1; i < passi; i++)
    {
      x_graph[i] = i;
      int_parz[i - 1] = fabs((2 - integrale->mid_point(i))/2)*100;
    }
    //Grafico
	  TCanvas *c1 = new TCanvas("c1", "Graph Test",1);
    TGraph *gr = new TGraph(passi, x_graph, int_parz);

    // gr.GetXaxis()->SetTitle("Numero intervalli");
    // gr.GetYaxis()->SetTitle("Errore");
    gr->SetLineColor(2);
    gr->SetLineWidth(4);
    gr->SetMarkerColor(4);
    gr->SetTitle("Errore (%) sulla valutazione dell'integrale col metodo Mid-point.");
    gr->GetXaxis()->SetTitle("Numero passi");
    gr->GetYaxis()->SetTitle("Errore");
    gr->Draw();
    c1->Modified();
    c1->Update();
    myApp.Run();
  	delete gr;
    return 0;

  }

  if(n == 2) //Simpson
  {
    Integral* integrale = new Integral(0, pi, s);
    cout << "L'integrale vale " << integrale->Simpson(passi) << endl << endl;
    //Valutazione errore
    Double_t int_parz[passi];

    for(Int_t i = 0; i < (passi/2) - 1; i++)
    {
      x_graph[i] = 2*(i + 1);
      int_parz[i] = (fabs((2 - integrale->Simpson(2*(i + 1)))/2))*100;
    }
    TCanvas *c1 = new TCanvas("c1", "Graph Test",1);
    TGraph *gr = new TGraph(passi/2 - 1, x_graph, int_parz);

    // gr.GetXaxis()->SetTitle("Numero intervalli");
    // gr.GetYaxis()->SetTitle("Errore");
    gr->SetLineColor(2);
    gr->SetLineWidth(4);
    gr->SetMarkerColor(4);
    gr->SetTitle("Errore (%) sulla valutazione dell'integrale col metodo Simpson.");
    gr->GetXaxis()->SetTitle("Numero passi");
    gr->GetYaxis()->SetTitle("Errore");
    gr->Draw();
    c1->Modified();
    c1->Update();
    myApp.Run();
    delete gr;
    return 0;
  }

  else
  {
    cerr << "Errore! Scegliere [1] o [2]" << endl;
    return -1;
  }

}
