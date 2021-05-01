#pragma once
#include "AGameObject.h"
#include "IEExecutionEvent.h"
#include "TextureManager.h"
#include "GameObjectManager.h"
#include <vector>
#include<iostream>

class LoadingScren : public AGameObject
{
private:
	~LoadingScren();
	typedef std::vector<sf::Texture*> TextureList;
	TextureList textureList;
	//sf::Sprite* sprite;
	float upTime = 0;
	int currPic = 0;
public:
	LoadingScren(std::string name);
	
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
};

