#include "FunzioneBase.h"
#include "Solutore.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#define pi 3.14159265358979323846
using namespace std;

int main()
{
  double prec;
  FunzioneBase* g = new Sinusoide;

  cout << "Programma che calcola gli zeri della x = tan(x) in [n*pi, n*pi + pi/2] con n = 1, 2, ... 20 e precisione a scelta" << endl;
  cout << "Inserire la precisione (10^-6 minimo) " << endl;
  cin >> prec;

  for(int i = 0; i < 20; i++)
  {
    Valuta* t = new Valuta(i * pi, i * pi + pi/2, prec);
    cout << "\nNell'intervallo [ " << i << "*pi , " << i << "*pi + pi/2):" << endl;
    t->cercaZeri(g);
    t->Print();
  }
  return 0;
}
