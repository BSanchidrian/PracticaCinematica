#pragma once
#include <ctime>
#include "Objeto.h"
#include "Vector2.h"

class Misil : public Objeto
{
private:
	float mVelocidadInicial;
	float mAnguloLanzamiento;
	clock_t mTiempoVuelo;
	Vector2<float> *mPosicion;
public:
	Misil(const float &velocidad, const float &angulo);

	~Misil();

	void tick() override;

	inline clock_t getTiempoVuelo() const { return (clock() - mTiempoVuelo) / 1000; }
};

