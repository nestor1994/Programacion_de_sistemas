#include <iostream>

using namespace std;
const int n=5;
int num[n];
int suma;
int mayor;
void ingreso(int num[], int n)
{

    int i;
    for (i=0; i<n; i++)
    {
        cout<<"Ingresar num["<<i<<"]......:";
        cin>>num[i];
    }



}




void presentar (int num[], int n)
{


    int i;
    for(i=0; i<n; i++)
    {
        cout<<"Num["<<i<<"]......"<<num[i]<<endl;

    }




}

int sumaarreglo(int num[],int n)
{
    int i;
    int xsuma=0;
    for(i=0; i<n; i++)
    {
        xsuma+=num[i];
    }
    return xsuma;

}



int maximo(int num[], int n)
{
    int i;
    int xmax=0;
    for (i=0; i<n; i++)
    {
       if (xmax<num[i])
       {
           xmax+=num[i];
       }


    }

    return xmax;
}




int main()
{

    mayor=0;
    suma=0;

    ingreso(num,n);
    presentar(num,n);
     suma=sumaarreglo(num,n);
     mayor= maximo(num,n);

    cout<<"Suma del arreglo es......:"<<suma<<endl;
    cout<<"Numero mayor....: "<<mayor<<endl;

}



