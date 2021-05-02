#pragma once
#include <unordered_map>

#include "IWorkerAction.h"
#include "SFML/Graphics.hpp"
#include "StreamAssetLoader.h"
#include "ThreadPool.h"
class TextureManager
{
public:
	typedef std::string String;
	typedef std::vector<sf::Texture*> TextureList;
	typedef std::unordered_map<String, TextureList> HashTable;
	IEExecutionEvent* execEvent;
	
public:
	static TextureManager* getInstance();
	void loadFromAssetList(); //loading of all assets needed for startup
	void loadSingleStreamAsset(int index, IEExecutionEvent* ExecEvent); //loads a single streaming asset based on index in directory
	sf::Texture* getFromTextureMap(const String assetName, int frameIndex);
	int getNumFrames(const String assetName);

	sf::Texture* getStreamTextureFromList(const int index);
	int getNumLoadedStreamTextures() const;
	void instantiateAsTexture(String path, String assetName, bool isStreaming);

private:
	TextureManager();
	TextureManager(TextureManager const&) {};             // copy constructor is private
	TextureManager& operator=(TextureManager const&) {};  // assignment operator is private
	static TextureManager* sharedInstance;

	//Created here because it needs to be constant
	ThreadPool* AssetLoader;
	HashTable textureMap;
	TextureList baseTextureList;
	TextureList streamTextureList;

	const std::string STREAMING_PATH = "Media/Weebification/";
	int streamingAssetCount = 0;

	void countStreamingAssets();
	

};