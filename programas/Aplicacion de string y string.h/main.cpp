#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
   string cadena1, cadena2,com1;

   cout<<"Escribir una cadena de texto: ";
   cin>>cadena1;


   cout<<"Cadena a buscar dentro de la cadena de texto.....: ";
   cin>>cadena2;

   int largo= cadena1.size();
   int largo2= cadena2.size();
   int c=0;
   int bandera=0;

   while (c<largo)
   {

       com1=cadena1.substr(c,largo2);
       if(com1==cadena2)
       {
           bandera=1;
           break;


       }

      c++;



   }

if(bandera==1)
{
    cout<<"Encontrada la cadena: "<<com1<<endl;
}
else
{
     cout<<"No existe la cadena ";
}



    return 0;
}
