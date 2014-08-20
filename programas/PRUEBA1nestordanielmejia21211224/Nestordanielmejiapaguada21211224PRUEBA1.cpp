#include <iostream>
using namespace std;
/*
Ingresar un numero y determinar cuantas cifras tiene, evaluar hasta
cuatro cifras y luego decir tiene de 4 cifras.
no tiene que importar el signo se evaluara el valor absoluto.


<----------------------------------------------------------->
    0 9 99  999  9999
    si se pasa de las cuatro cifras que diga mayor de 4 cifras



*/


int main()
{

 int x;
 cout<<"Ingrese numero: ";
 cin>>x;


 if(x<10){cout<<"Solo tiene una cifra"<<endl;}

 else if(x<100){cout<<"Solo tiene dos cifras"<<endl;}

 else if(x<1000){cout<<"solo tiene tres cifras"<<endl;}

 else if(x<10000){cout<<"solo tiene cuatro cifras"<<endl;}

 else if(x<10000000){cout<<"es mayor de cuatro cifras"<<endl;}

  if(x<0){(x=x*-1)&&cout <<"se cambia a positivo= "<<x<<endl;}

























    return 0;
}
