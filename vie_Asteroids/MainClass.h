#pragma once

#include <vie/Engine.h>

class MainClass : public vie::Engine
{
public:
	MainClass();
	~MainClass();

	void onCreate() override;
	void update(float et) override;
	void render(vie::Graphics* g) override;

};
