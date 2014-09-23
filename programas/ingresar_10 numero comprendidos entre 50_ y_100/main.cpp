#include <iostream>
/*
Ingresar 5 numeros comprendidos entre 50-100 y sacar el promedio de los numeros pares
y sacar el numero menor


*/
using namespace std;

int main()
{

    int num, conta=0, prom, menor, suma;
    int i=0;
    for(i=0; i<5; i++)
    {

        do{


            cout<<"N-"<<i+1<< "Ingresar un numero entre 50-100: ";
            cin>>num;

        }while(!((num>=50)&&(num<=100))); /* el ! sirve que cuando se cumpla la condición pare*/ /* !sirve para negar*/

          if(num<menor){menor=num;}
          if(num%2==0){conta++; suma+=num;}


    }
     if(conta>0){prom=suma/conta;}
     else{prom=0;}
     cout<<"numero menor: "<<menor<<endl;




    return 0;
}
