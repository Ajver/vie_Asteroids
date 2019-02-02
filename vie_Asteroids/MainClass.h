#pragma once

#include <vie/Engine.h>
#include <vie/Timer.h>

class MainClass : public vie::Engine
{
public:
	MainClass();
	~MainClass();

	void onCreate() override;
	void update(float et) override;
	void render(vie::Graphics* g) override;

private:
	void createAsteroid();

	vie::Timer nextAsteroidTimer;
};
