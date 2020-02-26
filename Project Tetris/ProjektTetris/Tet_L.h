#pragma once
#include "Tet.h"

class Tet;
class L_type : public Tet
{
public:
	L_type();
	void rotate(Board &field) ;
private:
	int state;
	void setL();
	void L_rotStateFirst();
	void L_rotStateSecond();
	void L_rotStateThird();

	bool canFall(int array[Wer][Col], int cx, int cy) ;
	void fallingMove(Board& field) ;

	bool canMoveLeft(int array[Wer][Col], int cx, int cy) ;
	bool canMoveRight(int array[Wer][Col], int cx, int cy) ;
	void moveLeft(Board& field) ;
	void moveRight(Board& field) ;

	bool canRotate(Board &field);
};