#ifndef TROPAS_H
#define TROPAS_H

#include<string>
using namespace std;

class Tropas{
private:
public:
	virtual string getSexo()=0;
	virtual double getCosto_Alimentacion()=0;
	virtual double getCosto_Oro()=0;
	virtual double getAttack()=0;
	virtual double getDefensa()=0;
	virtual double getVida()=0;
	virtual double getVelocidad()=0;
	virtual int getTiempo()=0;
	virtual void setVida(double)=0;
	virtual void toString()=0;
};
#endif