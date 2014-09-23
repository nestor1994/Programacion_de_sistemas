#define MAX_FILA 3
#define MAX_COLUM 3
#define MAX_JUG 2
#define MAX_TURNO 9
#define GANA_O 237
#define GANA_X 264
#include <conio.h>
#include <iostream>

using namespace std;


void turno_jugador();
void imprimir_tablero(char X0[MAX_FILA][MAX_COLUM]);
int verificar_filas(char X0[MAX_FILA][MAX_COLUM]);
int verificar_columnas(char X0[MAX_FILA][MAX_COLUM]);
int verificar_diagonal(char X0[MAX_FILA][MAX_COLUM]);
int verificar_d_inversa(char X0[MAX_FILA][MAX_COLUM]);
int main()
{
    cout<<"Juego del X y 0"<<endl;
    turno_jugador();
    return 0;
}
void imprimir_tablero(char X0[MAX_FILA][MAX_COLUM])
{
    int i,j;
    for(i=0;i<MAX_FILA;i++)
    {
        for(j=0;j<MAX_COLUM;j++)
        {
            if((X0[i][j]=='X')||(X0[i][j]=='O'))
                cout<<X0[i][j];
            else
               cout<<" ";
               cout<<"|";
        }
        cout<<endl;
           cout<<"______";
        cout<<endl;
    }
}
int verificar_filas(char X0[MAX_FILA][MAX_COLUM])
{
    int i,j,suma,ganador=0;
    for(i=0;i<MAX_FILA;i++)
    {
        suma=0;
        for(j=0;j<MAX_COLUM;j++)
            suma=suma+X0[i][j];
        if(suma==GANA_X)
        {
            cout<<"El ganador es el jugador X"<<endl;
            ganador=1;
            return ganador;
        }
        else if(suma==GANA_O)
        {
            cout<<"El ganador es el jugador 0"<<endl;
            ganador=2;
            return ganador;
        }
        else
           ganador=0;
    }
    if(ganador==0)
       ganador=verificar_columnas(X0);
    return ganador;
}
int verificar_columnas(char X0[MAX_FILA][MAX_COLUM])
{
    int i,j,suma,ganador;
    for(i=0;i<MAX_FILA;i++)
    {
        suma=0;
        for(j=0;j<MAX_COLUM;j++)
            suma=suma+X0[j][i];
        if(suma==GANA_X)
        {
            cout<<"El ganador es el jugador X"<<endl;
            ganador=1;
            return ganador;
        }
        else if(suma==GANA_O)
        {
            cout<<"El ganador es el jugador 0"<<endl;
            ganador=2;
            return ganador;
        }
        else
           ganador=0;
    }
    if(ganador==0)
       ganador=verificar_diagonal(X0);
    return ganador;
}
int verificar_diagonal(char X0[MAX_FILA][MAX_COLUM])
{
    int i,suma=0,ganador;
    for(i=0;i<MAX_FILA;i++)
       suma=suma+X0[i][i];
    if(suma==GANA_X)
    {
        cout<<"El ganador es el jugador X"<<endl;
        ganador=1;
        return ganador;
    }
    else if(suma==GANA_O)
    {
        cout<<"El ganador es el jugador 0"<<endl;
        ganador=2;
        return ganador;
    }
    else
       ganador=0;
    if(ganador==0)
       ganador=verificar_d_inversa(X0);
    return ganador;
}
int verificar_d_inversa(char X0[MAX_FILA][MAX_COLUM])
{
    int i,j,suma=0,ganador;
    for(i=2,j=0;j<MAX_COLUM;i--,j++)
       suma=suma+X0[i][j];
    if(suma==GANA_X)
    {
        cout<<"El ganador es el jugador X"<<endl;
        ganador=1;
        return ganador;
    }
    else if(suma==GANA_O)
    {
        cout<<"El ganador es el jugador 0"<<endl;
        ganador=2;
        return ganador;
    }
    else
       ganador=0;
    return ganador;
}
void turno_jugador()
{
    int fila,columna,i,turno,ganador=0;
    char jugador[]={'X','O'};
    char X0[MAX_FILA][MAX_COLUM],letra;
    turno=1;
    do
    {
        for(i=0;i<MAX_JUG;i++)
        {

            cout<<"Es turno del jugador"<<jugador[i]<<endl<<endl;
            do{
            cout<<"Elija la fila (1 a 3): ";
            cin>>fila;
            }while(!((fila>=1)and(fila<=3)));
            do{
            cout<<"Elija la columna(1 a 3): ";
            cin>>columna;
            }while(!((columna>=1)and(columna<=3)));
            letra=jugador[i];
            X0[fila-1][columna-1]=letra;
            imprimir_tablero(X0);
            ganador=verificar_filas(X0);
            if(ganador!=0)
                i=MAX_JUG+1;
            cout<<"Pulse enter para continuar con el juego..."<<endl;
            getch();

            turno++;
        }
    }while((turno<=MAX_TURNO)&&(ganador==0));
}
