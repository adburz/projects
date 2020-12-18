#include "HotelBook_dateCheck.h"

int dateCheck(struct room **_rooms, struct user **_user, int *bed_count, time_t wt_f, time_t wt_t)
{
	char name[30];
	char surname[30];
	if ((*_user)->isAdmin == true)
	{
		printf("\nEnter name:");
		scanf_s("%s", &name, 30);
		clear();
		printf("Enter surname:");
		scanf_s("%s", &surname, 30);
		clear();
	}
	else
	{
		strcpy(name, (*_user)->name);
		strcpy(surname, (*_user)->surname);
	}
	struct room *pHead = (*_rooms);
	struct room *curRoom = findRoom(&(*_rooms), &(*bed_count));
	struct reservation *searchRes = curRoom->_reservation;
	struct reservation *pResHead = NULL;
	int changerC = 1, changerD = 1, changerE = 1;
	while (changerC == 1 && curRoom->bed_number == (*bed_count))
	{
		pResHead = searchRes;
		if (searchRes == NULL)
		{
			printf("Number of your room:%d", curRoom->number);
			addNew(&searchRes, wt_f, wt_t, &name, &surname);
			changerC = 0;
			break;
		}
		else
		{
			//dodajemy na poczatek
			if (wt_t < searchRes->t_from)
			{
				printf("Number of your room:%d", curRoom->number);
				addOnBegining(&searchRes, wt_f, wt_t, &name, &surname);
				changerC = 0;
				break;
			}
			while (searchRes != NULL && changerD == 1)
			{
				if (wt_t == searchRes->t_from || wt_t == searchRes->t_to || wt_f == searchRes->t_from || wt_f == searchRes->t_to)
					break;
				else if (wt_f > searchRes->t_to)
				{
					//je¿eli na koñcu
					if (searchRes->pNext == NULL)
					{
						printf("Number of your room:%d", curRoom->number);
						addAtTheEnd(&searchRes, &pResHead, wt_f, wt_t, &name, &surname);
						changerC = 0;
						changerE = 0;
						break;
					}
					else if (wt_t < searchRes->pNext->t_from)
					{
						printf("Number of your room:%d", curRoom->number);
						addBetween(&pResHead, &searchRes, wt_f, wt_t, &name, &surname);
						changerC = 0;
						changerE = 0;
						break;
					}
				}
				if (changerC == 1)
				{
					searchRes = searchRes->pNext;
				}
			}
		}
		if (changerC == 1)
		{
			curRoom = curRoom->pNext;
			searchRes = curRoom->_reservation;
		}
	}
	if (!changerE)
		curRoom->_reservation = pResHead;
	else
		curRoom->_reservation = searchRes;
	(*_rooms) = pHead;
	if (!changerC)
		printf("\nYou've succesfuly reserved a room.");
	else
		printf("\nThere is no empty room for this date.");
	return returnToMenu;
}
struct room *findRoom(struct room **_rooms, int *bed_count)
{
	struct room *tmp = *_rooms;
	while (tmp->bed_number != (*bed_count))
	{
		if (tmp == NULL)
		{
			return NULL;
		}
		tmp = tmp->pNext;
	}
	return tmp;
}