#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Vettore.h"
#include "funzioni.h"

using namespace std;


int main(int argc, char** argv)
{
  if(argc < 3)
  {
    cout << "Uso del programma: " << argv[0] << " <n_data> <file_name>" << endl;
    return -1;
  }
  int num_data = atoi(argv[1]);
  const char *file_name = argv[2];
  Vettore v = Read(num_data, file_name);

  Print(v);
  cout << "Media: " << media(v) << endl;
  mediana(v);
  std_dev(v);
  Print(v);
  Print(v, "data_out.txt");


  return 0;

}
