#include <iostream>
#include <stdlib.h>
using namespace std;
// ingresar 2 numeros y determinar cual es el mayor

int main()
{   int n1,n2,mayor;

cout<<"Ingrese el primer numero:...";
cin>>n1;
cout<<"Ingrese el segundo numero:...";
cin>>n2;

if (n1>n2)
    { mayor=n1;}
else
    { mayor= n2;}
 cout<<"El numero mayor es:..."<<mayor<<"\n";

 system("PAUSE")   ;
}
