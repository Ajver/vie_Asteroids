#include "MainClass.h"

#include <vie/ObjectsManager.h>
#include <vie/Input.h>

#include "Player.h"

MainClass::MainClass()
{
	runEngine("Asteroids", 1280, 728);
}

MainClass::~MainClass() 
{
}

void MainClass::onCreate() 
{
	objectsManager->appendObject(new Player());

	graphics->setBackgroundColor(vie::COLOR::BLACK);
}

void MainClass::update(float et) 
{
	if (vie::Input::isKeyPressed(SDLK_ESCAPE))
		destroyEngine();

	objectsManager->update(et);
}

void MainClass::render(vie::Graphics* g)
{
	objectsManager->render(g);
}