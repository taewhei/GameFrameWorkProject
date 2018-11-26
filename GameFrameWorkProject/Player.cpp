#include"Player.h"
#include"InputHandler.h"


Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	effectsound = Mix_LoadWAV("Asset/PlayerColl.wav");
}
void Player::draw()
{
	SDLGameObject::draw();
}
void Player::update()
{
	prePos = m_position;
	handleInput();
	SDLGameObject::update();
}

void Player::handleInput()
{
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	if (vec->getX() < 90)
	{
		m_position.setX(30);
	}
	else if (vec->getX() > 390)
	{
		m_position.setX(450-m_width);
	}
	else
	{
	m_velocity.setX(vec->getX() - m_position.getX() - 60);
	}
	
}
void Player::collision(GameObject* obj)
{
	Mix_PlayChannel(-1, effectsound, 0);
}
void Player::clean()
{

}
