#include "UIManager.h"

UIManager* UIManager::s_pInstance = 0;
void UIManager::load(std::string Filename,int fontsize)
{
	TTF_Init();
	gFont = TTF_OpenFont(Filename.c_str(),fontsize);
	
}
bool UIManager::write(std::string TextTexture, std::string id,SDL_Renderer* pRenderer, SDL_Color textcolor )
{
	TTF_Init();
	SDL_Surface* pTempSurface = TTF_RenderText_Solid(gFont, TextTexture.c_str(), textcolor);
	if (pTempSurface == 0)
	{
		return false;
	}
	SDL_Texture* pTexture =
		SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0) {
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}
void UIManager::draw(std::string id, int x, int y,int width,int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{

	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	destRect.w = width;
	destRect.h = height;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], 0,
		&destRect, 0,0, flip);

}
void UIManager::clean()
{

}
