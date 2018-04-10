#pragma once
#include "Globals.h";
class Particle
{
private:
	Vector2f position;
	Vector2f dir;
	Vector2f velocity;
	RectangleShape shape;
	Vector2f size;
	Vector2f startVelocity, startSize;
	Vector2f endVelocity, endSize;
	String dScale, dVelocity;
	float lifetime;
	float timePassed;
	Clock clock;
	bool alive;

public:
	Particle(Vector2f startPos, Vector2f velocity, Vector2f size, Vector2f dir, float lifetime, int tex);
	Particle(Vector2f startPos, Vector2f velocity, Vector2f size, Vector2f dir, float lifetime, int tex, String scale, String speedChange);
	~Particle();
	void Update();
	void Draw();
	bool isDead();
};

