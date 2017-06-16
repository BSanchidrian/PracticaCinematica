#include "Misil.h"
#include <complex>
#define PI 3.14159265
#define GRAVEDAD 9.80665

// La posicion inicial del misil es (0,0)
Misil::Misil(const float &velocidad, const float &angulo, const float &tiempoLanzamiento) : Objeto(new Vector2<float>(0, 0))
{
	mVelocidadInicial = velocidad;
	mAnguloLanzamiento = angulo;
	mTiempoLanzamiento = tiempoLanzamiento;
}

float Misil::getTiempo() const
{
	return Objeto::getTiempo() - mTiempoLanzamiento;
}

void Misil::tick()
{
	if (getTiempo() < 0) return;

	// En el eje X => MRU (X = Xo + Vx*t)
	auto Vx = mVelocidadInicial * std::cos(mAnguloLanzamiento * PI / 180);
	mPosicion->setX(static_cast<float>(0 + Vx * getTiempo()));


	// En el eje Y => MRUA (Y = Yo + Voy*t - (1/2)*g*t^2)
	auto Vy = mVelocidadInicial * std::sin(mAnguloLanzamiento * PI / 180);
	auto Y = 0 + Vy * getTiempo() - (GRAVEDAD * powf(getTiempo(), 2)) / 2;
	mPosicion->setY(Y < 0 ? 0 : static_cast<float>(Y));
}
