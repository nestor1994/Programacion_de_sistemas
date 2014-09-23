#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
/*
Ingresar el nombre del empleado, las ventas del mes y el turno
de trabajo (1,2,3, validarlo), luego determinar el % de comisión usando el turno

turno  %comision
1        5%
2        6%
3        7%
preguntar si desea continuar.




*/




int main()
{
    char nombre[30], res;
    int turno;
    double comis, pc, ventas;
    do
    {

    cout<<"Ingresar el nombre del empleado: ";
    cin.getline(nombre,30);
    cout<<"Ventas del mes: ";
    cin>>ventas;

    do
    {

        cout<<"Turno de trabajo: ";
        cin>>turno;

    }while(!((turno>=1)&&(turno<=3)));

       switch(turno)
       {
       case 1:
        pc=0.05;
        break;

        case 2:
        pc=0.06;
        break;

        default:
        pc=0.07;
        break;







       }

     comis=ventas*pc;
     _flushall();
     cout<<"% de Comision: "<<pc<<endl;
     cout<<"Comision ganada"<<comis<<endl;

     do
        {
        cout<<"Desea continuar :";
        cin.get(res);
        _flushall();
        }while((res!='s')&&(res!='N'));

    }while(res!='N');






    return 0;
}
