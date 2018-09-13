#include "Edificio.h"

	Edificio::Edificio(){

	}
	Edificio::Edificio(int Coro,int cMad,int cPied){
		c_oro=Coro;
		c_madera=cMad;
		c_piedra=cPied;
	}
	Edificio::~Edificio(){

	}
	int Edificio::getcOro(){
		return c_oro;
	}
	int Edificio::getcMadera(){
		return c_madera;
	}
	int Edificio::getcPiedra(){
		return c_piedra;
	}

	void Edificio::setcOro(int Coro){
		c_oro=Coro;
	}
	void Edificio::setcMadera(int cMad){
		c_madera=cMad;
	}
	void Edificio::setcPiedra(int cPied){
		c_piedra=cPied;
	}
