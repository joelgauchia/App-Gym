#ifndef USUARI_H
#define USUARI_H

#include <string>
using namespace std;

class Usuari
{
public:
	Usuari();
	Usuari(string nom, int edat);

	void mostrar_usuari() const;
	string nom() const;
	bool operator<(const Usuari& usuari) const;
	bool operator==(const Usuari& usuari) const;

private:
	string _nom;
	int _edat;
};

#endif // USUARI_H