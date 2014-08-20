#include <iostream>

using namespace std;
/*ingresar 5 numeros y presentar la sumatoria al final del ciclo
usar while*/


int main()
{
   int numero;
   int contador, suma, cont100, promedio;
   contador=0; suma=0; cont100=0;

   while(contador<5)
   {

       cout<<"Ingresar numero....: ";
       cin>>numero;


       suma +=numero; //suma= suma+numero;

       contador++; //contador=contador+1;


     if(numero>100) cont100++;



   }
    promedio=suma/contador;

   cout<<"suma de los numeros es: "<<suma<<"\n";
 cout<<"numeros mayores a 100.....: "<<cont100<<"\n";
    cout<<"Promedio: "<<promedio<<"\n";

    return 0;
}
