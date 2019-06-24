#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Posizione.h"
using namespace std;

int main()
{
  Corpoceleste T("Terra", 5.9742E24, 6.372797E6, 0, 0, 1.496E11);
  Corpoceleste L("Luna", 7.3477E22, 1.737E6, 0, 0, 1.49984E11);
  Corpoceleste S("Sole", 1.989E30, 6.95510E8, 0, 0, 0);



cout << "Su Luna da Sole " << S.GetPotenziale(L) << " m^2/s^2" << endl;
cout << "Su Luna da Terra " << T.GetPotenziale(L) << " m^2/s^2" << endl;
cout << "Su Terra da Luna " << L.GetPotenziale(T) << " m^2/s^2" << endl;
cout << "Su Terra da Sole " << S.GetPotenziale(T) << " m^2/s^2" << endl;
cout << "Su Sole da Terra " << T.GetPotenziale(S) << " m^2/s^2" << endl;
cout << "Su Sole da Luna " << L.GetPotenziale(S) << " m^2/s^2" << endl;
return 0;
}
