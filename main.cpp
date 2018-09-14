#include "Civilizacion.h"
#include "Edificios.h"
#include "Tropas.h"
#include "Jugador.h"
#include "Caballero.h"
#include "Special.h"
#include "Soldado.h"

#include<iostream>
#include<string>
#include<vector>
#include<time.h>
using namespace std;

vector<Civilizacion*> Civilizaciones;
vector<Jugador*> Jugadores;

//crear civs
void createCivs();
void createJugador();
void Ingresar();
void newBuilding(int);
void newTroop(int);
void die_populace(int);
void Batalla(int);
void printPlayer(int);

int main(){
	cout<<"MENU:: \n";
	cout<<"1.Crear Civilizacion \n";
	cout<<"2.Crear Jugador \n";
	cout<<"3.Ingresar \n";
	cout<<"Ingrese su opcion deseada: \n";
	int menu;
	cin>>menu;
	while(menu>0 && menu<4){
		switch(menu){
			case 1:{
				createCivs();
				break;
			}//fin case 1
			case 2:{
				if(Civilizaciones.size() == 0){
					cout<<"No puede ingresar aqui todavia , ocupa tener Civs creadas \n";
				}
				else{
					createJugador();
				}
				break;
			}//fin case 2 
			case 3:{
				if(Jugadores.size()==0){
					cout<<"No puede ingresar aqui todavia \n";
				}else{
					Ingresar();
				}
				break;
			}//fin case 3
		}//fin switch
		cout<<"_____________ \n";
		cout<<"_____________ \n";
		cout<<"MENU:: \n";
		cout<<"1.Crear Civilizacion \n";
		cout<<"2.Crear Jugador \n";
		cout<<"3.Ingresar \n";
		cout<<"Ingrese su opcion deseada: \n";
		cin>>menu;
	}//fin while menu
	Jugadores.clear();
	Civilizaciones.clear();

}

void createCivs(){
	cout<<"Ingrese el nombre de su Civ: ";
	string nombre;
	cin>>nombre;
	cout<<"Su poblacion maxima cera de 200(como en age of empires 3 que es el juego superior) \n";
	Civilizacion* nueva = new Civilizacion(nombre,0,0,100,0,200,0,5,false,false);
	Civilizaciones.push_back(nueva);
	cout<<"EXITO en su creacion \n";
}

void createJugador(){
	cout<<"Ingrese su nombre: ";
	string nombre;
	cin>>nombre;
	for(int i = 0 ; i < Civilizaciones.size() ; i++){
		cout<<i<<" "<<Civilizaciones[i]->getName()<<endl;
	}
	cout<<"Introduzca el numero de la civ que quiere ser \n";
	int decision;
	cin>>decision;
	Jugador* nuevo = new Jugador(nombre,Civilizaciones[decision]);
	Jugadores.push_back(nuevo);
	cout<<"EXITOOO \n";
}

