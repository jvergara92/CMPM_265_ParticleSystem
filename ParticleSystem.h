#pragma once
#include "Globals.h";
#include "Particle.h";

class ParticleSystem
{
private:
	Vector2f position;
	Vector2f leftBound;
	Vector2f rightBound;
	vector<Particle*> particles;

public:
	ParticleSystem(Vector2f position);
	~ParticleSystem();

	void Update();
	void Draw();
	Particle* CreateParticle();

};

