#include "ParticleSystem.h"



ParticleSystem::ParticleSystem(Vector2f position, float emitRate)
{
	this->position = position;
	this->leftBound = Vector2f(position.x - 50, position.y - 100);
	this->rightBound = Vector2f(position.x + 50, position.y - 100);
	this->emitRate = emitRate;
}


ParticleSystem::~ParticleSystem()
{
}


void ParticleSystem::Update() 
{

	float dt = clock.restart().asSeconds();
	timePassed += dt;

	for (Particle* p : particles) {
		p->Update();
	}

	ClearDeadParticles();

	if (timePassed > emitRate) {
		particles.push_back(CreateParticle());
		timePassed = 0;
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
	Vector2f velocity = Vector2f(.04, .04);
	Vector2f size = Vector2f(3, 3);
	int xMin = leftBound.x;
	int xMax = rightBound.x - leftBound.x;
	Vector2f dir = Vector2f(rand() % xMin + xMax, rightBound.y) - position;
	dir = Normalize(dir);
	return new Particle(this->position, velocity, size, dir, rand() % 1 + 2);
}


Vector2f ParticleSystem::Normalize(Vector2f n) {
	float length = sqrtf(n.x * n.x + n.y * n.y);
	Vector2f v;
	v.x = n.x / length;
	v.y = n.y / length;
	return v;
}


void ParticleSystem::ClearDeadParticles() {
	Particle* p;
	for (auto it = particles.begin(); it != particles.end(); ++it) {
		p = *it;
		if (p->isDead()) {
			delete p;
			particles.erase(it);
			break;
		}
	}
}
