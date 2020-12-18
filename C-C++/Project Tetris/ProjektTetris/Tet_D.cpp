#include "Tet_D.h"
#include "Board.h"
#define IF_CAN_GO_RIGHT_X 2
#define IF_CAN_GO_LEFT_X 1
#define IF_CAN_GO_WITH_Y 1

#define FALLING_DOWN_Y 2
#define FALLING_DOWN_X 1

//! W SPRAWOZDANIU JAKIŒ RYSUNEK FUNKCJI canMoveR/L ?

D_type::D_type()
{
	setD();
}

void D_type::setD()
{
	clear();
	array[0][0] = true;
	array[0][1] = true;
	array[1][0] = true;
	array[1][1] = true;
	x_max = 1;
	y_max = 1;
}

void D_type::rotate(Board& field)
{
	return;
}

bool D_type::canMoveLeft(int array[Wer][Col], int cx, int cy)
{
	if (array[cy][cx - IF_CAN_GO_LEFT_X] == 0 && array[cy + IF_CAN_GO_WITH_Y][cx - IF_CAN_GO_LEFT_X] == 0)
		return true;
	else return false;
}
bool D_type::canMoveRight(int array[Wer][Col], int cx, int cy)
{
	if (array[cy][cx + IF_CAN_GO_RIGHT_X] == 0 && array[cy + IF_CAN_GO_WITH_Y][cx + IF_CAN_GO_RIGHT_X] == 0 && cx+ IF_CAN_GO_RIGHT_X <10)
		return true;
	else return false;
}

void D_type::moveLeft(Board& field)
{
	field.clearTetris();
	field.cx--;
	field.update(this->colour);
}
void D_type::moveRight(Board& field)
{
	field.clearTetris();
	field.cx++;
	field.update(this->colour);

}
void D_type::fallingMove(Board& field)
{
	if (canFall(field.board, field.cx, field.cy)) {
		field.clearTetris();
		field.cy++;
		field.update(this->colour);
	}
	return;
}

bool D_type::canFall(int array[Wer][Col], int cx, int cy)
{
	if ((array[cy + FALLING_DOWN_Y][cx] == 0) && (array[cy + FALLING_DOWN_Y][cx + FALLING_DOWN_X] == 0) && (cy+this->y_max)<19)	
		return true;
	return false;
}