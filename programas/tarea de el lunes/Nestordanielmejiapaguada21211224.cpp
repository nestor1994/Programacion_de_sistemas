#include <iostream>
#include <math.h>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <cstdio>

/*
Se tiene un arreglo de 4 líneas
con 4 columnas, existen 4 minas puestas aleatoriamente.

Usted deberá de preguntar la línea
y la columna donde aplicara una marca, si usted pisa una mina el programa le dirá,
la misión será encontrar las 4 minas y así el programa termina.

El programa deberá de funcionar
para dos jugadores 1 y 2, uno juega primero y se guarda los intentos que tubo
para encontrar las minas y luego el segundo jugador y el que menos intentos
tenga será el ganador.


*/
using namespace std;

//Tamaños máximos de las matrices
const int MAX_HORIZONTAL = 4;
const int MAX_VERTICAL = 4;

//Constante que identifican los valores posibles del tablero interno
const int MINA = -1;
const int NO_ASIGNADO = -2;

//Constantes que identifican los valores posibles del tablero del jugador
const int TAPADO = 1;
const int DESTAPADO = 2;
const int MARCADO_POSIBLE_MINA = 3;
const int MARCADO_MINA = 4;

//Constantes que definen los posibles niveles de dificultad
const int JUEGO_FACIL = 1;
const int JUEGO_INTERMEDIO = 2;
const int JUEGO_AVANZADO = 3;

//Variables del juego
int tamanoHorizontal;
int tamanoVertical;
int numeroMinas;
int minasMarcadas;
bool juegoIniciado;
bool juegoTerminado;
char separador = '-';
int tiempo;
clock_t inicioJuego;
int nivel;
int mejorTiempoPrincipiante = 0;
string nombreMejorTiempoPrincipiante;
int mejorTiempoIntermedio = 0;
string nombreMejorTiempoIntermedio;
int mejorTiempoAvanzado = 0;
string nombreMejorTiempoAvanzado;

//Tablero de las jugadas realizadas
int tableroJugador[MAX_HORIZONTAL][MAX_VERTICAL];

//Tablero de la ubicación de las minas y las posiciones de proximidad
int tableroInterno[MAX_HORIZONTAL][MAX_VERTICAL];

int minasAdyacentes(int x, int y)
{
	int minasAdyacentes = 0;
	if (tableroInterno[x][y] == MINA)
	{
		minasAdyacentes = MINA;
	}
	else
	{
		if(x-1 >= 0 && y-1 >= 0)
			if(tableroInterno[x-1][y-1] == MINA)
				minasAdyacentes++;
		if(x-1 >= 0)
			if(tableroInterno[x-1][y] == MINA)
				minasAdyacentes++;
		if(x-1 >= 0 && y+1 < tamanoVertical)
			if(tableroInterno[x-1][y+1] == MINA)
				minasAdyacentes++;
		if(y-1 >= 0)
			if(tableroInterno[x][y-1] == MINA)
				minasAdyacentes++;
		if(y+1 < tamanoVertical)
			if(tableroInterno[x][y+1] == MINA)
				minasAdyacentes++;
		if(x+1 < tamanoHorizontal && y-1 >= 0)
			if(tableroInterno[x+1][y-1] == MINA)
				minasAdyacentes++;
		if(x+1 < tamanoHorizontal)
			if(tableroInterno[x+1][y] == MINA)
				minasAdyacentes++;
		if(x+1 < tamanoHorizontal && y+1 < tamanoVertical)
			if(tableroInterno[x+1][y+1] == MINA)
				minasAdyacentes++;
	}
	return minasAdyacentes;
}

void iniciarTableros()
{
	//Se marca todo el tablero del jugador con posiciones cubiertas, y se inicializan
	//los contenidos del tablero interno
	for(int j = 0; j<MAX_VERTICAL; j++)
	{
		for(int i = 0; i<MAX_HORIZONTAL; i++)
		{
			tableroJugador[i][j] = TAPADO;
			tableroInterno[i][j] = NO_ASIGNADO;
		}
	}

	//Se ubican las minas
	int minasEnTablero = 0;
	do
	{
		int posicionX = rand() % tamanoHorizontal;
		int posicionY = rand() % tamanoVertical;
		if (tableroInterno[posicionX][posicionY] == NO_ASIGNADO)
		{
			tableroInterno[posicionX][posicionY] = MINA;
			minasEnTablero++;
		}
	}
	while(minasEnTablero < numeroMinas);

	//Se ponen los números de minas adyacentes
	for(int j = 0; j<tamanoVertical; j++)
	{
		for(int i = 0; i<tamanoHorizontal; i++)
		{
			if (tableroInterno[i][j] == NO_ASIGNADO)
			{
				tableroInterno[i][j] = minasAdyacentes(i,j);
			}
		}
	}
}

