#include "Civilizacion.h"
#include <typeinfo>	
#include "Casa.h"

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
	void Civilizacion::setOro(int pOro){
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
		//cout<<"cap_pob:"<<cap_pob;
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
		int costo=alimento-ald.getCosto();
		cout<<"Alimento: "<<alimento<<" -"<<costo<<endl;
		if(costo>0){
			//cout<<"Entro al for...."<<endl;
		aldeano.push_back(ald);
		alimento=costo;
		pob_actual=pob_actual+1;
		}else{
			cout<<"No tiene Alimentos suficiente..."<<endl;
		}
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

	void Civilizacion::addEdificio(Edificio p,int cant,int tipo){
		cout<<"Oro: "<<oro<<" Madera: "<<madera<<" Piedra: "<<piedra<<endl;
		//cap_pob+=cant;
		int a,b,c;
		a=oro-p.getcOro();
		b=madera-p.getcMadera();
		c=piedra-p.getcPiedra();
		cout<<"A:"<<a<<" B:"<<b<<" C:"<<c<<endl;
		cout<<"cant: "<<cant<< " Pob:"<<cap_pob<<endl;
		if((a>0)&&(b>0)&&(c>0)){
			oro-=p.getcOro();
			madera-=p.getcMadera();
			piedra-=p.getcPiedra();
			if(tipo==1){
			cuartel=true;
			}else if(tipo==2){
			castillo=true;
			}
		}else{
		cout<<"No tiene Recurso Suficientes..."<<endl;
		}

	}

	bool Civilizacion::getCuartel(){
		return cuartel;
	}
	bool Civilizacion::getCastillo(){
		return castillo;
	}
