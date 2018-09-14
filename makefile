main: main.o Tropa.o Aldeano.o Soldado.o Edificio.o Civilizacion.o Jugador.o Guerrero.o Caballero.o Castillo.o Casa.o Cuarteles.o 
		g++ main.o Tropa.o Aldeano.o Soldado.o Edificio.o Civilizacion.o Jugador.o Guerrero.o Caballero.o Castillo.o Casa.o Cuarteles.o  -o main
		rm *.o
main.o: main.cpp
	g++ -c main.cpp
Tropa.o: Tropa.h Tropa.cpp
	g++ -c Tropa.cpp
Soldado.o: Soldado.h Soldado.cpp
	g++ -c Soldado.cpp
Caballero.o: Caballero.h Caballero.cpp
	g++ -c Caballero.cpp
Guerrero.o: Guerrero.h Guerrero.cpp
	g++ -c Guerrero.cpp
Civilizacion.o: Civilizacion.h Civilizacion.cpp
	g++ -c Civilizacion.cpp
Jugador.o: Jugador.h Jugador.cpp
	g++ -c Jugador.cpp
Aldeano.o: Aldeano.h Aldeano.cpp
	g++ -c Aldeano.cpp
Casa.o: Casa.h Casa.cpp
	g++ -c Casa.cpp
Cuarteles.o: Cuarteles.h Cuarteles.cpp
	g++ -c Cuarteles.cpp
Castillo.o: Castillo.h Castillo.cpp
	g++ -c Castillo.cpp
Edificio.o: Edificio.cpp Edificio.h
	g++ -c Edificio.cpp


