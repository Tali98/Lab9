#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include "Tropas.h"
#include "Edificios.h"
#include "Casa.h"
#include "Aldeano.h"

#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Civilizacion{
private:
	string name;
	int oro;
	int piedra;
	int alimento;
	int madera;
	int poblacion_maxima;
	int poblacion_actual;
	int capacidad;
	vector<Tropas*>troops;
	vector<Casa*>buildings;
	int aldeanos;
	bool cuartel;
	bool castillo;
public:
	Civilizacion(string,int,int,int,int,int,int,int,bool,bool);//oro, piedra , alimento , madera , pm . pa . c .
	int getOro();
	int getMadera();
	int getPiedra();
	int getAlimento();
	int getPoblacion_Maxima();
	int getPoblacion_Actual();
	int getCapacidad();
	Tropas* getTropa(int);
	Edificios* getEdificio(int);
	void setOro(int);
	void setPiedra(int);
	void setAlimento(int);
	void setMadera(int);
	void setPoblacion_Actual(int);
	void setPoblacion_Maxima(int);
	void setCapacidad(int);
	void addTropa(Tropas*);
	void addCasa(Casa*);

	//booleanos para saber si construir tropas o no 
	bool getCuartel();
	bool getCastillo();
	void setCuartel(bool);
	void setCastillo(bool);

	string getName();
	void setName(string);

	void setAldeano(int);
	int getAldeano();

	void getSizeTropas();
	void getSizeCasas();
	int getSize();
	vector<Tropas*> getTroops();
};
#endif