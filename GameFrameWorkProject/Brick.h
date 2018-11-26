#pragma once
#include "Define.h"
#include "SDLGameObject.h"
#include<SDL_mixer.h>

class Brick : public SDLGameObject
{
private:
	Mix_Chunk *effectsound;
public:
	Brick(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void collision(GameObject* obj);
	SDL_Rect brickRect[MAXBRICK];

};
