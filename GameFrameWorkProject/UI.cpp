#include "UI.h"
#include"InputHandler.h"
#include"Map.h"
#include"UIManager.h"
#include"PlayState.h"
#include"Game.h"
#include"Timer.h"
UI::UI(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}
void UI::draw()
{

	UIManager::Instance()->write(wholeUI, m_textureID, TheGame::Instance()->getRenderer(), UIColor);

	SDLGameObject::draw(); // we now use SDLGameObject
}
void UI::update()
{
	if (m_textureID == "Score")
	{
		string score = to_string(PlayState::Instance()->score);
		wholeUI = "Score:" + score;
	}
	else if (m_textureID == "Life")
	{
		string life = to_string(PlayState::Instance()->playerlife);
		wholeUI = "Life:" + life;
	}
	else if (m_textureID == "Combo")
	{
		if (PlayState::Instance()->combo == 5)
		{
			UIColor = { 250,100,15 };

			effectsound = Mix_LoadWAV("Asset/GreatSound.wav");
			if (onetime == false)
			{
				Mix_PlayChannel(-1, effectsound, 0);
				onetime = true;
			}
		}
		else if (PlayState::Instance()->combo == 10)
		{
			UIColor = { 240,250,20 };

			effectsound = Mix_LoadWAV("Asset/NiceSound.wav");
			if (onetime == false)
			{
				Mix_PlayChannel(-1, effectsound, 0);
				onetime = true;
			}
		}
		else if (PlayState::Instance()->combo == 15)
		{
			UIColor = { 0,255,0 };

			effectsound = Mix_LoadWAV("Asset/ExcellentSound.wav");
			if (onetime == false)
			{
				Mix_PlayChannel(-1, effectsound, 0);
				onetime = true;
			}

		}
		else if (PlayState::Instance()->combo == 20)
		{
			UIColor = { 0,0,255 };
			effectsound = Mix_LoadWAV("Asset/FantasticSound.wav");
			if (onetime == false)
			{
				Mix_PlayChannel(-1, effectsound, 0);
				onetime = true;
			}
		}
		else
		{
			onetime = false;
		}
		
		string combo = to_string(PlayState::Instance()->combo);
		wholeUI = combo + " Combo";	

		if (PlayState::Instance()->combo < 3)
		{
			UIColor = { 255,0,0 };
			wholeUI = " ";
		}
	}
	else if (m_textureID == "Timer")
	{
		UIColor = { 255,255,255 };
		if (TheTimer::Instance()->printAllSec <= 30&&TheTimer::Instance()->printAllSec > 20)
		{
			UIColor = { 240,250,20 };
		}
		else if (TheTimer::Instance()->printAllSec <= 20 && TheTimer::Instance()->printAllSec > 10)
		{
			UIColor = { 250,100,15 };
		}	
		else if (TheTimer::Instance()->printAllSec <= 10)
		{
			UIColor = { 255,0,0 };	
			if (TheTimer::Instance()->printAllSec == 10)
			{
				if (onetime == false)
				{
				effectsound = Mix_LoadWAV("Asset/TickTock.wav");
				effectsound->volume = 60;
				Mix_PlayChannel(-1, effectsound, 0);
				onetime = true;
				}
			}
		}
	
		wholeUI =ReturnTime(TheTimer::Instance()->printAllSec / 60) + " : " 
			+ReturnTime(TheTimer::Instance()->printAllSec % 60);
	}
	else if (m_textureID == "TotalScore")
	{
		string total = to_string(PlayState::Instance()->score);
		wholeUI = "Total Score: " + total;
	}
	else if (m_textureID == "Info")
	{
		wholeUI = "Press Space to continue";
	}
	SDLGameObject::update();
}

void UI::clean()
{
}
void UI::collision(GameObject* obj)
{
	
}
string UI::ReturnTime(int sec)
{
	std::string time;
	if (sec < 10)
	{
		time = to_string(sec);
		return "0" + time;
	}
	else
	{
		time = to_string(sec);
		return time;
	}
}

