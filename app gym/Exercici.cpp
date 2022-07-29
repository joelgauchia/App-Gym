#include "Exercici.h"
#include <iostream>

using namespace std;

Exercici::Exercici() {
	_nom_exercici = " ";
	_series = -1;
	_repeticions = -1;
}

Exercici::Exercici(string nom_exercici, int series, int repeticions, int pes){
	_nom_exercici = nom_exercici;
	_series = series;
	_repeticions = repeticions;
	_pes = pes;
}

void Exercici::mostrar_exercici() const {
	cout << _nom_exercici << ": " << _series << " x " << _repeticions << " amb " << _pes << "kg" << endl;
}

string Exercici::nom() const {
	return _nom_exercici;
}

bool Exercici::operator<(const Exercici& exercici) {
	return _nom_exercici < exercici._nom_exercici;
}
