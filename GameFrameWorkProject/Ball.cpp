#include "Ball.h"
#include "BreakBrick.h"
#include "Map.h"
Ball::Ball(SDL_Renderer* m_InRenderer,SDL_Surface* InTempSurface,SDL_Texture* m_InTexture )
{
	//BreakBrick의 값을 받아오기
	pTempSurface = InTempSurface;
	m_pRenderer = m_InRenderer;
	m_pTexture = m_InTexture;

	pTempSurface = IMG_Load("Asset/Ball.png");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
}
 void Ball::DrawBall()
{
	 m_destinationRectangle.x = ballPos.VectorX;;
	 m_destinationRectangle.y = ballPos.VectorY;
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
}
 void Ball::ReturnBallMoving() {
	 if ( ballVector.VectorX == 0 && ballVector.VectorY == -Speed)
	 {
		 ballState = "UP";
	 }
	 else if (ballVector.VectorX == 0 && ballVector.VectorY == Speed)
	 {
		 ballState = "DOWN";
	 }
	 else if (ballVector.VectorX == Speed && ballVector.VectorY == -Speed)
	 {
		 ballState = "RIGHT_UP";
		
	 }
	 else if (ballVector.VectorX ==Speed && ballVector.VectorY ==Speed)
	 {
		 ballState == "RIGHT_DOWN";
		 
	 }
	 else if (ballVector.VectorX == -Speed && ballVector.VectorY == -Speed)
	 {
		 ballState = "LEFT_UP";
	 }
	 else if (ballVector.VectorX == -Speed && ballVector.VectorY == Speed)
	 {
		 ballState = "LEFT_DOWN";
	 }
	 else
	 {
		 ballState = "STOP";
	 }
 }
 void Ball::BallMoving(Deltatime deltatime)
 {
	 prePos = ballPos;
	 ballPos.VectorX += ballVector.VectorX*deltatime.ReturnDeltaTime();
	 ballPos.VectorY += ballVector.VectorY*deltatime.ReturnDeltaTime();
 }
void Ball::BallCollision(SDL_Rect player,Map* mymap)
{
	 //벽 충돌처리
	 if (ballPos.VectorX <= 30 || ballPos.VectorX >= 430)
	 {
		 ballPos = prePos;
		 ballVector.VectorX *= -1;
	 }

	 if (ballPos.VectorY <= 30)
	 {
		 ballPos = prePos;
		 ballVector.VectorY *= -1;
	 }
	
	 else if (Collision::recCollision(player, m_destinationRectangle))
	 {
		
			 ballPos.VectorY = player.y - m_destinationRectangle.h;
			 ballVector.VectorY *= -1;
		 
	 }
	
	 for (int i = 0; i <= mymap->ReturnBrickCount(); i++)
	 {
		 if (Collision::recCollision(mymap->ReturnBrickRect()[i], m_destinationRectangle))
		 {
			 ballPos = prePos;
			 if ((prePos.VectorY >= mymap->ReturnBrickRect()[i].h || prePos.VectorY <= mymap->ReturnBrickRect()[i].y + mymap->ReturnBrickRect()[i].h)
				 && (prePos.VectorX <= mymap->ReturnBrickRect()[i].x || prePos.VectorX >= mymap->ReturnBrickRect()[i].x + mymap->ReturnBrickRect()[i].w))
			 {
				 if (ballState == "LEFT_DOWN" || ballState == "RIGHT_DOWN")
				 {
					 if (prePos.VectorY <= mymap->ReturnBrickRect()[i].y)
						 ballVector.VectorY *= -1;
					 else
						 ballVector.VectorX *= -1;
				 }
				 else if (ballState == "LEFT_UP" || ballState == "RIGHT_UP")
				 {
					 if (prePos.VectorY>= mymap->ReturnBrickRect()[i].y+ mymap->ReturnBrickRect()[i].h)
						 ballVector.VectorY*= -1;
					 else
						 ballVector.VectorX *= -1;
				 }
			 }
			 else if (prePos.VectorY >= mymap->ReturnBrickRect()[i].h || prePos.VectorY <= mymap->ReturnBrickRect()[i].y + mymap->ReturnBrickRect()[i].h)
			 {
				 ballVector.VectorY *= -1;
			 }
			 else if (prePos.VectorX <= mymap->ReturnBrickRect()[i].x || prePos.VectorX >= mymap->ReturnBrickRect()[i].x + mymap->ReturnBrickRect()[i].w)
			 {
					 ballVector.VectorX *= -1;
			 }
	
		 }
	 }
	 for (int i = 0; i <= mymap->ReturnBrickCount(); i++)
	 {
		 if (Collision::recCollision(mymap->ReturnBrickRect()[i], m_destinationRectangle))
		 {
			 mymap->ReplaceBrick(i);
		 }
	 }
}

