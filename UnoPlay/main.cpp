#include <iostream>
#include "baraja.h"
#include "player.h"
void main(int narg, char* arg)
{
	Baraja baraja;


	int numeroJugadores = 2;
	int cartasRoboInicial = 7;
	int numeroJugadores = 10;

	Jugador** jugadores = new Jugador * [numeroJugadores]();

	jugadores[0] = new Jugador("Ray", 'H', &baraja);
	jugadores[1] = new Jugador("Maquina 1", 'M', &baraja);
	std::cout << "Ray" << std::endl;
	for (int i = 1; i < numeroJugadores; i++) 
	{
		jugadores[i] = new Jugador("Maquina " + i, 'M', &baraja);
	}

	for (int i = 0; i < cartasRoboInicial; i++) 
	{
		for (int iJugador = 0; iJugador < numeroJugadores; iJugador++) 
		{
			jugadores[iJugador]->robarCarta();
		}

	}


	
	baraja.cartaJugada(baraja.robar());

	

	bool siguePartida = true;
	while (siguePartida) {
		for (int iJugador = 0; iJugador < numeroJugadores && siguePartida; iJugador++) 
		{
			std::cout << "\r\nEsta jugando " << jugadores[iJugador]->nombre << std::endl;
			std::cout << "\r\nQuedan en mazo " << baraja.quedanMazo() << std::endl;
			int leQuedan = jugadores[iJugador]->jugar();
			if (leQuedan == 0) 
			{
				std::cout << "\r\nHa ganado " << jugadores[iJugador]->nombre << std::endl;
				siguePartida = false;
			}
			else 
			{
				std::cout << "\r\nLe quedan  " << leQuedan << std::endl;
			};
			if (siguePartida && baraja.quedanMazo() == 0) {
				baraja.recomponer();
			}
		}
	}


	for (int i = 0; i < numeroJugadores; i++)
	{

		if (jugadores[i]) {
			delete jugadores[i];
		}
	}
	delete[] jugadores;
}