#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <glut.h>
#include "cube.hpp"

using namespace sf;	

float angleX, angleY, x = 0, y = 0, z = 0, speed = 1.0, PI = 3.141592;

int main() {
	err().rdbuf(NULL);

	sf::RenderWindow window(sf::VideoMode(1280, 720), "test");
	window.setFramerateLimit(60);

	ShowCursor(false);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glClearDepth(1.f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	gluPerspective(80.f, 1.f, 1.f, 2000.f);
	glEnable(GL_TEXTURE_2D);

	float time = 0, size = 0;

	GLuint box[6];
		box[0] = LoadTexture("resources/1.jpg");
		box[1] = LoadTexture("resources/2.jpg");
		box[2] = LoadTexture("resources/3.jpg");
		box[3] = LoadTexture("resources/4.jpg");
		box[4] = LoadTexture("resources/5.jpg");
		box[5] = LoadTexture("resources/6.jpg");

	Clock clock;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		POINT mousexy;
		GetCursorPos(&mousexy);
		int xt = window.getPosition().x + window.getSize().x / 2;
		int yt = window.getPosition().y + window.getSize().y / 2;
		angleX += (xt - mousexy.x)*0.25;
		angleY += (yt - mousexy.y)*0.25;
		if (angleY < -89.0) angleY = -89.0;
		if (angleY > 89.0) angleY = 89.0;
		SetCursorPos(xt, yt);
		
		float dx = 0, dy = 0, dz = 0;
		if (Keyboard::isKeyPressed(Keyboard::LShift)) dy -= speed;
		if (Keyboard::isKeyPressed(Keyboard::Space)) dy += speed;
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			dx += -sin(angleX / 180 * PI) * speed;
			dz += -cos(angleX / 180 * PI) * speed;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			dx += sin(angleX / 180 * PI) * speed;
			dz += cos(angleX / 180 * PI) * speed;
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			dx += sin((angleX + 90) / 180 * PI)*speed;
			dz += cos((angleX + 90) / 180 * PI)*speed;
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			dx += sin((angleX - 90) / 180 * PI)*speed;
			dz += cos((angleX - 90) / 180 * PI)*speed;
		}
		x += dx;
		y += dy;
		z += dz;
		if (Keyboard::isKeyPressed(Keyboard::Escape)) return 0;

		time = clock.getElapsedTime().asSeconds() * 100;
		size = 20.f;


		glMatrixMode(GL_MODELVIEW);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(x, y, z, x - sin(angleX / 180 * PI), y + tan(angleY / 180 * PI), z - cos(angleX / 180 * PI), 0, 1, 0);

		for (int x = 0; x < 5; x++)
			for (int y = 0; y < 5; y++)
				for (int z = 0; z < 5; z++)
				{
					{
						{
							glTranslatef(x*size, y*size, z*size);
							createCube(box, size / 2);
							glTranslatef(-x * size, -y * size, -z*size);
						}
					}
				}
	
		window.display();
		window.clear(Color::Black);
	}

	return 0;
}