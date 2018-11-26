#pragma once
#include"Define.h"
#include<vector>
class Map
{
public:
	static	Map* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Map();
			return s_pInstance;
		}
		return s_pInstance;
	}

	void InitMap();
	void UpdateMap(std::vector<GameObject*>m_gameObjects);
	SDL_Rect* ReturnBrickRect() { return brickRect; }
	SDL_Rect* ReturnNon_BrickRect() { return non_brickRect; }
private:
	char level[15][17] = {
	{"################"},
	{"#**************#"},
	{"#**************#"},
	{"#*****1111*****#"},
	{"#*111******111*#"},
	{"#*****1111*****#"},
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
	SDL_Rect non_brickRect[44];
	static Map* s_pInstance;
	Map() {};

}; typedef Map Mymap;