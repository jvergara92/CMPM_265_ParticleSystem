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
	float minVel, maxVel;
	float particleSize;
	int tex;
	RectangleShape textureReference;
	float keyboardCooldown, keyboardTimePassed;

public:
	ParticleSystem(Vector2f position, float emitRate, float particleSize, float minVelocity, float maxVelocity, int tex);
	~ParticleSystem();

	void Update();
	void Draw();
	Particle* CreateParticle();
	Vector2f Normalize(Vector2f n);
	void ClearDeadParticles();
	int numParticles();

};

