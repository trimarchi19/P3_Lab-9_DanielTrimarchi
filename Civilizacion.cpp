#include "Civilizacion.h"	

	Civilizacion::Civilizacion(){

	}
	Civilizacion::~Civilizacion(){

	}
	
	//Setters
	void Civilizacion::Civilizacion::setOro(int pOro){
		oro=pOro;
	}
	void Civilizacion::setMadera(int pMadera){
		madera=pMadera;
	}
	void Civilizacion::setPiedra(int pPiedra){
		piedra=pPiedra;
	}
	void Civilizacion::setAlimento(int pAlimen){
		alimento=pAlimen;
	}
	void Civilizacion::setPoblacion_max(int pMax){
		pob_max=pMax;
	}
	void Civilizacion::setPoblacion_actual(int pAct){
		pob_actual=pAct;
	}
	void Civilizacion::setCap_poblacion(int Cap){
		cap_pob=Cap;
	}

	//Getters
	int Civilizacion::getOro(){
		return oro;
	}
	int Civilizacion::getMadera(){
		return madera;
	}
	int Civilizacion::getPiedra(){
		return piedra;
	}
	int Civilizacion::getAlimento(){
		return alimento;
	}
	int Civilizacion::getPoblacion_max(){
		return pob_max;
	}
	int Civilizacion::getPoblacion_actual(){
		return pob_actual;
	}
	int Civilizacion::getCap_poblacion(){
		return cap_pob;
	}
