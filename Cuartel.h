#ifndef CUARTEL_H
#define CUARTEL_H

#include "Edificios.h"
#include<string>
using namespace std;

class Cuartel:public Edificios{
private:
	int madera;
	int oro;
	int piedra;
public:
	Cuartel(int,int,int);
	virtual double getCosto_Oro();
	virtual double getCosto_Piedra();
	virtual double getCosto_Madera();
	virtual void toString();
};
#endif