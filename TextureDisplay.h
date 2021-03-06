#pragma once
#include "AGameObject.h"
#include "IEExecutionEvent.h"
#include "IFinishedTask.h"
#include "IWorkerAction.h"
#include "LoadingScren.h"
class IconObject;
/// <summary>
/// Class that deals with displaying of streamed textures
/// </summary>
class TextureDisplay: public AGameObject, public IEExecutionEvent
{
public:
	TextureDisplay();
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	void onFinished() override;
private:
	typedef std::vector<IconObject*> IconList;
	IconList iconList;

	enum StreamingType { BATCH_LOAD = 0, SINGLE_STREAM = 1 };
	const float STREAMING_LOAD_DELAY = 100.0f;
	const StreamingType streamingType = SINGLE_STREAM;
	float ticks = 0.0f;
	bool startedStreaming = false;

	int columnGrid = 0; int rowGrid = 0;
	
	const int MAX_COLUMN = 10;
	const int MAX_ROW = 5;
	const int MAX_ICONS = 41;

	int numIconsLoaded = 0;

	sf::Time currDelta;
	
	void spawnObject();
};

