#include "Brick.h"
#include"InputHandler.h"
#include"Map.h"


Brick::Brick(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Brick::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Brick::update()
{
	SDLGameObject::update();
}

void Brick::clean()
{
}
void Brick::collision(GameObject* obj)
{
	if (m_textureID == "Brick"&& ((SDLGameObject*)obj)->m_textureID=="Ball")
	{
		m_position.setX(rand() % 14 * 30 + 30);
		m_position.setY(rand() % 9 * 30 + 30);
	
		for (int i = 0; i < MAXBRICK; i++)
		{
			if (m_position.getX() == Mymap::Instance()->ReturnBrickRect()[i].x && (m_position.getY() == Mymap::Instance()->ReturnBrickRect()[i].y))
			{
				m_position.setX(rand() % 14 * 30 + 30);
				m_position.setY(rand() % 9 * 30 + 30);
				i = 0;
			}
		}
		
	}
}
