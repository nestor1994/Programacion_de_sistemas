#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
/*Se tiene un arreglo de registros con la siguiente estructura.
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
   int i;
   for (i=0;i<n;i++)
   {
       cout<<"Ingrese el nombre del empleado:  ";
       cin>>emple[i].nombre;

       cout<<"Ingrese las ventas:  ";
       cin>>emple[i].ventas;
       _flushall();

       do
       {
           cout<<"Ingrese la zona donde trabajo: ";
           cin.get(emple[i].zona);
           cout<<endl;
           _flushall();
       }while ((emple[i].zona!='A') and (emple[i].zona!='B') and (emple[i].zona!= 'C'));


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
{  int i;
    for(i=0;i<n;i++)
    {
       emple[i].comision= emple[i].ventas * comision(emple[i].zona);
    }
}

empleado mejorempleado(empleado emple[],int n)
{
    empleado mejorempleadox;
    mejorempleadox=emple[0];
    for(int i=0;i<n;i++)
    {
        if (mejorempleadox.comision<emple[i].comision)
         mejorempleadox=emple[i];
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
{  int i;
    for(i=0;i<n;i++)
    {
        presentacion_uno(emple[i]);
    }
}

void orden(empleado emple [], int n)
{
    empleado posicion;

    for (int i=1; i<n; i++){
          for (int j=0 ; j<n - 1; j++){
               if (emple[j].comision > emple[j+1].comision)
               {
                    posicion = emple[j];
                    emple[j]= emple[j+1];
                    emple[j+1]= posicion;
               }
          }
    }
}

void ordennombre(empleado emple [], int n)
{
    empleado posicion;

    for (int i=1; i<n; i++){
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
    cout<<"----------Presentacion por orden de comision------------"<<endl;
    presentaciontotal(emple,n);
    cout<<endl;
    cout<<"----------Presentacion por orden de nombre------------"<<endl;
    ordennombre(emple,n);
    presentaciontotal(emple,n);
    cout<<endl;
    cout<<"----El mejor empleado es-----: "<<endl;
    presentacion_uno(mejorempleado(emple,n));


}
