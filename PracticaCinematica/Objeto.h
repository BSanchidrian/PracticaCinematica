#pragma once
#include "Vector2.h"
#include <ctime>

/*
 * Clase Abstracta que define un objeto en el espacio
 * Contiene elementos b�sicos que todos los objetos (cohete/misil en este caso) deben tener, como lo es el tiempo y una posicion
 * Por otro lado una funcion llamada 'tick' que ser� usada para ejecutar una simulacion del objeto.
 */
class Objeto
{
protected:
	clock_t mTiempo;
	Vector2<float> *mPosicion;
public:
	explicit Objeto(Vector2<float> *v): mTiempo(0), mPosicion(v) {}
	virtual ~Objeto()
	{
		delete mPosicion;
	}

	virtual void tick() = 0;

	/*
	 * Getters
	 */
	void setTiempo(const clock_t &t) { mTiempo = t; }
	inline clock_t getTiempo() const { return mTiempo; }

	Vector2<float> *getPosicion() const { return mPosicion; }
};
