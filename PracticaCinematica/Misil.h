#pragma once
#include <ctime>
#include "Objeto.h"
#include "Vector2.h"

class Misil : public Objeto
{
private:
	float mVelocidadInicial;
	float mAnguloLanzamiento;
public:
	Misil(const float &velocidad, const float &angulo);

	void tick() override;
};

