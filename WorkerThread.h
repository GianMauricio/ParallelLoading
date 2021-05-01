#pragma once
#include "IETThread.h"
#include "IFinishedTask.h"
#include "IWorkerAction.h"

class WorkerThread : public IETThread
{
public:
	WorkerThread(int id, IFinishedTask* finishedTask);
	~WorkerThread();

	int getThreadID();
	void assignTask(IWorkerAction* action);
	
private:
	void run() override;
	int id = 0;
	IWorkerAction* action;
	IFinishedTask* onFinish;
};

