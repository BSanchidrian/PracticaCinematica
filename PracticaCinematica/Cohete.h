#pragma once
#include <ctime>
#include "Objeto.h"
#include "Vector2.h"

class Cohete : public Objeto
{
private:
	float mVelocidad;
	Vector2<float> *mPosicion;
	clock_t mTiempoVuelo;
public:
	Cohete(const float &altura, const float &velocidad);

	~Cohete();

	void tick() override;

	inline float getVelocidad() const { return mVelocidad; }

	inline Vector2<float> *getPosicion() const override { return mPosicion; }

	inline clock_t getTiempoVuelo() const { return (clock() - mTiempoVuelo)/1000; }
};

