#include <iostream>
#include <stdlib.h>
#include <time.h>

/*

presentar 10 numeros usando el ciclo for


*/
using namespace std;

int main()
{
    srand(time(0));// generar una nueva semilla
    int num,i;
    for(i=0;i<10;i++){


        num=1 + rand()%(101-1);
        cout<<i<<"...>"<<num<<endl;
    } //final del ciclo.





    return 0;
}
