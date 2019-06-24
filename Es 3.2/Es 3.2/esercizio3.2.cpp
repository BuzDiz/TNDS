#include <iostream>
#include <fstream>
#include <cstdlib>
#include "TH1.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TROOT.h"

#include "funzioniF.h"

using namespace std;


int main(int argc, char** argv)
{

  int num_data = atoi(argv[1]);
  // double *data = new double[num_data];
  const char *file_name = argv[2];
  vector<double> v = Read<double>(num_data, file_name);
  Print(v);
  cout << "Media: " << media<double>(v) << endl;
  cout << "Deviazione standard: " << std_dev<double>(v) << endl;
  cout << "Mediana: " << mediana<double>(v) << endl;
  Print(v);

  double x[num_data];
  double y[num_data];
  for(int i = 0; i < num_data; i++)
  {
    x[i] = i;

  }
  TApplication app("App",&argc,argv);
  double_t num = num_data;

  TH1F Isto("I", "Istogramma", num, 0, 100);

  for(int i = 0; i < v.size(); i++) Isto.Fill(v[i]);
  cout << "media caricati: " << Isto.GetMean() << endl;
  
  TCanvas mycanvas ("Isto", "Isto");
  Isto.Draw();
  Isto.GetXaxis() -> SetTitle("Misura");
  app.Run();


  return 0;

  //Scatter Plot con ROOT
  // TCanvas *C=new TCanvas("C","Sistema di punti",200,10,600,400);
  // TGraph *grafico = new TGraph(v.size(), x, &v[0]);
  // grafico->SetMarkerColor(kBlue);
  // grafico->Draw("A*");
}
