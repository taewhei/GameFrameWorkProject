#pragma once
#include"Define.h"
#include"Map.h"
#include"Player.h"
#include"SDLGameObject.h"

class Ball :public SDLGameObject
{
private:
	float Speed=4.5;

	//int nowState;
	//
	//Vector ballVector;
	//Vector ballPos;
	Vector2D prePos;
	//SDL_Renderer* m_pRenderer;
	//SDL_Surface* pTempSurface;
	//SDL_Texture* m_pTexture;
	//SDL_Rect m_sourceRectangle = { 0,0,401,411 };
	//SDL_Rect m_destinationRectangle = { 240,420,20,20 };
	string ballState;

public:
	//Ball(SDL_Renderer* m_InRenderer, SDL_Surface* InTempSurface, SDL_Texture* m_InTexture,Player* player);
	Ball(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void collision(GameObject* obj);
	void BallCollision(Player* player,Map* map);
	void ReturnBallMoving();
	void BallMoving(Deltatime deltatime);
	


};
