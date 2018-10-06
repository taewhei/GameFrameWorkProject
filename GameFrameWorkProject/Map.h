#pragma once
#include"Define.h"
class Map
{
private:
	int brickCount = 0;
	char level[15][17] = {
	{"################"},
	{"#**************#"},
	{"#**************#"},
	{"#***111**111***#"},
	{"#**************#"},
	{"#**************#"},
	{"#**************#"},
	{"#**************#"},
	{"#**************#"},
	{"#**************#"},
	{"#**************#"},
	{"#**************#"},
	{"#**************#"},
	{"#**************#"},
	{"#**************#"}
	};
	SDL_Rect brickRect[MAXBRICK];
	SDL_Renderer* m_pRenderer;
public:
	Map(SDL_Renderer* m_InRenderer);
	~Map();
	void DrawMap();
	int ReturnBrickCount() { return brickCount; }
	void ReplaceBrick(int i);
	SDL_Rect* ReturnBrickRect(){ return brickRect; }
};