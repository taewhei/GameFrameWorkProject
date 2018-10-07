#pragma once
#include "Define.h"
#include"Map.h"
#include"Player.h"

class Ball 
{
private:
	float Speed=0.2f;
	int nowState;

	Vector ballVector;
	Vector ballPos;
	Vector prePos;
	SDL_Renderer* m_pRenderer;
	SDL_Surface* pTempSurface;
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle = { 0,0,401,411 };
	SDL_Rect m_destinationRectangle = { 240,420,20,20 };
	string ballState;

public:
	Ball(SDL_Renderer* m_InRenderer, SDL_Surface* InTempSurface, SDL_Texture* m_InTexture,Player* player);
	~Ball();

	void DrawBall();
	void BallCollision(SDL_Rect player,Map* map);
	void ReturnBallMoving();
	void BallMoving(Deltatime deltatime);
	


};
