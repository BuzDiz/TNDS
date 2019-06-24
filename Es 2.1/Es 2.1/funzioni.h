#include <iostream>
#include <fstream>
#include "Vettore.h"

using namespace std;

Vettore Read(unsigned int, const char * );
void Print(Vettore &);
void Print(const char *, Vettore &, int);
void Print(Vettore &, string);
void SelectionSort(Vettore &);
double media(Vettore &);
double mediana(Vettore &);
double std_dev(Vettore &);
