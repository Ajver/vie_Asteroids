#include "Player.h"

#include <vie/Input.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

Player::Player() :
	rotate(0),
	rotateVel(0),
	shipTexture("Graphics/spaceship.png")
{
	position = { 0, 0 };
	size = { 128, 128 };
}

Player::~Player()
{
}

void Player::update(float et)
{
	setVelocity();
	setRotateVel();

	position += velocity * et;
	rotate += rotateVel * et;
}

void Player::render(vie::Graphics* g)
{
	g->translate(position);
	g->rotate(rotate);
	g->drawTexture(shipTexture, -size * 0.5f, size);
	g->rotate(-rotate);
	g->translate(-position);
}

void Player::setVelocity()
{
	static const float FORCE = -200.0f;

	velocity.x = 0;
	velocity.y = 0;

	if (vie::Input::isKeyPressed(SDLK_w) ||
		vie::Input::isKeyPressed(SDLK_UP))
		velocity = glm::rotate(glm::vec2(0, FORCE), rotate);
}

void Player::setRotateVel()
{
	static const float ROTATE_SPEED = 2.0f;

	rotateVel = 0;

	if (vie::Input::isKeyPressed(SDLK_a) ||
		vie::Input::isKeyPressed(SDLK_LEFT))
		rotateVel = -ROTATE_SPEED;
	else if (vie::Input::isKeyPressed(SDLK_d) ||
		vie::Input::isKeyPressed(SDLK_RIGHT))
		rotateVel = ROTATE_SPEED;
}
