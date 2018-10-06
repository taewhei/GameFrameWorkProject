#pragma once

class Deltatime
{
private:
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;
public:
	void DoDeltaTime()
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

	}
	double ReturnDeltaTime() { 
	
		return deltaTime;
	};
};