#pragma once
class IFinishedTask
{
public:
	virtual void onFinishedTask(int ThreadID) = 0;
};