void iniciarJuego(int tipoJuego)
{
	switch(tipoJuego)
	{
	case JUEGO_FACIL:
		tamanoHorizontal = 4;
		tamanoVertical = 4;
		numeroMinas = 4;
		break;
	case JUEGO_INTERMEDIO:
		tamanoHorizontal = 4;
		tamanoVertical = 4;
		numeroMinas = 4;
		break;
	case JUEGO_AVANZADO:
		tamanoHorizontal = 4;
		tamanoVertical = 4;
		numeroMinas = 4;
		break;
	}
	juegoIniciado = false;
	juegoTerminado = false;
	minasMarcadas = 0;
	tiempo = 0;
	nivel = tipoJuego;
	iniciarTableros();
}

void mostrarTableroInterno()
{
	for(int j = 0; j<tamanoVertical; j++)
	{
		for(int l = 0; l<(tamanoHorizontal * 2 + 1); l++)
			cout << separador;
		cout << endl;
		for(int i = 0; i<tamanoHorizontal; i++)
		{
			cout << separador;
			switch (tableroInterno[i][j])
			{
			case MINA:
				cout << 'M';
				break;
			default:
				cout << tableroInterno[i][j];
				break;
			}
		}
		cout << separador << endl;
	}
	for(int l = 0; l<(tamanoHorizontal * 2 + 1); l ++)
		cout << separador;
	cout << endl;
}

void mostrarTableroJugador()
{
	cout << "Minas por marcar: " << numeroMinas - minasMarcadas << endl;
	for(int j = 0; j<tamanoVertical; j++)
	{
		for(int l = 0; l<(tamanoHorizontal * 2 + 1); l++)
			cout << separador;
		cout << endl;
		for(int i = 0; i<tamanoHorizontal; i++)
		{
			cout << separador;
			switch (tableroJugador[i][j])
			{
			case TAPADO:
				cout << '*';
				break;
			case DESTAPADO:
				cout << tableroInterno[i][j];
				break;
			case MARCADO_POSIBLE_MINA:
				cout << 'P';
				break;
			case MARCADO_MINA:
				cout << 'M';
			break;
			}
		}
		cout << separador << endl;
	}
	for(int l = 0; l<(tamanoHorizontal * 2 + 1); l ++)
		cout << separador;
	cout << endl;
}

void cambiarMejorResultado()
{
	string nuevoNombre;
	cout << "Introduzca su nombre" << endl;
	getline (cin,nuevoNombre);
	fflush(stdin);
	switch(nivel)
		{
		case JUEGO_FACIL:
			nombreMejorTiempoPrincipiante = nuevoNombre;
			mejorTiempoPrincipiante = tiempo;
			break;
		case JUEGO_INTERMEDIO:
			nombreMejorTiempoIntermedio = nuevoNombre;
			mejorTiempoIntermedio = tiempo;
			break;
		case JUEGO_AVANZADO:
			nombreMejorTiempoAvanzado = nuevoNombre;
			mejorTiempoAvanzado = tiempo;
			break;
		}
}

bool verificarMejorResultado()
{
	switch(nivel)
	{
	case JUEGO_FACIL:
		return (tiempo < mejorTiempoPrincipiante || mejorTiempoPrincipiante == 0);
		break;
	case JUEGO_INTERMEDIO:
		return (tiempo < mejorTiempoIntermedio || mejorTiempoIntermedio == 0);
		break;
	case JUEGO_AVANZADO:
		return (tiempo < mejorTiempoAvanzado || mejorTiempoAvanzado == 0);
		break;
	}
}

bool verificarJuegoTerminado()
{
	bool terminoJuego = true;
	for(int j = 0; j<tamanoVertical; j++)
	{
		for(int i = 0; i<tamanoHorizontal; i++)
		{
			if(terminoJuego)
			{
				bool noCoincideMinaMarcadaConMinaReal = ((tableroInterno[i][j] == MINA) && (tableroJugador[i][j] != MARCADO_MINA));
				bool noCoincideNoMinaMarcadaConNoMina = ((tableroInterno[i][j] != MINA) && (tableroJugador[i][j] == MARCADO_MINA));
				if (noCoincideMinaMarcadaConMinaReal || noCoincideNoMinaMarcadaConNoMina)
				{
					terminoJuego = false;
				}
			}
		}
	}
	return terminoJuego;
}

