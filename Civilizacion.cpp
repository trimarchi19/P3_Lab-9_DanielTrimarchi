#include "Civilizacion.h"	

	Civilizacion::Civilizacion(){

	}

	Civilizacion::~Civilizacion(){

	}
	Civilizacion::Civilizacion(int pOro,int pMadera,int pPiedra,int pAlimen,int pMax){
		oro=pOro;
		madera=pMadera;
		piedra=pPiedra;
		alimento=pAlimen;
		pob_max=pMax;
		pob_actual=0;
		cap_pob=0;
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
	string Civilizacion::getNombre(){
		return nombre;
	}
	void Civilizacion::setNombre(string pNombre){
		nombre=pNombre;
	}
	void Civilizacion::setUso(bool pUso){
		uso=pUso;
	}
	bool Civilizacion::getUso(){
		return uso;
	}


	void Civilizacion::setAldeano(vector<Aldeano> pAldeano){
		aldeano=pAldeano;
	}
	void Civilizacion::setTropa(vector<Tropa> pTropa){
		tropa=pTropa;
	}

	//void addEdificio(Edificio);
	void Civilizacion::addAldeano(Aldeano ald){
		aldeano.push_back(ald);
	}
	void Civilizacion::addTropa(Tropa troop){
		tropa.push_back(troop);
	}

	//vector<Edificio> getEdificios();
	vector<Aldeano> Civilizacion::getAldeanos(){
		return aldeano;
	}
	vector<Tropa> Civilizacion::getTropas(){
		return tropa;
	}

	//Edificio getEdificio(int);
	Aldeano Civilizacion::getAldeano(int i){
		return aldeano[i];
	}
	Tropa Civilizacion::getTropa(int i){
		return tropa[i];
	}

