#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include"UIManager.h"


SDLGameObject::SDLGameObject(const LoaderParams* pParams) :

	GameObject(pParams),
	m_position(pParams->getX(), pParams->getY()),
	m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 1;
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height,Game::Instance()->getRenderer());
	UIManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height, Game::Instance()->getRenderer());
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDLGameObject::clean()
{
}
 