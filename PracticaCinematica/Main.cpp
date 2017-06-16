#include <iostream>
#include <Windows.h>
#include <string>
#include "Cohete.h"
#include <cstdlib>
#include "Misil.h"

using std::cout;
using std::endl;
using std::cin;

void ClearScreen()
{
	if (system("CLS")) system("clear");
}

int main()
{
	float alturaCohete, velocidadCohete;
	float velocidadInicialMisil, anguloLanzamieto;

	cout << "Altura del cohete a interceptar (m) = ";
	cin >> alturaCohete;

	cout << "Velocidad del cohete (m/s) = ";
	cin >> velocidadCohete;

	cout << "---------------------------------\n";

	cout << "Velocidad inicial del misil (m/s) = ";
	cin >> velocidadInicialMisil;

	cout << "Angulo de lanzamiento del misil (grados) = ";
	cin >> anguloLanzamieto;

	Cohete *cohete = new Cohete(alturaCohete, velocidadCohete);
	Misil *misil = new Misil(velocidadInicialMisil, anguloLanzamieto);

	cout << cohete->getTiempoVuelo();

	while(!GetAsyncKeyState(VK_F1))
	{
		ClearScreen();

		cohete->tick();
		misil->tick();

		printf("COHETE\nPosicion = %.2f m\nTiempo = %d s\n", cohete->getPosicion()->getX(), cohete->getTiempoVuelo());

		//printf("MISIL\nPosicion = %d m\nTiempo = %d s\n", cohete->getPosicion()->getX(), cohete->getTiempoVuelo());

		Sleep(1000);
	}

	return 0;
}