#include "Bullet.h"

#include <vie/ObjectsManager.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

Bullet::Bullet(vie::ObjectsManager* nom, const glm::vec2& npos, float nrotate) :
	om(nom),
	rotate(nrotate)
{
	position = npos;
	size = { 16, 16 };
	
	velocity = glm::rotate(glm::vec2(0.0f, -30.0f), rotate);
}

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::update(float et)
{
	position += velocity;
}

void Bullet::render(vie::Graphics* g)
{
	g->setColor(vie::COLOR::GREEN);

	g->translate(position);
	g->rotate(rotate);
	g->fillRect(-size * 0.5f, size);
	g->rotate(-rotate);
	g->translate(-position);
}

