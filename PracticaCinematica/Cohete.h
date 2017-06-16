#pragma once
#include <ctime>
#include "Objeto.h"
#include "Vector2.h"

class Cohete : public Objeto
{
private:
	float mVelocidad;
	Vector2<float> *mPosicion;
public:
	Cohete(const float &altura, const float &velocidad);
	~Cohete();

	/*
	 * Funcion para la simulacion de este objeto
	 */
	void tick() override;

	/*
	 * Getters
	 */
	inline float getVelocidad() const { return mVelocidad; }
	inline Vector2<float> *getPosicion() const override { return mPosicion; }
};

