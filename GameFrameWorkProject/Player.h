#pragma once
#include"Define.h"
class Player
{
private:
	SDL_Renderer* m_pRenderer;
	SDL_Rect player;
	float move = 0;
public:
	Player(SDL_Renderer* m_InRenderer);
	~Player();
	void DrawPlayer();
	SDL_Rect ReturnPlayer() { return player; }
	void PlayerMove(SDL_Event event);
};