void Ingresar(){
	for(int i = 0 ; i < Jugadores.size() ; i++){
		cout<<i<<" "<<Jugadores[i]->getNombre()<<endl;
	}
	cout<<"Ingrese que jugador desea usar: ";
	int selecion;
	cin>>selecion;
	Jugadores[selecion];
	cout<<"MENU NUMERO 2: \n";
	cout<<"1.Nuevo Aldeano \n";
	cout<<"2.Buscar Recursos \n";
	cout<<"3.Nuevo Edifico \n";
	cout<<"4.Nueva Tropa \n";
	cout<<"5.Desterrar Poblacion \n";
	cout<<"6.Batalla \n";
	cout<<"7.Finalizar Turno \n";
	cout<<"8.Regresar al menu inciial \n";
	cout<<"Ingrese que desea hacer \n";
	int decision;
	cin>>decision;
	while(decision > 0 && decision < 8){
		switch(decision){

			case 1:{
				if(Jugadores[selecion]->getCivilizacion()->getAlimento() > 55  &&	Jugadores[selecion]->getCivilizacion()->getPoblacion_Actual() < Jugadores[selecion]->getCivilizacion()->getCapacidad()){
					cout<<"Ingrese sexo del aldeano: \n";
					string sexo;
					cin>>sexo;
					int food = Jugadores[selecion]->getCivilizacion()->getAlimento() - 55;
					Jugadores[selecion]->getCivilizacion()->setAlimento(food);
					int aldeanos = Jugadores[selecion]->getCivilizacion()->getAldeano();
					int actual = Jugadores[selecion]->getCivilizacion()->getPoblacion_Actual();
					Jugadores[selecion]->getCivilizacion()->setPoblacion_Actual(actual+1);
					Jugadores[selecion]->getCivilizacion()->setAldeano(aldeanos+1);
					cout<<"EXITO EN CREACION \n";
				}else{
					cout<<"NOT ENOUGH FOOD BUILD MORE PYLONS \n";
				}
				break;
			}//case 1
			case 2:{
				int aldeanos = Jugadores[selecion]->getCivilizacion()->getAldeano();
				int food = aldeanos * 50;
				int madera = aldeanos * 40;
				int oro = aldeanos * 30;
				int piedra = aldeanos * 20;
				oro =oro+Jugadores[selecion]->getCivilizacion()->getOro();
				madera =madera+Jugadores[selecion]->getCivilizacion()->getMadera();
				piedra =piedra+Jugadores[selecion]->getCivilizacion()->getPiedra();
				food =food+Jugadores[selecion]->getCivilizacion()->getAlimento();
				Jugadores[selecion]->getCivilizacion()->setAlimento(food);
				Jugadores[selecion]->getCivilizacion()->setOro(oro);
				Jugadores[selecion]->getCivilizacion()->setMadera(madera);
				Jugadores[selecion]->getCivilizacion()->setPiedra(piedra);
				cout<<"EXITO EN LA RECOLECCION \n";
				break;
			}//case 2
			case 3:{
				newBuilding(selecion);
				break;
			}//case 3
			case 4:{
				newTroop(selecion);
				break;
			}//case 4
			case 5:{
				die_populace(selecion);
				break;
			}//case 5
			case 6:{
				int can_fight = 0;
				bool can= true;
				for(int i = 0 ; i < Jugadores.size() ; i++){
					if(Jugadores[i]->getCivilizacion()->getSize() == 0){
						can_fight++;
					}
				}
				if(can_fight == Jugadores.size()-1){
					can = false;
				}
				
				if(Jugadores.size()<2 || can == false ){
					cout<<"Necesita al menos dos Civilizaciones/Jugadores para ir a Batalla o sus enemigos no tienen tropas \n";
				}else{
				Batalla(selecion);

			}
				break;
			}//case 6
			case 7:{
				cout<<"TURNO FINALIZADO \n";
				for(int i = 0 ; i < 1000; i++){

				}
				cout<<"Matando gente \n";
				cout<<"Contemplando porque la gente estudia Sistemas \n";
				cout<<"LISTO \n ";
				break;
			}//case 7
		}//end switch
		cout<<"_____________ \n";
		cout<<"_____________ \n";
		cout<<"MENU NUMERO 2: \n";
		cout<<"1.Nuevo Aldeano \n";
		cout<<"2.Buscar Recursos \n";
		cout<<"3.Nuevo Edifico \n";
		cout<<"4.Nueva Tropa \n";
		cout<<"5.Desterrar Poblacion \n";
		cout<<"6.Batalla \n";
		cout<<"7.Finalizar Turno \n";
		cout<<"8.Regresar al menu inciial \n";
		cout<<"Ingrese que desea hacer \n";
		cin>>decision;
	}//while menu 2
}

