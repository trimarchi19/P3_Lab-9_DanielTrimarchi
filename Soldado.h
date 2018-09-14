#ifndef SOLDADO_H
#define SOLDADO_H 
#include "Tropa.h"
class Soldado:public Tropa
{
public:
	Soldado();
	~Soldado();
	 int Ataque();
	
};
#endif