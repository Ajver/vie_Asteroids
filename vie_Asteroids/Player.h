#pragma once

#include <vie/Object.h>
#include <vie/Timer.h>

namespace vie
{
	class ObjectsManager;
}

class Player : public vie::Object
{
public:
	Player(vie::ObjectsManager* nom);
	~Player();

	void update(float et) override;
	void render(vie::Graphics* g) override;
	
	static void nextPoint();

private:
	Player();

	float rotate;
	float rotateVel;
	vie::Texture shipTexture;
	vie::ObjectsManager* om;
	vie::Timer nextShotTimer;

	static int points;

	void setVelocity();
	void setRotateVel();

	void shot();
};

