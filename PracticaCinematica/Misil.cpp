#include "Misil.h"
#include <complex>
#include <cassert>
#define PI 3.14159265
#define GRAVEDAD 9.80665

// La posicion inicial del misil es (0,0)
Misil::Misil(const float &velocidad, const float &angulo, const float &tiempoLanzamiento) : Objeto(new Vector2<float>(0, 0))
{
	mVelocidadInicial = velocidad;
	mAnguloLanzamiento = angulo;
	mTiempoLanzamiento = tiempoLanzamiento;
}

//TODO
bool Misil::colisiona(const Cohete& cohete) const
{
	auto Vx = mVelocidadInicial * std::cos(mAnguloLanzamiento * PI / 180);
	auto tiempoColision = -(Vx * mTiempoLanzamiento) / static_cast<float>(cohete.getVelocidad() - Vx);
	printf("TIEMPO DE COLISION = %f\n", tiempoColision);

	// 1º Comprobar que las X son iguales { Vc * t = Vmx * (t - tl) } tl = tiempo lanzamiento
	

	// 2º Comprobar la Y { Y = h = tg a * Xc - (g * Xc^2)/(2 * Vm^2 * Cos^2 a) }
	auto Vy = mVelocidadInicial * std::sin(mAnguloLanzamiento * PI / 180);
	auto y = std::tan(mAnguloLanzamiento * PI / 180) * cohete.getPosicion()->getX() - (GRAVEDAD * powf(cohete.getPosicion()->getX(), 2)) / (2 * powf(Vy, 2)*powf(std::cos(mAnguloLanzamiento * PI / 180), 2));

	return cohete.getPosicion()->getY() == y;
}

float Misil::getTiempo() const
{
	return Objeto::getTiempo() - mTiempoLanzamiento;
}

void Misil::tick()
{
	// Si existe un tiempo de lanzamiento, hasta que este haya pasado los valores generados aqui serán erroneos así que los omitimos.
	if (getTiempo() < 0) return;

	// En el eje X => MRU (X = Xo + Vx*t)
	auto Vx = mVelocidadInicial * std::cos(mAnguloLanzamiento * PI / 180);
	mPosicion->setX(static_cast<float>(0 + Vx * getTiempo()));


	// En el eje Y => MRUA (Y = Yo + Voy*t - (1/2)*g*t^2)
	auto Vy = mVelocidadInicial * std::sin(mAnguloLanzamiento * PI / 180);
	auto Y = 0 + Vy * getTiempo() - (GRAVEDAD * powf(getTiempo(), 2)) / 2;
	mPosicion->setY(Y < 0 ? 0 : static_cast<float>(Y));
}
