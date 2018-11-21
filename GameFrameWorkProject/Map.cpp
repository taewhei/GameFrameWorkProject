#include"Map.h"
#include"SDLGameObject.h"
Map* Map::s_pInstance = 0;


void Map::InitMap()
{
	int nWidth = 16;
	int nHeight = 15;
	int brickCount = 0;
	int non_brickCount = 0;

	for (int y = 0; y < nHeight; y++)
	{
		for (int x = 0; x < nWidth; x++)
		{
			SDL_Rect rect = { x * 30,y * 30,30,30 };
			switch (level[y][x])
			{
			case '#':
				non_brickRect[non_brickCount] = rect;
				non_brickCount++;
				break;
			case '1':
				brickRect[brickCount] = rect;
				brickCount++;
				break;
			}
		}
	}
}
void Map::UpdateMap(std::vector<GameObject*> m_gameObjects)
{
	int brickCount = 0;
	for (std::vector<GameObject*>::size_type i = 1;
		i < MAXBRICK; i++)
	{
		SDL_Rect rect = { ((SDLGameObject*)m_gameObjects[i])->m_position.getX(),((SDLGameObject*)m_gameObjects[i])->m_position.getY(),
			((SDLGameObject*)m_gameObjects[i])->m_width,((SDLGameObject*)m_gameObjects[i])->m_height };
		brickRect[brickCount] = rect;
		brickCount++;
	}
}

