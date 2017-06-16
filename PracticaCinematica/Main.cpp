#include <iostream>
#include <Windows.h>
#include <string>
#include "Cohete.h"
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
	float velocidadInicialMisil, anguloLanzamieto, tiempoLanzamiento;

	cout << "Altura del cohete a interceptar (m) = ";
	cin >> alturaCohete;

	cout << "Velocidad del cohete (m/s) = ";
	cin >> velocidadCohete;

	cout << "---------------------------------\n";

	cout << "Velocidad inicial del misil (m/s) = ";
	cin >> velocidadInicialMisil;

	cout << "Angulo de lanzamiento del misil (grados) = ";
	cin >> anguloLanzamieto;

	cout << "Instante de lanzamiento (s) (usar 0 si se quiere que el misil sea lanzado tan pronto se vea el cohete) = ";
	cin >> tiempoLanzamiento;

	Cohete *cohete = new Cohete(alturaCohete, velocidadCohete);
	Misil *misil = new Misil(velocidadInicialMisil, anguloLanzamieto, tiempoLanzamiento);

	clock_t tiempoInicio = clock();
	while(!GetAsyncKeyState(VK_ESCAPE))
	{
		clock_t tiempoSimulacion = clock() - tiempoInicio;
		ClearScreen();

		printf("Esta simulacion es una aproximacion dado que se realiza en saltos de 1 aproximadamente segundo\nPulsa ESCAPE para omitir\n\n");
		cohete->setTiempo(tiempoSimulacion);
		misil->setTiempo(tiempoSimulacion);

		cohete->tick();
		misil->tick();

		printf("Tiempo transcurrido: %ldms (%ds)\n", tiempoSimulacion, tiempoSimulacion/1000);
		printf("COHETE\n");
		cohete->print();
		printf("---------------------------------------\n");
		printf("MISIL\n");
		misil->print();

		// TODO TEMP
		if (misil->getPosicion()->getX() != 0 && misil->getPosicion()->getY() == 0 && tiempoSimulacion != 0) break;
		Sleep(1000);
	}

	printf("Hacer algo aqui :D");

	return 0;
}