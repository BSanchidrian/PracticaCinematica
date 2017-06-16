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
	//Misil *misil = new Misil(velocidadInicialMisil, anguloLanzamieto);

	clock_t tiempoInicio = clock();
	while(!GetAsyncKeyState(VK_F1))
	{
		clock_t tiempo = clock() - tiempoInicio;
		ClearScreen();

		cohete->setTiempo(tiempo);
		cohete->tick();
		//misil->tick();

		printf("COHETE\nPosicion = %.2fm\nTiempo = %ds (%dms)\n", cohete->getPosicion()->getX(), cohete->getTiempo() / 1000, cohete->getTiempo());

		//printf("MISIL\nPosicion = %d m\nTiempo = %d s\n", cohete->getPosicion()->getX(), cohete->getTiempoVuelo());

		Sleep(1000);
	}

	return 0;
}