#include "FunzioneBase.h"
#include "Solutore.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
  double a, b;
  double x_min = 0;
  double x_max = 0;
  double prec;
  FunzioneBase* f = new Parabola(3., 5., -2.);
  cout << "Programma che calcola gli zeri della funzione f(x) = 3x^2 + 5x - 2 in un intervallo a scelta, con estremi di segno opposto e precisione a scelta" << endl;
  cout << "Inserire l'intervallo da valutare: " << endl;

  intervallo_in:
  cin >> a >> b;
  cout << "Verifico che le immagini siano di segno opposto... ";

  if(sign(f->eval(a)) * sign(f->eval(b)) > 0)
  {
    cout << "Intervallo non accettabile!\nInserirne altri:" << endl;
    goto intervallo_in;
  }

  else
  {
    cout << "Ok.\nInserire la precisione:" << endl;
    cin >> prec;
    cout << "Precisione impostata: " << prec << endl;
  }

  if((f->eval(a)) > (f->eval(b)))
  {
	   x_min = b;
	   x_max = a;
  }

  else
  {
	   x_min = a;
	   x_max = b;
  }
  if(a > b) swap (a , b);
  cout << "La funzione sara' valutata in [ " << a << " , " << b << " ]" << endl;

  Valuta zero(x_min, x_max, prec);
  zero.cercaZeri(f);
  zero.Print();

  return 0;
}
