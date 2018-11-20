#include "Brick.h"
#include"InputHandler.h"


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
	if (m_textureID == "Brick")
	{
		m_position.setX(rand() % 14 * 30 + 30);
		m_position.setY(rand() % 9 * 30 + 30);
	}
}
