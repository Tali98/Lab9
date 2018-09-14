#ifndef CASA_H
#define CASA_H

#include "Edificios.h"
#include<string>
using namespace std;

class Casa:public Edificios{
private:
	int madera;
	int oro;
	int piedra;
public:
	Casa(int,int,int);
	virtual double getCosto_Oro();
	virtual double getCosto_Piedra();
	virtual double getCosto_Madera();
	virtual void toString();
};
#endif