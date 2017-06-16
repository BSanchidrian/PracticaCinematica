#pragma once
class Objeto
{
public:
	virtual float getPosition();
	virtual void tick() = 0;
};
