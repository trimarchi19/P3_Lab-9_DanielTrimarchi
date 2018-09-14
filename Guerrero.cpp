#include "Guerrero.h"
	Guerrero::Guerrero():Tropa(150,90,20,15,50,15,3,'F','G'){
		ataque=20+10;
		defensa=15+10;
		ataque_neto= (ataque*(1 + (15/5)))+50*.15;
		//: neto = ataque*(1 + velocidad/5) +vida_oponente*0.15. S
	}
	Guerrero::~Guerrero(){

	}
		void Guerrero::setNeto(int net){
			ataque_neto=net;
		}
	int Guerrero::getNeto(){
		return ataque_neto;
	}
