#include "Usuari.h"
#include <iostream>

using namespace std;

Usuari::Usuari() {

	_nom = " ";
	_edat = -1;
}

Usuari::Usuari(string nom, int edat) {

	_nom = nom;
	_edat = edat;
}

void Usuari::mostrar_usuari() const {

	cout << "\t >> " << _nom << ", " << _edat << " anys" << endl;
}

string Usuari::nom() const {
	return this->_nom;
}

bool Usuari::operator<(const Usuari& usuari) const {

	return (this->_nom < usuari._nom);
}

bool Usuari::operator==(const Usuari& usuari) const {

	return (this->_nom == usuari._nom);
}