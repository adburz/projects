#pragma once
#include "Tet.h"

class Tet;
class rL_type : public Tet
{
public:
	rL_type();
	void rotate(Board& field) ;
private:
	int state;
	void setrL();
	void rL_rotStateFirst();
	void rL_rotStateSecond();
	void rL_rotStateThird();
	bool canFall(int array[Wer][Col], int cx, int cy) ;
	void fallingMove(Board& field) ;
	bool canMoveLeft(int array[Wer][Col], int cx, int cy) ;
	bool canMoveRight(int array[Wer][Col], int cx, int cy) ;
	
	bool canRotate(int array[Wer][Col], int& cx, int cy, Board& field);
	void moveLeft(Board& field) ;
	void moveRight(Board& field) ;
};