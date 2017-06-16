#pragma once
#include <ctime>
#include "Objeto.h"
#include "Vector2.h"

class Misil : public Objeto
{
private:
	float mVelocidadInicial;
	float mAnguloLanzamiento;
	float mTiempoLanzamiento;
public:
	Misil(const float &velocidad, const float &angulo, const float &tiempoLanzamiento);


	float getTiempo() const override;
	void tick() override;
};

