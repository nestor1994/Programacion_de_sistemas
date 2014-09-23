#include <iostream>

using namespace std;
/*
Ingresar 5 alumnos a un registro con los siguientes datos
nombre, parcial1,parcial2, promedio.

usando un procedimiento ingresar el nombre y las notas.
usar una función para calcular el promedio de un alumno.
usar un procedimiento para calcular los promedios de todos los alumnos.

usar una función para devolver el mejor alumno de todo el arreglo.
elaborar un procedimiento para presentar un alumno.
elaborar un procedimiento para presentar todos los empleados.


*/

struct registro

{
   char nombre[30];
   int parcial1,parcial2,promedio;//validar que el turno sea 1,2,3




};

int const n=5;
registro alumno[n];




void ingreso(registro alumno[],int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        cout<<"Ingresar nombre del alumno";
        cin.getline(alumno[i].nombre,30);
        cout<<"primer parcial....: ";
        cin>>alumno[i].parcial;
        cout<<"segundo parcial....: ";
        cin>>alumno[i].parcial;
        do
        {
            cout<<"Turno de trabajo...: ";
            cin>>alumno[i].parcial;
        }while(!((emple[i].parcial>=1)and(alumno[i].parcial<=3)));
         _flushall();
    }




}






int main()
{

    return 0;
}







