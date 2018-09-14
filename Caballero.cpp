#include "Caballero.h"
	Caballero::Caballero():Tropa(60,110,15,10,40,10,2,'M','C'){
		ataque_neto=(15+10)/2;
		//cout<<"ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑññ";
	}
	Caballero::~Caballero(){

	}
	void Caballero::setNeto(int net){
		ataque_neto=net;
		}
	int Caballero::getNeto(){
		return ataque_neto;
	}
	int Caballero::Ataque(){
		return ataque_neto;
	}