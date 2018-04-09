#include "Globals.h";
#include "ParticleManager.h";


RenderWindow window(sf::VideoMode(1000, 700), "JVergara Particle System");

int main()
{
	srand(time(NULL));
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
