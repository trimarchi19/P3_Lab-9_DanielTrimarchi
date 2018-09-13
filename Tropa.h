#ifndef TROPA_H
#define TROPA_H 
class Tropa
{
private:
	char sexo;
	int c_oro,c_alimentacion,ataque,defensa,vida,velocidad,tiempo;
public:
	Tropa();
	Tropa(int,int,int,int,int,int,int,char);
	~Tropa();
	int getC_Oro();
	int getC_Ali();
	int getAtk();
	int getDef();
	int getHP();
	int getVL();
	int getTime();
	char getSexo();

	void setC_Oro(int);
	void setC_Ali(int);
	void setAtk(int);
	void setDef(int);
	void setHP(int);
	void setVL(int);
	void setTime(int);
	void setSexo(char);
};
#endif

/*
sexo, costo
de alimentación, costo de oro, ataque, defensa, vida, velocidad y tiempo de
entrenamiento (en turnos). 
*/