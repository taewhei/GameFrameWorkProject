#include "Collision.h"
Collision* Collision::s_pInstance = 0;

bool Collision::RecColl(GameObject* object1, GameObject* object2)
{
	if (((SDLGameObject*)object1)->m_position.getX() + ((SDLGameObject*)object1)->m_width >= ((SDLGameObject*)object2)->m_position.getX() && ((SDLGameObject*)object1)->m_position.getX()
		<= ((SDLGameObject*)object2)->m_position.getX() + ((SDLGameObject*)object2)->m_width && ((SDLGameObject*)object1)->m_position.getY()
		+ ((SDLGameObject*)object1)->m_height >= ((SDLGameObject*)object2)->m_position.getY() && ((SDLGameObject*)object1)->m_position.getY()
		<= ((SDLGameObject*)object2)->m_position.getY() + ((SDLGameObject*)object2)->m_height)
	{
		return true;
	}
	return false;
}
