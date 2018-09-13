#ifndef EDIFICIO_H
#define EDIFICIO_H 

class Edificio
{
private:
	//Costos
	int c_oro,c_piedra,c_madera;
public:
	Edificio();
	Edificio(int,int,int);
	~Edificio();
	int getcOro();
	int getcMadera();
	int getcPiedra();

	void setcOro(int);
	void setcMadera(int);
	void setcPiedra(int);
	
};
#endif