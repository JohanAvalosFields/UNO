#pragma once
#include <string>
#include "baraja.h"
class Jugador 
{



	std::string nombre;


public: std::string nombre;

	  char tipo = 'M';
	  Carta* mano = NULL;
	  Baraja* mazo;
	  Baraja* mesa;
	  int numeroCartasEnMano = 0;
	  void robarCartas(int numeroCartas);
	  void jugarCarta();
	  int jugarMaquina();
	  int jugarHumano();


public:
	
	Jugador(std::string nombre, char tipo, Baraja* mazo);
	Jugador(std::string nombre, char tipo, Baraja* mesa);
	void mostrarMano();
	void jugar();

	
	
	
	int jugar();
	void robarCarta();

};
