#include "Registre.h"
#include <iostream>

using namespace std;

Registre::Registre() {

	if (not _usuaris_exercicis.empty()) _usuaris_exercicis.clear();
	if (not _usuaris.empty()) _usuaris.clear();
}

bool Registre::usuari_registrat(string usuari) {

	bool registrat = false;
	Usuari buscar(usuari, -1);
	for (Usuari u : _usuaris) {
		if (u == buscar) registrat = true;
		else registrat = false;
	}
	/*list<Usuari>::const_iterator it;

	it = find(_usuaris.begin(), _usuaris.end(), usuari);
	if (it != _usuaris.end()) registrat = true;
	*/
	return registrat;
}

void Registre::registrar_usuari(Usuari usuari) {

	_usuaris.push_back(usuari);
	cout << endl << endl << endl << "\t >> L'usuari ha quedat registrat: ";  usuari.mostrar_usuari(); cout << endl;
}

void Registre::afegir_exercicis_al_usuari(Usuari usuari, string data, Exercici exercici) {

	list<Usuari>::iterator it = find(_usuaris.begin(), _usuaris.end(), usuari);
	if(it != _usuaris.end()){
		multimap<string, Exercici> mapa_data;
		mapa_data.insert(make_pair(data, exercici));
		_usuaris_exercicis.insert(make_pair(usuari, mapa_data));
		cout << endl << "\t >> Afegit " << exercici.nom() << " per a la data " << data << " a " << usuari.nom() << endl;
	}
}

void Registre::donar_baixa_usuari() {

	string nom;
	cout << "\t >> Introdueix el nom de l'usuari a donar de baixa: " << endl;
	cin >> nom;

	Usuari copia(nom, -1);
	bool existent = false;
	for (Usuari u : _usuaris) {
		if (u == copia) {
			existent = true;
			copia = u;
		}
	}
	_usuaris.remove(copia);
	if (existent) cout << "\t >> S'ha eliminat l'usuari " << copia.nom() << " del registre!" << endl;
}

void Registre::borrar_servidor() {

	if (not _usuaris_exercicis.empty() or not _usuaris.empty()) {
		_usuaris_exercicis.clear();
		_usuaris.clear();
		cout << "\t >> S'han borrat totes les dades!" << endl;
	}
	else cout << "\t >> No hi ha cap dada al servidor!" << endl;
}

void Registre::borrar_per_data() {

	string data;
	cout << "\t >> Entra una data (DD/MM/AAAA): " << endl;
	cin >> data;

	multimap<Usuari, multimap<string, Exercici>>::const_iterator it = _usuaris_exercicis.begin();
	Usuari guardal;
	for (it; it != _usuaris_exercicis.end(); it++) {
		multimap<string, Exercici>::const_iterator it2 = it->second.begin();
		for (it2; it2 != it->second.end(); it2++) {
			if (it2->first == data) guardal = it->first;
		}
	}

	multimap<Usuari, multimap<string, Exercici>>::const_iterator it3 = _usuaris_exercicis.find(guardal);
	if (it != _usuaris_exercicis.end()) {
		_usuaris_exercicis.erase(guardal);
		cout << "\t >> Esborrada informacio de la data " << data << "!" << endl;
	}
	else cout << "\t >> No s'ha trobat informacio del " << data << "!" << endl;
}

void Registre::mostrar_usuaris_sistema() const {

	cout << endl << "\t*************************************" << endl;
	cout << "\t*    ---<USUARIS DEL SISTEMA>---    *" << endl;
	cout << "\t*************************************" << endl << endl;

	if (not _usuaris.empty()) {
		for (auto u : _usuaris) {
			u.mostrar_usuari();
		}
	}
	else cout << "\t >> No hi han dades a mostrar!" << endl;
	cout << "\t*************************************" << endl << endl;
}

void Registre::mostrar_registre_usuari() const { // no va

	string nom;
	cout << "\t >> Entra el nom de l'usuari" << endl;
	cin >> nom;

	Usuari buscar = Usuari(nom, -1);
	multimap<Usuari, multimap<string, Exercici>>::const_iterator it = _usuaris_exercicis.find(buscar);

	if (it != _usuaris_exercicis.end()) {
		multimap<string, Exercici>::const_iterator it2;
		for (it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			cout << it2->first << ": ";
			it2->second.mostrar_exercici();
		}
	}
	else cout << "\t >> Usuari no existent! " << endl;
}

void Registre::mostrar_totes_dades() const {

	cout << endl << "\t**************************" << endl;
	cout << "\t*    ---<REGISTRE>---    *" << endl;
	cout << "\t**************************" << endl << endl;
	
	multimap<Usuari, multimap<string, Exercici>>::const_iterator it;

	if (not _usuaris_exercicis.empty()) {
		for (it = _usuaris_exercicis.begin(); it != _usuaris_exercicis.end(); it++) {
			it->first.mostrar_usuari();
			multimap<string, Exercici>::const_iterator it2;
			for (it2 = it->second.begin(); it2 != it->second.end(); it2++) {
				cout << "\t" << it2->first << " ";
				it2->second.mostrar_exercici();
			}
		}
	}
	else cout << "\t >> No hi han dades a mostrar!" << endl;
	cout << endl << "\t**************************" << endl << endl;
}

void Registre::mostrar_dades_per_data() const { // funciona
	
	string data;
	cout << "Entra una data (DD/MM/AAAA): " << endl;
	cin >> data;

	bool trobat = false;
	multimap<Usuari, multimap<string, Exercici>>::const_iterator it = _usuaris_exercicis.begin();

	for (it; it != _usuaris_exercicis.end(); it++) {
		multimap<string, Exercici>::const_iterator it2 = it->second.find(data);
		if (it2 != it->second.end()) {
			cout << "\t >> Dia: " << data << ", usuari " << it->first.nom() << ": "; it2->second.mostrar_exercici();
		}
	}
}