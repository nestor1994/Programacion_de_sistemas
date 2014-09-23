#include <iostream>
#include <string.h>
using namespace std;
struct alumnos
{

    char nombre[30];
     int parcial[3];
    double promedio;
    char obs [30];
};
int const n=5;
alumnos alumno[n];

void ingreso(alumnos alumno[], int n)
{
    int i,k;
    for(i=0;i<n;i++)
    {
        cout<< "Ingresar el nombre del alumno : ";
        cin.getline(alumno[i].nombre,30);
        for(k=0;k<3;k++)
        {
            cout<< "Ingresar Parcial "<<k<<" : ";
            cin>>alumno[i].parcial[k];
        }
    }
}

double calpromedio(int parcial[])
{   int k;
    double suma=0;
    for(k=0;k<3;k++)
    {
        suma+=parcial[k];
    }

    return suma/3;
}

void calcular(alumnos alumno[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        alumno[i].promedio=calpromedio(alumno[i].parcial);
        if (alumno[i].promedio>60)
        {
            strcpy(alumno[i].obs,"Aprobado");
        }
        else
        {
            strcpy(alumno[i].obs, "Reprodado");
        }
    }
}

void calcularT(alumnos alumno[], int n)
{
    int i,k;
    for(i=0;i<n;i++)
    {
        cout<< alumno[i].nombre<< "Promedio : "<<alumno[i].promedio<< "Obs";
    }
}

int main()
{
    ingreso(alumno,n);
    calcular(alumno,n);
}
