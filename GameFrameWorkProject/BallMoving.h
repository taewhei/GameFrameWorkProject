#pragma once
#include "Define.h"
struct BallMoving
{
	Vector Ballmoving;
	string ballState;

	void ReturnBallmoving() {
		if (ballState == "UP")
		{
			Ballmoving.VectorY -= 0.15f;
		}
		else if (ballState == "DOWN")
		{
			Ballmoving.VectorY += 0.15f;
		}
		else if (ballState == "RIGHT_UP")
		{
			Ballmoving.VectorX += 0.15f;
			Ballmoving.VectorY -= 0.15f;
		}
		else if (ballState == "RIGHT_DOWN")
		{
			Ballmoving.VectorX += 0.15f;
			Ballmoving.VectorY += 0.15f;
		}
		else if (ballState == "LEFT_UP")
		{
			Ballmoving.VectorX -= 0.15f;
			Ballmoving.VectorY -= 0.15f;
		}
		else if (ballState == "LEFT_DOWN")
		{
			Ballmoving.VectorX -= 0.15f;
			Ballmoving.VectorY += 0.15f;
		}
	}
};
