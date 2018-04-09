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
	ParticleSystem* ps0 = new ParticleSystem(Vector2f(800, 500), 0.2, 20, .6, .9, "Sprites/bubble.png");
	ParticleSystem* ps1 = new ParticleSystem(Vector2f(500, 500), 0.1, 20, .3, .5, "Sprites/bubble.png");
	ParticleSystem* ps2 = new ParticleSystem(Vector2f(200, 500), 0.15, 75, .4, .8, "Sprites/water.png");
	ParticleSystem* ps3 = new ParticleSystem(Vector2f(800, 500), 0.2, 20, .6, .9, "Sprites/bubble.png");
	ParticleSystem* ps4 = new ParticleSystem(Vector2f(500, 500), 0.1, 100, .3, .5, "Sprites/smoke.png");
	ParticleSystem* ps5 = new ParticleSystem(Vector2f(200, 500), 0.15, 75, .4, .8, "Sprites/water.png");
	ParticleSystem* ps6 = new ParticleSystem(Vector2f(800, 500), 0.2, 20, .6, .9, "Sprites/bubble.png");
	ParticleSystem* ps7 = new ParticleSystem(Vector2f(500, 500), 0.1, 100, .3, .5, "Sprites/smoke.png");
	ParticleSystem* ps8 = new ParticleSystem(Vector2f(200, 500), 0.15, 75, .4, .8, "Sprites/water.png");
	systems.push_back(ps0);
	systems.push_back(ps4);
	systems.push_back(ps2);
	//systems.push_back(ps3);
	//systems.push_back(ps6);
	/*systems.push_back(ps5);
	systems.push_back(ps6);
	systems.push_back(ps7);
	systems.push_back(ps8);*/
}


void ParticleManager::Update()
{
	numParticles = 0;
	for (ParticleSystem* ps : systems) {
		ps->Update();
		numParticles += ps->numParticles();
	}
	cout << "Total number of particles: " << numParticles << endl;
}


void ParticleManager::Draw() 
{
	for (ParticleSystem* ps : systems) {
		ps->Draw();
	}
}
