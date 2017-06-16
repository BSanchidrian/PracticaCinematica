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
	Misil(const int &velocidad, const int &angulo);

	void tick() override;

	inline clock_t getTiempoVuelo() const { return (clock() - mTiempoVuelo) / 1000; }
};

