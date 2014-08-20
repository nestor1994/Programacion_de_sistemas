#include <iostream>

using namespace std;

int main()
{
   int numero, p;

  cout<<"introdusca numero entero: ";
  cin>>numero;

   while((numero>0)){

    p=numero%10;
    numero=numero/10;
    cout<<p;
}
    return 0;
}
