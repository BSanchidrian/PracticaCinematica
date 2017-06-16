#pragma once
#include "Vector2.h"

/*
 * Clase Abstracta que define un objeto en el espacio
 * Contiene elementos básicos que todos los objetos (cohete/misil en este caso) deben tener, como lo es el tiempo y una posicion
 * Por otro lado una funcion llamada 'tick' que será usada para ejecutar una simulacion del objeto.
 */
class Objeto
{
private:
	clock_t tiempo;
public:
	virtual ~Objeto() = default;

	void setTiempo(const clock_t &t) { tiempo = t; }
	inline clock_t getTiempo() const { return tiempo; }

	virtual Vector2<float> *getPosicion() const = 0;

	virtual void tick() = 0;
};
