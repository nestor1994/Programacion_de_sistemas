#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{  int numero;
   char resp;
   int mayor,menor;
   mayor=0;
   menor=99999999;
   int ncifras,auxnum,cifra,max,min,suma,prom;
     do
     {
       do
       {  cout<<"Ingresar un numero: ";
          cin>> numero;

       }
       while(numero%2!=0);
       _flushall();

       ncifras=1;
       auxnum=numero;suma=0;max=0;min=10;

       while (auxnum>10)
       {

           cifra=auxnum % 10;
           auxnum=auxnum/10;
           suma+=cifra;
           if (max<cifra)
                {max=cifra;}
           if (min>cifra)
                {min=cifra;}

          ncifras++;

       }
       suma+=auxnum;
       if (ncifras==1)
       {
           max=numero;
           min=numero;
           suma=numero;
           ncifras=1;
       }

       ;
       prom=suma/ncifras;
       cout<<"Cifras del Numero " <<ncifras<<"\n";
       cout<<"Mayor de las cifras "<<max<<"\n";
       cout<<"Menor de las cifras "<<min<<"\n";
       cout<<"suma "<<suma<<"\n";
       cout<<"Promedio            "<<prom<<"\n";
       do
       { cout<<"Desea Continuar..:";
         cin.get(resp);

       }while((resp!='n') and (resp!='s'));

       if (mayor<numero)
            {mayor=numero;}

       if (menor>numero)
       { menor = numero;}

     }while(resp!='n');
     cout<<"Numero Mayor es "<<mayor<<"\n";
     cout<<"Numero Menor es "<<menor<<"\n";

   return 0;
}
