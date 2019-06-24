#include "PuntoMateriale.h"
#include "CampoVettoriale.h"
#include "Particella.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TGraphPolar.h"
#include "TGraphPolargram.h"
#include "TCanvas.h"
#include "TROOT.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#define pi 3.1415926535897
#define g 9.80665

using namespace std;

int main()
{
  TApplication myApp("app", 0, 0);
  TGraph field;

//g su satellite:
double Massa_t = 5.9726E24;
double Raggio_t = 6.372797E6;
double Raggio_s = 2.5E5;
double Raggio_s_tot = Raggio_t + Raggio_s;


Corpoceleste Terra("Terra", Massa_t, Raggio_t, 0, 0, 0);

Posizione s(0, 0, Raggio_s_tot);
cout << "Valore di g su un satellite a 250 km dalla superficie: " << setprecision(13) << Terra.Getg(s) << endl;

//II Parte
double Raggio_m = 1E3;
double Raggio_m_tot = Raggio_t + Raggio_m;
double Massa_m = 3000*(4/3)*pi*pow(Raggio_m, 3);
PuntoMateriale** montagna = new PuntoMateriale* [100];

for(int i = 0; i < 100; i++)
{
  double phi = i*2.*Raggio_m/Raggio_m_tot;
  montagna[i] = new PuntoMateriale(Massa_m, 0., Raggio_m_tot*cos(phi), Raggio_m_tot*sin(phi), 0.);
}

Posizione** pos_s = new Posizione* [4162];

for(int i = 0; i < 4162; i++)
{
  double phi = i*1E4/Raggio_s_tot;
  pos_s[i] = new Posizione(Raggio_s_tot*cos(phi), Raggio_s_tot*sin(phi), 0.);
}
int num_scan = 2. * pi * Raggio_s_tot / 1E4;
double_t g_val[num_scan], x[num_scan];

for(int i = 0; i < num_scan; i++)
{
  x[i] = i;
  for(int j = 0; j < 100; j++)
  {
    g_val[i] = ((((*montagna[j]).CampoGravitazionale(*pos_s[i])).modulo_c() - g) + (Terra.Getg(*pos_s[i]) - g)) / g; /* ----- È qui il problema*/
    g_val[i] = g_val[i] + ((((*montagna[j]).CampoGravitazionale(*pos_s[i])).modulo_c() - g) + (Terra.Getg(*pos_s[i]) - g)) / g;
  }
}

TGraph graph(num_scan, x, g_val);
TCanvas mycanvas("Graph", "Graph");
graph.Draw();
// graph.GetXaxis();
graph.SetTitle("g");
myApp.Run();



return 0;








  // double_t E_graph[10], t[10];
  //
  // for(int i = 0; i < 10; i++)
  // {
  //   E_graph[i] = k * pow(d * 100 * (i + 1), alpha);
  //   cout << E_graph[i] << endl;
  //   t[i] = d * (i + 1);
  // }

  // TGraph graph(10, t, E_graph);
  // TCanvas mycanvas("Graph", "Graph");
  // graph.Draw("AC*");
  // // graph.GetXaxis();
  // graph.SetTitle("Andamento campo E di dipolo e-p");
  // myApp.Run();









}
