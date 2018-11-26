#include"Button.h"
#include"InputHandler.h"
#include"PlayState.h"
#include"Game.h"
Button::Button(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	effectsound = Mix_LoadWAV("Asset/ButtonSound.wav");
}
void Button::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Button::update()
{
	handleInput();
	SDLGameObject::update();
}

void Button::clean()
{
}
void Button::collision(GameObject* obj)
{

}
void Button::handleInput()
{
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	if ((((vec->getX() >= m_position.getX()) && (vec->getX() <= m_position.getX() + m_width))
		&& ((vec->getY() >= m_position.getY()) && (vec->getY() <= m_position.getY() + m_height)))
		&&(TheInputHandler::Instance()->getMouseButtonState(LEFT)))
	{
		if (m_textureID=="StartButton")
		{
			m_pGameStateMachine::Instance()->changeState(PlayState::Instance());
		}
		if (m_textureID == "QuitButton")
		{
			TheGame::Instance()->quit();
		}
		Mix_PlayChannel(-1, effectsound, 0);

	}
}