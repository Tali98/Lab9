#include "Caballero.h"
#include<iostream>
using namespace std;

Caballero::Caballero(string pSexo , double pCosto_A , double pCosto_O , double pAttack , double pDefensa , double pVida , double pVelocidad , int pTiempo){
	sexo = pSexo;
	costo_a = pCosto_A;
	costo_o = pCosto_O;
	attack = pAttack;
	defensa = pDefensa;
	vida = pVida;
	velocidad = pVelocidad;
	tiempo = pTiempo;
}

string Caballero::getSexo(){
	return sexo;
}

double Caballero::getCosto_Alimentacion(){
	return costo_a;
}

double Caballero::getCosto_Oro(){
	return costo_o;
}

double Caballero::getAttack(){
	attack = (attack + velocidad)/2;
	return attack;
}

double Caballero::getDefensa(){
	return defensa;
}

double Caballero::getVida(){
	return vida;
}

double Caballero::getVelocidad(){
	return velocidad;
}

int Caballero::getTiempo(){
	return tiempo;
}

void Caballero::setVida(double pVida){
	vida = pVida;
}

void Caballero::toString(){
	cout<<"Caballero \n";
}