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

bool Misil::colisiona(const Cohete& cohete) const
{
	// TODO añadir la opcion del rozamiento..
	auto Vx = mVelocidadInicial * std::cos(mAnguloLanzamiento * PI / 180);
	auto Vy = mVelocidadInicial * std::sin(mAnguloLanzamiento * PI / 180);

	// 1º Calcular el tiempo en el que el misil alcanza la altura H del cohete
	// Como el movimiento del misil es una parabola, existen dos tiempos en los que la Y es igual a la altura. Cuando sube y cuando baja.
	auto tiempoColision1 = ((-Vy + sqrtf(powf(Vy, 2) - 2 * GRAVEDAD * cohete.getPosicion()->getY())) / -GRAVEDAD) + mTiempoLanzamiento;
	auto tiempoColision2 = ((-Vy - sqrtf(powf(Vy, 2) - 2 * GRAVEDAD * cohete.getPosicion()->getY())) / -GRAVEDAD) + mTiempoLanzamiento;

	printf("TIEMPO DE COLISION = %f\n", tiempoColision1);
	printf("TIEMPO DE COLISION = %f\n", tiempoColision2);

	// 2º Comprobar que las X son iguales
	int xCohete = cohete.getVelocidad() * tiempoColision1;
	int xMisil = Vx * (tiempoColision1 - mTiempoLanzamiento);
	
	printf("Xc = %d\nXm = %d\n", xCohete, xMisil);
	// Supongamos un margen de error de 1 metro..
	if (abs(xCohete - xMisil) <= 1) return true;

	// Puede ser que el impacto se realice cuando el misil cae
	xCohete = cohete.getVelocidad() * tiempoColision2;
	xMisil = Vx * (tiempoColision2 - mTiempoLanzamiento);
	printf("Xc = %d\nXm = %d\n", xCohete, xMisil);

	if (abs(xCohete - xMisil) <= 1) return true;

	// Se supone que no colisiona
	return false;
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
