#include "Globals.h";
#include "ParticleManager.h";


RenderWindow window(sf::VideoMode(1000, 700), "JVergara Particle System");
vector<Texture> textures;

int main()
{
	srand(time(NULL));
	Texture tex1, tex2, tex3;
	textures.push_back(tex1);
	textures.push_back(tex2);
	textures.push_back(tex3);
	textures[0].loadFromFile("Sprites/bubble.png");
	textures[1].loadFromFile("Sprites/smoke.png");
	textures[2].loadFromFile("Sprites/water.png");
	ParticleManager particleManager;

	float accumulatedTime = 0;
	Clock clock;

	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();
		accumulatedTime += dt;
		if (accumulatedTime >= 0.01f) {
			window.clear();
			particleManager.Update();
			particleManager.Draw();
			window.display();
			accumulatedTime = 0;
		}


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
	}

	return 0;
}

void update_state() {

}

void render_frame() {

}
