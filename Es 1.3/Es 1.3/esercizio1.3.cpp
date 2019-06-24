#include <iostream>
#include <fstream>

using namespace std;
void Print(double *, int);
void Print(const char *, double *, int);

int main(int argc, char **argv)
{
  if(argc < 3)
  {
    cout << "Uso del programma: " << argv[0] << "<n_data> <file_name>" << endl;
    return -1;
  }
  int num_data = atoi(argv[1]);
  double *data = new double[num_data];
  const char *file_name = argv[2];
  double vec[num_data];
  ifstream input_file(argv[2]);
  for(int i = 0; i < num_data; i++)
    input_file >> vec[i];

  Print(vec, num_data);
  Print(file_name, vec, num_data);
  return 0;
}


//Stampa a video gli elementi del vettore "data" fino all'elemento numero "ndata"
void Print(double *data, int ndata)
{
  for(int i = 0; i < ndata; i++)
    cout << data[i] << endl;
  cout << "Numero elementi: " << ndata << endl;
}

//Stampa a video gli elementi del vettore "data" fino all'elemento numero "ndata" e il nome del file che sto leggendo
void Print(const char *file_name, double *data, int ndata)
{
  cout << "Nome del file: " << file_name << endl;
  for(int i = 0; i < ndata; i++)
    cout << data[i] << endl;
  cout << "Numero elementi: " << ndata << endl;
}
