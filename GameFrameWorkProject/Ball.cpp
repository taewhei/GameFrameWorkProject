#include "Ball.h"
#include "Game.h"
#include"InputHandler.h"
#include"PlayState.h"
#include"Timer.h"

Ball::Ball(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	TheGame::Instance()->Start = false;
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	effectsound = Mix_LoadWAV("Asset/Die.wav");
}

 void Ball::draw()
{
	 SDLGameObject::draw();
}
 void Ball::update()
 {
	
	 if (TheGame::Instance()->Start==false)
	 {	 
		 TheTimer::Instance()->pause();
		 m_position.setX(setPos.getX()+55) ;
		 m_position.setY(setPos.getY()-m_height-1);
		 handleInput();
	 }
	 else if (TheGame::Instance()->Start==true)
	 {
		 prePos = m_position;
		 UpdateBallMoving();
	 }
	 if (m_position.getY() >=500||m_position.getY()<=-50)
	 {
		 TheGame::Instance()->Start = false;
		 PlayState::Instance()->playerlife -=1;
		 m_velocity.setX(0);
		 m_velocity.setY(0); 
		 Mix_PlayChannel(-1, effectsound, 0);
		 PlayState::Instance()->combo = 0;
	
	 }
	 SDLGameObject::update();
 }
 void Ball::clean()
 {
 }
void Ball::UpdateBallMoving() {
	 if (m_velocity.getX() == 0 && m_velocity.getY()<0)
	 {
		 ballState = "UP";
	 }
	 else if (m_velocity.getX() == 0 && m_velocity.getY()>0)
	 {
		 ballState = "DOWN";
	 }
	 else if (m_velocity.getX() >0 && m_velocity.getY()<0)
	 {
		 ballState = "RIGHT_UP";
	 }
	 else if (m_velocity.getX() >0&& m_velocity.getY()>0)
	 {
		 ballState = "RIGHT_DOWN";
		 
	 }
	 else if (m_velocity.getX()<0 && m_velocity.getY()<0)
	 {
		 ballState = "LEFT_UP";
	 }
	 else if (m_velocity.getX() <0 && m_velocity.getY()>0)
	 {
		 ballState = "LEFT_DOWN";
	 }
	 else
	 {
		 ballState = "STOP";
	 }
}
void Ball::collision(GameObject* obj)
{
	if (TheGame::Instance()->Start == true)
	{
		if (m_position.getX() <= 30 || m_position.getX() >= 430)
		{
			m_position = prePos;
			m_velocity.setX(m_velocity.getX()*-1);

		}
		if (m_position.getY() <= 30)
		{
			m_position = prePos;
			m_velocity.setY(m_velocity.getY()*-1);

		}
		if (((SDLGameObject*)obj)->m_textureID == "Brick")
		{
			m_position = prePos;

			if ((prePos.getY() + m_height <= ((SDLGameObject*)obj)->m_position.getY() && (ballState == "LEFT_UP" || ballState == "RIGHT_UP"))
				|| (prePos.getY() >= ((SDLGameObject*)obj)->m_position.getY() + ((SDLGameObject*)obj)->m_height && (ballState == "LEFT_DOWN" || ballState == "RIGHT_DOWN"))
				|| (prePos.getX() + m_width <= ((SDLGameObject*)obj)->m_position.getX() && (ballState == "LEFT_UP" || ballState == "LEFT_DOWN"))
				|| (prePos.getX() >= ((SDLGameObject*)obj)->m_position.getX() + ((SDLGameObject*)obj)->m_width && (ballState == "RIGHT_UP" || ballState == "RIGHT_DOWN")))//2개충돌 방지
			{
				UpdateBallMoving();
			}
			//대각선
			else if ((prePos.getY() + m_height <= ((SDLGameObject*)obj)->m_position.getY() || prePos.getY() >= ((SDLGameObject*)obj)->m_position.getY() + ((SDLGameObject*)obj)->m_height)
				&& (prePos.getX() + m_width <= ((SDLGameObject*)obj)->m_position.getX() || prePos.getX() >= ((SDLGameObject*)obj)->m_position.getX() + ((SDLGameObject*)obj)->m_width))
			{

				if (ballState == "LEFT_DOWN" || ballState == "RIGHT_DOWN")
				{
					if (prePos.getY() + m_height <= ((SDLGameObject*)obj)->m_position.getY())
					{
						m_velocity.setY(m_velocity.getY()*-1);

					}
					else
					{
						m_velocity.setX(m_velocity.getX()*-1);

					}
				}
				else if (ballState == "LEFT_UP" || ballState == "RIGHT_UP")
				{
					if (prePos.getY() >= ((SDLGameObject*)obj)->m_position.getY() + ((SDLGameObject*)obj)->m_height)
					{
						m_velocity.setY(m_velocity.getY()*-1);

					}
					else
					{
						m_velocity.setX(m_velocity.getX()*-1);

					}

				}
			}
			//Y
			else if (prePos.getY() + m_height <= ((SDLGameObject*)obj)->m_position.getY() || prePos.getY() >= ((SDLGameObject*)obj)->m_position.getY() + ((SDLGameObject*)obj)->m_height)
			{
				//
				m_velocity.setY(m_velocity.getY()*-1);

			}
			//X
			else if (prePos.getX() + m_width <= ((SDLGameObject*)obj)->m_position.getX() || prePos.getX() >= ((SDLGameObject*)obj)->m_position.getX() + ((SDLGameObject*)obj)->m_width)
			{
				m_velocity.setX(m_velocity.getX()*-1);

			}
		}
		else if (((SDLGameObject*)obj)->m_textureID == "Player")
		{
			PlayState::Instance()->combo = 0;
			m_position.setY(420);
			m_velocity.setY(m_velocity.getY()*-1);
			m_velocity.setX(m_velocity.getX() + ((((Player*)obj)->m_position.getX() - ((Player*)obj)->prePos.getX())) / 10);

		}
	}
}
void Ball::handleInput()
{
	if(TheInputHandler::Instance()->isKeyOneDown(SDL_SCANCODE_SPACE) == 1)
	{
		m_velocity.setY(Speed);
		TheGame::Instance()->Start = true;
		TheTimer::Instance()->unpause();
	}
	
}
void Ball::setPosition(GameObject* obj)
{
	setPos = ((SDLGameObject*)obj)->m_position;
}
