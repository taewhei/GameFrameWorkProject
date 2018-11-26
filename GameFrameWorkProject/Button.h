#pragma once
#include "Define.h"
#include "SDLGameObject.h"
#include<SDL_mixer.h>
class Button : public SDLGameObject
{
private:
	void handleInput();
	Mix_Chunk *effectsound;
public:
	Button(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void collision(GameObject* obj);
};
