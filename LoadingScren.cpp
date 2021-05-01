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
	sf::Texture* texture1 = TextureManager::getInstance()->getFromTextureMap("AmWatson1", 0);
	textureList.push_back(texture1);
	
	sf::Texture* texture2 = TextureManager::getInstance()->getFromTextureMap("AmWatson2", 0);
	textureList.push_back(texture2);
	
	sf::Texture* texture3 = TextureManager::getInstance()->getFromTextureMap("Gawr1", 0);
	textureList.push_back(texture3);
	
	sf::Texture* texture4 = TextureManager::getInstance()->getFromTextureMap("Gawr2", 0);
	textureList.push_back(texture4);
	
	sf::Texture* texture5 = TextureManager::getInstance()->getFromTextureMap("Inanis1", 0);
	textureList.push_back(texture5);

	//Set textures initially
	//textureList.at(currPic) != texture1????

	
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

	if(upTime >= 3.0f)
	{
		std::cout << "updating texture" << std::endl;
		upTime = 0;
		currPic++;
		currPic %= textureList.size();
		this->sprite->setTexture(*textureList.at(currPic));
	}
}
