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
#include <iomanip>
#define pi 3.141592653589

using namespace std;

int main()
{
  TApplication myApp("app", 0, 0);
  TGraph field;

  int n;
  FunzioneBase* s = new Seno;
  Integral* integrale = new Integral(0, pi, s);
  cout << "Programma per valutare l'integrale della funzione sin(x) in [ 0, pi ]." << endl;
  cout << "Che metodo di integrazione vuoi utilizzare?\n[1] - Mid-point.\n[2] - Simpson.\n[3] - Trapezi." << endl;
  cin >> n;

  if(n == 1) //Mid-point
  {
    int passi;
    cout << "Inserire il numero di passi desiderati." << endl;
    cin >> passi;
    Double_t x_graph[passi];
    cout << integrale->mid_point(passi) << endl;

    //Valutazione errore
    Double_t int_parz[passi];
    for(Int_t i = 1; i < passi; i++)
    {
      x_graph[i] = i;
      int_parz[i - 1] = fabs((2 - integrale->mid_point(i))/2)*100;
    }
    //Grafico
	  TCanvas *c1 = new TCanvas("c1", "Mid-point",1);
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
    int passi;
    cout << "Inserire il numero di passi desiderati." << endl;
    cin >> passi;
    if(passi%2 != 0)
    {
      cout << "Il metodo Simpson prevede un numero pari di passi!" << endl;
      return -1;
    }

    cout << "L'integrale, a " << passi << " passi, vale " << integrale->Simpson(passi) << endl;
    //Valutazione errore
    Double_t int_parz[passi], x_graph[passi];
    for(Int_t i = 0; i < (passi/2) - 1; i++)
    {
      x_graph[i] = 2*(i + 1);
      int_parz[i] = (fabs((2 - integrale->Simpson(2*(i + 1)))/2))*100;
    }
    TCanvas *c1 = new TCanvas("c1", "Simpson",1);
    TGraph *gr = new TGraph(passi/2 - 1, x_graph, int_parz);

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

  if(n == 3) //Trapezi
  {
    double prec;
    cout << "Inserire la precisione con cui si vuole applicare il metodo." << endl;
    cin >> prec;

    int passi_T = integrale->T_Error(prec);
    cout << "Passi considerati: " << passi_T << endl;
    int cifre_sign = -int(log10(prec));
  	cout << fixed;
  	setprecision(cifre_sign);
    cout << "Valore dell'integrale a " << passi_T << " passi: " << integrale->Trapezi(passi_T) << endl;

    return 0;
  }
  else
  {
    cerr << "Errore! Scegliere [1], [2] o [3]." << endl;
    return -1;
  }

}
