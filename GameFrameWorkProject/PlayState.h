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
	virtual void Collision();
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
	void InputHandler();
	int playerlife = 3;	int score = 0; int combo = 0;int setSec = 180;
	void getscore(int get) { score += get; };
	void getcombo() { combo += 1; };

private:

	static const std::string s_playID;
	static PlayState* s_pInstance;
	SDL_Rect* brickRect;
	SDL_Rect* non_brickRect;
	std::vector<GameObject*>::size_type playertag;
}; typedef PlayState PlayState;
