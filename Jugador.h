#ifndef JUGADOR_H
#define JUGADOR_H 
#include <string>
#include "Civilizacion.h"
using namespace std;
class Jugador
{
private:
	string nombre;
	Civilizacion aldea;
public:
	Jugador();
	Jugador(string,Civilizacion);
	~Jugador();
	void setNombre(string);
	string getNombre();
	void setCiv(Civilizacion);
	Civilizacion getCiv();
	
};
#endif