#include "Player.h"

#include <vie/Input.h>
#include <vie/ObjectsManager.h>
#include <vie/Window.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

#include "Bullet.h"

Player::Player(vie::ObjectsManager* nom) :
	om(nom),
	rotate(0),
	rotateVel(0),
	shipTexture("Graphics/spaceship.png"),
	nextShotTimer(500)
{
	position = vie::Window::getScreenSize() * 0.5f;
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

	if (position.x < 0)
		position.x = vie::Window::getScreenWidth();
	else if (position.x > vie::Window::getScreenWidth())
		position.x = 0;

	if (position.y < 0)
		position.y = vie::Window::getScreenHeight();
	else if (position.y > vie::Window::getScreenHeight())
		position.y = 0;

	if(vie::Input::isKeyPressed(SDLK_SPACE))
		if (nextShotTimer.tick())
		{
			nextShotTimer.restart();
			shot();
		}
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

void Player::shot()
{
	glm::vec2 newBulletPos(0);
	newBulletPos.y -= size.y * 0.5f;
	newBulletPos = glm::rotate(newBulletPos, rotate);
	newBulletPos += position;

	Bullet * b = new Bullet(om, newBulletPos, rotate);
	om->appendObject(b);
}