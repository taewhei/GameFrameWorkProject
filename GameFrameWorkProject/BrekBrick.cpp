#include <iostream>
#include "BreakBrick.h"

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
	return 0;
}
void BreakBrick::update()
{
	
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_Rect rect = { 10,10,40,40 };
	SDL_SetRenderDrawColor(m_pRenderer, 10, 50, 10, 255);
	SDL_RenderDrawRect(m_pRenderer, &rect);
	//SDL_RenderFillRect(m_pRenderer, &rect);
}
void BreakBrick::render()
{
	SDL_RenderPresent(m_pRenderer);
	SDL_RenderClear(m_pRenderer);
	
}
void BreakBrick::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
void BreakBrick::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}