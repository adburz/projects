#include "HotelBook_loadBed.h"

int loadBed(struct room **_rooms, int *bed_count)
{
	if (bedCount(&(*_rooms), &(*bed_count)))
		return goToDateCheck;
	return 0;
}

int bedCount(struct room **_rooms, int *bed_count)
{
	struct room *pHead = *_rooms;
	int typesOfRooms[10] = { 0 };
	int bedNumber = 0, i = 0, result = 0;
	printf("\nBed number? (");
	bedNumber = (*_rooms)->bed_number;
	typesOfRooms[i] = bedNumber;
	printf("%d", bedNumber);
	while ((*_rooms) != NULL)		//wypisuje w taki sposob, zeby uniknac wypisania numeru ktory nie istnieje.
	{
		if (bedNumber != (*_rooms)->bed_number)
		{
			bedNumber = (*_rooms)->bed_number;
			if (thereWereThisNumber(typesOfRooms, bedNumber))
			{
				printf(", %d", bedNumber);
			}
			typesOfRooms[++i] = bedNumber;
		}
		(*_rooms) = (*_rooms)->pNext;
	}
	(*_rooms) = pHead;
	printf(")\nEnter bed number: ");
	scanf_s("%d", &(*bed_count), 1);
	clear();
	for (int j = 0; j < i +1; j++)
	{
		if ((*bed_count) == typesOfRooms[j])
			result = 1;
	}
	if (result)
		return 1;
	printf("Wrong type of room.");
	return 0;
}