#include "Misil.h"

Misil::Misil(const float &velocidad, const float &angulo)
{
	mVelocidadInicial = velocidad;
	mAnguloLanzamiento = angulo;
	// TODO tiempo..
	//mTiempoVuelo = clock();
}

Misil::~Misil()
{
	delete mPosicion;
}

void Misil::tick()
{
}
