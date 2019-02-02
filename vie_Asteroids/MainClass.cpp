#include "MainClass.h"

#include <vie/ObjectsManager.h>
#include <vie/Window.h>
#include <vie/Input.h>
#include <vie/Random.h>

#include "Player.h"
#include "Asteroid.h"


MainClass::MainClass() :
	nextAsteroidTimer(300)
{
	runEngine("Asteroids", 1024, 680);
}

MainClass::~MainClass() 
{
}

void MainClass::onCreate() 
{
	Asteroid::loadTextures();

	objectsManager->appendObject(new Player(objectsManager));

	createAsteroid();

	graphics->setBackgroundColor(vie::COLOR::BLACK);
	mainCamera->setPosition(vie::Window::getScreenSize() * 0.5f);
}

void MainClass::update(float et) 
{
	if (nextAsteroidTimer.tick())
	{
		nextAsteroidTimer.start(vie::Random::nextInt(2000, 4000));
		createAsteroid();
	}
	
	if (vie::Input::isKeyPressed(SDLK_ESCAPE))
		destroyEngine();

	objectsManager->update(et);
}

void MainClass::render(vie::Graphics* g)
{
	objectsManager->render(g);
}

void MainClass::createAsteroid()
{
	objectsManager->appendObject(new Asteroid(objectsManager));
}