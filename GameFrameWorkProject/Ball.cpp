#include "Ball.h"


Ball::Ball(SDL_Renderer* m_InRenderer,SDL_Surface* InTempSurface,SDL_Texture* m_InTexture,Player* Inplayer )
{
	//BreakBrick의 값을 받아오기
	pTempSurface = InTempSurface;
	m_pRenderer = m_InRenderer;
	m_pTexture = m_InTexture;


	ballPos.VectorX = Inplayer->ReturnPlayer().x+Inplayer->ReturnPlayer().w/2-m_destinationRectangle.w/2;
	ballPos.VectorY = Inplayer->ReturnPlayer().y-m_destinationRectangle.h;

	
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	ReturnBallMoving();
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
		 ballState = "RIGHT_DOWN";
		 
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
		 ReturnBallMoving();
	 }

	 if (ballPos.VectorY <= 30)
	 {
		 ballPos = prePos;
		 ballVector.VectorY *= -1;
		 ReturnBallMoving();
	 }
	
	 else if (Collision::recCollision(player, m_destinationRectangle))// player
	 {	 
		 ballPos.VectorY = player.y - m_destinationRectangle.h;
		 if (m_destinationRectangle.x<=player.x + player.w / 6)
		 {
			 ballVector.VectorX = -Speed;
			 ballVector.VectorY = -Speed;
		 }
		 else if ((player.x + player.w / 6 * 5<= m_destinationRectangle.x) && (m_destinationRectangle.x <= player.x + player.w))
		 {
			 ballVector.VectorX = Speed;
			 ballVector.VectorY = -Speed;
		 }
		 else
		 {
			 ballVector.VectorY *= -1;
		 }
	 }
	
	 for (int i = 0; i <= mymap->ReturnBrickCount(); i++)//brick
	 {
		 ReturnBallMoving();
		 //충돌시
		 if (Collision::recCollision(mymap->ReturnBrickRect()[i], m_destinationRectangle))
		 {
			 ballPos = prePos;
			
			 if (((prePos.VectorY + m_destinationRectangle.h <= mymap->ReturnBrickRect()[i].y && (ballState == "LEFT_UP" || ballState == "RIGHT_UP"))
				 || (prePos.VectorY >= mymap->ReturnBrickRect()[i].y + mymap->ReturnBrickRect()[i].h && (ballState == "LEFT_DOWN" || ballState == "RIGHT_DOWN")))
				 || ((prePos.VectorX + m_destinationRectangle.w <= mymap->ReturnBrickRect()[i].x && (ballState == "LEFT_UP" || ballState == "LEFT_DOWN"))
					 || (prePos.VectorX >= mymap->ReturnBrickRect()[i].x + mymap->ReturnBrickRect()[i].w && (ballState == "RIGHT_UP" || ballState == "RIGHT_DOWN"))))//2개충돌 방지
			 {

			 } 
			 //대각선
			 else if ((prePos.VectorY+m_destinationRectangle.h <= mymap->ReturnBrickRect()[i].y || prePos.VectorY >= mymap->ReturnBrickRect()[i].y + mymap->ReturnBrickRect()[i].h)
				 && (prePos.VectorX+m_destinationRectangle.w <= mymap->ReturnBrickRect()[i].x || prePos.VectorX >= mymap->ReturnBrickRect()[i].x + mymap->ReturnBrickRect()[i].w))
			 {
				 
				 if (ballState == "LEFT_DOWN" || ballState == "RIGHT_DOWN")
				 {
					 if (prePos.VectorY + m_destinationRectangle.h <= mymap->ReturnBrickRect()[i].y)
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
			 //Y
			 else if (prePos.VectorY + m_destinationRectangle.h <= mymap->ReturnBrickRect()[i].y || prePos.VectorY >= mymap->ReturnBrickRect()[i].y + mymap->ReturnBrickRect()[i].h)
			 {
				 //
				 ballVector.VectorY *= -1;
			 }
			 //X
			 else if (prePos.VectorX + m_destinationRectangle.w <= mymap->ReturnBrickRect()[i].x || prePos.VectorX >= mymap->ReturnBrickRect()[i].x + mymap->ReturnBrickRect()[i].w)
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

