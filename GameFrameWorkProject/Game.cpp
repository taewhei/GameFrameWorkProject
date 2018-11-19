#include "Game.h"
#include "Ball.h"
#include "Map.h"
#include"Brick.h"
#include "Player.h"
#include"TextureManager.h"
#include"InputHandler.h"
#include"Collision.h"

Game* Game::s_pInstance = 0;

Game* Game::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new Game();
		return s_pInstance;
	}
	return s_pInstance;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		pTempSurface = IMG_Load("Asset/Brick.png");
		SDL_SetWindowIcon(m_pWindow,pTempSurface);
		mymap = new Map(m_pRenderer);
		m_bRunning = true;
		deltatime = new Deltatime();
		TheTextureManager::Instance()->load("Asset/Player.png", "Player", m_pRenderer);
		TheTextureManager::Instance()->load("Asset/Brick.png", "Brick", m_pRenderer); 
		TheTextureManager::Instance()->load("Asset/Ball.png", "Ball", m_pRenderer);


		m_gameObjects.push_back(new Player(new LoaderParams(180,445,120,40, "Player")));
		mymap->UpdateMap();
		brickRect = mymap->ReturnBrickRect();
		for (int i = 0; i < MAXBRICK; i++)
		{
			m_gameObjects.push_back(new Brick(new LoaderParams(brickRect[i].x, brickRect[i].y, brickRect[i].w,
				brickRect[i].h, "Brick")));
		}
	
		m_gameObjects.push_back(new Ball(new LoaderParams(200, 425, 20, 20, "Ball")));
	}
	else {
		return false; // sdl could not initialize
	}
	return true;

}
void Game::update()
{
	deltatime->DoDeltaTime();	
	mymap->UpdateMap();
	brickRect = mymap->ReturnBrickRect();
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	//myball->ReturnBallMoving();
	//myball->BallCollision(player->ReturnPlayer(),mymap);
	//myball->BallMoving(*deltatime);

}
void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	mymap->UpdateMap();
	SDL_RenderPresent(m_pRenderer); // draw to the screen

//SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
//SDL_RenderClear(m_pRenderer);
//mymap->DrawMap();
//myball->DrawBall();
//player->DrawPlayer();
//SDL_RenderPresent(m_pRenderer);
	
}
void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyTexture(m_pTexture);
	SDL_Quit();
}
void Game::collision()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		for (std::vector<GameObject*>::size_type j = i+1;
			j != m_gameObjects.size(); j++)
		{
			if (TheCollision::Instance()->RecColl(m_gameObjects[i], m_gameObjects[j])&&(((SDLGameObject*)m_gameObjects[i])->m_textureID != ((SDLGameObject*)m_gameObjects[j])->m_textureID))
			{
				m_gameObjects[i]->collision(m_gameObjects[j]);
				m_gameObjects[j]->collision(m_gameObjects[i]);
				break;
			}
	
		}
		
	}
}
void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}
void Game::quit()
{
	m_bRunning = false;
}




