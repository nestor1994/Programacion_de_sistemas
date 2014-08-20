#include <iostream>
#include <stdlib.h>
using namespace std;


/*
Ingresar las horas trabajadas y el pago por hora del empleado
luego determinar su pago de horas, la deducción del rap que
es el 1.5% del ingreso, presentar el total a pagar.


*/

int main()
{
    int horas, pxh,phoras,rap,totalp;

    cout<<"Ingresar las horas trabajadas......: ";
    cin>> horas;

    cout<<"Ingresar el pago por hora......: ";
    cin>> pxh;


    phoras= pxh * horas;
    rap = phoras * 0.015;
    totalp= phoras - rap;

    cout<<"Pago total de horas es: "<< phoras<<"\n";
    cout<<"deduccion del rap..... "<<rap<<"\n";
    cout<<"Total a pagar es.......: "<<totalp<<"\n";


    system("PAUSE");



}
