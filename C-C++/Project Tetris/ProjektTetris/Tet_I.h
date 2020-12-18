#pragma once
#include "Tet.h"
class Tet;
class I_type :public Tet
{
public:
	I_type();
	void rotate(Board& field) ;
private:
	int state;
	void setI();
	void I_rotStateFirst();
	bool canFall(int array[Wer][Col], int cx, int cy) ;
	void fallingMove(Board& field) ;

	bool canWallJump(Board& field);
	bool canMoveLeft(int array[Wer][Col], int cx, int cy) ;
	bool canMoveRight(int array[Wer][Col], int cx, int cy) ;
	void moveLeft(Board& field) ;
	void moveRight(Board& field) ;

	bool canRotate(Board& field);
};