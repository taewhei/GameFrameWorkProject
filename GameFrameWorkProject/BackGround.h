#pragma once
#include "Define.h"
#include "SDLGameObject.h"
#include<SDL_mixer.h>

class BackGround : public SDLGameObject
{
private:

public:
	BackGround(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void collision(GameObject* obj);
	Mix_Chunk *BackGroundMusic=NULL;
	
};
