#include "ParticleSystem.h"



ParticleSystem::ParticleSystem(Vector2f position)
{
	this->position = position;
	this->leftBound = Vector2f(position.x - 50, position.y - 50);
	this->rightBound = Vector2f(position.x + 50, position.y - 50);
}


ParticleSystem::~ParticleSystem()
{
}


void ParticleSystem::Update() 
{
	for (Particle* p : particles) {
		p->Update();
		/*if (p->isDead) {
			delete p;
			p = CreateParticle();
		}*/
	}
}


void ParticleSystem::Draw() 
{
	for (Particle* p : particles) {
		p->Draw();
	}
}


Particle* ParticleSystem::CreateParticle() 
{

}
