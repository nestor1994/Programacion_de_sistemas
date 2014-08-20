#include <iostream>

using namespace std;
/*
ingresar  nota acumulada y examen del alumno, calcular la nota final,
luego presentar si esta aprobado o reprobado, luego de finalizar el ciclo
hacerlo para 5 alumnos.

 */

int na,ne,nf,capr,crep,paso,cont,c;

int main()
{
    c=0;

    while(c<5){



        cout<<"Nota acumulada: ";
        cin>>na;
        cout<<"Nota de Examen: ";
        cin>>ne;

        nf=na+ne;

        cout<<"Nota final: "<<nf<<"\n";
        if(nf>=60){
                capr++;
        cout<<"Estado aprobado";

        }

     else{crep++;


        cout<<"Estado reprobado"<<"\n";
     }




       cout<<"Pasaron"<<paso<<endl;
       cout<<"No pasaron"<<cont<<endl;
    }





    return 0;
}
