#include"Player.h"

Player::Player(SDL_Renderer* m_InRenderer)
{
	m_pRenderer = m_InRenderer;
	player = { 240 ,470,60,10 };
}
void Player::DrawPlayer()
{
		player = { 240 + (int)move,470,60,10 };
		Lcontroll = { player.x ,player.y, player.w / 6, player.h };
		Rcontroll = { player.x+player.w / 6*5,player.y, player.w / 6, player.h };
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
		SDL_RenderFillRect(m_pRenderer, &player);
		SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
		SDL_RenderFillRect(m_pRenderer,&Lcontroll);
		SDL_RenderFillRect(m_pRenderer, &Rcontroll);
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