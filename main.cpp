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
#include "Guerrero.h"
#include <iostream>
#include <vector>
#include <typeinfo>

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
		cout<<endl;
		if(opt>0||opt<5){
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
			//players[0].getCiv().setMadera(266);
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
		}	
}while(opt!=5);
	cout<<"-------------------------------------------"<<endl;

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
		cout<<i<<") "<<civ[i].getNombre()<<endl;
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
	}while((opt<0||opt>civ.size()));
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
		cout<<i<<") "<<player[i].getNombre()<<endl;
	}
	cout<<"1)Escoja su Jugador: ";
	cin >>jug1;
	cout<<"2) Escoja su Jugador: ";
	cin >>jug2;
	turno=jug1;
	if((jug1&&jug2)>-1||(jug1&&jug2)<player.size()){
	do{
		//Civilizacion actual=player[turno].getCiv();
		cout<<"-------------------------------------------"<<endl;
		cout<<"Turno del Jugador: "<<player[turno].getNombre()<<endl;
		cout<<"Capacidad: "<<player[turno].getCiv().getCap_poblacion();
		cout<<"  Poblacion Actual: "<<player[turno].getCiv().getPoblacion_actual()<<endl<<endl;

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
		cout<<"-------------------------------------------"<<endl;
		if(opt>0||opt<8){
			switch(opt){
				case 1:
				{
				//if que valida si la poblacion actual no pasa la maxima
					if(player[turno].getCiv().getPoblacion_actual()< 	player[turno].getCiv().getPoblacion_max()){
				//if que valida que tenga espacio en la poblacion
				//sino ocupa crear casa
						if(player[turno].getCiv().getPoblacion_actual()<player[turno].getCiv().getCap_poblacion()){
								Aldeano ald=Aldeano();
								player[turno].getCiv().addAldeano(ald);

								//player[turno].getCiv().setPoblacion_actual(player[turno].getCiv().getPoblacion_actual()+1);
							}else{
							cout<<"Debe Crear Una Casa Primero...."<<endl;
							}
						}else{
							cout<<"Ya alcanzo el Limite en su poblacion..."<<endl;
					}
				
				}				
					break;
				case 2:
					if(player[turno].getCiv().getAldeanos().size()>0){
						//+50 de alimento, +40 de madera, +30 de oro y +20 de piedra
						cout<<"Actualmente tiene..."<<endl;
						cout<<"Oro: "<<player[turno].getCiv().getOro()
						<<" Madera: "<<player[turno].getCiv().getMadera()
						<<"Piedra: "<<player[turno].getCiv().getPiedra()
						<<"Alimento: "<<player[turno].getCiv().getAlimento()<<endl;


						for (int i = 0; i < player[turno].getCiv().getAldeanos().size(); ++i)
						{
						player[turno].getCiv().setOro(player[turno].getCiv().getOro()+30);
						player[turno].getCiv().setMadera(player[turno].getCiv().getMadera()+40);
						player[turno].getCiv().setPiedra(player[turno].getCiv().getPiedra()+20);
						player[turno].getCiv().setAlimento(player[turno].getCiv().getAlimento()+50);
							
						}
						cout<<"Ahora tiene..."<<endl;
						cout<<"Oro: "<<player[turno].getCiv().getOro()
						<<" Madera: "<<player[turno].getCiv().getMadera()
						<<"Piedra: "<<player[turno].getCiv().getPiedra()
						<<"Alimento: "<<player[turno].getCiv().getAlimento()<<endl;

					}else{
						cout<<"Todavia no tiene Aldeanos..."<<endl;
					}
					break;
				case 3:{
					int opt2;
					do{
						cout<<"1) Casa"<<endl
						<<"2) Cuartel"<<endl
						<<"3) Castillo"<<endl
						<<"Que Desea Hacer: ";
						cin >>opt2;
					}while(opt2<0||opt2>3);
					switch(opt2){
						case 1:
						{
							Edificio home=Casa();
							//player[turno].getCiv().setCap_poblacion(100);
							player[turno].getCiv().addEdificio(home,5,0);
							player[turno].getCiv().setCap_poblacion(player[turno].getCiv().getCap_poblacion()+5);
							//player[turno].getCiv().setMadera(456);
							//cout<<"---"<<actual.getMadera();
						}

							break;
						case 2:
						{
							Edificio cuartel=Cuarteles();
							player[turno].getCiv().addEdificio(cuartel,0,1);
						//cuartel
						}
							break;
						case 3:
						//castillo
						{
							Edificio castillo=Castillo();
							player[turno].getCiv().addEdificio(castillo,0,2);
						}
							break;
					}


					}	
					break;
				case 4:	{
					int opt2;
					/*
					 soldado, el cual tiene un costo de 90 unidades de alimento
					y 25 de oro, unidad de caballería, con costo de 110 unidades de alimento y 60 de oro, por último, el
					guerrero especial, este tiene un costo de 150 unidades de alimento y 90 de oro.
					*/
					if((player[turno].getCiv().getPoblacion_actual()< 	player[turno].getCiv().getPoblacion_max())
					&& player[turno].getCiv().getPoblacion_actual()<player[turno].getCiv().getCap_poblacion()){
						
					do{
						cout<<"1) Soldado"<<endl
						<<"2) Caballero"<<endl
						<<"3) Guerrero Especial"<<endl
						<<"Que Desea Hacer: ";
						cin >>opt2;
					}while(opt2<0||opt2>3);
					switch(opt2){
						case 1:
						{
							Tropa t=Soldado();
						}
							break;
						case 2:
						{
							Tropa t=Caballero();
						}
							break;
						case 3:
						{
							Tropa t=Guerrero();
						}				//cguerrero
							break;
					}
					}else{
						cout<<"Ya no Tiene Espacio Disponible..."<<endl;	
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