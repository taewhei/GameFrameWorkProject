#include "PlayState.h"
#include"TextureManager.h"
#include"Map.h"
#include"Player.h"
#include"Brick.h"
#include"Game.h"
#include"Ball.h"
#include"Map.h"
#include"BackGround.h"
#include"InputHandler.h"
#include"UIManager.h"
#include"MenuState.h"
#include"EndState.h"
#include"UI.h"
#include"Timer.h"
#include<iostream>
PlayState* PlayState::s_pInstance = 0;
const std::string PlayState::s_playID = "PLAY";
void PlayState::update()
{
	TheTimer::Instance()->reversetimer();
	brickRect = Mymap::Instance()->ReturnBrickRect();
	for (std::vector<GameObject*>::size_type i = 1;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
		if (((SDLGameObject*)m_gameObjects[i])->m_textureID == "Ball")
		{
			((Ball*)m_gameObjects[i])->setPosition(m_gameObjects[playertag]);
		}
	}
	Mymap::Instance()->UpdateMap(m_gameObjects);
	InputHandler();
	if (playerlife == 0)
	{
		m_pGameStateMachine::Instance()->changeState(EndState::Instance());
	}
	if (Timer::Instance()->printAllSec == 0)
	{
		m_pGameStateMachine::Instance()->changeState(EndState::Instance());
	}

	// nothing for now
}
void PlayState::render()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	// nothing for now
}
bool PlayState::onEnter()
{
	TheTimer::Instance()->start();
	TheTimer::Instance()->setSec(setSec);
	TheTextureManager::Instance()->load("Asset/Player.png", "Player", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/Brick.png", "Brick", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/non_Brick.png", "non_Brick", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/Ball.png", "Ball", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/CityBackGround.png", "CityBackGround", TheGame::Instance()->getRenderer());
	TheUIManager::Instance()->load("Asset/barbie.ttf",30);
	m_gameObjects.push_back(new BackGround(new LoaderParams(0, 0, 480, 480, "CityBackGround")));
	m_gameObjects.push_back(new Player(new LoaderParams(180, 455, 120, 40, "Player")));
	Mymap::Instance()->InitMap();
	brickRect = Mymap::Instance()->ReturnBrickRect();
	non_brickRect = Mymap::Instance()->ReturnNon_BrickRect();
	for (int i = 0; i < MAXBRICK; i++)
	{
		m_gameObjects.push_back(new Brick(new LoaderParams(brickRect[i].x, brickRect[i].y, brickRect[i].w,
			brickRect[i].h, "Brick")));
	}
	for (int i = 0; i < 44; i++)
	{
		m_gameObjects.push_back(new Brick(new LoaderParams(non_brickRect[i].x, non_brickRect[i].y, non_brickRect[i].w,
			non_brickRect[i].h, "non_Brick")));
	}
	m_gameObjects.push_back(new Ball(new LoaderParams(205, 390, 20, 20, "Ball")));
	m_gameObjects.push_back(new UI(new LoaderParams(0, 0, 100, 30, "Score")));
	m_gameObjects.push_back(new UI(new LoaderParams(380, 0, 100, 30, "Life")));
	m_gameObjects.push_back(new UI(new LoaderParams(200, 200, 100, 30, "Combo")));
	m_gameObjects.push_back(new UI(new LoaderParams(190, 0, 100, 30, "Timer")));
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		if (((SDLGameObject*)m_gameObjects[i])->m_textureID == "Player")
		{
			playertag = i;
		}
	}
	playerlife = 3;
	score = 0;
	combo = 0;
	return true;
}

bool PlayState::onExit()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTimer::Instance()->stop();
	return true;
}
void PlayState::Collision()
{
	for (std::vector<GameObject*>::size_type i = 1;
		i != m_gameObjects.size(); i++)
	{
		for (std::vector<GameObject*>::size_type j = 1;
			j != m_gameObjects.size(); j++)
		{
			if (TheCollision::Instance()->RecColl(m_gameObjects[i], m_gameObjects[j]) && (((SDLGameObject*)m_gameObjects[i])->m_textureID != ((SDLGameObject*)m_gameObjects[j])->m_textureID))
			{
				m_gameObjects[j]->collision(m_gameObjects[i]);
				m_gameObjects[i]->collision(m_gameObjects[j]);

			}
		}
	}
}
void PlayState::InputHandler()
{
	if (TheInputHandler::Instance()->isKeyOneDown(SDL_SCANCODE_ESCAPE) == 1)
	{
		m_pGameStateMachine::Instance()->changeState(MenuState::Instance());
	}
}
