#pragma once
#include "IETThread.h"
#include "IEExecutionEvent.h"
#include "IWorkerAction.h"

class StreamAssetLoader : public IWorkerAction
{
private:
	typedef std::string String;
	String path;
	IEExecutionEvent* execEvent;
	void onStartTask() override;
public:
	StreamAssetLoader(String path, IEExecutionEvent* execEvent);
	~StreamAssetLoader();
};

