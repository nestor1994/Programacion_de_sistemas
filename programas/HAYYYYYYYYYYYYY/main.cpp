#include <iostream>
#include <iomanip>

using namespace std;



unsigned long factorial(unsigned long); // prototipo de funcion, utilice unsigned long
                                                              //porque el factorial crece muy rápido!

int main()
{
    // calcula factorial 0-15
    for(int i=0;i<=15;i++)
    {
        cout<<setw(2)<<i<<"! = "<<factorial(i)<<endl; // imprimo el numero de iteracion
    }                                                                          //y el valor del factorial, con la llamada a la funcion.

    return 0;
}

unsigned long factorial(unsigned long numero) // La definicion de la funcion
{

    if (numero<=1) // esta condicion es para los casos 0! y 1! que como sabemos son igual a 1.
        return 1;
    else
        return numero*factorial(numero-1); // aqui la recursion es evidente pues dentro de la misma funcion
}                                                            // hacemos otro llamado, hasta que la condicion del if se cumpla.
