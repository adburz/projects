#pragma once
#include "Core.h"
#include "ConstantVar.h"

class Board;
class Tet
{
	friend class Board;
public:
	int colour;
	int x_max, y_max;
	//funkcja rotujaca klocek
	virtual void rotate(Board& field) = 0;
	//funkcja sprawdzajaca czy klocek ma pod soba miejsce i moze spasc
	virtual bool canFall(int array[Wer][Col], int cx, int cy) = 0;
	virtual void fallingMove(Board& field) = 0;
	//funkcje poruszajace klockiem w lewo/prawo
	virtual void moveLeft(Board& field) = 0;
	virtual void moveRight(Board& field) = 0;
	//funkcje sprawdzajace czy klocek moze sie poruszyc w lewo/prawo
	virtual bool canMoveLeft(int array[Wer][Col], int cx, int cy) = 0;
	virtual bool canMoveRight(int array[Wer][Col], int cx, int cy) = 0;
	bool array[4][4] = { false };
protected:
	void clear() {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) array[i][j] = false;
	}
};