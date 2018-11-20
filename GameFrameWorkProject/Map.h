#pragma once
#include"Define.h"

class Map
{
private:
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
	SDL_Rect non_brickRect[44];
	SDL_Renderer* m_pRenderer = 0;
public:
	Map(SDL_Renderer* m_InRenderer);
	~Map();
	void InitMap();
	//int ReturnBrickCount() { return brickCount; }
	SDL_Rect* ReturnBrickRect(){ return brickRect; }
	SDL_Rect* ReturnNon_BrickRect() { return non_brickRect; }
};