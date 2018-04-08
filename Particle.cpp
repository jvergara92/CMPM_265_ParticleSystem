#include "Particle.h"



Particle::Particle(Vector2f startPos, Vector2f velocity, Vector2f size, Vector2f dir, float lifetime)
{
	this->position = startPos;
	this->velocity = velocity;
	this->size = size;
	this->dir = dir;
	this->alive = true;
	this->lifetime = lifetime;
	timePassed = 0;
	
	shape.setSize(size);
	shape.setPosition(startPos);
	shape.setFillColor(Color::Red);
	shape.setOrigin(size.x / 2, size.y / 2);
}


Particle::~Particle()
{
}


void Particle::Update() 
{
	shape.move(Vector2f(dir.x * velocity.x, dir.y * velocity.y));
	float dt = clock.restart().asSeconds();
	timePassed += dt;
	if (timePassed >= lifetime)
		alive = false;
}


void Particle::Draw() 
{
	window.draw(shape);
}


bool Particle::isDead() 
{
	return !alive;
}
