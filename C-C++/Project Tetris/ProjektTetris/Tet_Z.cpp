#include "Tet_Z.h"
#include "Board.h"

Z_type::Z_type()
{
	setZ();
}

bool  Z_type::canRotate(Board& field)
{
	if(state==0)
	{ 
		if (field.board[field.cy + 1][field.cx] == 0 && field.board[field.cy + 2][field.cx] == 0)
			return true;
	}
	else if (state == 1)
	{
		if (field.board[field.cy][field.cx] == 0 && field.board[field.cy + 1][field.cx+2] == 0)
		{
			if (field.cx + 3 < 10)
				return true;
			else if (canMoveLeft(field.board, field.cx, field.cy))
			{
				moveLeft(field);
				return true;
			}
		}
	}
	return false;
}
void Z_type::rotate(Board& field)
{
	if (canRotate(field))
	{
		std::cout << "rotate:Z_type\n";
		field.clearTetris();
		if (state == 0) Z_rotStateFirst();
		else if (state == 1) setZ();
		field.update(this->colour);

	}
}
void Z_type::Z_rotStateFirst()
{
	clear();
	array[0][1] = true;
	array[1][1] = true;
	array[1][0] = true;
	array[2][0] = true;
	x_max = 1; y_max = 2; state = 1;
}
void Z_type::setZ()
{
	clear();
	array[0][0] = true;
	array[0][1] = true;
	array[1][1] = true;
	array[1][2] = true;
	x_max = 2;
	y_max = 1;
	state = 0;
}

bool Z_type::canFall(int array[Wer][Col], int cx, int cy)
{
	if (cy + this->y_max < 19)
	{
		if (this->state == 0)
		{
			if (array[cy + 1][cx] == 0 && array[cy + 2][cx + 1] == 0 && array[cy + 2][cx + 2] == 0)
				return true;
		}
		else if (this->state == 1)
		{
			if (array[cy + 3][cx] == 0 && array[cy + 2][cx + 1] == 0)
				return true;
		}
	}
	return false;
}
void Z_type::fallingMove(Board& field)
{
	if (canFall(field.board, field.cx, field.cy)) {
		std::cout << "fallingMove:Z_type\n";
		field.clearTetris();
		field.cy++;
		field.update(this->colour);
	}
}

bool Z_type::canMoveLeft(int array[Wer][Col], int cx, int cy)
{
	if (state == 0)
	{
		if (array[cy][cx - 1] == 0 && array[cy + 1][cx ] == 0)
			return true;
	}
	else if (state == 1)
	{
		if (array[cy][cx] == 0 && array[cy+1][cx - 1] == 0 && array[cy+2][cx - 1] == 0)
			return true;
	}
	return false;
}
bool Z_type::canMoveRight(int array[Wer][Col], int cx, int cy)
{
	if (state == 0)
	{
		if (array[cy][cx + 2] == 0 && array[cy + 1][cx+3] == 0 && cx + 3 < 10)
			return true;
	}
	else if (state == 1)
	{
		if (array[cy][cx+2] == 0 && array[cy + 1][cx +2] == 0 && array[cy + 2][cx + 1] == 0 && cx + 2 < 10)
			return true;
	}
	return false;
}

void Z_type::moveLeft(Board& field)
{
	field.clearTetris();
	field.cx--;
	field.update(this->colour);
}
void Z_type::moveRight(Board& field)
{
	field.clearTetris();
	field.cx++;
	field.update(this->colour);
}
