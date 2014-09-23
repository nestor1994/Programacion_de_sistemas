#include <iostream>
/*
se tiene que pedir un numero entero y guardar en la lista de punteros solos los pares
y luego preguntar si desea ingresar otro numero luego presentar la lista
*/
using namespace std;

#include <iostream>

using namespace std;
struct nodo {
int numero;
struct nodo *siguiente;



};
struct nodo *primero, *ultimo;
struct nodo *nuevo;






int main()
{
    primero = new nodo;
    ultimo = new nodo;
    primero= NULL;
    int xnum;
    char decision;
    do
    {
        nuevo = new nodo;
        cout<<"Ingresar un numero: ";
        cin>>xnum;
        nuevo-> numero=xnum;
        nuevo-> siguiente=NULL;

        if(primero==NULL)
        {
          primero =nuevo;
          ultimo = nuevo;
          cout<<"Inicio"<<endl;

        }
        else
        {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }

        cout<<"Desea continuar: ";
        cin>>decision;


    }while(decision == 's');

    ultimo->siguiente=NULL;
    struct nodo *aux;
    aux= primero;
    cout<<"\nMostrando la lista completa: \n";
    while (aux!=NULL){
            if((aux->numero%2)==0)
                {cout<<"Numero"<<aux->numero<<endl;}
        aux=aux ->siguiente;



    }






    return 0;
}
