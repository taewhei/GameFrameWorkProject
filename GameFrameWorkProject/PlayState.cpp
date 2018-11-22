#include "PlayState.h"
#include"TextureManager.h"
#include"Map.h"
#include"Player.h"
#include"Brick.h"
#include"Game.h"
#include"Ball.h"
#include"Map.h"
#include<iostream>
PlayState* PlayState::s_pInstance = 0;
const std::string PlayState::s_playID = "PLAY";
void PlayState::update()
{
	brickRect = Mymap::Instance()->ReturnBrickRect();
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	Mymap::Instance()->UpdateMap(m_gameObjects);
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
	std::cout << "entering PlayState\n";
	TheTextureManager::Instance()->load("Asset/Player.png", "Player", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/Brick.png", "Brick", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/non_Brick.png", "non_Brick", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/Ball.png", "Ball", TheGame::Instance()->getRenderer());

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

	m_gameObjects.push_back(new Ball(new LoaderParams(200, 425, 20, 20, "Ball")));
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}
bool PlayState::Collision(GameObject* obj)
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		for (std::vector<GameObject*>::size_type j = 0;
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
