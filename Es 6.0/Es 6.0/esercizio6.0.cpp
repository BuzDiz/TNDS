#include "PuntoMateriale.h"
#include "CampoVettoriale.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TROOT.h"
#include <iostream>
#include <cstdlib>
#define k 8.99E9

using namespace std;

int main(int argc, char ** argv)
{
  TApplication myApp("app", 0, 0);
  TGraph field;

  if(argc != 4)
  {
    cerr << "Da fornire: " << argv[0] << " <x> <y> <z>" << endl;
    exit(-1);
  }
  double x = atof(argv[1]);
  double y = atof(argv[2]);
  double z = atof(argv[3]);
  Posizione pos(x, y, z);

  const double e = 1.60217653E-19;
  const double m_e = 9.1093826E-31;
  const double m_p = 1.67262171E-27;
  const double d = 1.E-10;

  PuntoMateriale elettrone(m_e, -e, 0., 0., -d/2.);
  PuntoMateriale protone(m_p, e, 0., 0., d/2.);

  CampoVettoriale E = elettrone.CampoElettrico(pos) + protone.CampoElettrico(pos);

  cout << "Campo elettrico dipolo protone-elettrone in (" << x << ", " << y << ", " << z << "): E = (" << E.getFx() << ", " << E.getFy() << ", " << E.getFz() << ")" << endl;

  Posizione bound1(0, 0, 100 * d);
  Posizione bound2(0, 0, 1000 * d);
  CampoVettoriale E_s = elettrone.CampoElettrico(bound1) + protone.CampoElettrico(bound1);
  CampoVettoriale E_d = elettrone.CampoElettrico(bound2) + protone.CampoElettrico(bound2);
  cout << E_s.getFx() << endl;
  cout << E_s.getFy() << endl;
  cout << E_s.getFz() << endl;
  cout << E_d.getFx() << endl;
  cout << E_d.getFy() << endl;
  cout << E_d.getFz() << endl;
  double alpha = log(E_s.modulo_c()/E_d.modulo_c())/log(bound1.modulo_pos()/bound2.modulo_pos());

  double_t E_graph[10], t[10];

  for(int i = 0; i < 10; i++)
  {
    E_graph[i] = k * pow(d * 100 * (i + 1), alpha);
    cout << E_graph[i] << endl;
    t[i] = d * (i + 1);
  }

  TGraph graph(10, t, E_graph);
  TCanvas mycanvas("Graph", "Graph");
  graph.Draw("AC*");
  // graph.GetXaxis();
  graph.SetTitle("Andamento campo E di dipolo e-p");
  myApp.Run();
  return 0;









}
