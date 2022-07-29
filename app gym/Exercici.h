#ifndef EXERCICI_H
#define EXERCICI_H

#include <string>
using namespace std;

class Exercici
{
public:
	Exercici();
	Exercici(string nom_exercici, int series, int repeticions, int pes);

	void mostrar_exercici() const;
	string nom() const;

	bool operator<(const Exercici& exercici);

private:
	string _nom_exercici;
	int _series;
	int _repeticions;
	int _pes;
};

#endif //EXERCICI_h
