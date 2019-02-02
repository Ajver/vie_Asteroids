#pragma once

#include <vie/Object.h>

class Player : public vie::Object
{
public:
	Player();
	~Player();

	void update(float et) override;
	void render(vie::Graphics* g) override;

private:
	float rotate;
	float rotateVel;
	vie::Texture shipTexture;

	void setVelocity();
	void setRotateVel();
};

