#ifndef CABALLERO_H
#define CABALLERO_H
#include "Tropa.h" 
class Caballero:public Tropa
{

public:
	int ataque_neto;
	Caballero();
	~Caballero();
	void setNeto(int);
	int getNeto();
	int Ataque();
	
};
#endif