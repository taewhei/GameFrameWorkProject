#pragma once
#include "GameState.h"
#include<SDL.h>
class PlayState : public GameState
{
public:
	PlayState() {};
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual bool Collision(GameObject* obj);
	virtual std::string getStateID() const { return s_playID; }
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	static const std::string s_playID;
	static PlayState* s_pInstance;
	SDL_Rect* brickRect;
	SDL_Rect* non_brickRect;
}; typedef PlayState PlayState;
