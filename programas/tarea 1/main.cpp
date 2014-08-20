#include <iostream>
using namespace std;

int main(){
	cout << endl <<" Ingrese el año [debe ser mayor que 0] ";
	int ano;
	cin >> ano;

	if(ano < 0){
		cout << endl <<"dato correcto\n"<<"evalue el año: [" << ano << "] .";
		return 1;
	}

	cout << endl << "el mes[1 - 12]: ";
	int mes;
	cin >> mes;

	if(mes < 1 || mes > 12){
		cout << endl <<"INCORRECT DATE\n"<<"The month value [" << mes << "]debe ser mayor que cero: [1 - 12]";
		return 1;
	}

	bool bisiesto = (ano % 4 == 0);

	int dia;

	if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
		dia = 31;
	else if(mes == 2)
		if(bisiesto)
			dia = 29;
		else
			dia = 28;
	else if( mes == 4 || mes == 6 || mes == 9 || mes == 11)
		dia = 30;

	cout<< endl << "dia del mes [1 - " << mes<< "]: ";

	cin >> dia;



	if(dia < 1 || dia > dia){
		cout << endl <<"dato incorrecto\n"<<"evalue el dia [" << dia << "] debe estar entre el rango: [1 - "<< dia<<"]";
		return 1;
	}


	cout << endl <<"el dia: [Dia: " <<dia << " - mes: "<<mes <<" - año: "<<ano <<"] es correcto";

	return 0;
}