void newBuilding(int a){
	cout<<"Que desea construir? \n";
	cout<<"1.Casa \n";
	cout<<"2.Cuartel \n";
	cout<<"3.Castillo \n";
	cout<<"Ingrese su opcion \n";
	int select;
	cin>>select;
	switch(select){
		case 1:{
			if(Jugadores[a]->getCivilizacion()->getMadera() < 50){
				cout<<"Not Enough Wood \n";
			}else{
			Jugadores[a]->getCivilizacion()->addCasa(new Casa(50,0,0));
			int capacidad = Jugadores[a]->getCivilizacion()->getCapacidad();
			capacidad = capacidad + 5;
			if(capacidad > 200){
				capacidad = 200;
			}
			Jugadores[a]->getCivilizacion()->setCapacidad(capacidad);
			int wood = Jugadores[a]->getCivilizacion()->getMadera() - 50;
			Jugadores[a]->getCivilizacion()->setMadera(wood);
			cout<<"EXITO en creacion de casa \n";
			}
			break;
		}//case 1
		case 2:{
			if(Jugadores[a]->getCivilizacion()->getPiedra()<80 || Jugadores[a]->getCivilizacion()->getMadera() < 120){
				cout<<"Le hace falta madera o piedra \n";
			}
			else{
				int piedra = Jugadores[a]->getCivilizacion()->getPiedra() - 80;
				int wood = Jugadores[a]->getCivilizacion()->getMadera() - 120;
				Jugadores[a]->getCivilizacion()->setMadera(wood);
				Jugadores[a]->getCivilizacion()->setPiedra(piedra);
				Jugadores[a]->getCivilizacion()->setCuartel(true);
				cout<<"EXITOOO EN CREACION DE CUARTEL \n";
			}
			break;
		}//case 2
		case 3:{
			if(Jugadores[a]->getCivilizacion()->getPiedra()<200 || Jugadores[a]->getCivilizacion()->getMadera() < 275){
				cout<<"Le hace falta madera o piedra \n";
			}
			else{
				int piedra = Jugadores[a]->getCivilizacion()->getPiedra() - 200;
				int wood = Jugadores[a]->getCivilizacion()->getMadera() - 275;
				Jugadores[a]->getCivilizacion()->setMadera(wood);
				Jugadores[a]->getCivilizacion()->setPiedra(piedra);
				Jugadores[a]->getCivilizacion()->setCastillo(true);
				cout<<"EXITOOO EN CREACION DE CASTILLO \n";
			}
			break;
		}//case3
		default:{
			cout<<"Esta opcion no existe lel \n";
			break;
		}
	}//switch
}//end createBuilding

