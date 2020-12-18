#include "HotelRooms.h"



int extraBed(struct room **_rooms)
{
	int roNumber, reNumber;
	printf("Enter number of your room:");
	scanf_s("%d", &roNumber, 1);
	clear();
	printf("Enter number of your reservation:");
	scanf_s("%d", &reNumber, 1);
	clear();
	struct reservation *rTmp = fRoomByReNum(&(*_rooms), roNumber, reNumber);
	if (rTmp == NULL)
	{
		printf("\nCan't find your room/reservation.");
		return ifYouStay;
	}
	else
	{
		printf("\nWould you like to add or to remove extra bed? (1-add, 2-remove):");
		scanf_s("%d", &reNumber, 1);
		if (reNumber == 1)
		{
			rTmp->extra_bed = true;
		}
		else if (reNumber == 2)
		{
			rTmp->extra_bed = false;
		}
		else
			printf("Wrong number.");
	}
	return ifYouStay;
}


int deleteRoom(struct room **_rooms)
{
	struct room *pHead = *_rooms;
	struct room *pPrev = NULL;
	int roomNumber;
	printf("Enter number of room:");
	scanf_s("%d", &roomNumber, 1);
	clear();
	if ((*_rooms)->number == roomNumber)
	{
		pHead = pHead->pNext;
		clearReservations(&(*_rooms)->_reservation);
		free(*_rooms);
		*_rooms = pHead;
		printf("Room has been deleted.");
		return ifYouStay;
	}
	while ((*_rooms)->number != roomNumber)
	{
		if ((*_rooms)->pNext == NULL)
		{
			printf("Can't find room.");
			*_rooms = pHead;
			return ifYouStay;
		}
		pPrev = (*_rooms);
		(*_rooms) = (*_rooms)->pNext;
	}
	clearReservations(&(*_rooms)->_reservation);
	pPrev->pNext = (*_rooms)->pNext;
	free((*_rooms));
	*_rooms = pHead;
	printf("Room has been deleted.");
	return ifYouStay;
}

int printBookedRooms(struct room **_rooms)
{
	struct room *ro_pHead = *_rooms;
	struct room *re_pHead = NULL;
	int m=0;
	while (*_rooms != NULL)
	{
		
		if ((*_rooms)->_reservation != NULL)
		{
			re_pHead = (*_rooms)->_reservation;
			printf(ANSI_COLOR_GREEN "Room number: %d  Bed number:%d" ANSI_COLOR_RESET "\n\n", (*_rooms)->number, (*_rooms)->bed_number);
			while ((*_rooms)->_reservation != NULL)
			{
				printf("Res number:%d",(*_rooms)->_reservation->resNumber);
				printf("   From:");
				printDate((*_rooms)->_reservation->t_from);
				printf("   To:");
				printDate((*_rooms)->_reservation->t_to);
				printf("\n");
				(*_rooms)->_reservation = (*_rooms)->_reservation->pNext;
				m++;
			}
			(*_rooms)->_reservation = re_pHead;
			printf("\n");
		}
		(*_rooms) = (*_rooms)->pNext;
	}
	if (m == 0)
		printf("No rooms were reserved.\n");
	*_rooms = ro_pHead;
	return ifYouStay;
}

struct reservation *fRoomByReNum(struct room **_rooms, int roomNumber, int reservationNumber)
{
	struct room *roTmp = *_rooms;
	if (roTmp != NULL)
	{
		while (roTmp->number != roomNumber)
		{
			if (roTmp->pNext == NULL)
				return NULL;
			roTmp = roTmp->pNext;
		}
		if (roTmp->_reservation != NULL)
		{
			struct reservation *reTmp = roTmp->_reservation;
			while (reTmp->resNumber != reservationNumber)
			{
				if (reTmp->pNext == NULL)
					return NULL;
				reTmp = reTmp->pNext;
			}
			return reTmp;
		}
	}
	return NULL;
}