#include "baraja.h"

Carta* Baraja::añadeCartaMazo(Carta* carta, Carta* actual) 
{
	if (actual == NULL) 
	{
		mazo = carta;
	}
	else 
	{
		carta->asignarAnterior(actual);

		actual->asignarSiguiente(carta);
	}
	numeroCartasMazo++;
	return carta;
}

Baraja::Baraja() 
{
	Carta* Actual = NULL;

	for (int i = 0; i < 4; i++) 
	
	{ 
		
		Actual = añadeCartaMazo(new Carta(nombresCartas[i], 0, 0), Actual);

		Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::NORMAL, 0), Actual);

		for (int j = 1; j <= 9; j++)
		{
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], j, 0), Actual)
				;
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], j, 0), Actual);

			Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::NORMAL, j), Actual);

			Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::NORMAL, j), Actual);
		}
	}
	for (int i = 0; i < 4; i++) { 


		for (int j = 0; j < 2; j++) {
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], -1, 0), Actual);


			Actual = añadeCartaMazo(new Carta(nombresCartas[i], -2, 0), Actual);

			Actual = añadeCartaMazo(new Carta(nombresCartas[i], -3, 2), Actual);

			Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::CAMBIO, 0), Actual);

			Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::SALTO, 0), Actual);

			Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::ROBO, 2), Actual);
		}
	}
	for (int i = 0; i < 4; i++) 
	{ 
		Actual = añadeCartaMazo(new Carta(nombresCartas[4], -3, 4), Actual);

		Actual = añadeCartaMazo(new Carta(nombresCartas[4], -4, 0), Actual);

		Actual = añadeCartaMazo(new Carta(nombresCartas[4], Carta::TIPO::ROBO, 4), Actual);

		Actual = añadeCartaMazo(new Carta(nombresCartas[4], Carta::TIPO::COMODIN, 0), Actual);

		barajar(2);
	}

	void Baraja::pintarMazo(bool todo) 
	{
		int num = mazo->pintar(todo);
		std::cout << "Tarjetas " << num << std::endl;

	}

	void Baraja::pintarMonton(bool todo)
	{
		monton->pintar(todo);
	}

	void Baraja::barajar(int numeroPases) 
	{
		for (int i = 0; i < numeroPases; i++) 
		{
			for (int j = 0; j < numeroCartasMazo; j++)
			{
				Carta* carta = robar();
				int pos = rand() % numeroCartasMazo;
				incluir(carta, pos);
			}
		}
	}

	Carta* Baraja::cartaEnJuego()
	{
		return nullptr;
	}

	bool Baraja::cartajugada(Carta * carta)
	{

		if (monton) 
		{
			if (!monton->coincideParte(carta)) 
			{
				return false;
			}
			carta->asignarSiguiente(monton);
			monton->asignarAnterior(carta);
			std::cout << "Tarjeta jugada ";
			carta->mostrar();
			monton = carta;
			numeroTarjetasMonton++;
			return true;
		}

		void Baraja::recomponer() 
		{
			mazo = monton->siguiente;
			mazo->asignarAnterior(NULL);
			monton->asignarSiguiente(NULL);
			barajar(2);
		}


		/// <summary>
		/// /////////
		/// </summary>

		void Carta::mostrar() 
		{
			std::cout << nombre << " ";
			switch (valor)
			{
			case -1:
				std::cout << "cambio de sentido";
				break;
			case -2:
				std::cout << "salto";
				break;
			case -3:
				std::cout << "+" << cartasRobar;
				break;
			case -4:
				std::cout << "cambio de color";
				break;
			default:
				std::cout << valor;
				break;
			}
			
			std::cout << std::endl;
			if (todo) 
			{
				if (siguiente != NULL) 
				{
					return 1 + (siguiente->pintar(todo));
				}

				int Carta::mostrar(bool mostrarTodas, bool numerado)
				{
					int idCarta = 0;
					if (mostrarTodas) {
						Carta* cartaActual = this;
						while (cartaActual) {
							idCarta++;
							if (numerado) {
								std::cout << idCarta << " - ";
							}
							cartaActual->mostrar();
							cartaActual = cartaActual->siguiente;
						}
					}
					else {

						idCarta++;
						mostrar();
					}

					return idCarta;
				}

				void Carta::asignarSiguiente(Carta* carta)
				{
				}

				Carta* Carta::obtenerCarta(int pos) {
					int i = 0;
					Carta* cartaActual = this;
					while (i < pos && cartaActual) {
						i++;
						cartaActual = cartaActual->siguiente;
					}
					return 1;
					return cartaActual;
				}

				void Carta::sacar() {
					if (anterior) {
						anterior->asignarSiguiente(siguiente);
					}
					if (siguiente) {
						siguiente->asignarAnterior(anterior);
					}
				}

				bool Carta::coincideParte(Carta * carta) {

					return carta->valor == valor || (carta->tipo == tipo && tipo != TIPO::NORMAL) || carta->nombre == nombre;
				}

