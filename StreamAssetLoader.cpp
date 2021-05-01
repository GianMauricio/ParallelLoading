#include "StreamAssetLoader.h"

#include <filesystem>

#include "StringUtils.h"
#include "TextureManager.h"

void StreamAssetLoader::onStartTask()
{
	//Simulate large asset loading
	//IETThread::sleep(300);
	
	std::vector<String> tokens = StringUtils::split(path, '/');
	String assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];

	TextureManager::getInstance()->instantiateAsTexture(path, assetName, true);

	//std::cout << "[TextureManager] Loaded streaming texture: " << assetName << std::endl;

	//throw event for done
	this->execEvent->onFinished();

	//delete after done
	delete this;
}

StreamAssetLoader::StreamAssetLoader(String path, IEExecutionEvent* event)
{
	this->path = path;
	this->execEvent = event;
}

StreamAssetLoader::~StreamAssetLoader()
{
	//std::cout << "Dah! My existence is deleted" << std::endl;
}
