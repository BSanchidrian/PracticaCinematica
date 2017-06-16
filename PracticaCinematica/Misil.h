#pragma once
#include <ctime>
#include "Objeto.h"

class Misil : public Objeto
{
private:
	int mVelocidadInicial;
	int mAnguloLanzamiento;
	clock_t mTiempoVuelo;
public:
	Misil(int velocidad, int angulo);

	void tick() override;

	inline clock_t getTiempoVuelo() const { return (clock() - mTiempoVuelo) / 1000; }
};

