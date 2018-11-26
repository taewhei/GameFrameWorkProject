#include"BackGround.h"
#include"InputHandler.h"


BackGround::BackGround(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	if (m_textureID == "MenuBackGround")
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		BackGroundMusic = Mix_LoadWAV("Asset/MainBackGround.wav");
		BackGroundMusic->volume = 30;
		Mix_PlayChannel(-1, BackGroundMusic, -1);
	}
	else if(m_textureID=="CityBackGround")
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		BackGroundMusic = Mix_LoadWAV("Asset/CityBackGround.wav");
		BackGroundMusic->volume = 50;
		Mix_PlayChannel(-1, BackGroundMusic, -1);
	}

}
void BackGround::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void BackGround::update()
{
	SDLGameObject::update();
}

void BackGround::clean()
{
	Mix_HaltChannel(-1);
}
void BackGround::collision(GameObject* obj)
{

}