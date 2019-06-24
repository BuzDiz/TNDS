#include "Vettore.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


template <typename T> void SelectionSort(Vettore<T> &vec)
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
          vec.scambia(min, j);//scambia(vec.getValue(min), vec.getValue(j));
        }
    }
}



template <typename T> Vettore<T> Read(unsigned int n, const char * filename)
{
  Vettore<T> v(n);
  ifstream file(filename);
    for(int i = 0; i < n; i++)
    {
      T val[n];
      file >> val[i];
      v.addVec(val[i]);
    }

  return v;
}

//Stampa a video gli elementi del vettore "data" fino all'elemento numero "ndata"
template <typename T> Vettore<T> Print(const Vettore<T> &data)
{
  for(int i = 0; i < data.getIndex(); i++)
    cout << data.getValue(i) << endl;
  return data.getIndex();

}

//Stampa a video gli elementi del vettore "data" fino all'elemento numero "ndata" e il nome del file che sto leggendo
template <typename T> Vettore<T> Print(const char *file_name, const Vettore<T> &data)
{
  ofstream file(file_name);
  if (!file)
  {
    cerr << "Non posso creare il file " << file_name << endl;
    return 1;
  }
  for (int i = 0; i < data.getIndex(); i++) file << data.getValue(i) << endl;
  file.close();
  return 0;
}

template <typename T> double media(Vettore<T> &vec)
{
  T somma = 0;
  for(int i = 0; i < vec.getIndex(); i++)
    somma += vec.getValue(i);
  return (somma / vec.getIndex());
}

template <typename T> double mediana(Vettore<T> &vec)
{
  SelectionSort(vec);
  T mediana = 0;
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
template <typename T> double std_dev(Vettore<T> &vec)
{
  T somma = 0;
  T sigma = 0;
  T avg = 0;
  double s = 0;
    for(int i = 0; i < vec.getIndex(); i++)
    {
      s += vec.getValue(i);
      avg = s/vec.getIndex();
    }
  for(int i = 0; i < vec.getIndex(); i++)
  {
    somma += pow((vec.getValue(i) - avg), 2);
  }
  sigma = pow(somma / vec.getIndex(), 0.5);
  cout << "La deviazione standard è: " << sigma << endl;
  return sigma;
}
