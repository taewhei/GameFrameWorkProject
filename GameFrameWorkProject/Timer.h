#pragma once
#include<SDL.h>
class Timer
{
public:
	Timer();
	~Timer();
	void start();
	void stop();
	void pause();
	void unpause();
	void reversetimer();

	Uint32 getTicks();

	bool isStarted();
	bool isPaused();

	static Timer* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Timer();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void setSec(int set) { SetSec = set; };
	int printAllSec;
private:
	int SetSec;
	static Timer* s_pInstance;
	Uint32 mStartTicks;
	Uint32 mPausedTicks;
	bool mPaused;
	bool mStarted;
}; typedef Timer TheTimer;

