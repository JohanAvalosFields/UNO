#include "player.h"


void Jugador::robarCartas(int numeroCartas) {
	
	
	for (int i = 0; i < numeroCartas; i++) {
		
		
		Carta* carta = mazo->robar();
		carta->asignarSiguiente(mano);
		if (mano) {
			mano->asignarAnterior(carta);
			robarCarta();
		}
	}
	int Jugador::jugarMaquina() {
		
		int iCarta = 0;
		
		bool sigueJugando = true;
		
		Carta* cartaEnMesa = mesa->cartaEnJuego();
		
		Carta* cartaActual = mano;
		
		while (sigueJugando) {
			
			
			if (cartaActual) {
				
				if (cartaActual->coincideParte(cartaEnMesa)) {
					
					
					if (cartaActual == mano) {
						mano = cartaActual->siguiente;
					}
					
					cartaActual->sacar();
					
					mesa->cartaJugada(cartaActual);
					
					numeroCartasEnMano--;
					
					sigueJugando = false;
				}
				else {
					cartaActual = cartaActual->siguiente;
				}
			}
			else {
				robarCarta();
				
				cartaActual = mano;
			}
			mano = carta;
		}
		return numeroCartasEnMano;

	}

	void Jugador::robarCarta()
	{
		
		
		Carta* carta = mesa->robar();
		
		carta->asignarSiguiente(mano);
		
		if (mano) 
		{
			mano->asignarAnterior(carta);
		}
		mano = carta;
		numeroCartasEnMano++;
	}
	int Jugador::jugarHumano()
	{


		Jugador::Jugador(std::string nombre, char tipo, Baraja * mazo) 
		{
			bool enJuego = true;
			while (enJuego) 
			{
				mostrarMano();
				Carta* carta = mesa->cartaEnJuego();
				if (carta == NULL) {
					return 0;
				}
				std::cout << "Carta en la mesa: ";
				carta->mostrar();
				std::cout << "�Carta a tirar?[1-" << numeroCartasEnMano << "](0 para Robar):";

				int idCartaJugar = -1;
				while (idCartaJugar<0 || idCartaJugar>numeroCartasEnMano) {
					std::cin >> idCartaJugar;
				}

				//Buscamos la carta
				idCartaJugar--;
				if (idCartaJugar >= 0) 
				{
					enJuego = false;
					Carta* cartaAJugar = mano->obtenerCarta(idCartaJugar);
					if (cartaAJugar)
					{
						if (cartaAJugar == mano) 
						{
							mano = cartaAJugar->siguiente;
						}
						cartaAJugar->sacar();

						enJuego = !mesa->cartaJugada(cartaAJugar);
						if (enJuego) 
						{
							std::cout << "Carta no v�lida\r\n ";
							cartaAJugar->asignarSiguiente(mano);
							mano->asignarAnterior(cartaAJugar);
							mano = cartaAJugar;

						}
						else 
						{
							numeroCartasEnMano--;
						}
					}

				}
				else if (idCartaJugar == -1) 
				{
					robarCarta();
				}
			}

			return numeroCartasEnMano;
		}

		Jugador::Jugador(std::string nombre, char tipo, Baraja * mesa) {
			this->nombre = nombre;
			this->tipo = tipo;
			this->mazo = mazo;
			robarCartas(7);
			this->mesa = mesa;
		}

		void Jugador::mostrarMano() 
		
		{
			int num = 0;
			if (mano) {
				num = mano->pintar(true);
				num = mano->mostrar(true, true);
			}
			std::cout << "Cartas " << num << std::endl;
		}

		void Jugador::jugar() 
		
		{
			int Jugador::jugar()
			
			{
				int resultado = 0;
				switch (tipo)
				
				{
				case 'M':
					jugarCarta();
					resultado = jugarMaquina();
					break;
				case 'H':
					mostrarMano();
					resultado = jugarHumano();
					break;
				}
				return resultado;
			}