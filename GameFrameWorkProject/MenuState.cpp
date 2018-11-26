#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "BackGround.h"
#include"Button.h"
#include <iostream>

MenuState* MenuState::s_pInstance=0;
const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	for (std::vector<GameObject*>::size_type i = 1;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	TheTextureManager::Instance()->load("Asset/BrickBackGround.png", "MenuBackGround", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/Title.png", "Title", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/StartButton.png", "StartButton", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/HostButton.png", "HostButton", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/JoinButton.png", "JoinButton", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Asset/QuitButton.png", "QuitButton", TheGame::Instance()->getRenderer());

	m_gameObjects.push_back(new BackGround(new LoaderParams(0, 0, 480, 480, "MenuBackGround")));
	m_gameObjects.push_back(new BackGround(new LoaderParams(120, 20, 240, 87, "Title")));
	m_gameObjects.push_back(new Button(new LoaderParams(120, 130, 240, 58, "StartButton")));
	m_gameObjects.push_back(new Button(new LoaderParams(120, 210, 240, 58, "HostButton")));
	m_gameObjects.push_back(new Button(new LoaderParams(120, 290, 240, 58, "JoinButton")));
	m_gameObjects.push_back(new Button(new LoaderParams(120, 360, 240, 58, "QuitButton")));
	return true;
}

bool MenuState::onExit()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	return true;
}
void MenuState::Collision()
{

}
