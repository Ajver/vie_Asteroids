#include "Bullet.h"

#include <vie/ObjectsManager.h>
#include <vie/Window.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

#include "Asteroid.h"
#include "Player.h"

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

	int osize = om->getObjectsVector().size();
	for (int i = 0; i < osize; i++)
	{
		Object* ob = om->getObject(i);
		if (ob->isLabeled("asteroid"))
		{
			float d = glm::distance(position, ob->getPosition());

			if (d <= ob->getSize().x * 0.5f)
			{
				if (ob->getSize().x > 64)
				{
					glm::vec2 pos = ob->getPosition();
					glm::vec2 siz = ob->getSize() * 0.5f;
					om->appendObject(new Asteroid(om, pos, siz));
					om->appendObject(new Asteroid(om, pos, siz));
				}
				else
				{
					Player::nextPoint();
				}
				om->removeObject(ob);
				om->removeObject(this);
				return;
			}
		}
	}

	if(position.x < 0 || 
		position.x > vie::Window::getScreenWidth() ||
		position.y < 0 || 
		position.y > vie::Window::getScreenHeight())
		om->removeObject(this);
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

