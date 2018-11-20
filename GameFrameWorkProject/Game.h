#pragma once
#include "Define.h"
#include <vector>
#include"GameObject.h"

class Ball;
class Deltatime;
class Map;
class Player;

class Game
{
public:
	Game(){}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void collision();
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	static Game* Instance();
	void quit();
private:
	bool m_bRunning = true;	
	int m_CurrentFrame;

	SDL_Window * m_pWindow=0;
	SDL_Renderer* m_pRenderer=0;
	SDL_Surface* pTempSurface;
	SDL_Texture* m_pTexture;
	
	static Game* s_pInstance;
	SDL_Event event;
	
	std::vector<GameObject*> m_gameObjects;
	Ball* myball;
	Deltatime* deltatime;
	Map* mymap;
	Player* player;
	SDL_Rect* brickRect;
	SDL_Rect* non_brickRect;
}; typedef Game TheGame;
