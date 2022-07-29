#ifndef REGISTRE_H
#define REGISTRE_H

#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <string>
#include "Exercici.h"
#include "Usuari.h"
using namespace std;

class Registre
{
public:
	Registre();

	// MODIFICADORS
	bool usuari_registrat(string usuari);
	void registrar_usuari(Usuari usuari);
	void afegir_exercicis_al_usuari(Usuari usuari, string data, Exercici exercici);
	void donar_baixa_usuari();
	void borrar_per_data();
	void borrar_servidor();

	// CONSULTORS
	void mostrar_usuaris_sistema() const;
	void mostrar_registre_usuari() const;
	void mostrar_totes_dades() const;
	void mostrar_dades_per_data() const;

private:
	multimap<Usuari, multimap<string, Exercici>> _usuaris_exercicis;
	list<Usuari> _usuaris;
};

#endif //EXERCICI_h


