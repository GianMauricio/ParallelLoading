#include "WorkerThread.h"
#include "IWorkerAction.h"

WorkerThread::WorkerThread(int id, IFinishedTask* finishedTask)
{
	this->id = id;
	this->onFinish = finishedTask;
}

WorkerThread::~WorkerThread()
{
}

int WorkerThread::getThreadID()
{
	return this->id;
}

void WorkerThread::assignTask(IWorkerAction* action)
{
	this->action = action;
}

void WorkerThread::run()
{
	this->action->onStartTask();
	this->onFinish->onFinishedTask(this->id);
}
