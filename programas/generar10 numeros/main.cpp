#include <iostream>
#include<stdlib.h>
#include<time.h>


/*

generar 10 numeros entre 200 y 500 y determinar cuantos son numeros divisibles entre 5

el numero mayor y el numero menor.

*/
using namespace std;

int main()
{
   int num,cd5;
   int conta=0;
   int mayor,menor;
   srand(time(0));//generar una nueva semilla

   mayor=0; cd5=0; menor=500;
   while(conta<10){
    num=200+rand()%(501-200);
    if(num%5==0)
    {
        cd5++;
    }
    if(num>mayor)
    {
        mayor=num;
    }
    if(num<menor)
    {
        menor=num;
    }
    cout<<cd5<<"===>"<<num<<endl;

    conta++;

   }

   cout<<"Numero divisible entre 5: "<<cd5<<endl;
   cout<<"Menor: "<<menor<<endl;
   cout<<"Mayor: "<<mayor<<endl;


    return 0;
}
