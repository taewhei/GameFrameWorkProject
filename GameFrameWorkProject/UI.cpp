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
	if (m_textureID == "Score")
	{
		UIManager::Instance()->write(scoreUI, "Score", TheGame::Instance()->getRenderer(), UIColor);
	}
	else if (m_textureID == "Life")
	{	
		UIManager::Instance()->write(lifeUI, "Life", TheGame::Instance()->getRenderer(), UIColor);
	}
	else if (m_textureID == "Combo")
	{
		UIManager::Instance()->write(comboUI, "Combo", TheGame::Instance()->getRenderer(), UIColor);
	}
	else if (m_textureID == "Timer")
	{
		UIManager::Instance()->write(timerUI, "Timer", TheGame::Instance()->getRenderer(), UIColor);
	}
	else if (m_textureID == "TotalScore")
	{
		string total = to_string(PlayState::Instance()->score);
		totalUI = "Total Score: " + total;
		UIManager::Instance()->write(totalUI, "TotalScore", TheGame::Instance()->getRenderer(), UIColor);
	}
	else if (m_textureID == "Info")
	{
		totalUI = "Press Space to continue";
		UIManager::Instance()->write(totalUI, "Info", TheGame::Instance()->getRenderer(), UIColor);
	}
	SDLGameObject::draw(); // we now use SDLGameObject
}
void UI::update()
{
	if (m_textureID == "Score")
	{
		string score = to_string(PlayState::Instance()->score);
		scoreUI = "Score:" + score;
	}
	else if (m_textureID == "Life")
	{
		string life = to_string(PlayState::Instance()->playerlife);
		lifeUI = "Life:" + life;
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
		comboUI = combo + " Combo";	

		if (PlayState::Instance()->combo < 3)
		{
			UIColor = { 255,0,0 };
			comboUI = " ";
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
		}
		timerUI =ReturnTime(TheTimer::Instance()->printAllSec / 60) + " : " 
			+ReturnTime(TheTimer::Instance()->printAllSec % 60);
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

