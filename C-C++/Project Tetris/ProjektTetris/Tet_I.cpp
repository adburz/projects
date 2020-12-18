#include "Tet_I.h"
#include "Board.h"

I_type::I_type()
{
	setI();
}

bool I_type::canRotate(Board& field)
{
	if (state == 0)
	{
		if (field.board[field.cy][field.cx + 1] == 0 && field.board[field.cy][field.cx + 2] == 0 && field.board[field.cy][field.cx + 3] == 0)
			if (field.cx + 3 < 10)
				return true;
			else if (canWallJump(field)) {
				return true;
			}
	}
	else if (state == 1)
	{
		if (field.board[field.cy + 1][field.cx] == 0 && field.board[field.cy + 2][field.cx] == 0 && field.board[field.cy + 3][field.cx] == 0)
			return true;
	}
	return false;
}
bool I_type::canWallJump(Board& field)
{
	if (field.board[field.cy][field.cx - 3] == 0 && field.board[field.cy][field.cx - 2] == 0 && field.board[field.cy][field.cx - 1] == 0)
	{
		field.clearTetris();
		if (field.cx + 2 == 9)field.cx--;
		else if (field.cx + 1 == 9)field.cx -= 2;
		else field.cx -= 3;
		return true;
	}
		
	return false;
}
void I_type::rotate(Board& field)
{
	if (canRotate(field))
	{
		std::cout << "rotate:I_type\n";
		field.clearTetris();
		if (state == 0) I_rotStateFirst();
		else if (state == 1) setI();
		field.update(this->colour);

	}
}
void I_type::setI()
{
	clear();
	array[0][0] = true;
	array[1][0] = true;
	array[2][0] = true;
	array[3][0] = true;
	y_max = 3; x_max = 0; state = 0;

}
void I_type::I_rotStateFirst()
{
	clear();
	array[0][0] = true;
	array[0][1] = true;
	array[0][2] = true;
	array[0][3] = true;
	y_max = 0; x_max = 3; state = 1;
}

bool I_type::canFall(int array[Wer][Col], int cx, int cy)
{
	if (cy + this->y_max < 19)
	{
		if (this->state == 0)
		{
			if (array[cy + 4][cx] == 0)
				return true;
		}
		else if (this->state == 1)
		{
			if (array[cy + 1][cx] == 0 && array[cy + 1][cx + 1] == 0 && array[cy + 1][cx + 2] == 0 && array[cy + 1][cx + 3] == 0)
				return true;
		}
	}
	return false;
}
void I_type::fallingMove(Board& field)
{
	if (canFall(field.board, field.cx, field.cy)) {
		std::cout << "fallingMove:I_type\n";
		field.clearTetris();
		field.cy++;
		field.update(this->colour);
	}
}

bool I_type::canMoveLeft(int array[Wer][Col], int cx, int cy)
{
	if (state == 0)
	{
		if (array[cy][cx - 1] == 0 && array[cy + 1][cx - 1] == 0 && array[cy + 2][cx - 1] == 0 && array[cy + 3][cx - 1] == 0)
			return true;
	}
	else if (state == 1)
	{
		if (array[cy][cx - 1] == 0)
			return true;
	}
	return false;
}
bool I_type::canMoveRight(int array[Wer][Col], int cx, int cy)
{
	if (state == 0)
	{
		if (array[cy][cx + 1] == 0 && array[cy + 1][cx + 1] == 0 && array[cy + 2][cx + 1] == 0 && array[cy + 3][cx + 1] == 0)
			return true;
	}
	else if (state == 1)
	{
		if (array[cy][cx + 5] == 0 && cx + 4 <10)
			return true;
	}
	return false;
}

void I_type::moveLeft(Board& field)
{
	field.clearTetris();
	field.cx--;
	field.update(this->colour);
}
void I_type::moveRight(Board& field)
{
	field.clearTetris();
	field.cx++;
	field.update(this->colour);
}