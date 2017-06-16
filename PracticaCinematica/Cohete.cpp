#include "Cohete.h"

Cohete::Cohete(const float &altura, const float &velocidad)
{
	mVelocidad = velocidad;
	mPosicion = new Vector2<float>(0, altura);	//Supongo que el cohete empieza en la posición x = 0
}

Cohete::~Cohete()
{
	delete mPosicion;
}

void Cohete::tick()
{
	// V = cte
	// X = Xo + Vt
	mPosicion->setX(0 + mVelocidad * getTiempo());
}
