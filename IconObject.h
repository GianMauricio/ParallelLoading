#pragma once
#include "AGameObject.h"
class IconObject :    public AGameObject
{
public:
	IconObject(String name, int textureIndex);
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

	void fadeIn(sf::Time deltaTime);
private:
	int textureIndex = 0;
	float fadeTime = 5.0f;
	sf::Time timeFading = sf::Time::Zero;
};

