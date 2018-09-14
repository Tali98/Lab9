#include "Cuartel.h"
#include<iostream>
using namespace std;


Cuartel::Cuartel(int pMadera, int pOro , int pPiedra){
	madera = pMadera;
	oro = pOro;
	piedra = pPiedra;
}

double Cuartel::getCosto_Oro(){
	return oro;
}

double Cuartel::getCosto_Madera(){
	return madera;
}

double Cuartel::getCosto_Piedra(){
	return piedra;
}

void Cuartel::toString(){
	cout<<" Casa \n";
}