#include "Globals.h";
#include "ParticleSystem.h";

void update_state();
void render_frame();

RenderWindow window(sf::VideoMode(1000, 700), "JVergara Particle System");

int main()
{
	srand(time(NULL));
	ParticleSystem *ps = new ParticleSystem(Vector2f(500, 500), .1);
	
	float accumulatedTime = 0;
	Clock clock;

	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();
		accumulatedTime += dt;
		if (accumulatedTime >= 0.02f) {
			update_state();
			render_frame();
			window.display();
			accumulatedTime = 0;
		}


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		ps->Update();
		ps->Draw();
		window.display();
	}

	return 0;
}

void update_state() {

}

void render_frame() {

}