void newTroop(int a){
	cout<<"Que desea construir? \n";
	cout<<"1.Soldado \n";
	cout<<"2.Caballero \n";
	cout<<"3.Special Warrior\n";
	cout<<"Ingrese su opcion \n";
	int select;
	cin>>select;

	switch(select){
		case 1:{
			if(Jugadores[a]->getCivilizacion()->getAlimento()<90 || Jugadores[a]->getCivilizacion()->getOro()<20 || Jugadores[a]->getCivilizacion()->getCuartel() == false || Jugadores[a]->getCivilizacion()->getPoblacion_Actual() >= Jugadores[a]->getCivilizacion()->getCapacidad()){
				cout<<"No tiene suficiente oro o alimento o casas \n";
			}else{
				int actual = Jugadores[a]->getCivilizacion()->getPoblacion_Actual();
				Jugadores[a]->getCivilizacion()->setPoblacion_Actual(actual+1);
				int alimento = Jugadores[a]->getCivilizacion()->getAlimento()-90;
				int oro = Jugadores[a]->getCivilizacion()->getOro()-20;
				Jugadores[a]->getCivilizacion()->setOro(oro);
				Jugadores[a]->getCivilizacion()->setAlimento(alimento);
				Jugadores[a]->getCivilizacion()->addTropa(new Soldado("Masculino",90,20,20,50,100,20,1));
				cout<<"EXITOOO creacion Soldado \n";
			}
			break;
		}//end case 1
		case 2:{
			if(Jugadores[a]->getCivilizacion()->getAlimento()<110 || Jugadores[a]->getCivilizacion()->getOro()<60 || Jugadores[a]->getCivilizacion()->getCuartel() == false || Jugadores[a]->getCivilizacion()->getPoblacion_Actual() >= Jugadores[a]->getCivilizacion()->getCapacidad()){
				cout<<"No tiene suficiente oro o alimento o casa \n";
			}else{
				int actual = Jugadores[a]->getCivilizacion()->getPoblacion_Actual();
				Jugadores[a]->getCivilizacion()->setPoblacion_Actual(actual+1);
				int alimento = Jugadores[a]->getCivilizacion()->getAlimento()-110;
				int oro = Jugadores[a]->getCivilizacion()->getOro()-60;
				Jugadores[a]->getCivilizacion()->setOro(oro);
				Jugadores[a]->getCivilizacion()->setAlimento(alimento);
				Jugadores[a]->getCivilizacion()->addTropa(new Caballero("Masculino",110,60,10,10,150,150,2));
				cout<<"EXITOOO creacion Caballero \n";
			}
			break;
		}//end case 2
		case 3:{
			if(Jugadores[a]->getCivilizacion()->getAlimento()<150 || Jugadores[a]->getCivilizacion()->getOro()<90 || Jugadores[a]->getCivilizacion()->getCastillo() == false || Jugadores[a]->getCivilizacion()->getPoblacion_Actual() >= Jugadores[a]->getCivilizacion()->getCapacidad()){
				cout<<"No tiene suficiente oro o alimento o casa \n";
			}else{
				int actual = Jugadores[a]->getCivilizacion()->getPoblacion_Actual();
				Jugadores[a]->getCivilizacion()->setPoblacion_Actual(actual+1);
				int alimento = Jugadores[a]->getCivilizacion()->getAlimento()-150;
				int oro = Jugadores[a]->getCivilizacion()->getOro()-90;
				Jugadores[a]->getCivilizacion()->setOro(oro);
				Jugadores[a]->getCivilizacion()->setAlimento(alimento);
				Jugadores[a]->getCivilizacion()->addTropa(new Special("Masculino",150,90,100,100,150,150,2));
				cout<<"EXITOOO creacion Special \n";
			}
			break;
		}//end case 3
		default:{
			cout<<"No existe esa opcion \n";
		}
	}//end switch
}//end newTroop

void die_populace(int a){
	cout<<"Matan... Relocando a toda la poblacion \n";
	Jugadores[a]->getCivilizacion()->setOro(0);
	Jugadores[a]->getCivilizacion()->setMadera(0);
	Jugadores[a]->getCivilizacion()->setPiedra(0);
	Jugadores[a]->getCivilizacion()->setAlimento(0);
	Jugadores[a]->getCivilizacion()->setAldeano(0);
	Jugadores[a]->getCivilizacion()->setCapacidad(5);
	Jugadores[a]->getCivilizacion()->setPoblacion_Actual(0);
	Jugadores[a]->getCivilizacion()->setCuartel(false);
	Jugadores[a]->getCivilizacion()->setCastillo(false);
	Jugadores[a]->getCivilizacion()->getSizeTropas();
	Jugadores[a]->getCivilizacion()->getSizeCasas();
	cout<<"EXITOOOO MAT... RELOCO A TODA SU POBLACION \n";
}

