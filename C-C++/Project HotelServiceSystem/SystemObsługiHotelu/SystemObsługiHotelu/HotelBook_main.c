#include "HotelBook_main.h"


int book_room(struct room **_rooms, struct user **_user)
{
	time_t wanted_time_from;
	time_t wanted_time_to;
	int dd_f = 0, dd_t = 0, mm_f = 0, mm_t = 0, yy_f = 0, yy_t = 0, bed_count = 0, loopBreaker = 5, changerB = 1;
	system("cls");
	do
	{
		switch (changerB)
		{
		case 0:
			changerB = getBack(loopBreaker);
			break;
		case 1:
			changerB = loadTerm(&(*_rooms), &wanted_time_from, &wanted_time_to, &dd_f, &mm_f, &yy_f, &dd_t, &mm_t, &yy_t);
			break;
		case 2:
			changerB = loadBed(&(*_rooms), &bed_count);
			break;
		case 3:
			changerB = dateCheck(&(*_rooms), &(*_user), &bed_count, wanted_time_from, wanted_time_to);
			break;
		}
	} while (changerB != loopBreaker);
	return returnToMenu;
}
int getBack(int *loopBreaker)
{
	printf("\n\nWould you like to get back into main menu?\n(1-yes, 0-no): ");
	char tmp;
	tmp = getc(stdin);
	clear();
	if (tmp == '0')
		return 1;
	else
	{
		return loopBreaker;
	}
}