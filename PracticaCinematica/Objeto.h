#pragma once
#include "Vector2.h"
#include <ctime>

/*
 * Clase Abstracta que define un objeto en el espacio
 * Contiene elementos básicos que todos los objetos (cohete/misil en este caso) deben tener, como lo es el tiempo y una posicion
 * Por otro lado una funcion llamada 'tick' que será usada para ejecutar una simulacion del objeto.
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

	void print() const
	{
		printf("Posicion {\n");
		printf("\tX = %.2fm\n", getPosicion()->getX());
		printf("\tY = %.2fm\n", getPosicion()->getY());
		printf("}\n");
	}

	/*
	 * Getters
	 */
	void setTiempo(const clock_t &t) { mTiempo = t; }
	virtual float getTiempo() const { return mTiempo / static_cast<float>(1000); }

	Vector2<float> *getPosicion() const { return mPosicion; }
};
