#pragma once
#include <ctime>
#include "Objeto.h"
#include "Vector2.h"
#include "Cohete.h"

class Misil : public Objeto
{
private:
	float mVelocidadInicial;
	float mAnguloLanzamiento;
	float mTiempoLanzamiento;
public:
	Misil(const float &velocidad, const float &angulo, const float &tiempoLanzamiento);

	bool colisiona(const Cohete &cohete) const;

	void tick() override;

	float getTiempo() const override;
};

