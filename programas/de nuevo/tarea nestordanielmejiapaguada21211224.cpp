#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
/*
Se tiene un arreglo de registros con la siguiente estructura.
Nombre
zona
Ventas
comision
Elaborar un procedimiento para ingresar el registro nombre, ventas y validar ventas.
Debera de calcular la comision ganada usando una funcion.
Turno           comis
A                  5%
B                  6%
C                  8%

Elaborar un procedimiento para calcular todas las comisiones.
Elaborar una funcion para devolver el mejor empleado usando la comision ganada.
*/

struct empleado
{
    string nombre;
    char zona;
    double ventas;
    double comision;
};
const int n=3;

empleado emple[n];



void ingresar(empleado emple[], int n)
{
   int j;
   for (j=0;j<n;j++)
   {
       cout<<"Ingrese el nombre del empleado:  ";
       cin>>emple[j].nombre;

       cout<<"Ingrese las ventas:  ";
       cin>>emple[j].ventas;
       _flushall();

       do
       {
           cout<<"Ingrese la zona donde trabajo: ";
           cin.get(emple[j].zona);
           cout<<endl;
           _flushall();
       }while ((emple[j].zona!='A') and (emple[j].zona!='B') and (emple[j].zona!= 'C'));


   }
}

double comision(char zona)
{
    switch (zona)
    {
     case 'A':
        return 0.05;
        break;
     case 'B':
        return 0.06;
        break;
     case 'C':
        return 0.08;
        break;
    }
}

void comisiones(empleado emple[],int n)
{  int k;
    for(k=0;k<n;k++)
    {
       emple[k].comision= emple[k].ventas * comision(emple[k].zona);
    }
}

empleado mejorempleado(empleado emple[],int n)
{
    empleado mejorempleadox;
    mejorempleadox=emple[0];
    for(int k=0;k<n;k++)
    {
        if (mejorempleadox.comision<emple[k].comision)
         mejorempleadox=emple[k];
    }return mejorempleadox;

}

void presentacion_uno(empleado emple)
{
    cout<<"Nombre del empleado: "<<emple.nombre<<endl;
    cout<<"Zona en que trabaja: "<<emple.zona<<endl;
    cout<<"Las ventas que realizo: "<<emple.ventas<<endl;
    cout<<"La comision ganada: "<<emple.comision<<endl;
    cout<<endl;
    cout<<endl;
}

void presentaciontotal(empleado emple[], int n)
{  int j;
    for(j=0;j<n;j++)
    {
        presentacion_uno(emple[j]);
    }
}

void orden(empleado emple [], int n)
{
    empleado posicion;

    for (int i=1; i<n; i++){
          for (int k=0 ; k<n - 1; k++){
               if (emple[k].comision > emple[k+1].comision)
               {
                    posicion = emple[k];
                    emple[k]= emple[k+1];
                    emple[k+1]= posicion;
                }
              }
           }
         }

void ordennombre(empleado emple [], int n)
{
    empleado posicion;

    for (int k=1; k<n; k++){
          for (int j=0 ; j<n - 1; j++){
               if (emple[j].nombre > emple[j+1].nombre)
               {
                    posicion = emple[j];
                    emple[j]= emple[j+1];
                    emple[j+1]= posicion;
                 }
             }
           }
        }

int main()
{
    ingresar(emple,n);
    comisiones(emple,n);
    orden(emple,n);
    cout<<"Presentacion por orden de comision: "<<endl;
    presentaciontotal(emple,n);
    cout<<endl;
    cout<<"Presentacion por orden de nombre: "<<endl;
    ordennombre(emple,n);
    presentaciontotal(emple,n);
    cout<<endl;
    cout<<"El mejor empleado es: "<<endl;
    presentacion_uno(mejorempleado(emple,n));


}
