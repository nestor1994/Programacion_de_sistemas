#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




using namespace std;
char cadena[30];

void presentar1 (char cadena[])
{
    int i,k;
    for(i=0; i<strlen(cadena); i++)
    {

        for(k=0; k<=i; k++)
        {
            cout<<cadena[k];
        }
         cout<<endl;
    }

}

void presentar2(char cadena[])
{
    int i,k;
    for(i=strlen(cadena); i>=0; i--)
    {
        for(k=0;k<=i;k++)
        {
            cout<<cadena[k];
        }
        cout<<endl;
    }

}




int main()
{
    cout << "Ingresar cadena de texto....: ";
    cin.getline(cadena,30);
    presentar1(cadena);
    presentar2(cadena);

    for(int i=0; i<strlen(cadena); i++)
    {cadena[i]='X';}

    cout<<endl;
    presentar1(cadena);







}
