#pragma once
#include "ParticleSystem.h";

class ParticleManager
{
public:
	vector<ParticleSystem*> systems;

public:
	ParticleManager();
	~ParticleManager();
	void CreateParticleSystems();
	void Update();
	void Draw();
};

