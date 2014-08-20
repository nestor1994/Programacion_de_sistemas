#include <iostream>
#include <stdlib.h>
using namespace std;
/*
Ingresar el nombre del empleado, las ventas y el turno
luego calcular el % de comision, ihss y total a pagar turno %comision
1             5%
2             7%
3             9%

BONO
Este se da si la persona vendio mas de 50,000 y es de la zona 1 o 3
el bono es de 500 sino es de 150;

*/



int main()
{
    char nombre[30];
    double ventas, comis, ihss, pc , tp;
    int turno;
    int bono;

    cout<<"Ingresar el nombre del empleado........:";
    cin.getline(nombre,30);

    cout<<"ventas del mes.....";
    cin>>ventas;

    cout<<"turno del empleado.... :";
    cin>>turno;

    if(turno==1)
        pc=0.05;
    else if(turno==2)
        pc=0.07;
    else if (turno==3)
        pc=0.09;
        else
        pc=0;
    comis=ventas*pc;
if((ventas>50000)&&((turno==1)||(turno==3)))
bono=500;
else bono=150;

if(comis>7000)
        ihss=245;
    else
        ihss=0.035*comis;

    tp=comis-ihss;

    cout<<"el % de comision.....:"<<pc<<"\n";
    cout<<"comision ganada "<<comis<<"\n";
    cout<<"Bono"<<bono<<"\n";
    cout<<"ihss"<<ihss<<"\n";
    cout<<"Total a pagar "<<tp<<"\n";

    cout<<"\n";
    system("PAUSE");


}
