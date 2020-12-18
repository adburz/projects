#include "Tet_L.h"
#include "Board.h"

#define FALLING_DOWN_X 1


L_type::L_type()
{
	setL();
}
void L_type::setL()
{
	clear();
	array[0][0] = true;
	array[1][0] = true;
	array[2][0] = true;
	array[2][1] = true;
	x_max = 1;
	y_max = 2;
	state = 0;
}

void L_type::rotate(Board& field)
{
	if (canRotate(field))
	{
		std::cout << "rotate:L_type\n";
		field.clearTetris();
		if (state == 0)L_rotStateFirst();
		else if (state == 1) L_rotStateSecond();
		else if (state == 2)  L_rotStateThird();
		else if (state == 3)  setL();
		field.update(this->colour);
	}
}
void L_type::L_rotStateFirst()
{
	clear();
	array[0][0] = true;
	array[0][1] = true;
	array[0][2] = true;
	array[1][0] = true;
	x_max = 2; y_max = 1; state = 1;

}
void L_type::L_rotStateSecond()
{
	clear();
	array[0][0] = true;
	array[0][1] = true;
	array[1][1] = true;
	array[2][1] = true;
	x_max = 1; y_max = 2; state = 2;

}
void L_type::L_rotStateThird()
{
	clear();
	array[0][2] = true;
	array[1][0] = true;
	array[1][1] = true;
	array[1][2] = true;
	x_max = 2; y_max = 1; state = 3;

}

void L_type::fallingMove(Board& field)
{
	if (canFall(field.board, field.cx, field.cy)) {
		std::cout << "fallingMove:L_type\n";
		field.clearTetris();
		field.cy++;
		field.update(this->colour);
	}
}
bool L_type::canFall(int array[Wer][Col], int cx, int cy)
{
	if (cy + this->y_max < 19)
	{
		if (this->state == 0) {
			if (array[cy + y_max + 1][cx] == 0 && array[cy + y_max + 1][cx + 1] == 0)
				return true;
		}
		else if (this->state == 1) { //!w sprawozdaniu jakis rysunek. Jak dokladnie klocek bedzie opadal i jak ja to sprawdzam index po indexie
			if (array[cy + 2][cx] == 0 && array[cy + 1][cx + 1] == 0
				&& array[cy + 1][cx + 2] == 0)
				return true;
		}
		else if (this->state == 2) {
			if (array[cy + 1][cx] == 0 && array[cy + 3][cx + 1] == 0)
				return true;
		}
		else if (this->state == 3) {
			if (array[cy + 2][cx] == 0 && array[cy + 2][cx + 1] == 0 && array[cy + 2][cx + 2] == 0)
				return true;
		}
	}
	return false;
}

bool L_type::canRotate(Board& field)
{
	//? sprawdzane na podstawie kratek czy w danym miejscu bêdzie miejsce na rotate
	if (state == 0){
		if (field.board[field.cy][field.cx + 1] == 0 && field.board[field.cy][field.cx + 2] == 0)
		{
			if (field.cx + 2 < 10)
				return true;
			else if (canMoveLeft(field.board, field.cx, field.cy))
			{
				moveLeft(field);
				return true;
			}
		}
	}
	else if (state == 1){
		if (field.board[field.cy + 1][field.cx + 1] == 0 && field.board[field.cy + 2][field.cx + 1] == 0 && field.cx + 2 < 10)
			return true;
	}
	else if (state == 2){
		if (field.board[field.cy + 1][field.cx] == 0 && field.board[field.cy + 1][field.cx + 2] == 0 && field.board[field.cy][field.cx + 2] == 0)
			if (field.cx + 2 < 10)
				return true;
			else if (canMoveLeft(field.board, field.cx, field.cy))
			{
				moveLeft(field);
				return true;
			}
	}
	else if (state == 3)
		if (field.board[field.cy][field.cx] == 0 && field.board[field.cy + 2][field.cx] == 0 && field.board[field.cy + 2][field.cx + 1] == 0 && field.cx + 2 < 10)
			return true;
	return false;
}

bool L_type::canMoveLeft(int array[Wer][Col], int cx, int cy)
{
	if (state == 0)
	{
		if (array[cy][cx - 1] == 0 && array[cy + 1][cx - 1] == 0 && array[cy + 2][cx - 1] == 0)
			return true;
	}
	else if (state == 1)
	{
		if (array[cy][cx - 1] == 0 && array[cy + 1][cx - 1] == 0)
			return true;
	}
	else if (state == 2)
	{
		if (array[cy][cx - 1] == 0 && array[cy + 1][cx] == 0 && array[cy + 2][cx] == 0)
			return true;
	}
	else if (state == 3)
	{
		if (array[cy][cx + 1] == 0 && array[cy + 1][cx - 1] == 0)
			return true;
	}
	return false;
}
bool L_type::canMoveRight(int array[Wer][Col], int cx, int cy)
{
	if (state == 0)
	{
		if (array[cy][cx + 1] == 0 && array[cy + 1][cx + 1] == 0 && array[cy + 2][cx + 2] == 0 && cx + 2 < 10)
			return true;
	}
	else if (state == 1)
	{
		if (array[cy][cx + 3] == 0 && array[cy + 1][cx + 1] == 0 && cx + 3 < 10)
			return true;
	}
	else if (state == 2)
	{
		if (array[cy][cx + 2] == 0 && array[cy + 1][cx + 2] == 0 && array[cy + 2][cx + 2] == 0 && cx + 2 < 10)
			return true;
	}
	else if (state == 3)
	{
		if (array[cy][cx + 3] == 0 && array[cy + 1][cx + 3] == 0 && cx + 3 < 10)
			return true;
	}
	return false;
}

void L_type::moveLeft(Board& field)
{
	field.clearTetris();
	field.cx--;
	field.update(this->colour);
}
void L_type::moveRight(Board& field)
{
	field.clearTetris();
	field.cx++;
	field.update(this->colour);
}
