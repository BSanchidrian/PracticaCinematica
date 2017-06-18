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

	void tick() override;

	float getTiempo() const override;

	inline float getVelocidadInicial() const { return mVelocidadInicial; }
	inline float getAngulo() const { return mAnguloLanzamiento; }
	inline float getTiempoLanzamiento() const { return mTiempoLanzamiento; }
};

