#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <map>
#include <set>
#include "string.h"
#include "Usuari.h"
#include "Exercici.h"
#include "Registre.h"

using namespace std;

void mostra_titol() {

	cout << "--------------------------------------------------------------------------" << endl;
	cout << ".d88b                      db" << endl;
	cout << "8P www Yb  dP 8d8b.d8b.   dPYb   88b. 88b." << endl;
	cout << "8b  d8  YbdP  8P Y8P Y8  dPwwYb  8  8 8  8" << endl;
	cout << "`Y88P'   dP   8   8   8 dP    Yb 88P' 88P'" << endl;
	cout << "        dP                       8    8                   By: Joel Gauchia" << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl << endl;
}

void barra_loading(string& nom)
{

	// Initialize char for printing
	// loading bar
	char a = 177, b = 219;

	cout << endl << endl << "\t\t\t\t\tBuscant l'usuari " << nom << "..." << endl << endl;
	cout << "\t\t\t\t\t";

	// Print initial loading bar
	for (int i = 0; i < 26; i++)
		printf("%c", a);

	// Set the cursor again starting
	// point of loading bar
	printf("\r");
	printf("\t\t\t\t\t");

	// Print loading bar progress
	for (int i = 0; i < 26; i++) {
		printf("%c", b);

		// Sleep for 1 second
		Sleep(100);
	}
}

void entrar_dades(string& data, Exercici& exercici, Registre& registre, Usuari& usuari) {

	string nom;
	cout << "\t >> Identifica't: " << endl;
	cin >> nom;

	barra_loading(nom);

	bool registrat = registre.usuari_registrat(nom);
	while (not registrat) {

		cout << endl << endl << "\t >> No s'ha trobat l'usuari..." << endl;
		cout << "\t >> Vols enregistrar-lo? (S/N)" << endl;
		char opcio;
		cin >> opcio;

		if (opcio == 'S') {
			cout << "\t >> Quin nom vols que figuri al registre?" << endl;
			string nom;
			cin >> nom;
			cout << "\t >> Quants anys tens?" << endl;
			int edat;
			cin >> edat;
			usuari = Usuari(nom, edat);
			system("cls");
			mostra_titol();
			registre.registrar_usuari(usuari);
			registrat = registre.usuari_registrat(nom);
		}
		cout << "\t >> Identifica't: " << endl;
		cin >> nom;
		barra_loading(nom);
	}

	cout << endl << endl << "\t >> S'ha trobat l'usuari " << nom << "!" << endl;
	cout << endl << "\t >> Entra una data (DD/MM/AAAA):" << endl;
	cin >> data;

	cout << "\t >> Entra un nou exercici per la data " << data << " (* PER ACABAR): " << endl;
	string nom_exercici;
	cin >> nom_exercici;

	while (nom_exercici != "*") {

		cout << "\t >> Entra les series per " << nom_exercici << " (numero):" << endl;
		int series;
		cin >> series;

		while (series <= 0 or series > 99) {
			cout << "\t >> Entra un numero bro!" << endl;
			cin >> series;
		}

		cout << "\t >> Entra les repeticions per " << nom_exercici << ", " << series << " x (numero):" << endl;
		int repeticions;
		cin >> repeticions;

		while (repeticions <= 0 or repeticions > 99) {
			cout << "\t >> Entra un numero bro!" << endl;
			cin >> series;
		}

		cout << "\t >> Entra el pes: " << endl;
		int pes;
		cin >> pes;

		while (pes <= 0 or pes > 999) {
			cout << "\t >> Entra un numero bro!" << endl;
			cin >> pes;
		}

		exercici = Exercici(nom_exercici, series, repeticions, pes);

		registre.afegir_exercicis_al_usuari(usuari, data, exercici);

		cout << endl << "\t >> Entra un nou exercici per la data " << data << " (nom): " << endl;
		cin >> nom_exercici;
	}

	registre.mostrar_totes_dades();
}

void menu() {
	cout << endl << "\tMenu d'opcions _________________________________" << endl;
	cout << "\t************************************************" << endl;
	cout << "\t*  (1) Entrar mes dades                        *" << endl;
	cout << "\t*  (2) Mostrar usuaris del sistema             *" << endl;
	cout << "\t*  (3) Mostrar exercicis d'un usuari           *" << endl;
	cout << "\t*  (4) Mostrar tota la informacio del sistema  *" << endl;
	cout << "\t*  (5) Donar de baixa un usuari                *" << endl;
	cout << "\t*  (6) Mostrar dades per data                  *" << endl;
	cout << "\t*  (7) Borrar informacio d'una data            *" << endl;
	cout << "\t*  (8) Borrar informacio del servidor          *" << endl;
	cout << "\t*  (10) Sortir                                 *" << endl;
	cout << "\t************************************************" << endl << endl;
}

void consultar_opcio(int& opcio, string& data, Exercici& exercici, Registre& registre, Usuari& usuari){

	do {
		cout << "Entra una opcio:" << endl;
		cin >> opcio;

		switch (opcio) {
		case 1:
			entrar_dades(data, exercici, registre, usuari);
			break;
		case 2:
			registre.mostrar_usuaris_sistema();
			break;
		case 3:
			registre.mostrar_registre_usuari();
			break;
		case 4:	
			registre.mostrar_totes_dades();
			break;
		case 5:
			registre.donar_baixa_usuari();
			break;
		case 6:
			registre.mostrar_dades_per_data();
			break;
		case 7:
			registre.borrar_per_data();
			break;
		case 8:
			system("cls");
			mostra_titol();
			registre.borrar_servidor();
			break;
		}
		menu();

	} while (opcio != 10);

	cout << endl << "\t >> Fins aviat!" << endl;
}

int main() {

	// 1 - Fons blau
	// 7 - Text blanc
	system("color 17");
	SetConsoleTitleA("GymApp");

	mostra_titol();

	int opcio = 0;
	string data;
	Usuari usuari;
	Exercici exercici;
	Registre registre;
	entrar_dades(data, exercici, registre, usuari);
	menu();
	consultar_opcio(opcio, data, exercici, registre, usuari);
}
