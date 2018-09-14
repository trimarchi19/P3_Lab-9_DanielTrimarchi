#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include <string>
#include <vector>
#include "Edificio.h"
#include "Aldeano.h"
#include "Tropa.h"
//#include "Jugador.h"
#include <iostream>
using namespace std;

class Civilizacion{
private:
	vector<Edificio> edificio;
	vector<Aldeano> aldeano;
	vector<Tropa> tropa;
	vector<Tropa> salientes;
	string nombre;
	bool uso=false,cuartel=false,castillo=false;
	int oro,madera,piedra,alimento,pob_max,pob_actual,cap_pob;
public:
	Civilizacion();
	Civilizacion(int,int,int,int,int);
	~Civilizacion();
	
	//Setters
	void setUso(bool);
	void setNombre(string);
	void setOro(int);
	void setMadera(int);
	void setPiedra(int);
	void setAlimento(int);
	void setPoblacion_max(int);
	void setPoblacion_actual(int);
	void setCap_poblacion(int);

	//Getters
	bool getUso();
	string getNombre();
	int getOro();
	int getMadera();
	int getPiedra();
	int getAlimento();
	int getPoblacion_max();
	int getPoblacion_actual();
	int getCap_poblacion();


	//void setEdificio(vector<Edificio>);
	void setAldeano(vector<Aldeano>);
	void setTropa(vector<Tropa>);

	void addEdificio(Edificio,int,int);
	void addAldeano(Aldeano);
	void addTropa(Tropa);

	//vector<Edificio> getEdificios();
	vector<Aldeano> getAldeanos();
	vector<Tropa> getTropas();

	//Edificio getEdificio(int);
	Aldeano getAldeano(int);
	Tropa& getTropa(int);

	bool getCuartel();
	bool getCastillo();
	void removeTropa(int);

	void setSaliente(vector<Tropa>);
	Tropa getSaliente(int);
	void addSaliente(Tropa);
	vector<Tropa> getSalientes();
	void removeSaliente(int);

	//void SimularBatalla(vector<Jugador>&,int,int,int,int);

	
};
#endif