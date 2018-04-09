#include "Particle.h"

Particle::Particle(Vector2f startPos, Vector2f velocity, Vector2f size, Vector2f dir, float lifetime, String tex)
{
	this->position = startPos;
	this->velocity = velocity;
	this->size = size;
	this->dir = dir;
	this->alive = true;
	this->lifetime = lifetime;
	timePassed = 0;

	texture.loadFromFile(tex);
	shape.setSize(size);
	shape.setPosition(startPos);
	shape.setTexture(&texture);
	shape.setOrigin(size.x / 2, size.y / 2);
}

Particle::Particle(Vector2f startPos, Vector2f velocity, Vector2f size, Vector2f dir, float lifetime, String tex, String scale, String speedChange)
{
	this->position = startPos;
	this->startVelocity = this->velocity = velocity;
	this->startSize = this->size = size;
	this->dir = dir;
	this->alive = true;
	this->lifetime = lifetime;
	this->dScale = scale;
	this->dVelocity = speedChange;
	timePassed = 0;
	
	texture.loadFromFile(tex);
	shape.setSize(size);
	shape.setPosition(startPos);
	shape.setTexture(&texture);
	shape.setOrigin(size.x / 2, size.y / 2);

	if (scale == "grow") {
		this->endSize = size * 2.0f;
	}
	else if (scale == "shrink") {
		this->endSize = size * 0.5f;
	}

	if (speedChange == "fast") {
		this->endVelocity = velocity * 2.0f;
	}
	else if (speedChange == "slow") {
		this->endVelocity = velocity * 0.5f;
	}
}


Particle::~Particle()
{
}


void Particle::Update() 
{
	if (dScale != "") {
		Vector2f size = startSize + ((lifetime - timePassed) / lifetime)*endSize;
		shape.setSize(size);
	}
	if (dVelocity != "") {
		Vector2f vel = startVelocity + ((lifetime - timePassed) / lifetime)*endVelocity;
		velocity = vel;
	}
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
