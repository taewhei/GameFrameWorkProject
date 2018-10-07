#pragma once
#include"Define.h"

class Player
{
private:
	SDL_Renderer* m_pRenderer;
	SDL_Rect player;
	SDL_Rect Lcontroll;
	SDL_Rect Rcontroll;
	float move = 0;
public:
	Player(SDL_Renderer* m_InRenderer);
	~Player();
	void DrawPlayer();
	SDL_Rect ReturnPlayer() { return player; }
	void PlayerMove(SDL_Event event);
};