#include "Ball.h"


Ball::Ball(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setX(Speed);
	m_velocity.setY(-Speed);
}
//
//Ball::Ball(SDL_Renderer* m_InRenderer,SDL_Surface* InTempSurface,SDL_Texture* m_InTexture,Player* Inplayer )
//{
//	//BreakBrick의 값을 받아오기
//	pTempSurface = InTempSurface;
//	m_pRenderer = m_InRenderer;
//	m_pTexture = m_InTexture;
//
//
//	m_position.getX() = Inplayer->ReturnPlayer().x+Inplayer->ReturnPlayer().w/2-m_destinationRectangle.w/2;
//	m_position.getY() = Inplayer->ReturnPlayer().y-m_destinationRectangle.h;
//
//	
//	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
//	ReturnBallMoving();
//}
 void Ball::draw()
{
	 SDLGameObject::draw();
	// m_destinationRectangle.x = m_position.getX();;
	// m_destinationRectangle.y = m_position.getY();
	// SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
}
 void Ball::update()
 {
	 prePos = m_position;
      if (m_position.getX() <= 30 || m_position.getX() >= 430)
      {
     	 m_position = prePos;
     	 m_velocity.setX(m_velocity.getX()*-1);
     	 ReturnBallMoving();
      }
     
      if (m_position.getY() <= 30)
      {
     	 m_position = prePos;
     	 m_velocity.setY(m_velocity.getY()*-1);
     	 ReturnBallMoving();
      }
     
	 SDLGameObject::update();
 }
 void Ball::clean()
 {
 }
