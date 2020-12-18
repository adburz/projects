#pragma once
#include "Tet.h"
#include "Board.h"

class Tet;
class D_type : public Tet
{
public:
	D_type();
	//!rotating does nothing
	void rotate(Board &field) override;
private:	
	void fallingMove(Board& field) override;
	bool canMoveLeft(int array[Wer][Col], int cx, int cy) override;
	bool canMoveRight(int array[Wer][Col], int cx, int cy) override;
	bool canFall(int array[Wer][Col], int cx, int cy)override;
	void moveLeft(Board& field)override;
	void moveRight(Board& field)override;
	void setD();
};