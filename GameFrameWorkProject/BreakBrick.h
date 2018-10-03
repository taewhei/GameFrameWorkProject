#pragma once
#include "Define.h"

class BreakBrick
{
public:
	BreakBrick() {}
	~BreakBrick() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void map();
	void Ball();
	bool running() { return m_bRunning; }

	
private:
	bool m_bRunning = true;	
	void object();

	Vector ballVector;
	
	Vector ballPos = { 240,420 };
	Vector prePos;

	SDL_Window * m_pWindow=0;
	SDL_Renderer* m_pRenderer=0;
	SDL_Surface* pTempSurface;
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;
};
