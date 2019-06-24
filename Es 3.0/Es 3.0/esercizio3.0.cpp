#include <iostream>
#include <fstream>
#include "Vettore.h"
#include "funzioniT.h"

using namespace std;


int main(int argc, char** argv)
{
  if(argc < 3)
  {
    cout << "Uso del programma: " << argv[0] << "<n_data> <file_name>" << endl;
    return -1;
  }
  int num_data = atoi(argv[1]);
  // double *data = new double[num_data];
  const char *file_name = argv[2];
  Vettore<double> v = Read<double>(num_data, file_name);
  Print(v);
  cout << "Media: " << media(v) << endl;

  mediana<double>(v);
  std_dev<double>(v);
  Print(v);


  return 0;

}
