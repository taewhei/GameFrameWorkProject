#include "Game.h"
#include "Ball.h"
#include "Map.h"
#include"Brick.h"
#include "Player.h"
#include"TextureManager.h"
#include"InputHandler.h"
#include"Collision.h"
#include"MenuState.h"
#include"PlayState.h"

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
		m_bRunning = true;
		deltatime = new Deltatime();
		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(PlayState::Instance());
		
		/*TheTextureManager::Instance()->load("Asset/Player.png", "Player", m_pRenderer);
		TheTextureManager::Instance()->load("Asset/Brick.png", "Brick", m_pRenderer); 
		TheTextureManager::Instance()->load("Asset/non_Brick.png", "non_Brick", m_pRenderer);
		TheTextureManager::Instance()->load("Asset/Ball.png", "Ball", m_pRenderer);

		m_gameObjects.push_back(new Player(new LoaderParams(180,455,120,40, "Player")));
		Mymap::Instance()->InitMap();
		brickRect = Mymap::Instance()->ReturnBrickRect();
		non_brickRect = Mymap::Instance()->ReturnNon_BrickRect();
		for (int i = 0; i < MAXBRICK; i++)
		{
			m_gameObjects.push_back(new Brick(new LoaderParams(brickRect[i].x, brickRect[i].y, brickRect[i].w,
				brickRect[i].h, "Brick")));
		}
		for (int i = 0; i < 44; i++)
		{
			m_gameObjects.push_back(new Brick(new LoaderParams(non_brickRect[i].x, non_brickRect[i].y, non_brickRect[i].w,
				non_brickRect[i].h, "non_Brick")));
		}
	
		m_gameObjects.push_back(new Ball(new LoaderParams(200, 425, 20, 20, "Ball")));*/
	}
	else {
		return false; // sdl could not initialize
	}
	return true;

}
void Game::update()
{
	deltatime->DoDeltaTime();	

	//brickRect = mymap->ReturnBrickRect();
	m_pGameStateMachine->update();
	//for (std::vector<GameObject*>::size_type i = 0;
	//	i != m_gameObjects.size(); i++)
	//{
	//	m_gameObjects[i]->update();
	//}
	//Mymap::Instance()->UpdateMap(m_gameObjects);
}
void Game::render()
{
	
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	//for (std::vector<GameObject*>::size_type i = 0;
	//	i != m_gameObjects.size(); i++)
	//{
	//	m_gameObjects[i]->draw();
	//}
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer); // draw to the screen
	
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
	m_pGameStateMachine->collision();
}
void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}
void Game::quit()
{
	m_bRunning = false;
}