void Batalla(int a){
	for(int i = 0 ; i < Jugadores.size() ; i++){
		if(i == a || Jugadores[i]->getCivilizacion()->getSize() < 1){

		}else{
			cout<<i<<" "<<Jugadores[a]->getNombre()<<endl;
		}
	}
	cout<<"Seleccione su oponente: \n";
	int oponente;
	cin>>oponente;
	printPlayer(a);
	cout<<"VS------------------- \n";
	cout<<"--------------------- \n";
	printPlayer(oponente);
	bool win = false;
	int life_1=0;
	int life_2=0;
	while(win == false){
		double attack_1 = Jugadores[a]->getCivilizacion()->getTropa(life_1)->getAttack();
		double hp_2 = Jugadores[oponente]->getCivilizacion()->getTropa(life_2)->getAttack() - attack_1;
		Jugadores[oponente]->getCivilizacion()->getTropa(life_2)->setVida(hp_2);
		if(hp_2 == 0 || hp_2 < 0){
			life_2++;
			if(life_2 == Jugadores[oponente]->getCivilizacion()->getSize()){
				win = false;
				break;
			}
		}
		double attack_2 = Jugadores[oponente]->getCivilizacion()->getTropa(life_2)->getAttack();
		double hp_1 = Jugadores[a]->getCivilizacion()->getTropa(life_1)->getAttack() - attack_2;
		Jugadores[a]->getCivilizacion()->getTropa(life_1)->setVida(hp_1);
		if(hp_1 == 0 || hp_1 < 0){
			life_1++;
			if(life_1 == Jugadores[a]->getCivilizacion()->getSize()){
				win = true;
				break;
			}
		}

		}
		if(win == false){
			cout<<"GANO EL JUGADOR: "<<Jugadores[a]->getNombre()<<endl;
			int oro =Jugadores[a]->getCivilizacion()->getOro() + Jugadores[oponente]->getCivilizacion()->getOro();
			int madera =Jugadores[a]->getCivilizacion()->getMadera()+Jugadores[oponente]->getCivilizacion()->getMadera();
			int piedra =Jugadores[a]->getCivilizacion()->getPiedra()+Jugadores[oponente]->getCivilizacion()->getPiedra();
			int alimento =Jugadores[a]->getCivilizacion()->getAlimento() + Jugadores[oponente]->getCivilizacion()->getAlimento();
			Jugadores[a]->getCivilizacion()->setOro(oro);
			Jugadores[a]->getCivilizacion()->setMadera(madera);
			Jugadores[a]->getCivilizacion()->setPiedra(piedra);
			Jugadores[a]->getCivilizacion()->setAlimento(alimento);
			die_populace(oponente);
		}else{
			cout<<"GANO EL JUGADOR: "<<Jugadores[oponente]->getNombre()<<endl;
			int oro =Jugadores[a]->getCivilizacion()->getOro() + Jugadores[oponente]->getCivilizacion()->getOro();
			int madera =Jugadores[a]->getCivilizacion()->getMadera()+Jugadores[oponente]->getCivilizacion()->getMadera();
			int piedra =Jugadores[a]->getCivilizacion()->getPiedra()+Jugadores[oponente]->getCivilizacion()->getPiedra();
			int alimento =Jugadores[a]->getCivilizacion()->getAlimento() + Jugadores[oponente]->getCivilizacion()->getAlimento();
			Jugadores[oponente]->getCivilizacion()->setOro(oro);
			Jugadores[oponente]->getCivilizacion()->setMadera(madera);
			Jugadores[oponente]->getCivilizacion()->setPiedra(piedra);
			Jugadores[oponente]->getCivilizacion()->setAlimento(alimento);
			die_populace(a);
		}
}
void printPlayer(int a){
	cout<<"Nombre: "<<Jugadores[a]->getNombre()<<endl;
	cout<<"Civilizacion: "<<Jugadores[a]->getCivilizacion()->getName()<<endl;
	cout<<"Numero de Aldeanos: "<<Jugadores[a]->getCivilizacion()->getAldeano()<<endl;
	cout<<"Oro: "<<Jugadores[a]->getCivilizacion()->getOro()<<endl;
	cout<<"Alimento: "<<Jugadores[a]->getCivilizacion()->getAlimento()<<endl;
	cout<<"Madera: "<<Jugadores[a]->getCivilizacion()->getMadera()<<endl;
	cout<<"Piedra: "<<Jugadores[a]->getCivilizacion()->getPiedra()<<endl;
	cout<<"Tropas: "<<Jugadores[a]->getCivilizacion()->getSize()<<endl;
}