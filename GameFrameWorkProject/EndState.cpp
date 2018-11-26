#include "EndState.h"
#include "TextureManager.h"
#include "Game.h"
#include "BackGround.h"
#include"UIManager.h"
#include"MenuState.h"
#include"UI.h"
#include"InputHandler.h"
#include <iostream>

EndState* EndState::s_pInstance = 0;
const std::string EndState::s_menuID = "END";

void EndState::update()
{
	HandleInput();
	for (std::vector<GameObject*>::size_type i = 1;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	
}

void EndState::render()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool EndState::onEnter()
{
	TheUIManager::Instance()->load("Asset/barbie.ttf", 30);
	TheTextureManager::Instance()->load("Asset/BrickBackGround.png", "EndBackGround", TheGame::Instance()->getRenderer());
	m_gameObjects.push_back(new BackGround(new LoaderParams(0, 0, 480, 480, "EndBackGround")));
	m_gameObjects.push_back(new UI(new LoaderParams(125, 120, 250, 100, "TotalScore")));
	m_gameObjects.push_back(new UI(new LoaderParams(50, 280, 400, 100, "Info")));
	

	return true;
}

bool EndState::onExit()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	return true;
}
void EndState::Collision()
{

}
void EndState::HandleInput()
{
	if (TheInputHandler::Instance()->isKeyOneDown(SDL_SCANCODE_SPACE) == 1)
	{
		m_pGameStateMachine::Instance()->changeState(MenuState::Instance());
	}
}
