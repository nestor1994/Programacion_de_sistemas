#include <iostream>

using namespace std;
/*

ingresar 5 numeros y contar cuantos son pares e impares.

*/


int main()
{

    int num,cpar,cimpar;
    int conta=0;
    cpar=0; cimpar=0;

    while(conta<5){

        cout<<"Ingresar un numero :";
        cin>>num;

        if((num%2)==0) //mod(x1,2) == num%2

            {cpar++;}

        else{cimpar++;}

        conta++;

    }

    cout<<"Numero de pares :"<<cpar<<endl;

    cout<<"Numero de impares :"<<cimpar;




    return 0;
}
