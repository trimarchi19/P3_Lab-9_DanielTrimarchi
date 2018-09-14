#ifndef GUERRERO_H
#define GUERRERO_H 	
#include "Tropa.h"
#include <iostream>

using namespace std;

class Guerrero:public Tropa{
private:
	int ataque_neto;
public:
	Guerrero();
	~Guerrero();
	void setNeto(int);
	int getNeto();
	
};
#endif