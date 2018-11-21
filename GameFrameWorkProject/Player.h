#pragma once
#include"Define.h"
#include"SDLGameObject.h"

class Player:public SDLGameObject
{
private:
	SDL_Renderer* m_pRenderer;
	SDL_Rect player;
	SDL_Rect Lcontroll;
	SDL_Rect Rcontroll;
	float move = 0;
	void handleInput();

public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void collision(GameObject* obj);
	Vector2D prePos;
};