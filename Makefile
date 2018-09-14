main.out:	main.o Jugador.o Civilizacion.o Tropas.h Caballero.o Soldado.o Aldeano.o Special.o Edificios.h Casa.o Cuartel.o Castillo.o
	g++ main.o Jugador.o Civilizacion.o Tropas.h Caballero.o Soldado.o Aldeano.o Special.o Edificios.h Casa.o Cuartel.o Castillo.o -o main.out

main.o:	main.cpp Civilizacion.h Tropas.h Edificios.h Jugador.h
	g++ -c main.cpp

Jugador.o:	Jugador.cpp Jugador.h Civilizacion.h
	g++ -c Jugador.cpp

Civilizacion.o:	Civilizacion.cpp Civilizacion.h Tropas.h Edificios.h Casa.h
	g++ -c Civilizacion.cpp

Caballero.o:	Caballero.cpp Caballero.h Tropas.h
	g++ -c Caballero.cpp

Soldado.o:	Soldado.cpp Soldado.h Tropas.h
	g++ -c Soldado.cpp

Aldeano.o:	Aldeano.cpp Aldeano.h Tropas.h
	g++ -c Aldeano.cpp

Special.o:	Special.cpp Special.h Tropas.h
	g++ -c Special.cpp

Casa.o: Casa.cpp Casa.h Edificios.h
	g++ -c Casa.cpp

Cuartel.o:	Cuartel.cpp Cuartel.h Edificios.h
	g++ -c Cuartel.cpp

Castillo.o:	Castillo.cpp Castillo.h Edificios.h
	g++ -c Castillo.cpp

clean:
	rm *.o main.out