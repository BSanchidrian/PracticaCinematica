#include "Cohete.h"

Cohete::Cohete(int altura, int velocidad)
{
	mAltura = altura;
	mVelocidad = velocidad;
	mPosicion = 0;	//Supongo que el cohete empieza en la posición x = 0
	mTiempoVuelo = clock();
}

void Cohete::tick()
{
	// V = cte
	// X = Xo + Vt
	mPosicion = 0 + mVelocidad * getTiempoVuelo();
}
