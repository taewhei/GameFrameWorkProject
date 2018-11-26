#pragma once
#include "Define.h"
#include "SDLGameObject.h"
#include<SDL_mixer.h>

class UI : public SDLGameObject
{
private:
	std::string wholeUI;

	std::string ComboState;
	SDL_Color UIColor = { 255,255,255 };
	Mix_Chunk *effectsound;
	bool onetime = false;
public:
	UI(const LoaderParams* pParams);
	std::string ReturnTime(int sec);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void collision(GameObject* obj);
};
