#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
/*
Ingresar el nombre del empleado, las horas de 4 dias trabajados (usar un ciclo for para ingresar las 4 horas),
luego se debera de presentar el total de las horas. Se determina el pago por hora usando la zona de
trabajo.
Zona    Pago
A       150
B       200
C       250
Determinar el salario, ihss, y total a pagar.
Preguntar si desea continuar. (validar respuesta).
ihss>7000= 245; sino es de 0.035
*/

int main()
{
    char nombre[30], respuesta, zona;
    int totalhoras=0;
    int horas;
    double salario, ihss, tp, pagoxhora;
    int i;

    do
    {

        cout<<"Ingresar el nombre del empleado:...";
        cin.getline (nombre,30);

        for (i=0;i<4;i++)
        {
        do
         {
           cout<<"Ingresar las horas trabajadas en el dia #"<<i+1<<":...";
            cin>>horas;

            totalhoras+= horas;
         }while (!((horas>=0) and (horas<=24)));
        }

        cout<<"Total de horas trabajadas:..."<<totalhoras<<endl;


        do
        {
            cout<<"Ingresar la zona de trabajo (A,B,o C):...";
            cin>>zona;

        }while ((zona != 'A') and (zona != 'B') and (zona != 'C'));

        switch (zona)
        {
            case 'A':
                pagoxhora= 150;
                break;
            case 'B':
                pagoxhora= 200;
                break;
            case 'C':
                pagoxhora= 250;
                break;
        }

        salario= pagoxhora * totalhoras;


        if (salario>7000)
            ihss= 245;
        else
            ihss= 0.035 * salario;

        tp= salario - ihss;

        cout<<"El salario es:..."<<salario<<endl;
        cout<<"El IHSS es:..."<<ihss<<endl;
        cout<<"El total a pagar es:..."<<tp<<endl;

        _flushall();
        do
        {
            cout<<"Desea continuar?(S= SI/ N= NO):";
            cin.get (respuesta);
        _flushall();
        }while ((respuesta!='S') and (respuesta!='N'));
    }while (respuesta!='N');

system("PAUSE");
}
