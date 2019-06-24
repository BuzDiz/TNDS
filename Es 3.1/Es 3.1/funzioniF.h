#ifndef __vectorF_H
#define __vectorF_H

#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// template <typename T> Vettore<T> Read(unsigned int n, const char * filename)
// {
//   Vettore<T> v(n);
//   ifstream file(filename);
//     for(int i = 0; i < n; i++)
//     {
//       T val[n];
//       file >> val[i];
//       v.addVec(val[i]);
//     }
//
//   return v;
// }

template <typename T> vector<T> Read(int n, const char * file_name)
{
  vector<T> v;
  ifstream input_file(file_name);


  // if(!input_file)
  //   {
  //     cout << "Non posso aprire " << file_name << endl;
  //     exit(11);
  //   }
  // else
  //   {

  for(int i = 0; i < n; i++)
      {
      T value = 0;
      input_file >> value;
      v.push_back(value);
    }
      // assert(!(input_file.eof()) && "Lettura file terminata");
      // if(input_file.eof())
      //   {
      //     cout << "Fine del file. Uscita." << endl;
      //     exit(11);
      //   }


  return v;
};

template <typename T> void Print(const vector<T> & vec)
{
  for(int i = 0; i < vec.size(); i++) cout << vec[i] << endl;
  return;
};

template <typename T> void Print(const vector<T> & vec, const char* file_name)
{
  ifstream output_file(file_name);
  if(!output_file)
  {
    cerr << "Non posso creare il file " << file_name << endl;
    return;
  }
  for(int i = 0; i < vec.size(); i++) cout << vec[i] << endl;
  output_file.close();
  return;
};
//Ho già la funzione sort
// template <typename T> void SelectionSort(vector<T> &vec)
// {
//   // Carico gli indici del vector
//   for (int i = 0; i < vec.size(); i++)
//     {
//       int min = i;
//
//       // Identifico il valore minimo
//       for (int j = i + 1; j < vec.size(); j++)
//         {
//           if (vec[j] < vec[min])
//           // Scambio il valore minimo col primo elemento dell'array
//           vec.scambia(min, j);//scambia(vec.getValue(min), vec.getValue(j));
//         }
//     }
// }
//



template <typename T> double media(vector<T> &vec)
{
  T somma = 0;
  for(int i = 0; i < vec.size(); i++)
    somma += vec[i];
  return (somma / vec.size());
}

template <typename T> double mediana(vector<T> &vec)
{
  sort(vec.begin(), vec.end());
  T mediana = 0;
  if(vec.size()%2==0){
    mediana = (vec[(vec.size()/2) - 1] + vec[vec.size()/2])/2;
  // cout << "La mediana dei valori è: " << mediana << ", ovvero la media tra " << vec[(vec.size()/2) - 1] << " e " << vec[vec.size()/2] << endl;
  }
  else
  {
    mediana = vec[vec.size()/2];

    // cout << "La mediana dei valori è: " << vec[vec.size()/2] << endl;
  }
  return mediana;
}

//Deviazione standard
template <typename T> double std_dev(vector<T> &vec)
{
  T somma = 0;
  T sigma = 0;
  T avg = 0;
  double s = 0;
    for(int i = 0; i < vec.size(); i++)
    {
      s += vec[i];
      avg = s/vec.size();
    }
  for(int i = 0; i < vec.size(); i++)
  {
    somma += pow((vec[i] - avg), 2);
  }
  sigma = pow(somma / vec.size(), 0.5);

  return sigma;
}

#endif
