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

	ballVector.VectorX = 0.5f;
	ballVector.VectorY = -0.5f;

	pTempSurface = IMG_Load("Asset/Ball.png");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	m_sourceRectangle = { 0,0,401,411 };
	m_destinationRectangle = { 240,420,30,30 };



	return 0;
}
void BreakBrick::update()
{

	LAST = NOW;
	NOW = SDL_GetPerformanceCounter();

	deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

}
void BreakBrick::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer);
	map();
	Ball();
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

void BreakBrick::object()
{

}
void BreakBrick::map()
{
	int nWidth = 16;
	int nHeight = 15;
	char level[15][17] = {
		{"################"},
		{"#**************#"},
		{"#**************#"},
		{"#**************#"},
		{"#**************#"},
		{"#**************#"},
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

	for (int y=0; y < nHeight; y++)
	{
		for (int x=0; x < nWidth; x++)
		{
			SDL_Rect rect = { x * 30,y * 30,30,30 };
			switch (level[y][x])
			{
			case '#':
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
				SDL_RenderFillRect(m_pRenderer, &rect);
				break;
			case '*':
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
				SDL_RenderFillRect(m_pRenderer, &rect);
				break;
			}
		}
	}
}
void BreakBrick :: Ball()
{
	if (ballPos.VectorX <= 30||ballPos.VectorX>=420)
	{
		ballPos = prePos;
		ballVector.VectorX *= -1;
	}
	if (ballPos.VectorY <= 30 || ballPos.VectorY>=450)
	{
		ballPos = prePos;
		ballVector.VectorY *= -1;
	}
	prePos = ballPos;
	ballPos.VectorX += ballVector.VectorX*deltaTime;
	ballPos.VectorY += ballVector.VectorY*deltaTime;
	m_destinationRectangle.x = ballPos.VectorX;
	m_destinationRectangle.y = ballPos.VectorY;
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

}