void marcarMina()
{
	if(minasMarcadas == numeroMinas)
	{
		cout << "Marco el maximo posible de minas, debe desmarcar alguna para poder marcar otra" << endl;
		mostrarTableroJugador();
	}
	else
	{
		int mina_x, mina_y;
		cout << "Introduzca la posicion horizontal" << endl;
		cin >> mina_x;
		fflush(stdin);
		cout << "Introduzca la posicion vertical" << endl;
		cin >> mina_y;
		fflush(stdin);
		if (!juegoIniciado)
		{
			juegoIniciado = true;
			inicioJuego = clock();
		}
		if (tableroJugador[mina_x-1][mina_y-1] == TAPADO  || tableroJugador[mina_x-1][mina_y-1] == MARCADO_POSIBLE_MINA)
		{
			tableroJugador[mina_x-1][mina_y-1] = MARCADO_MINA;
			minasMarcadas = minasMarcadas++;
			if(verificarJuegoTerminado())
			{
				juegoTerminado = true;
				tiempo = clock() - inicioJuego;
				cout << "Juego terminado, ha ganado, se demoro " << tiempo << " segundos" << endl;
				if(verificarMejorResultado())
				{
					cambiarMejorResultado();
				}
			}
			else
				mostrarTableroJugador();
		}
		else
			mostrarTableroJugador;
	}
}

void marcarPosibleMina()
{
	int posibleMina_x, posibleMina_y;
	cout << "Introduzca la posicion horizontal" << endl;
	cin >> posibleMina_x;
	fflush(stdin);
	cout << "Introduzca la posicion vertical" << endl;
	cin >> posibleMina_y;
	fflush(stdin);
	if (!juegoIniciado)
	{
		juegoIniciado = true;
		inicioJuego = clock();
	}
	tableroJugador[posibleMina_x-1][posibleMina_y-1] = MARCADO_POSIBLE_MINA;
}

void limpiarPosicion()
{
	int limpiar_x, limpiar_y;
	cout << "Introduzca la posicion horizontal" << endl;
	cin >> limpiar_x;
	fflush(stdin);
	cout << "Introduzca la posicion vertical" << endl;
	cin >> limpiar_y;
	fflush(stdin);
	if (!juegoIniciado)
	{
		juegoIniciado = true;
		inicioJuego = clock();
	}
	tableroJugador[limpiar_x-1][limpiar_y-1] = TAPADO;
}

void destaparPosicionDeterminada(int x, int y)
{
	tableroJugador[x][y] = DESTAPADO;
	if (tableroInterno[x][y] == 0)
		{
			if(x-1 >= 0 && y-1 >= 0)
				if (tableroJugador[x-1][y-1] != DESTAPADO)
					destaparPosicionDeterminada(x-1,y-1);
			if(x-1 >= 0)
				if (tableroJugador[x-1][y] != DESTAPADO)
					destaparPosicionDeterminada(x-1,y);
			if(x-1 >= 0 && y+1 < tamanoVertical)
				if (tableroJugador[x-1][y+1] != DESTAPADO)
					destaparPosicionDeterminada(x-1,y+1);
			if(y-1 >= 0)
				if (tableroJugador[x][y-1] != DESTAPADO)
					destaparPosicionDeterminada(x,y-1);
			if(y+1 < tamanoVertical)
				if (tableroJugador[x-1][y+1] != DESTAPADO)
					destaparPosicionDeterminada(x,y+1);
			if(x+1 < tamanoHorizontal && y-1 >= 0)
				if (tableroJugador[x+1][y-1] != DESTAPADO)
					destaparPosicionDeterminada(x+1,y-1);
			if(x+1 < tamanoHorizontal)
				if (tableroJugador[x+1][y] != DESTAPADO)
					destaparPosicionDeterminada(x+1,y);
			if(x+1 < tamanoHorizontal && y+1 < tamanoVertical)
				if (tableroJugador[x+1][y+1] != DESTAPADO)
					destaparPosicionDeterminada(x+1,y+1);
		}
}

void destaparPosicion()
{
	int destapar_x, destapar_y;
	cout << "Introduzca la posicion horizontal" << endl;
	cin >> destapar_x;
	fflush(stdin);
	cout << "Introduzca la posicion vertical" << endl;
	cin >> destapar_y;
	fflush(stdin);
	if (!juegoIniciado)
	{
		juegoIniciado = true;
		inicioJuego = clock();
	}
	if(tableroInterno[destapar_x-1][destapar_y-1] == MINA)
	{
		juegoTerminado = true;
		cout << "Juego terminado, ha perdido" << endl;
	}
	else
	{
		destaparPosicionDeterminada(destapar_x-1, destapar_y-1);
		mostrarTableroJugador();
	}
}

