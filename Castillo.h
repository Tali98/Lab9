#ifndef CASTILLO_H
#define CASTILLO_H

#include "Edificios.h"
#include<string>
using namespace std;

class Castillo:public Edificios{
private:
	int madera;
	int oro;
	int piedra;
public:
	Castillo(int,int,int);
	virtual double getCosto_Oro();
	virtual double getCosto_Piedra();
	virtual double getCosto_Madera();
	virtual void toString();
};
#endif