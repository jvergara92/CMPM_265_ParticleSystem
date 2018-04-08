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
	float lifetime;
	float timePassed;
	Clock clock;
	bool alive;
	Texture texture;

public:

	Particle(Vector2f startPos, Vector2f velocity, Vector2f size, Vector2f dir, float lifetime, String tex);
	~Particle();
	void Update();
	void Draw();
	bool isDead();
};

