#include "Jugador.h"

Jugador::Jugador(string pNombre , Civilizacion* pCivilizacion){
	nombre = pNombre;
	civ = pCivilizacion;
}

string Jugador::getNombre(){
	return nombre;
}

void Jugador::setNombre(string pNombre){
	nombre = pNombre;
}

Civilizacion* Jugador::getCivilizacion(){
	return civ;
}