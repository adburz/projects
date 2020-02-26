#include "Reservation.h"

int findLastResNumber(struct reservation **_reservation)
{
	struct reservation *pHead = *_reservation;
	int res = pHead->resNumber;
	while (pHead != NULL)
	{
		if (res < pHead->resNumber)
		{
			res = pHead->resNumber;
		}
		pHead = pHead->pNext;
	}
	return res;
}
int compareUserNames(struct user **_user, struct reservation **_reservation)
{
	if (strcmp((*_user)->name, (*_reservation)->name) != 0)
	{
		printf("\nThat's not your reservation!");
		return 0;
	}
	else if (strcmp((*_user)->surname, (*_reservation)->surname) != 0)
	{
		printf("\nThat's not your reservation!");
		return 0;
	}
	return 1;
}
