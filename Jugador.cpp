#include "Jugador.h"

	Jugador::Jugador(){

	}
	Jugador::Jugador(string pNom,Civilizacion pAldea){
		nombre=pNom;
		aldea=pAldea;
	}
	Jugador::~Jugador(){

	}
	void Jugador::setNombre(string pNom){
		nombre=pNom;
	}
	string Jugador::getNombre(){
		return nombre;
	}
	void Jugador::setCiv(Civilizacion pAldea){
		aldea=pAldea;
	}
	Civilizacion& Jugador::getCiv(){
		return aldea;
	}