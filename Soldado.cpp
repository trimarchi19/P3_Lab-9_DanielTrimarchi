#include "Soldado.h"
//int oro,int alimen,int pAtaque,int pDef,int pVida,int pVel,int pTiempo,char pSexo
	Soldado::Soldado():Tropa(25,90,10,5,30,5,1,'M','S'){

	}
	Soldado::~Soldado(){

	}
	int Soldado::Ataque(){
		return 10;
	}

/*
son el tipo de tropa más básico, su ataque y defensa funcionan de
manera normal. Además, su tiempo de entrenamiento es de 1 turno.

el cual tiene un costo de 90 unidades de alimento
y 25 de oro
*/