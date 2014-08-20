#include <iostream>

using namespace std;
 /*
 se ingresa el nombre del aspirante, la edad, experiencia,
 (1o0), si tiene titulo(1o0)
 luego se imprime si esta contratado a no lo esta.
 si la edad esta entre 22-27 y tiene titulo se contrata o si tiene 15
 años de experiencia

 */


int main()
{
    int titulo,expe,edad;
    char nombre[30];

    cout<<"Ingresar el nombre del aspirante: ";
    cin.getline(nombre,30);

    cout<<"tiene titulo ";
    cin>>titulo;

    cout<<"edad...";
    cin>>edad;

    if((((edad>1)and(edad<=27)) and (titulo==1)) or (expe>15))
        cout<<"contratado";
    else
        cout<<"vuelva ha intentarlo no esta contratado";



}
