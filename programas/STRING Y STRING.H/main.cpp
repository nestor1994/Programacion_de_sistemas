#include <iostream>
#include <string>
#include <string.h>

using namespace std;
string cadena,insertado;

int main()
{
    cout << "Ingresar la cadena...: ";
    cin>>cadena;
    insertado=cadena.insert(1,"Juan");
    cout<<"Valor insertado: "<<insertado<<endl;
    string ree;
    ree= "XXXXX";
    ree= ree.replace(0,1,"Rommel");
    cout<<"Valor ree"<<ree<<endl;

    return 0;
}
