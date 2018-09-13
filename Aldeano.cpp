#include "Aldeano.h"


	Aldeano::Aldeano(){

	}
	Aldeano::Aldeano(char pSexo,int pCosto){
		sexo=pSexo;
		costo_alimento=pCosto;
	}
	Aldeano::~Aldeano(){

	}
	char Aldeano::getSexo(){
		return sexo;
	}
	int Aldeano::getCosto(){
		return costo_alimento;
	}

	void Aldeano::setSexo(char pSexo){
		sexo=pSexo;
	}
	void Aldeano::setCosto(int pCosto){
		costo_alimento=pCosto;
	}