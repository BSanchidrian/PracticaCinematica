#include "Misil.h"

// La posicion inicial del misil es (0,0)
Misil::Misil(const float &velocidad, const float &angulo) : Objeto(new Vector2<float>(0, 0))
{
	mVelocidadInicial = velocidad;
	mAnguloLanzamiento = angulo;
	// TODO mTiempo..
	//mTiempoVuelo = clock();
}

void Misil::tick()
{
}
