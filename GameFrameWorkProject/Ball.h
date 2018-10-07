#pragma once
#include "Define.h"
class BreakBrick;
class Ball 
{
private:
	float Speed=0.15f;
	int nowState;

	Vector ballVector= {Speed,Speed};
	Vector ballPos = { 100,50 };
	Vector prePos;
	SDL_Renderer* m_pRenderer;
	SDL_Surface* pTempSurface;
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle = { 0,0,401,411 };
	SDL_Rect m_destinationRectangle = { 240,420,20,20 };
	string ballState="RIGHT_DOWN";

	
public:
	Ball(SDL_Renderer* m_InRenderer, SDL_Surface* InTempSurface, SDL_Texture* m_InTexture);
	~Ball();

	void DrawBall();
	void BallCollision(SDL_Rect player,Map* map);
	void ReturnBallMoving();
	void BallMoving(Deltatime deltatime);
	


};
