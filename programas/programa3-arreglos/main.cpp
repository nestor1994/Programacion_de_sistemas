#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
/*
Generar en un arreglo que se llama base, 5 numeros entre 1 y 10, igual en el otro arreglo que se
llama expo.
Usar un procedimiento.
Luego determinar la potencia elevando la base al expo y copiarla en otro arreglo.
*/
int const n=5;
int base[n];
int expo[n];
long pot[n];

void generar (int base[],int expo[], int n)
{
    int i;
    srand(time(0));
    for (i=0;i<n;i++)
    {
        base[i]= 1+ rand ()%(10-1);
        expo[i]=1+ rand ()%(10-1);
    }
}
long potencia(int base, int expo)
{
    int i;
    int pot= 1;
    for(i=0;i<expo;i++)
    {
        pot= base * pot;
    }
    return base;
}

void calcular (int base[],int expo[],long pot[], int n)
{
    int i;

    for (i=0;i<n;i++)
    {
        pot[i]= potencia(base[i],expo[i]);
        cout<<"base[i]]"<<" elevado a la"<<expo[i]<<" es "<<pot[i]<<endl;
    }
}
int main()
{
    generar(base,expo,n);
    calcular(base, expo, pot, n);
}
