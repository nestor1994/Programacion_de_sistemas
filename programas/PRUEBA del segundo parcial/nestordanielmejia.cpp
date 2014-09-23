#include <iostream>
#include<stdlib.h>
#include<stdio.h>





using namespace std;

using namespace std;
struct empleado

{
   char nombre[50],zona;
   int horas,ventas,comision;




};

empleado m;

int main(){

cout<<"Nombre del empleado :";
cin.getline(m.nombre,50);


cout<<"horas: ";
cin>>m.horas;

cout<<"ventas: ";
cin>>m.ventas;

cout<<"Zona A B C: "<<m.zona;



}

 empleado(int zona)
{
  switch(m.zona)
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
return m.zona;

}







