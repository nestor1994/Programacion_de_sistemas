#include <iostream>
/* Ingresar la tabla de la multiplicacion a presentar, usar el ciclo for asi

1x5=5
2x5=10
........           */



using namespace std;

int main()
{
   int tabla,resp,i;


   cout<<"Tabla de multiplicar a presentar....:";
   cin>>tabla;

   for(i=1; i<=10; i++)
   {

       resp= i*tabla;
       cout<<i<<"X"<<tabla<<"="<<resp<<endl;

   }


    return 0;
}
