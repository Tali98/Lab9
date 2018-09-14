#include "Soldado.h"
#include<iostream>
using namespace std;


Soldado::Soldado(string pSexo , double pCosto_A , double pCosto_O , double pAttack , double pDefensa , double pVida , double pVelocidad , int pTiempo){
	sexo = pSexo;
	costo_a = pCosto_A;
	costo_o = pCosto_O;
	attack = pAttack;
	defensa = pDefensa;
	vida = pVida;
	velocidad = pVelocidad;
	tiempo = pTiempo;
}

string Soldado::getSexo(){
	return sexo;
}

double Soldado::getCosto_Alimentacion(){
	return costo_a;
}

double Soldado::getCosto_Oro(){
	return costo_o;
}

double Soldado::getAttack(){
	return attack;
}

double Soldado::getDefensa(){
	return defensa;
}

double Soldado::getVida(){
	return vida;
}

double Soldado::getVelocidad(){
	return velocidad;
}

int Soldado::getTiempo(){
	return tiempo;
}

void Soldado::setVida(double pVida){
	vida = pVida;
}

void Soldado::toString(){
	cout<<"Soldado \n";
}