#pragma once
#include <string>
#include <queue>
#include <unordered_map>


#include "IETThread.h"
#include "IFinishedTask.h"
#include "WorkerThread.h"
#include "IWorkerAction.h"

class ThreadPool : public IFinishedTask, public IETThread
{
private:
	typedef std::string String;
	typedef std::queue<WorkerThread*> ThreadList; 
	typedef std::unordered_map<int, WorkerThread*> ActiveThreadMap;
	typedef std::queue<IWorkerAction*> ActionList;

	String name;
	int numWorkers = 0;
	bool isRunning = false;

	//Queue implementation
	ThreadList InactiveThreads;

	//Hashmap style implementation
	ActiveThreadMap ActiveThreads;

	ActionList pendingActions;

	void onFinishedTask(int ThreadID) override;
	void run() override;
	
public:
	ThreadPool(String name, int numWorkers);
	~ThreadPool();

	void scheduleTask(IWorkerAction* action);
	void startScheduler();
	void stopScheduler();
};

