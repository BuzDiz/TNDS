#include "funzioni.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

Vettore Read(unsigned int n, const char * filename)
{
  Vettore v(n);
  ifstream file(filename);
    for(int i = 0; i < n; i++)
    {
      double val[n];
      file >> val[i];
      v.addValue(val[i]);
    }
  return v;
}

void Print(Vettore &data)
{
  for(int i = 0; i < data.getIndex(); i++)
    cout << data.getValue(i) << endl;
  cout << "Numero elementi: " << data.getIndex() << endl;
}
//Stampa a video gli elementi del vettore "data" fino all'elemento numero "ndata"
// void Print(Vettore &data, int ndata)
// {
//   for(int i = 0; i < ndata; i++)
//     cout << data.getValue(i) << endl;
//   cout << "Numero elementi: " << ndata << endl;
// }

//Stampa a video gli elementi del vettore "data" fino all'elemento numero "ndata" e il nome del file che sto leggendo
void Print(const char *file_name, Vettore &data, int ndata)
{
  cout << "Nome del file: " << file_name << endl;
  for(int i = 0; i < ndata; i++)
    cout << data.getValue(i) << endl;
  cout << "Numero elementi: " << ndata << endl;
}

void Print(Vettore &vec, string file_name)
{
  ofstream after(file_name);
  for(int j = 0; j < vec.getIndex(); j++)
  {
    after << vec.getValue(j) << endl;
	}
	after.close();
}

void SelectionSort(Vettore &vec)
{
  // Carico gli indici del vettore
  for (int i = 0; i < vec.getIndex(); i++)
    {
      int min = i;

      // Identifico il valore minimo
      for (int j = i + 1; j < vec.getIndex(); j++)
        {
          if (vec.getValue(j) < vec.getValue(min))
          // Scambio il valore minimo col primo elemento dell'array
          vec.scambia(min, j);
        }
    }
}

double media(Vettore &vec)
{
  double somma = 0;
  for(int i = 0; i < vec.getIndex(); i++)
    somma += vec.getValue(i);
  return somma / vec.getIndex();
}

double mediana(Vettore &vec)
{
  SelectionSort(vec);
  double mediana = 0;
  if(vec.getIndex()%2==0){
    mediana = ((vec.getValue((vec.getIndex()/2) - 1) + vec.getValue((vec.getIndex()/2)))/2);
  cout << "La mediana dei valori è: " << mediana << ", ovvero la media tra " << vec.getValue((vec.getIndex()/2) - 1) << " e " << vec.getValue((vec.getIndex()/2)) << endl;
  }
  if(vec.getIndex()%2!=0){
    mediana = vec.getValue(((vec.getIndex()+1)/2) - 1);
    cout << "La mediana dei valori è: " << mediana << endl;
  }
  return mediana;
}

//Deviazione standard
double std_dev(Vettore &vec)
{
  double somma = 0;
  double sigma = 0;
  for(int i = 0; i < vec.getIndex(); i++)
  {
    somma += pow((vec.getValue(i) - media(vec)), 2);
  }
  sigma = pow(somma / vec.getIndex(), 0.5);
  cout << "La deviazione standard è: " << sigma << endl;
  return sigma;
}
