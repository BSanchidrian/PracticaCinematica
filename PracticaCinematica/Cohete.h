#pragma once
#include <ctime>
#include "Objeto.h"

class Cohete : public Objeto
{
private:
	int mAltura;
	int mVelocidad;
	int mPosicion;
	clock_t mTiempoVuelo;
public:
	Cohete(const int &altura, const int &velocidad);

	void tick() override;

	inline int getAltura() const { return mAltura; }

	inline int getVelocidad() const { return mVelocidad; }

	inline int getPosicion() const { return mPosicion; }

	inline clock_t getTiempoVuelo() const { return (clock() - mTiempoVuelo)/1000; }
};

