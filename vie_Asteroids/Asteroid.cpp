#include "Asteroid.h"

#include <vie/Random.h>
#include <vie/Window.h>
#include <vie/ObjectsManager.h>

#include <iostream>

vie::Texture Asteroid::asteroidTextures[64];

Asteroid::Asteroid(vie::ObjectsManager* nom, const glm::vec2& nsize) :
	om(nom),
	rotateVel(vie::Random::nextFloat()),
	animationStep(vie::Random::nextInt(64)),
	animationTimer(vie::Random::nextInt(200, 700))
{
	size = nsize;

	position.x = vie::Random::nextInt(vie::Window::getScreenWidth());
	position.y = vie::Random::nextInt(vie::Window::getScreenHeight());

	velocity.x = vie::Random::nextFloat() - 0.5f;
	velocity.y = vie::Random::nextFloat() - 0.5f;
	velocity *= 200.0f;

	label = "asteroid";
}

Asteroid::Asteroid(vie::ObjectsManager* nom, const glm::vec2& npos, const glm::vec2& nsize) :
	om(nom),
	rotateVel(vie::Random::nextFloat()),
	animationStep(vie::Random::nextInt(64)),
	animationTimer(vie::Random::nextInt(200, 700))
{
	size = nsize;

	position = npos;

	velocity.x = vie::Random::nextFloat() - 0.5f;
	velocity.y = vie::Random::nextFloat() - 0.5f;
	velocity *= 200.0f;

	label = "asteroid";
}

Asteroid::Asteroid()
{
}

Asteroid::~Asteroid()
{
}

void Asteroid::update(float et)
{
	position += velocity * et;
	rotate += rotateVel * et;

	if (position.x < 0)
		position.x = vie::Window::getScreenWidth();
	else if (position.x > vie::Window::getScreenWidth())
		position.x = 0;

	if (position.y < 0)
		position.y = vie::Window::getScreenHeight();
	else if (position.y > vie::Window::getScreenHeight())
		position.y = 0;

	if (animationTimer.tick())
	{
		animationTimer.restart();
		if (++animationStep > 63)
			animationStep = 0;
	}
}

void Asteroid::render(vie::Graphics* g)
{
	g->translate(position);
	g->rotate(rotate);
	g->drawTexture(asteroidTextures[animationStep], -size * 0.5f, size);
	g->rotate(-rotate);
	g->translate(-position);
}

void Asteroid::loadTextures()
{
	vie::Texture ss("Graphics/asteroids-sprites.png");
	for (int i = 0; i < 64; i++)
	{
		int x = 32 * (i % 8);
		int y = 32 * (i / 8);
		asteroidTextures[i] = ss.getSubTexture(x, y, 32, 32);
	}
}