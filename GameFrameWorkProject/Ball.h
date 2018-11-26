#pragma once
#include"Define.h"
#include"Map.h"
#include"Player.h"
#include"SDLGameObject.h"

class Ball :public SDLGameObject
{
private:
	float Speed =5.5;
	Vector2D prePos;
	string ballState;
	Vector2D setPos;
	Mix_Chunk *effectsound;
public:
	Ball(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void collision(GameObject* obj);
	void handleInput();
	void UpdateBallMoving();
	void setPosition(GameObject* obj);
};
