#ifndef CIVILIZACION_H
#define CIVILIZACION_H


class Civilizacion{
private:
	int oro,madera,piedra,alimento,pob_max,pob_actual,cap_pob;
public:
	Civilizacion();
	~Civilizacion();
	
	//Setters
	void setOro(int);
	void setMadera(int);
	void setPiedra(int);
	void setAlimento(int);
	void setPoblacion_max(int);
	void setPoblacion_actual(int);
	void setCap_poblacion(int);

	//Getters
	int getOro();
	int getMadera();
	int getPiedra();
	int getAlimento();
	int getPoblacion_max();
	int getPoblacion_actual();
	int getCap_poblacion();

	
};
#endif