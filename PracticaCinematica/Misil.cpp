#include "Misil.h"
#include <complex>
#define PI 3.14159265
#define GRAVEDAD 9.80665

// La posicion inicial del misil es (0,0)
Misil::Misil(const float &velocidad, const float &angulo) : Objeto(new Vector2<float>(0, 0))
{
	mVelocidadInicial = velocidad;
	mAnguloLanzamiento = angulo;
}

void Misil::tick()
{
	auto tempTiempo = getTiempo() / static_cast<float>(1000);

	// En el eje X => MRU (X = Xo + Vx*t)
	auto Vx = mVelocidadInicial * std::cos(mAnguloLanzamiento * PI / 180);
	mPosicion->setX(static_cast<float>(0 + Vx * tempTiempo));


	// En el eje Y => MRUA (Y = Yo + Voy*t - (1/2)*g*t^2)
	auto Vy = mVelocidadInicial * std::sin(mAnguloLanzamiento * PI / 180);
	auto Y = 0 + Vy * tempTiempo - (GRAVEDAD * powf(tempTiempo, 2)) / 2;
	mPosicion->setY(Y < 0 ? 0 : static_cast<float>(Y));
}
