#include"Map.h"
Map::Map(SDL_Renderer* m_InRenderer)
{
	m_pRenderer = m_InRenderer;
}
void Map::UpdateMap()
{
	int nWidth = 16;
	int nHeight = 15;
	brickCount = 0;

	for (int y = 0; y < nHeight; y++)
	{
		for (int x = 0; x < nWidth; x++)
		{
			SDL_Rect rect = { x * 30,y * 30,30,30 };
			switch (level[y][x])
			{
			case '#':
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
				SDL_RenderFillRect(m_pRenderer, &rect);
				break;
			//case '*':
			//	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			//	SDL_RenderFillRect(m_pRenderer, &rect);
			//	break;
			case '1':
				brickRect[brickCount] = rect;
				brickCount++;

				break;
			}
		}
	}
}
void Map::ReplaceBrick(int i)
{
	int y = rand() % 9 + 1;
	int x = rand() % 14 + 1;

	level[brickRect[i].y / 30][brickRect[i].x / 30] = '*';
	
	while (level[y][x] == '1'||(y==brickRect->y/30&&x==brickRect->x/30))
	{
		y = rand() % 9 + 1;
		x = rand() % 14 + 1;
	}
	level[y][x] = '1';
	brickRect[i] = { 0,0,0,0 };
}