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

/*
 * Hay que añadir un "tiempoLanzamiento" al misil, de forma que:
 * Cohete	= tiempoAvistamiento
 * Misil	= tiempoAvistamiento + tiempoLanzamiento
 * 
 * De esa forma el instante de tiempo en el que se encuentren será el mismo (al igual que X e Y)
 * Si el misil se lanza tan pronto se avista el cohete seria tiempoAvistamiento + 0 (Es tal y como esta programado ahora mismo)
 * 
 * Igual es buena idea cambiar el metodo getTime a virtual para implementarlo segun convenga en cada clase 
 */

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

	clock_t tiempoInicio = clock();
	while(!GetAsyncKeyState(VK_ESCAPE))
	{
		clock_t tiempo = clock() - tiempoInicio;
		ClearScreen();

		printf("Esta simulacion es una aproximacion dado que se realiza en saltos de 1 aproximadamente segundo\nPulsa ESCAPE para omitir\n\n");
		cohete->setTiempo(tiempo);
		misil->setTiempo(tiempo);

		cohete->tick();
		misil->tick();

		printf("Tiempo transcurrido: %ldms (%ds)\n", tiempo, tiempo/1000);
		printf("COHETE\n");
		cohete->print();
		printf("---------------------------------------\n");
		printf("MISIL\n");
		misil->print();

		if (misil->getPosicion()->getY() == 0 && tiempo != 0) break;
		Sleep(1000);
	}

	printf("Hacer algo aqui :D");

	return 0;
}