void Ball::ReturnBallMoving() {
	 if (m_velocity.getX() == 0 && m_velocity.getY()== -Speed)
	 {
		 ballState = "UP";
	 }
	 else if (m_velocity.getX() == 0 && m_velocity.getY()== Speed)
	 {
		 ballState = "DOWN";
	 }
	 else if (m_velocity.getX() == Speed && m_velocity.getY()== -Speed)
	 {
		 ballState = "RIGHT_UP";
		
	 }
	 else if (m_velocity.getX() ==Speed && m_velocity.getY()==Speed)
	 {
		 ballState = "RIGHT_DOWN";
		 
	 }
	 else if (m_velocity.getX() == -Speed && m_velocity.getY()== -Speed)
	 {
		 ballState = "LEFT_UP";
	 }
	 else if (m_velocity.getX() == -Speed && m_velocity.getY()== Speed)
	 {
		 ballState = "LEFT_DOWN";
	 }
	 else
	 {
		 ballState = "STOP";
	 }
}
void Ball::collision(GameObject* obj)
{

	if (((SDLGameObject*)obj)->m_textureID == "Brick")
	{
		m_position = prePos;
		m_velocity.setY(m_velocity.getY()*-1);
	}
	else if (((SDLGameObject*)obj)->m_textureID == "Player")
	{
		m_position = prePos;
		m_velocity.setY(m_velocity.getY()*-1);
	}
}
//void Ball::BallMoving(Deltatime deltatime)
//{
//	 prePos = m_position;
//	 m_position.getX() += m_velocity.getX()*deltatime.ReturnDeltaTime();
//	 m_position.getY() += ballVector.getY()*deltatime.ReturnDeltaTime();
//}
//void Ball::BallCollision(Player* player,Map* mymap)
//{
//	 //벽 충돌처리
//	 if (m_position.getX() <= 30 || m_position.getX() >= 430)
//	 {
//		 m_position = prePos;
//		 m_velocity.operator*=-1;
//		 ReturnBallMoving();
//	 }
//
//	 if (m_position.getY() <= 30)
//	 {
//		 m_position = prePos;
//		 m_velocity.operator**= -1;
//		 ReturnBallMoving();
//	 }
//	
//	 else if (Collision::recCollision(player,))// player
//	 {	 
//		 m_position.getY() = player->m_width - m_height;
//		 if (m_destinationRectangle.x<=player.x + player.w / 6)
//		 {
//			 m_velocity.getX() = -Speed;
//			 m_velocity.getY()= -Speed;
//		 }
//		 else if ((player.x + player.w / 6 * 5<= m_destinationRectangle.x) && (m_destinationRectangle.x <= player.x + player.w))
//		 {
//			 m_velocity.getX() = Speed;
//			 m_velocity.getY()= -Speed;
//		 }
//		 else
//		 {
//			 m_velocity.getY()*= -1;
//		 }
//	 }
//	
//	 for (int i = 0; i <= mymap->ReturnBrickCount(); i++)//brick
//	 {
//		 ReturnBallMoving();
//		 //충돌시
//		 if (Collision::recCollision(mymap->ReturnBrickRect()[i], m_destinationRectangle))
//		 {
//			 m_position = prePos;
//			
//			 if (((prePos.getY() + m_destinationRectangle.h <= mymap->ReturnBrickRect()[i].y && (ballState == "LEFT_UP" || ballState == "RIGHT_UP"))
//				 || (prePos.getY() >= mymap->ReturnBrickRect()[i].y + mymap->ReturnBrickRect()[i].h && (ballState == "LEFT_DOWN" || ballState == "RIGHT_DOWN")))
//				 || ((prePos.VectorX + m_destinationRectangle.w <= mymap->ReturnBrickRect()[i].x && (ballState == "LEFT_UP" || ballState == "LEFT_DOWN"))
//					 || (prePos.VectorX >= mymap->ReturnBrickRect()[i].x + mymap->ReturnBrickRect()[i].w && (ballState == "RIGHT_UP" || ballState == "RIGHT_DOWN"))))//2개충돌 방지
//			 {
//
//			 } 
//			 //대각선
//			 else if ((prePos.getY()+m_destinationRectangle.h <= mymap->ReturnBrickRect()[i].y || prePos.getY() >= mymap->ReturnBrickRect()[i].y + mymap->ReturnBrickRect()[i].h)
//				 && (prePos.VectorX+m_destinationRectangle.w <= mymap->ReturnBrickRect()[i].x || prePos.VectorX >= mymap->ReturnBrickRect()[i].x + mymap->ReturnBrickRect()[i].w))
//			 {
//				 
//				 if (ballState == "LEFT_DOWN" || ballState == "RIGHT_DOWN")
//				 {
//					 if (prePos.getY() + m_destinationRectangle.h <= mymap->ReturnBrickRect()[i].y)
//						 m_velocity.getY()*= -1;
//					 else
//						 m_velocity.getX() *= -1;
//				 }
//				 else if (ballState == "LEFT_UP" || ballState == "RIGHT_UP")
//				 {
//					 if (prePos.getY()>= mymap->ReturnBrickRect()[i].y+ mymap->ReturnBrickRect()[i].h)
//						 ballVector.getY()*= -1;
//					 else
//						 m_velocity.getX() *= -1;
//				 }
//			 }
//			 //Y
//			 else if (prePos.getY() + m_destinationRectangle.h <= mymap->ReturnBrickRect()[i].y || prePos.getY() >= mymap->ReturnBrickRect()[i].y + mymap->ReturnBrickRect()[i].h)
//			 {
//				 //
//				 m_velocity.getY()*= -1;
//			 }
//			 //X
//			 else if (prePos.VectorX + m_destinationRectangle.w <= mymap->ReturnBrickRect()[i].x || prePos.VectorX >= mymap->ReturnBrickRect()[i].x + mymap->ReturnBrickRect()[i].w)
//			 {
//					 m_velocity.getX() *= -1;
//			 }
//			
//		 }
//	 }
//	 for (int i = 0; i <= mymap->ReturnBrickCount(); i++)
//	 {
//		 if (Collision::recCollision(mymap->ReturnBrickRect()[i], m_destinationRectangle))
//		 {
//			 mymap->ReplaceBrick(i);
//		 }
//	 }
//}
//
//