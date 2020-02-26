#pragma once
#include "Tet.h"
class Tet;
class T_type : public Tet
{
	
public:
	T_type();
	void rotate(Board& field) ;
private:
	int state;
	void setT();
	void T_rotStateFirst();
	void T_rotStateSecond();
	void T_rotStateThird();

	bool canRotate(Board& field);
	bool canFall(int array[Wer][Col], int cx, int cy) ;
	void fallingMove(Board& field) ;

	bool canMoveLeft(int array[Wer][Col], int cx, int cy) ;
	bool canMoveRight(int array[Wer][Col], int cx, int cy) ;
	void moveLeft(Board& field) ;
	void moveRight(Board& field) ;
};