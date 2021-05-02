#include "IconObject.h"
#include <iostream>
#include "BaseRunner.h"
#include "TextureManager.h"

IconObject::IconObject(String name, int textureIndex): AGameObject(name)
{
	this->textureIndex = textureIndex;
}

void IconObject::initialize()
{
	//assign texture
	this->sprite = new sf::Sprite();
	sf::Texture* texture = TextureManager::getInstance()->getStreamTextureFromList(this->textureIndex);
	this->sprite->setTexture(*texture);
	this->setScale(0.1f, 0.1f);
}

void IconObject::processInput(sf::Event event)
{
	
}

void IconObject::update(sf::Time deltaTime)
{
	fadeIn(deltaTime);
}

void IconObject::fadeIn(sf::Time deltaTime)
{
	if (this->isFadingIn)
	{
		this->timeFading += deltaTime;
		float convertedTime = this->timeFading.asSeconds();
		//cout << "Converted Time = " << convertedTime << std::endl;
		float fadeFactor = 255 * (convertedTime / this->fadeTime);

		if (fadeFactor > 255) fadeFactor = 255;
		//cout << "Fade Factor = " << fadeFactor << std::endl;

		this->setOpacity(fadeFactor);
	}

	else
	{
		this->timeFading = sf::Time::Zero;
	}
}
