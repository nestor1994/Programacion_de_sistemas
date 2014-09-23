#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
// Comparación de cadenas
using namespace std;
const int t=4;
char nombre[t][30];


void ingresoCadenas(char nombre[t][30])
{
    for(int i=0; i<=t; i++)
    {
         cout << "Ingresar el nombre.....: ";
         cin.getline(nombre[i],30);
    }

}

void Comparar2(char nombre[t][30])
{
    char cadcompa[30];
    cout << "Ingresar cadena a comparar: ";
    cin.getline(cadcompa,30);
    for(int i=0; i<=t; i++)
    {
         if(strcmp(nombre[i],cadcompa)==0)
         {

            cout << "Comparacion correcta con "<<nombre[i]<<endl;

         }

    }

}


int main()

{

    ingresoCadenas(nombre);
    Comparar2(nombre);
    cout<<endl<<"Otro tipo de comparacion "<<endl;
    //Comparar (nombre);


    return 0;




}


