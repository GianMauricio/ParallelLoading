#include "ThreadPool.h"

void ThreadPool::onFinishedTask(int ThreadID)
{
	if(this->ActiveThreads[ThreadID] != nullptr)
	{
		//create fresh worker thread
		delete this->ActiveThreads[ThreadID];
		this->ActiveThreads.erase(ThreadID);

		this->InactiveThreads.push(new WorkerThread(ThreadID, this));
	}
}

void ThreadPool::run()
{
	while (isRunning) {
		//if there are actions to be done
		if (!this->pendingActions.empty())
		{
			//If there are threads available
			if (!this->InactiveThreads.empty())
			{
				WorkerThread* currWorker = this->InactiveThreads.front();
				this->InactiveThreads.pop();
				this->ActiveThreads[currWorker->getThreadID()] = currWorker;

				currWorker->assignTask(this->pendingActions.front());
				currWorker->start();
				this->pendingActions.pop();
			}
			else
			{
				std::cout << "[Threadpool " << this->name << " Has no available threads" << std::endl;
			}
		}
		else
		{
			//std::cout << "[Threadpool " << this->name << " Has no pending tasks" << std::endl;
		}
	}
}

ThreadPool::ThreadPool(String name, int numWorkers)
{
	this->name = name;
	this->numWorkers = numWorkers;

	for(int i = 0; i < this->numWorkers; i++)
	{
		this->InactiveThreads.push(new WorkerThread(i, this));
	}
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::scheduleTask(IWorkerAction* action)
{
	this->pendingActions.push(action);
}

void ThreadPool::startScheduler()
{
	if (!isRunning) {
		this->start();
	}
	
	this->isRunning = true;
}

void ThreadPool::stopScheduler()
{
	this->isRunning = false;
}
