#include "Civilizacion.h"

Civilizacion::Civilizacion(string pName,int pOro , int pPiedra , int pAlimento , int pMadera , int pPoblacion_Maxima , int pPoblacion_Actual , int pCapacidad, bool pCuartel , bool pCastillo){
	name = pName;
	oro = pOro;
	piedra = pPiedra;
	alimento = pAlimento;
	madera = pMadera;
	poblacion_maxima = pPoblacion_Maxima;
	poblacion_actual = pPoblacion_Actual;
	capacidad = pCapacidad;
	cuartel = pCuartel;
	castillo = pCastillo;
}

void Civilizacion::getSizeTropas(){
	troops.clear();
}

void Civilizacion::getSizeCasas(){
	buildings.clear();		
}

void Civilizacion::setAldeano(int pAldeano){
	aldeanos = pAldeano;
}

int Civilizacion::getAldeano(){
	return aldeanos;
}

string Civilizacion::getName(){
	return name;
}

void Civilizacion::setName(string pName){
	name = pName;
}

int Civilizacion::getOro(){
	return oro;
}

int Civilizacion::getPiedra(){
	return piedra;
}

int Civilizacion::getAlimento(){
	return alimento;
}

int Civilizacion::getMadera(){
	return madera;
}

int Civilizacion::getPoblacion_Maxima(){
	return poblacion_maxima;
}

int Civilizacion::getPoblacion_Actual(){
	return poblacion_actual;
}

int Civilizacion::getCapacidad(){
	return capacidad;
}

Tropas* Civilizacion::getTropa(int a){
	return troops[a];
}

Edificios* Civilizacion::getEdificio(int a){
	return buildings[a];
}

void Civilizacion::setOro(int pOro){
	oro=pOro;
}

void Civilizacion::setPiedra(int pPiedra){
	piedra=pPiedra;
}

void Civilizacion::setAlimento(int pAlimento){
	alimento=pAlimento;
}

void Civilizacion::setMadera(int pMadera){
	madera=pMadera;
}

void Civilizacion::setPoblacion_Maxima(int pPoblacion_Maxima){
	poblacion_maxima=pPoblacion_Maxima;
}

void Civilizacion::setPoblacion_Actual(int pPoblacion_Actual){
	poblacion_actual = pPoblacion_Actual;
}

void Civilizacion::setCapacidad(int pCapacidad){
	capacidad=pCapacidad;
}

void Civilizacion::addTropa(Tropas* pTropa){
	troops.push_back(pTropa);
}

void Civilizacion::addCasa(Casa* pCasa){
	buildings.push_back(pCasa);
}

bool Civilizacion::getCuartel(){
	return cuartel;
}

bool Civilizacion::getCastillo(){
	return castillo;
}

void Civilizacion::setCuartel(bool pCuartel){
	cuartel = pCuartel;
}

void Civilizacion::setCastillo(bool pCastillo){
	castillo = pCastillo;
}

int Civilizacion::getSize(){
	return troops.size();
}

vector<Tropas*> Civilizacion::getTroops(){
	return troops;
}
