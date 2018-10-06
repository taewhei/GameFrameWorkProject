#include "BreakBrick.h"
#include "Ball.h"
#include "Map.h"
#include "Player.h"
bool BreakBrick::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		if (fullscreen == true)
		{
			m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_FULLSCREEN);
		}
		else
		{
			m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

		}
	}
	else {
		return 1;
	}

	deltatime = new Deltatime();	
	mymap = new Map(m_pRenderer);
	myball=new Ball(m_pRenderer, pTempSurface, m_pTexture);
	player = new Player(m_pRenderer);
	
	return 0;
}
void BreakBrick::update()
{
	deltatime->DoDeltaTime();
	myball->BallCollision(player->ReturnPlayer(),mymap);
	myball->ReturnBallMoving();
	myball->BallMoving(*deltatime);

}
void BreakBrick::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer);
	mymap->DrawMap();
	myball->DrawBall();
	player->DrawPlayer();
	SDL_RenderPresent(m_pRenderer);
	
}
void BreakBrick::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyTexture(m_pTexture);
	SDL_Quit();
}
void BreakBrick::handleEvents()
{
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			player->PlayerMove(event);
			break;
		case SDL_QUIT:
			m_bRunning = false;
			break;
		}
	}
}




