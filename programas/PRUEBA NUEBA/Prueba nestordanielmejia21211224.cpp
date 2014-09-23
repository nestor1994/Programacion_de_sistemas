#include <iostream>

/*
Elaborar un progroma donde ingresemos datos en un arreglo bidimensional
de 4 lineas y 5 columnas y dejemos la ultima linea reservada para sumar los numeros pares.
si no hay pares debera de aparecer 0.

*/


using namespace std;

int const lin=4;
int const col=5;
int bidi[lin][col];
int linsuma,sumal;

void ingreso(int bidi[][col],int lin, int col)
{
    int l,c;
    for(l=0; l<lin-1;l++ )
    {
        for(c=0; c<col;c++)
        {
            cout<<"Ingresar numero["<<l<<","<<c<<"].....:";
            cin>>bidi[l][c];
        }

    }



}
void presentar(int bidi[][col],int lin, int col)
{
   int l,c;
for(l=0; l<lin;l++ )
    {
        for(c=0; c<col;c++)
        {
            cout<<bidi[l][c]<<" ";

        }
        cout<<endl;
    }
}
int sumarfila(int bidi[][col],int lin,int col,int linsuma)
{
   int c,xsuma=0;
   for (c=0;c<col;c++)
   {
       xsuma+=bidi[linsuma][c];
   }

    return xsuma;

}

void sumadepares(int bidi[][col],int col,int lin)
{

     int l,c;
for (c=0;c<col;c++)
    {

   for(l=0; l<lin-1;l++ )
    {
    if(bidi[l][c]%2==0)
    {

    bidi[lin-1][c]+=bidi[l][c];

    }

    }

    }

}

int main()
{
   ingreso(bidi,lin,col);

    sumadepares(bidi,col,lin);
   presentar(bidi,lin,col);

}
