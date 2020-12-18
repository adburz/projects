#include "HotelReadSave.h"



int rooms_save(struct room **_hotel)
{
	FILE *saving_file = fopen("rooms.txt", "w");
	
	if (saving_file)
	{
		struct room *ro_pHead = *_hotel;
		struct reservation *re_pHead = NULL;
		while ((*_hotel) != NULL)
		{	
			fprintf(saving_file, "%d;%d;", (*_hotel)->number, (*_hotel)->bed_number);
			re_pHead = (*_hotel)->_reservation;

			while ((*_hotel)->_reservation != NULL)
			{
				fprintf(saving_file, "%s.%s", (*_hotel)->_reservation->name, (*_hotel)->_reservation->surname);

				fprintf(saving_file, ".");
				fprintf(saving_file, "%d", (*_hotel)->_reservation->resNumber);
				fprintf(saving_file, ".");
				fprintf(saving_file, "%d", (*_hotel)->_reservation->extra_bed);
				fprintf(saving_file, ".");
				fprintf(saving_file, "%d", (*_hotel)->_reservation->t_from);
				fprintf(saving_file, ".");
				fprintf(saving_file, "%d", (*_hotel)->_reservation->t_to);
				if ((*_hotel)->_reservation->pNext != NULL)
					fprintf(saving_file, ".");
				(*_hotel)->_reservation = (*_hotel)->_reservation->pNext;
			}
			(*_hotel)->_reservation = re_pHead;

			fprintf(saving_file, "\n");
			(*_hotel) = (*_hotel)->pNext;
		}
		*_hotel = ro_pHead;
		fclose(saving_file);
		return 1;
	}
	else
	{
		printf("Can't open file.");
	}
	return 0;
}

int load_rooms(struct room **_rooms)
{
	FILE *in_data = fopen("rooms.txt", "r");
	//nr pokoju;ilosc lozek;imie;nazwisko;(od)d.m.r;(do)d.m.r;imie;nazwisko;(od)...
	if (in_data)
	{
		struct room *pHeadRoom = NULL;
		char *tmp;
		int roomNumber = 0;
		char *room_data = (char*)calloc(1, 200 * sizeof(char));
		char *position;
		char tmpArr[30];

		while (fscanf(in_data, "%s", room_data) != EOF)
		{
			if ((*_rooms) != NULL)
			{
				(*_rooms)->pNext = (struct room*)calloc(1, sizeof(struct room));
				(*_rooms) = (*_rooms)->pNext;
			}
			else
			{
				*_rooms = (struct room*)calloc(1, sizeof(struct room));
				pHeadRoom = *_rooms;
			}
			//LOADING ROOM NUMBER
			tmp = strtok_s(room_data, ";", &position);
			strcpy(tmpArr, tmp);
			roomNumber = atoi(tmpArr);
			(*_rooms)->number = roomNumber;
			//LOADING BED NUMBER
			tmp = strtok_s(position, ";", &position);
			strcpy(tmpArr, tmp);
			roomNumber = atoi(tmpArr);
			(*_rooms)->bed_number = roomNumber;

			struct reservation *resTmp = NULL;
			(*_rooms)->_reservation = NULL;

			while ((tmp = strtok_s(position, ".", &position)) != NULL)
			{
				if ((*_rooms)->_reservation != NULL)
				{
					(*_rooms)->_reservation->pNext = (struct reservation*)calloc(1,sizeof(struct reservation));
					(*_rooms)->_reservation = (*_rooms)->_reservation->pNext;
				}
				else
				{
					(*_rooms)->_reservation = (struct reservation*)calloc(1, sizeof(struct reservation));
					resTmp = (*_rooms)->_reservation;
				}
				//NAME
				strcpy(tmpArr, tmp);
				(*_rooms)->_reservation->name = (char*)calloc(strlen(tmpArr) + 1, sizeof(char));
				strcpy((*_rooms)->_reservation->name, tmpArr);
				//SURNAME
				tmp = strtok_s(position, ".", &position);
				(*_rooms)->_reservation->surname = (char*)calloc(strlen(tmp) + 1, sizeof(char));
				strcpy(tmpArr, tmp);
				strcpy((*_rooms)->_reservation->surname, tmpArr);
				//RESERVATION NUMBER
				tmp = strtok_s(position, ".", &position);
				strcpy(tmpArr, tmp);
				(*_rooms)->_reservation->resNumber = atoi(tmpArr);
				//EXTRA BED
				tmp = strtok_s(position, ".", &position);
				strcpy(tmpArr, tmp);
				(*_rooms)->_reservation->extra_bed = atoi(tmpArr);
				//DATE FROM
				tmp = strtok_s(position, ".", &position);
				strcpy(tmpArr, tmp);
				(*_rooms)->_reservation->t_from = atoi(tmpArr);
				//DATE TO
				tmp = strtok_s(position, ".", &position);
				strcpy(tmpArr, tmp);
				(*_rooms)->_reservation->t_to = atoi(tmpArr);
				(*_rooms)->_reservation->pNext = NULL;
			}
			(*_rooms)->_reservation = resTmp;
		}
		free(room_data);
		fclose(in_data);
		if (pHeadRoom == NULL) {
			printf("File with rooms is empty!");
			return 0;
		}
		else{
			(*_rooms)->pNext = NULL;
			*_rooms = pHeadRoom;
			return 1;
		}
	}
	printf("Can't open file with room data.");
	return 0;
}