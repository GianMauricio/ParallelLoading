#include "LoadingScren.h"
#include "BaseRunner.h"

LoadingScren::~LoadingScren()
{
	AGameObject::~AGameObject();
}

LoadingScren::LoadingScren(std::string name) : AGameObject(name)
{
	
}

void LoadingScren::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";
	//Initialize Sprite
	this->sprite = new sf::Sprite();
	
	//Initialize textures
	sf::Texture* texture1 = TextureManager::getInstance()->getFromTextureMap("VW1", 0);
	textureList.push_back(texture1);
	
	sf::Texture* texture2 = TextureManager::getInstance()->getFromTextureMap("VW2", 0);
	textureList.push_back(texture2);
	
	sf::Texture* texture3 = TextureManager::getInstance()->getFromTextureMap("VW3", 0);
	textureList.push_back(texture3);
	
	sf::Texture* texture4 = TextureManager::getInstance()->getFromTextureMap("VW4", 0);
	textureList.push_back(texture4);
	
	sf::Texture* texture5 = TextureManager::getInstance()->getFromTextureMap("VW5", 0);
	textureList.push_back(texture5);

	sf::Texture* texture6 = TextureManager::getInstance()->getFromTextureMap("VW6", 0);
	textureList.push_back(texture6);

	this->sprite->setTexture(*textureList.at(currPic));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	
	//Make Height and width same as window
	this->sprite->setTextureRect(sf::IntRect(0, 0, BaseRunner::WINDOW_WIDTH, BaseRunner::WINDOW_HEIGHT));
	this->setPosition(0, 0);
}

void LoadingScren::processInput(sf::Event event)
{
	
}

void LoadingScren::update(sf::Time deltaTime)
{
	upTime += deltaTime.asSeconds();

	fadeOut(deltaTime);

	if(upTime >= 3.0f)
	{
		std::cout << "updating texture" << std::endl;
		upTime = 0;
		currPic++;
		currPic %= textureList.size();
		this->sprite->setTexture(*textureList.at(currPic));
	}
}

void LoadingScren::fadeOut(sf::Time deltaTime)
{
	if(this->isFadingOut)
	{
		this->timeFading += deltaTime;
		float convertedTime = this->timeFading.asSeconds();
		//cout << "Converted Time = " << convertedTime << std::endl;
		float fadeFactor = 255 * (1 - convertedTime / this->fadeTime);

		if (fadeFactor < 0) fadeFactor = 0;
		//cout << "Fade Factor = " << fadeFactor << std::endl;

		this->setOpacity(fadeFactor);
	}

	else
	{
		this->timeFading = sf::Time::Zero;
	}
}
