#pragma once
#include "Define.h"
#include "Collision.h"
class Ball;
class Deltatime;
class Map;
class Player;

class BreakBrick
{
public:
	BreakBrick(){}
	~BreakBrick() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

private:
	bool m_bRunning = true;	
	
	SDL_Window * m_pWindow=0;
	SDL_Renderer* m_pRenderer=0;
	SDL_Surface* pTempSurface;
	SDL_Texture* m_pTexture;
	
	SDL_Event event;
	
	Ball* myball;
	Deltatime* deltatime;
	Map* mymap;
	Player* player;

};
