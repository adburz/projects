#include "Reservation_erasing.h"

void clearReservations(struct reservation **res)
{
	if (*res != NULL)
	{
		struct reservation *tmp = NULL;
		while (*res != NULL)
		{
			tmp = *res;
			*res = (*res)->pNext;
			free(tmp->name);
			free(tmp->surname);
			free(tmp);
			tmp = NULL;
		}
	}
	return;
}
void freeReservation(struct reservation **_res)
{
	free((*_res)->name);
	free((*_res)->surname);
	free((*_res));
	(*_res) = NULL;
	printf("\nYou've deleted reservation!");
}
struct reservation  *deleteFirstRes(struct reservation **_res)
{
	struct reservation *pHead = (*_res)->pNext;
	free((*_res)->name);
	free((*_res)->surname);
	free((*_res));
	(*_res) = NULL;
	(*_res) = pHead;
	printf("\nYou've deleted reservation!");
	return *_res;
}
int eraseReservation(struct room **_rooms, struct user **_user)
{
	int roNumber, reNumber;
	char answear;
	if (*_rooms != NULL)
	{
		printf("Enter the number of your room:");
		scanf_s("%d", &roNumber, 1);
		clear();
		printf("Enter the number of your reservation:");
		scanf_s("%d", &reNumber, 1);
		clear();

		printf("Are you sure to delete your reservation?\n(1-yes, 0-no):");
		answear = getc(stdin);
		clear();
		if (answear == '1')
		{
			struct room *pRoomHead = *_rooms;
			while ((*_rooms)->number != roNumber)
			{
				(*_rooms) = (*_rooms)->pNext;
				if ((*_rooms) == NULL)
				{
					printf("\nCan't find your reservation.");
					(*_rooms) = pRoomHead;
					return ifYouStay;
				}
			}
			//jesli nie ma rezerwacji pod danym numerem
			if ((*_rooms)->_reservation == NULL)
			{
				printf("\nCan't find your reservation.");
				(*_rooms) = pRoomHead;
				return ifYouStay;
			}
			//jesli szukana rezerwacja jest pierwsza
			else if ((*_rooms)->_reservation->resNumber == reNumber)
			{
				if ((*_user)->isAdmin == false)
				{
					if (!compareUserNames(&(*_user), &(*_rooms)->_reservation)) {
						(*_rooms) = pRoomHead;
						return ifYouStay;
					}
				}
				(*_rooms)->_reservation = deleteFirstRes(&(*_rooms)->_reservation);
				(*_rooms) = pRoomHead;
				return ifYouStay;
			}
			else if (findResIfNotFirst(&(*_user), (&(*_rooms)->_reservation), reNumber))
			{
				*_rooms = pRoomHead;
				return ifYouStay;
			}
		}
		else
			return ifYouStay;
	}
	printf("There is no rooms.");
	return ifYouStay;
}

int findResIfNotFirst(struct user **_user, struct reservation **_res, int reNumber)
{
	struct reservation *resTmp = *_res;
	struct reservation *pPrev = *_res;
	while (resTmp->resNumber != reNumber)
	{
		if (resTmp->pNext == NULL)
		{
			printf("\nCan't find your reservation.");
			return 0;
		}
		pPrev = resTmp;
		resTmp = resTmp->pNext;
	}
	//czy ostatni element
	if (resTmp->pNext == NULL)
	{
		if ((*_user)->isAdmin == false)
		{
			if (!compareUserNames(&(*_user), &resTmp))
				return 0;
		}
		freeReservation(&resTmp);
		pPrev->pNext = NULL;
		return 1;
	}
	//czy na pewno dobra rezerwacja
	else if ((*_user)->isAdmin == false)
	{
		if (!compareUserNames(&(*_user), &resTmp))
			return 0;
	}

	pPrev->pNext = resTmp->pNext;
	freeReservation(&resTmp);
	return 1;
}