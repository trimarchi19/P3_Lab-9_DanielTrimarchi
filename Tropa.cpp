#include "Tropa.h"

	Tropa::Tropa(){

	}
	Tropa::~Tropa(){

	}
	//int c_oro,c_alimentacion,ataque,defensa,vida,velocidad,tiempo;
	Tropa::Tropa(int oro,int alimen,int pAtaque,int pDef,int pVida,int pVel,int pTiempo,char pSexo,char pTipo){
		//cout<<"..............................."<<endl;
		 c_oro=oro;
		 c_alimentacion=alimen;
		 ataque=pAtaque;
		 defensa=pDef;
		 vida=pVida;
		 velocidad=pVel;
		 tiempo=pTiempo;
		 sexo=pSexo;
		 //cout<<"Tipo##"<<tipo<<endl;
		 tipo=pTipo;
	}

	int Tropa::getC_Oro(){
		return c_oro;
	}
	int Tropa::getC_Ali(){
		return c_alimentacion;
	}
	int Tropa::getAtk(){
		return ataque;
	}
	int Tropa::getDef(){
		return defensa;
	}
	int Tropa::getHP(){
		return vida;
	}
	int Tropa::getVL(){
		return velocidad;
	}
	int Tropa::getTime(){
		return tiempo;
	}
	char Tropa::getSexo(){
		return sexo;
	}

	void Tropa::setC_Oro(int oro){
		c_oro=oro;
	}
	void Tropa::setC_Ali(int alimen){
		c_alimentacion=alimen;
	}
	void Tropa::setAtk(int pAtaque){
		ataque=pAtaque;
	}
	void Tropa::setDef(int pDef){
		defensa=pDef;
	}
	void Tropa::setHP(int pVida){
		//cout<<vida<<"##############"<<pVida;
		vida=pVida;
		//cout<<"$$$$$$$$$$$"<<vida;
	}
	void Tropa::setVL(int pVel){
		velocidad=pVel;
	}
	void Tropa::setTime(int pTiempo){
		tiempo=pTiempo;
		//cout<<"Time..."<<tiempo<<" pTiempo"<<pTiempo<<endl;
	}
	void Tropa::setSexo(char pSexo){
		sexo=pSexo;
	}
	int Tropa::Ataque(){
		return ataque;
	}
	char Tropa::getTipo(){
		return tipo;
	}
/*



*/