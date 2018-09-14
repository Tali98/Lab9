#include "Castillo.h"
#include<iostream>
using namespace std;


Castillo::Castillo(int pMadera, int pOro , int pPiedra){
	madera = pMadera;
	oro = pOro;
	piedra = pPiedra;
}

double Castillo::getCosto_Oro(){
	return oro;
}

double Castillo::getCosto_Madera(){
	return madera;
}

double Castillo::getCosto_Piedra(){
	return piedra;
}

void Castillo::toString(){
	cout<<" Casa \n";
}