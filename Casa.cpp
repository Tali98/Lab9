#include "Casa.h"
#include<iostream>
using namespace std;


Casa::Casa(int pMadera, int pOro , int pPiedra){
	madera = pMadera;
	oro = pOro;
	piedra = pPiedra;
}

double Casa::getCosto_Oro(){
	return oro;
}

double Casa::getCosto_Madera(){
	return madera;
}

double Casa::getCosto_Piedra(){
	return piedra;
}

void Casa::toString(){
	cout<<" Casa \n";
}