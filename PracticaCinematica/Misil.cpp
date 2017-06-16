#include "Misil.h"

Misil::Misil(int velocidad, int angulo)
{
	mVelocidadInicial = velocidad;
	mAnguloLanzamiento = angulo;
	// TODO tiempo..
	//mTiempoVuelo = clock();
}

void Misil::tick()
{
}
