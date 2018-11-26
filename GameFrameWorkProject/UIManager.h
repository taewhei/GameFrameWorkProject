#pragma once
#include<map>
#include<SDL.h>
#include<SDL_ttf.h>

class UIManager
{
public:
	void load( std::string Filename, int fontsize);
	bool write(std::string TextTexture, std::string id, SDL_Renderer* pRenderer, SDL_Color textcolor);
	void draw(std::string id, int x, int y, int width,int height,SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void clean();
	static UIManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new UIManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	TTF_Font *gFont = NULL;
private:
	std::map<std::string, SDL_Texture*> m_textureMap;
	UIManager() {}
	static UIManager* s_pInstance;
};
typedef UIManager TheUIManager;