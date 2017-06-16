#include "Cohete.h"

//Supongo que el cohete empieza en la posición x = 0
Cohete::Cohete(const float &altura, const float &velocidad) : Objeto(new Vector2<float>(0, altura))
{
	mVelocidad = velocidad;
}

void Cohete::tick()
{
	// V = cte
	// X = Xo + Vt
	mPosicion->setX(0 + mVelocidad * getTiempo()/1000);
}