void mostrarMejoresPuntajes()
{
	cout << " Primer jugador: ";
	if (mejorTiempoPrincipiante > 0)
		cout << mejorTiempoPrincipiante << ", por" << nombreMejorTiempoPrincipiante << endl;
	else
		cout << " No Definido" << endl;
	cout << "Segundo jugador: ";
	if (mejorTiempoIntermedio > 0)
		cout << mejorTiempoIntermedio << ", por" << nombreMejorTiempoIntermedio << endl;
	else
		cout << " No Definido" << endl;
	cout << "Tercer jugador: ";
	if (mejorTiempoAvanzado > 0)
		cout << mejorTiempoAvanzado << ", por" << nombreMejorTiempoAvanzado << endl;
	else
		cout << " No Definido" << endl;
}

void obtenerNuevoSeparador()
{
	string nuevoSeparador;
	cout << "Introduzca el nuevo separador" << endl;
	getline (cin,nuevoSeparador);
	fflush(stdin);
	separador = nuevoSeparador[0];
}

int main() {
	string entrada;
	nivel = JUEGO_FACIL;
	iniciarJuego(nivel);
	mostrarTableroJugador();
	do
	{
		if(juegoTerminado)
		{
			cout << "Introduzca B para el primer jugador "<< endl;
			cout << "Introduzca I para el segundo jugador" << endl;
			cout << "Introduzca A para para el tercer jugador "<< endl;
			cout << "O para mostrar los mejores puntajes," << endl;
			cout << "C para cambiar el separador del tablero, " << endl;
			cout << "S para salir" << endl;
		}
		else
		{
			cout << "Introduzca M para marcar una posicion como mina, "<<endl;
			cout << "P para marcar una posicion como posible mina," << endl;
			cout << "L para limpiar una marca de posible mina, "<< endl;
			cout << "D para descubrir una posicion," << endl;
			cout << "Introduzca B para el primer jugador "<< endl;
			cout << "Introduzca I para el segundo jugador" << endl;
			cout << "Introduzca A para para el tercer jugador "<< endl;
			cout << "O para mostrar los mejores puntajes," << endl;
			cout << "C para cambiar el separador del tablero, " << endl;
			cout << "S para salir" << endl;
		}

		getline (cin,entrada);
		fflush(stdin);

		switch(entrada[0])
		{
		case 'M':
		case 'm':
			if(!juegoTerminado)
				marcarMina();
			else
				cout << "Inicie un nuevo juego" << endl;
			break;

		case 'P':
		case 'p':
			if(!juegoTerminado)
			{
				marcarPosibleMina();
				mostrarTableroJugador();
			}
			else
				cout << "Inicie un nuevo juego" << endl;
			break;

		case 'L':
		case 'l':
			if(!juegoTerminado)
			{
				limpiarPosicion();
				mostrarTableroJugador();
			}
			else
				cout << "Inicie un nuevo juego" << endl;
			break;

		case 'D':
		case 'd':
			if(!juegoTerminado)
				destaparPosicion();
			else
				cout << "Inicie un nuevo juego" << endl;

			break;

		case 'B':
		case 'b':
			nivel = JUEGO_FACIL;
			iniciarJuego(JUEGO_FACIL);
			mostrarTableroJugador();
			break;

		case 'I':
		case 'i':
			nivel = JUEGO_INTERMEDIO;
			iniciarJuego(JUEGO_INTERMEDIO);
			mostrarTableroJugador();
			break;

		case 'A':
		case 'a':
			nivel = JUEGO_AVANZADO;
			iniciarJuego(JUEGO_AVANZADO);
			mostrarTableroJugador();
			break;

		case 'O':
		case 'o':
			mostrarMejoresPuntajes();
			if(!juegoTerminado)
				mostrarTableroJugador();
			break;

		case 'C':
		case 'c':
			obtenerNuevoSeparador();
			if(!juegoTerminado)
				mostrarTableroJugador();
			break;

		case 'S':
		case 's':
			cout << "Gracias por jugar, hasta pronto" << endl;
			return 0;
			break;

		default:
			cout << "Ingrese una opción válida" << endl;
			if(!juegoTerminado)
				mostrarTableroJugador();
			break;
		}

	} while (entrada[0] != 'S' || entrada[0] != 's');
	return 0;
}
