#include <iostream>
#include <stdlib.h>
#include <stdio.h>
/*

Ingresar el nombre del empleado, las horas de 4 dias trabajados
(usar un ciclo for para ingresar las 4 horas), luego se debera de presentar
el total de las horas, se determina el pago por hora usando
la zona de trabajo
ZONA      PAGO
A          150
B          200
C          250

determinar el salario, ihss y total pagar.
preguntar se desea continuar (validar respuesta)


*/

/*

usar el for preguntando 4 veces cuantas horas trabajo en el dia y que despues se sumen

*/


using namespace std;

int main()
{
   char d[40];
   int g, i, j;



    for(i=1; i<5; i++)
    {
        for(j=1; j<i; j++)
            {
            cout<<"cuantas horas trabajo: "<<endl;
            cin>>g;
            _flushall();
            }



    cout << "Nombre del empleado: "<<endl;
    cin.getline(d,40);
    _flushall();

    }












    return 0;
}
