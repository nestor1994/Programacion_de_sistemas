#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
//generar 10 numeros aleatorios
int main()
{
    int num;
    int conta=0;
    int mayor;

    srand(time(0));//generar una nueva semilla
     cout<<"Numero aleatorios"<<endl;
   mayor=0;
    while(conta<10)

        {
        num=1+rand()%(101-1);
        //num=30+rand()%(41-30)
        // num=linferior+rand()%(limitesuperior+1-1limiteinferior);
        cout<<num<<endl;
        conta++;

        if(num>mayor){

            mayor=num;
        }





        }

        cout<<"Numero mayor es :"<<mayor<<endl;





    return 0;
}
