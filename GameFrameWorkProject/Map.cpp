#include"Map.h"
Map::Map(SDL_Renderer* m_InRenderer)
{
	m_pRenderer = m_InRenderer;
}
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

