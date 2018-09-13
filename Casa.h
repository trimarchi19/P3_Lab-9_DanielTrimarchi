#ifndef CASA_H
#define CASA_H 
#include "Edificio.h"
class Casa: public Edificio
{
private:
	int aumenta=5;
public:
	Casa();
	~Casa();
	int getAumento();
	
};
#endif