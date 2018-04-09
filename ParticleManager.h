#pragma once
#include "ParticleSystem.h";

class ParticleManager
{
private:
	vector<ParticleSystem*> systems;
	int numParticles;

public:
	ParticleManager();
	~ParticleManager();
	void CreateParticleSystems();
	void Update();
	void Draw();
};

