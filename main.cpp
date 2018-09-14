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
		cout<<"---------------------------------------"<<endl;
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
			cout<<"GRACIAS POR USAR EL PROGRAMA...."<<endl;
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
	if(opt>-1 && opt<civ.size()){
		cout<<"Entro...."<<endl;
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
		cout<<i<<") "<<player[i].getNombre()<<endl;
	}

	cout<<endl<<"Jugador#1)Escoja su Jugador: ";
	cin >>jug1;
	cout<<"Jugador#2) Escoja su Jugador: ";
	cin >>jug2;
	turno=jug1;
	if(jug1>-1 && jug2>-1 && jug1<player.size() && jug2<player.size()) {
	do{

		//Civilizacion actual=player[turno].getCiv();
		cout<<"-------------------------------------------"<<endl;
		cout<<"Turno del Jugador: "<<player[turno].getNombre()<<endl;
		cout<<"Capacidad: "<<player[turno].getCiv().getCap_poblacion();
		cout<<"  Poblacion Actual: "<<player[turno].getCiv().getPoblacion_actual()<<endl;
		cout<<"Alimento:"<<player[turno].getCiv().getAlimento()<<" Oro:"<<player[turno].getCiv().getOro()
		<<" Madera:"<<player[turno].getCiv().getMadera()<<" Piedra:"<<player[turno].getCiv().getPiedra()<<endl<<endl;
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
		cout<<"-------------------------------------------"<<endl<<endl;

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
					if((player[turno].getCiv().getPoblacion_actual()< 	player[turno].getCiv().getPoblacion_max())
					&& player[turno].getCiv().getPoblacion_actual()<player[turno].getCiv().getCap_poblacion()){
						
					do{
						cout<<"[ATK/DEF/HP/VEL]"<<endl;
						cout<<"1) Soldado[10,5,30,5]"<<endl
						<<"2) Caballero[15,10,40,10]"<<endl
						<<"3) Guerrero Especial[20+,15+,50,15]"<<endl
						<<"Que Desea Hacer: ";
						cin >>opt2;
						cout<<"-------------------------------"<<endl;
					}while(opt2<0||opt2>3);
					switch(opt2){

						case 1:
						{
							if(player[turno].getCiv().getCuartel()==true){
							Tropa t=Soldado();
							player[turno].getCiv().addTropa(t);

							}else{
								cout<<"Debe Crear un Cuartel..."<<endl;
							}
						}
							break;
						case 2:
						{
							if(player[turno].getCiv().getCuartel()==true){
							Tropa t=Caballero();
							player[turno].getCiv().addTropa(t);
							}else{
								cout<<"Debe Crear un Cuartel..."<<endl;
							}
						}
							break;
						case 3:
						{	
							if(player[turno].getCiv().getCastillo()==true){
							Tropa t=Guerrero();
							player[turno].getCiv().addTropa(t);
							}else{
								cout<<"Debe Crear un Castillo..."<<endl;
							}
						}				//cguerrero
							break;
					}
					}else{
						cout<<"Debe incrementar su Capacidad de Poblacion..."<<endl;
					}
				}
					break;
				case 5:	{
					Civilizacion nueva_civ=Civilizacion();
					player[turno].setCiv(nueva_civ);
					}
					break;
				case 6:	
				{
					if(player[jug1].getCiv().getSalientes().size()>0){
						cout<<"HMMM"<<player[jug2].getCiv().getSalientes().size()<<endl;
						if(player[jug2].getCiv().getSalientes().size()>0){
							//varibles que cambian el orden de dar golpes para simular battala
								int	n1=jug1;
								int n2=jug2;
								int tropa_actual_1,tropa_actual_2;;
								cout<<"[S/Soldado],[C/Caballero],[G/Guerrero]"<<endl;
							do{	cout<<"---------------------------------------------"<<endl;
								cout<<"Jugador#1"<<endl;
								if(player[n1].getCiv().getSalientes().size()>0&& player[n2].getCiv().getSalientes().size()){
								for (int i = 0; i < player[n1].getCiv().getSalientes().size(); ++i)
								{
									cout<<i<<") "<<player[n1].getCiv().getSaliente(i).getTipo()<<endl;
								}
								do{
									cout<<"Cual Tropa Dese Usar: ";
									cin >>tropa_actual_1;
								}while(tropa_actual_1<0||tropa_actual_1>=player[n1].getCiv().getSalientes().size());
								cout<<"Jugador#2"<<endl;
								for (int i = 0; i < player[n2].getCiv().getSalientes().size(); ++i)
								{
									cout<<i<<") "<<player[n2].getCiv().getSaliente(i).getTipo()<<endl;
								}
								do{
									cout<<"Cual Tropa Dese Usar: ";
									cin >>tropa_actual_2;
								}while(tropa_actual_2<0||tropa_actual_2>=player[n2].getCiv().getSalientes().size());
								do{
									int vida1=player[n1].getCiv().getSaliente(tropa_actual_1).getHP();
									int vida2=player[n2].getCiv().getSaliente(tropa_actual_2).getHP();
									int ataque=player[n1].getCiv().getSaliente(tropa_actual_1).Ataque();
									int ataque2=player[n2].getCiv().getSaliente(tropa_actual_2).Ataque();
									
								if(vida1>0){
									player[n2].getCiv().getSaliente(tropa_actual_2).setHP(vida2-ataque);
								}else if(vida2>0){
									player[n1].getCiv().getSaliente(tropa_actual_1).setHP(vida1-ataque2);
								}
								if(vida2>0){
									player[n1].getCiv().getSaliente(tropa_actual_1).setHP(vida1-ataque2);
								}
								if(vida1>0){
									player[n2].getCiv().getSaliente(tropa_actual_2).setHP(vida2-ataque);
								}
									 vida1=player[n1].getCiv().getSaliente(tropa_actual_1).getHP();
									 vida2=player[n2].getCiv().getSaliente(tropa_actual_2).getHP();
									if(vida1<0){
										player[n1].getCiv().removeSaliente(tropa_actual_1);
									}else if(vida2<0){
										player[n2].getCiv().removeSaliente(tropa_actual_2);
									}
								
								}while((player[n1].getCiv().getSaliente(tropa_actual_1).getHP()>0)&&
										player[n2].getCiv().getSaliente(tropa_actual_2).getHP()>0);
								}
							}while(player[jug1].getCiv().getSalientes().size()>0 && player[jug2].getCiv().getSalientes().size()>0);
							Aldeano ald=Aldeano();
							cout<<"--------------------------------------------"<<endl;
							if(player[jug1].getCiv().getSalientes().size()==0){
								cout<<"GANO EL JUGADOR#2: "<<player[jug2].getNombre()<<endl;
								player[n1].getCiv().getAldeanos().clear();
							}else{
								cout<<"GANO EL JUGADOR#1: "<<player[jug1].getNombre()<<endl;
								player[n2].getCiv().getAldeanos().clear();
							}
						}else{
							cout<<"El Jugador Dos todavia no tiene Tropas disponibles..."<<endl;
						}
					}else{
						cout<<"El Jugador Uno todavia no tiene Tropas disponibles..."<<endl;
					}
				}
					break;
				case 7:	
				//Cambia los turnos entre Jugadores
					if(turno==jug1){
						turno=jug2;
					}else if(turno==jug2){
						turno=jug1;
					}
					for (int i = 0; i < player[turno].getCiv().getTropas().size(); i++)
					{
						if((player[turno].getCiv().getTropa(i).getTime())>0){
						int cant=player[turno].getCiv().getTropa(i).getTime()-1;
						player[turno].getCiv().getTropa(i).setTime(cant);
				//cout<<cant<<":::HMMM::: "<<player[turno].getCiv().getTropa(i).getTime()<<endl;
					}
					if((player[turno].getCiv().getTropa(i).getTime())==0){
						cout<<"Se Ha Creado Una Tropa..."<<endl;
						player[turno].getCiv().addSaliente(player[turno].getCiv().getTropa(i));
						player[turno].getCiv().removeTropa(i);

					}
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


