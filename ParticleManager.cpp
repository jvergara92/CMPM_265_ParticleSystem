#include "ParticleManager.h"



ParticleManager::ParticleManager()
{
	CreateParticleSystems();
}


ParticleManager::~ParticleManager()
{
}


void ParticleManager::CreateParticleSystems()
{
	ParticleSystem* ps0 = new ParticleSystem(Vector2f(800, 600), 0.2, .08, .1);
	ParticleSystem* ps1 = new ParticleSystem(Vector2f(500, 600), 0.1, .02, .05);
	ParticleSystem* ps2 = new ParticleSystem(Vector2f(200, 600), 0.15, .008, .01);
	systems.push_back(ps0);
	systems.push_back(ps1);
	systems.push_back(ps2);
}


void ParticleManager::Update()
{
	for (ParticleSystem* ps : systems) {
		ps->Update();
	}
}


void ParticleManager::Draw() 
{
	for (ParticleSystem* ps : systems) {
		ps->Draw();
	}
}
