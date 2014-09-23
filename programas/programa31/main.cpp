#include <iostream>


using namespace std;
/*  "PROCEDIMIENTOS":
Ingresar 2 numeros usando un procedimiento, luego calcular la suma, el numero mayor usando un procedimeitno,
presentar los datos.
*/

int suma, mayor, menor;

int menornumero(int num1,int num2)
{
    int menor;
    if (num1< num2)
        menor =num1;
    else
        menor= num2;
    return menor;
}

void ingresar (int &num1,int &num2)
{
    cout<<"Ingresar numero 1 >";
    cin>>num1;

    cout<<"Ingresar numero 2 >";
    cin>>num2;
}

void calcular (int num1, int num2, int &mayor, int&suma)
{
    suma= num1 +num2;
    if (num1>num2)
        mayor= num1;
    else
        mayor= num2;
}


int main()
{
    int num1=0, num2=0;
    ingresar(num1,num2);
    calcular(num1,num2,mayor,suma);
    menor = menornumero(num1, num2);

    cout<<"Valor numero1 "<<num1<<endl;
    cout<<"Valor numero2 "<<num2<<endl;
    cout<<"Suma "<<suma<<endl;
    cout<<"Mayor "<<mayor<<endl;
    cout<<"Menor "<<menor<<endl;

}
