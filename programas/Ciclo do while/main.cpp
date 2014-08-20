#include <iostream>
#include<stdlib.h>
#include<stdio.h>


/*
Ingresar un numero hasta que el usuario diga que no quiere ingresar mas numeros.......


*/
using namespace std;

int main()
{

    int num;
    char resp;
    int mayor=0;
    do
    {
        cout<<"Ingresar un numero: ";
        cin>>num;
        _flushall();
        if(mayor<num)
        {
            mayor=num;
        }
      do
      {
          cout<<"Desea continuar :";
          cin.get(resp);
          _flushall();
      }while  ((resp!='S') and (resp!='N'));


        cout<<"Desea continuar: ";
        cin.get(resp);


    } while (resp!='N');



 cout<<"El nombre mayor es: "<<mayor<<endl;





return 0;

}
