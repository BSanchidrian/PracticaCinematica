#pragma once
#include <tuple>

/*
 * Clase usada para almacenar la variable X e Y de la posición (principalmente)
 * Referencia: https://codereview.stackexchange.com/questions/26608/review-of-2d-vector-class
 */
template <typename T>
class Vector2
{
private:
	T mX;
	T mY;
public:
	Vector2() : mX(T(0)), mY(T(0)) {}

	Vector2(const T& x, const T& y) : mX(x), mY(y) {}

	void setX(const T &x) { mX = x; }
	void setY(const T &y) { mY = y; }

	inline T getX() const { return mX; }
	inline T getY() const { return mY; }

	Vector2 & operator+=(const Vector2 &v) { mX += v.mX; mY += v.mY; return *this; }
	Vector2 & operator-=(const Vector2 &v) { mX -= v.mX; mY -= v.mY; return *this; }
	Vector2 & operator*=(const Vector2 &v) { mX *= v.mX; mY *= v.mY; return *this; }
	Vector2 & operator/=(const Vector2 &v) { mX /= v.mX; mY /= v.mY; return *this; }

	friend bool operator==(const Vector2 &l, const Vector2 &r) { return std::tie(l.mX, l.mY) == std::tie(r.mX, r.mY); }
};

