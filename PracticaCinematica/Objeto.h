#pragma once
#include "Vector2.h"

/*
 * Clase Abstracta que define un objeto en el espacio
 */
class Objeto
{
public:
	virtual Vector2<float> *getPosicion() const = 0;

	virtual void tick() = 0;
};
