#ifndef JUGADOR_H
#define JUGADOR_H

#include "Civilizacion.h"
#include<string>
using namespace std;
class Jugador{
private:
	string nombre;
	Civilizacion* civ;
public:
	Jugador(string , Civilizacion*);
	string getNombre();
	Civilizacion* getCivilizacion();
	void setNombre(string);

};

#endif