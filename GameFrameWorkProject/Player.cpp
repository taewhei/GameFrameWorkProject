#include"Player.h"

Player::Player(SDL_Renderer* m_InRenderer)
{
	m_pRenderer = m_InRenderer;
}
void Player::DrawPlayer()
{
		player = { 240 + (int)move,470,60,10 };
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
		SDL_RenderFillRect(m_pRenderer, &player);
}
void Player::PlayerMove(SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_LEFT:
		move -= 5.0f;
		break;
	case SDLK_RIGHT:
		move += 5.0f;
		break;
	}

}