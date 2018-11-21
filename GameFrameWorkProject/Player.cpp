#include"Player.h"
#include"InputHandler.h"


Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}
void Player::draw()
{
	
	SDLGameObject::draw();
}
void Player::update()
{
	handleInput(); // add our function
	prePos = m_position;
	SDLGameObject::update();
}

void Player::handleInput()
{
	
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity.setX(vec->getX() - m_position.getX() - 60);
}
void Player::collision(GameObject* obj)
{
}
void Player::clean()
{

}
