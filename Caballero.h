#ifndef CABALLERO_H
#define CABALLERO_H

#include "Tropas.h"
#include<string>
using namespace std;


class Caballero:public Tropas{
private:
	string sexo;
	double costo_a;
	double costo_o;
	double attack;
	double defensa;
	double vida;
	double velocidad;
	int tiempo;
public:
	Caballero(string,double,double,double,double,double,double,int);//sexo , costo , costo , attack ,defense , vida, velocidad , tiempo
	virtual string getSexo();
	virtual double getCosto_Alimentacion();
	virtual double getCosto_Oro();
	virtual double getAttack();
	virtual double getDefensa();
	virtual double getVida();
	virtual double getVelocidad();
	virtual int getTiempo();
	virtual void setVida(double);
	virtual void toString();
};

#endif

