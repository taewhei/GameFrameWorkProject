#pragma once
#include "Define.h"
#include "SDLGameObject.h"

class Brick : public SDLGameObject
{
private:

public:
	Brick(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void collision(GameObject* obj);
	SDL_Rect brickRect[MAXBRICK];
};
