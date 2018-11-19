#pragma once
#include"Define.h"
#include"SDLGameObject.h"
class Collision
{
public:

	bool RecColl(GameObject* object1, GameObject* object2);
	static Collision* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Collision();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	static Collision* s_pInstance;
};
typedef Collision TheCollision;
