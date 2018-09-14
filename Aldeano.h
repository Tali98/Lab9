#ifndef ALDEANO_H
#define ALDEANO_H

#include "Tropas.h"
#include<string>
using namespace std;

class Aldeano:public Tropas{
private:
	string sexo;
	double costo_a;
public:
	Aldeano(string,double);
	virtual string getSexo();
	virtual double getCosto_Alimentacion();
};
#endif