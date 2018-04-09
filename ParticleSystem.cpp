#include "ParticleSystem.h"



ParticleSystem::ParticleSystem(Vector2f position, float emitRate, float particleSize, float minVelocity, float maxVelocity, String textureFile)
{
	this->position = position;
	float angle = rand() % 10 + 50;
	this->leftBound = Vector2f(position.x - angle, position.y - 100);
	this->rightBound = Vector2f(position.x + angle, position.y - 100);
	this->emitRate = emitRate;
	this->particleSize = particleSize;
	this->minVel = minVelocity;
	this->maxVel = maxVelocity;
	this->tex = textureFile;
	this->keyboardTimePassed = 0;
	this->keyboardCooldown = 0.1f;
}


ParticleSystem::~ParticleSystem()
{
}


void ParticleSystem::Update() 
{

	float dt = clock.restart().asSeconds();
	timePassed += dt;
	keyboardTimePassed += dt;

	for (Particle* p : particles) {
		p->Update();
	}

	ClearDeadParticles();

	if (timePassed > emitRate) {
		particles.push_back(CreateParticle());
		timePassed = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left) && keyboardTimePassed >= keyboardCooldown) {
		emitRate *= 1.2f;
		keyboardTimePassed = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && keyboardTimePassed >= keyboardCooldown) {
		emitRate *= 0.8f;
		keyboardTimePassed = 0;
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
	float vel = minVel + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (maxVel - minVel)));
	Vector2f velocity = Vector2f(vel, vel);
	Vector2f size = Vector2f(particleSize, particleSize);
	int xMin = leftBound.x;
	int xMax = rightBound.x - leftBound.x;
	Vector2f dir = Vector2f(rand() % xMin + xMax, rightBound.y) - position;
	dir = Normalize(dir);
	return new Particle(this->position, velocity, size, dir, rand() % 1 + 2, tex, "shrink", "slow");
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

int ParticleSystem::numParticles() {
	return particles.size();
}
