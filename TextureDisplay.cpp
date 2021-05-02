#include "TextureDisplay.h"
#include <iostream>
#include "TextureManager.h"
#include "BaseRunner.h"
#include "GameObjectManager.h"
#include "IconObject.h"
TextureDisplay::TextureDisplay(): AGameObject("TextureDisplay")
{
	
}

void TextureDisplay::initialize()
{

}

void TextureDisplay::processInput(sf::Event event)
{
	
}

void TextureDisplay::update(sf::Time deltaTime)
{
	this->ticks += BaseRunner::TIME_PER_FRAME.asMilliseconds();
	
	//<code here for spawning icon object periodically>
	if(streamingType == StreamingType::SINGLE_STREAM && this->ticks > this->STREAMING_LOAD_DELAY && this->numIconsLoaded < this->MAX_ICONS)
	{
		this->ticks = 0;
		TextureManager::getInstance()->loadSingleStreamAsset(TextureManager::getInstance()->getNumLoadedStreamTextures(), this);
		numIconsLoaded++;
	}
}

void TextureDisplay::onFinished()
{
	this->spawnObject();
}


void TextureDisplay::spawnObject()
{
	String objectName = "Icon_" + to_string(this->iconList.size());
	IconObject* iconObj = new IconObject(objectName, this->iconList.size() % MAX_ICONS);
	iconObj->setActive(false);
	this->iconList.push_back(iconObj);

	//set position
	int IMG_WIDTH = 192; int IMG_HEIGHT = 108;
	float x = this->columnGrid * IMG_WIDTH;
	float y = this->rowGrid * IMG_HEIGHT;
	iconObj->setPosition(x, y);

	std::cout << "Set position: " << x << " " << y << std::endl;

	this->columnGrid++;
	if(this->columnGrid == this->MAX_COLUMN)
	{
		this->columnGrid = 0;
		this->rowGrid++;
	}
	GameObjectManager::getInstance()->addObject(iconObj);

	//If all icons done then set all to active
	if(this->iconList.size() >= 41)
	{
		GameObjectManager::getInstance()->findObjectByName("LoadingScreen")->setFade();
		for (AGameObject* icon : this->iconList)
		{
			icon->setFade();
			icon->setActive(true);
		}
	}
}
