#pragma once
#include "Objeto.h"

class Cohete : public Objeto
{
private:
	float mVelocidad;
public:
	Cohete(const float &altura, const float &velocidad);

	/*
	 * Funcion para la simulacion de este objeto
	 */
	void tick() override;

	/*
	 * Getters
	 */
	inline float getVelocidad() const { return mVelocidad; }
};

