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
	String tex;
	RectangleShape textureReference;

public:
	ParticleSystem(Vector2f position, float emitRate, float particleSize, float minVelocity, float maxVelocity, String textureFile);
	~ParticleSystem();

	void Update();
	void Draw();
	Particle* CreateParticle();
	Vector2f Normalize(Vector2f n);
	void ClearDeadParticles();

};

