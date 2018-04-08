#include "Globals.h";
#include "Particle.h";

void update_state();
void render_frame();

RenderWindow window(sf::VideoMode(1000, 700), "JVergara Particle System");

int main()
{
	Particle *p = new Particle(Vector2f(100, 100), Vector2f(.1, .1), Vector2f(50, 50), Vector2f(.2, .2), 5);
	float accumulatedTime = 0;
	Clock clock;

	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();
		accumulatedTime += dt;
		if (accumulatedTime >= 0.1f) {
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
		p->Update();
		p->Draw();
		window.display();
	}

	return 0;
}

void update_state() {

}

void render_frame() {

}
