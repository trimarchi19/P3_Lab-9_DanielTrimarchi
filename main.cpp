#include "Tropa.h"
#include <string>
#include "Aldeano.h"
#include "Castillo.h"
#include "Soldado.h"
#include "Caballero.h"
#include "Casa.h"
#include "Cuarteles.h"
#include "Civilizacion.h"
#include "Jugador.h"
#include "Edificio.h"
#include <iostream>
#include <vector>
using namespace std;
void CrearCiv(vector<Civilizacion>&);
void CrearJugador(vector<Jugador>&,vector<Civilizacion>&);
void Guardar();
void Ingresar(vector<Civilizacion>&,vector<Jugador>&,int);

int main(){
	int opt;
	bool salir=false;
	vector<Civilizacion> civilizaciones;
	vector<Jugador> players;
	do{
		cout<<"-------------------------------------------"<<endl;
		cout<<"				MENU PRINCIPAL"<<endl
		<<"1)Crear Civilizacion"<<endl
		<<"2)Crear Jugador"<<endl
		<<"3)Guardar Informacion"<<endl
		<<"4)Ingresar"<<endl
		<<"5)Salir"<<endl
		<<"Que desea hacer: ";
		cin >> opt;		
	}while(opt!=4);
	cout<<"-------------------------------------------"<<endl;
	switch(opt){
		case 1:
			CrearCiv(civilizaciones);
			break;
		case 2:
			if(civilizaciones.size()>0){
			CrearJugador(players,civilizaciones);
			}else{
				cout<<"Debe Crear Una Civilizacion..."<<endl;
			}
			break;
		case 3:
			break;
		case 4:{	
			if(players.size()>1){
			int turno=1;
			Ingresar(civilizaciones,players,turno);
			}else{
				cout<<"Debe Crear almenos dos Jugadores..."<<endl;
			}
		}
			break;
		case 5:
			cout<<"GRACIAS POR USAR EL PROGRAMA";
			break;
	}
	return 0;
}

void CrearCiv(vector<Civilizacion>& civ){
	int oro,madera,piedra,alimento,pob_max,cap_pob;
	string nombre;
	cout<<"Ingrese cantidad de oro: ";
	cin >> oro;
	cout<<"Ingrese cantidad de Madera: ";
	cin >> madera;
	cout<<"Ingrese cantidad de Piedra: ";
	cin >> piedra;
	cout<<"Ingrese cantidad de Alimento: ";
	cin >> alimento;
	cout<<"Ingrese cantidad de Poblacion Maxima: ";
	cin >> pob_max;
	cout<<"Ingrese el Nombre de La Civilizacion: ";
	cin >>nombre;

	Civilizacion Civ_nueva=Civilizacion(oro,madera,piedra,alimento,pob_max);
	Civ_nueva.setNombre(nombre);
	civ.push_back(Civ_nueva);
}
void CrearJugador(vector<Jugador>& jug, vector<Civilizacion>& civ){
	string nombre;
	int opt;
	bool no_esta_en_uso;
	cout<<"Ingrese su Nombre: ";
	cin >>nombre;
	for (int i = 0; i < civ.size(); i++)
	{
		cout<<"1) "<<civ[i].getNombre()<<endl;
	}
	do{
	cout<<"Cual desea usar?: ";
	cin >>opt;
	if(opt>-1||opt<civ.size()){
		no_esta_en_uso=civ[opt].getUso();
		if(no_esta_en_uso==true){
			cout<<"Esta Civilizacion esta en Uso... Escoja o Cree Otra"<<endl;
		}
	}
	}while((opt<0||opt>=civ.size()));
	if(no_esta_en_uso==false){
		Jugador player=Jugador(nombre,civ[opt]);
		jug.push_back(player);
	}


}
void Ingresar(vector<Civilizacion>& civ,vector<Jugador>& player,int turno){
	int opt;
	int jug1,jug2;
	for (int i = 0; i < player.size(); ++i)
	{
		cout<<"1) "<<player[i].getNombre()<<endl;
	}
	cout<<"1)Escoja su Jugador: ";
	cin >>jug1;
	cout<<"2) Escoja su Jugador: ";
	cin >>jug2;
	if((jug1&&jug2)>-1||(jug1&&jug2)<player.size()){
	do{
		cout<<"-------------------------------------------"<<endl;
		cout<<"Turno del Jugador: "<<player[turno].getNombre()<<endl<<endl;

		cout<<"1) Nuevo Aldeano"<<endl
		<<"2) Buscar Recurso"<<endl
		<<"3) Nuevo Edificio"<<endl
		<<"4) Nueva Tropa"<<endl
		<<"5) Desterrar Poblacion"<<endl
		<<"6) Batalla"<<endl
		<<"7) Finalizar Turno"<<endl
		<<"8) Volver Al Menu"<<endl
		<<"Que Desea Hacer: ";
		cin >> opt;
		if(opt>0||opt<8){
			switch(opt){
				case 1:

					break;
				case 2:

					break;
				case 3:{
					int opt2;
					do{
						cout<<"1) Casa"<<endl
						<<"2) Cuartel"<<endl
						<<"3) Castillo"<<endl
						<<"Que Desea Hacer: ";
					}while(opt2<0||opt2>3);
					switch(opt2){
						case 1:
						//casa
							break;
						case 2:
						//cuartel
							break;
						case 3:
						//castillo
							break;
					}

					}	
					break;
				case 4:	{
					int opt2;
					do{
						cout<<"1) Soldado"<<endl
						<<"2) Caballero"<<endl
						<<"3) Guerrero Especial"<<endl
						<<"Que Desea Hacer: ";
					}while(opt2<0||opt2>3);
					switch(opt2){
						case 1:
						//soldado
							break;
						case 2:
						//caballero
							break;
						case 3:
						//cguerrero
							break;
					}
				}
					break;
				case 5:	

					break;
				case 6:	

					break;
				case 7:	
				//Cambia los turnos entre Jugadores
					if(turno==jug1){
						turno=jug2;
					}else if(turno==jug2){
						turno=jug1;
					}
					break;
			}

		}
		cout<<endl;
	}while(opt!=8);
}else{
	cout<<"Uno de los Jugadores No Existe..."<<endl;
}
}
/*
Crear civilización
 Crear jugador
 Guardar información
 Ingresar
o Nuevo aldeano
o Buscar recursos
o Nuevo edificio
 Casa
 Cuartel
 Castillo
o Nueva tropa
 Soldado
 Caballería
 Guerrero especial
o Desterrar población
o Batalla
o Finalizar turno
o Volver a menú principal


*/