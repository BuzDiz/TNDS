#include <iostream>
#include <fstream>
#include <cstdlib>


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

  return 0;

}
