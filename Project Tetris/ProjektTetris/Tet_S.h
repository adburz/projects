#pragma once
#include "Tet.h"
class Tet;
class S_type : public Tet
{
public:
	S_type();
	void rotate(Board& field) ;
private:
	int state;
	void setS();
	void S_rotStateFirst();

	bool canRotate(Board& field);
	bool canFall(int array[Wer][Col], int cx, int cy) ;
	void fallingMove(Board& field) ;

	bool canMoveLeft(int array[Wer][Col], int cx, int cy) ;
	bool canMoveRight(int array[Wer][Col], int cx, int cy) ;
	void moveLeft(Board& field) ;
	void moveRight(Board& field) ;
};