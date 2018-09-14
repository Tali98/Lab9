#include "Special.h"
#include<iostream>
using namespace std;


Special::Special(string pSexo , double pCosto_A , double pCosto_O , double pAttack , double pDefensa , double pVida , double pVelocidad , int pTiempo){
	sexo = pSexo;
	costo_a = pCosto_A;
	costo_o = pCosto_O;
	attack = pAttack;
	defensa = pDefensa;
	vida = pVida;
	velocidad = pVelocidad;
	tiempo = pTiempo;
}

string Special::getSexo(){
	return sexo;
}

double Special::getCosto_Alimentacion(){
	return costo_a;
}

double Special::getCosto_Oro(){
	return costo_o;
}

double Special::getAttack(){
	attack = attack*(1 + velocidad/5)+50*.15;
	return attack;
}

double Special::getDefensa(){
	return defensa;
}

double Special::getVida(){
	return vida;
}

double Special::getVelocidad(){
	return velocidad;
}

int Special::getTiempo(){
	return tiempo;
}

void Special::setVida(double pVida){
	vida = pVida;
}

void Special::toString(){
	cout<<"Special \n";
}