#pragma once

#include <vie/Object.h>

namespace vie
{
	class ObjectsManager;
}

class Bullet : public vie::Object
{
public:
	Bullet(vie::ObjectsManager* nom, const glm::vec2& npos, float nrotate);
	~Bullet();

	void update(float et) override;
	void render(vie::Graphics* g) override;

private:
	Bullet();

	float rotate;
	vie::ObjectsManager* om;
};

