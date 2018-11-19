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
	{"#**************#"},
	{"#**111*********#"},
	{"#**************#"},
	{"#*********11111#"},
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
	SDL_Renderer* m_pRenderer = 0;
public:
	Map(SDL_Renderer* m_InRenderer);
	~Map();
	void UpdateMap();
	int ReturnBrickCount() { return brickCount; }
	void ReplaceBrick(int i);
	SDL_Rect* ReturnBrickRect(){ return brickRect; }
};