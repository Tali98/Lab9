#ifndef EDIFICIOS_H
#define EDIFICIOS_H

#include<string>
using namespace std;

class Edificios{
private:
public:
	virtual double getCosto_Oro()=0;
	virtual double getCosto_Piedra()=0;
	virtual double getCosto_Madera()=0;
	virtual void toString()=0;
};
#endif