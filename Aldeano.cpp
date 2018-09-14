#include "Aldeano.h"

Aldeano::Aldeano(string pSexo , double pCosto_A){
	sexo = pSexo;
	costo_a = pCosto_A;
}

string Aldeano::getSexo(){
	return sexo;
}

double Aldeano::getCosto_Alimentacion(){
	return costo_a;
}