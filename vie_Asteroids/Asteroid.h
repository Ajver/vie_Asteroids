#pragma once

#include <vie/Object.h>
#include <vie/Timer.h>

namespace vie 
{
	class ObjectsManager;
}

class Asteroid : public vie::Object
{
public:
	Asteroid(vie::ObjectsManager* nom, const glm::vec2& nsize = {128, 128});
	~Asteroid();

	void update(float et) override;
	void render(vie::Graphics* g) override;

	static void loadTextures();

private:
	Asteroid();

	float rotate;
	float rotateVel;

	vie::ObjectsManager* om;

	vie::Timer animationTimer;
	int animationStep;
	static vie::Texture asteroidTextures[64];
};

