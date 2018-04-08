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
	Clock clock;
	float emitRate;
	float timePassed;

public:
	ParticleSystem(Vector2f position, float emitRate);
	~ParticleSystem();

	void Update();
	void Draw();
	Particle* CreateParticle();
	Vector2f Normalize(Vector2f n);
	void ClearDeadParticles();

};

