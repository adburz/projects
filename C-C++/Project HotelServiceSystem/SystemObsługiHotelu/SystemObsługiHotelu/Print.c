#include "Print.h"


void printDate(time_t time)
{
	char *tmp = NULL;
	char buf[50];
	int day, month, year;
	t = *localtime(&time);
	strftime(buf, sizeof(buf), "%Y-%m-%d", &t);
	tmp = strtok(buf, "-");
	day = atoi(tmp);
	tmp = strtok(NULL, "-");
	month = atoi(tmp);
	tmp = strtok(NULL, "-");
	year = atoi(tmp);
	printf("%d.%d.%d", year, month, day);
}
void convertNprint(struct reservation **res, int roNumber, int reNumber)
{
	printf(" Room number:%d", roNumber);
	printf(" Res number:%d", reNumber);
	//from
	printf("\tReservation from:");
	printDate((*res)->t_from);
	//to
	printf("\tReservation to:");
	printDate((*res)->t_to);
	printf("\n");
}
int printOnName(struct room **_rooms, struct user **_user)
{
	int changer = 0;
	struct room *ro_pHead = *_rooms;
	struct reservation *re_pHead = NULL;
	struct room *tmp = *_rooms;
	char *name = (char*)calloc(31, sizeof(char));
	char *surname = (char*)calloc(31,sizeof(char));

	if ((*_user)->isAdmin)
	{
		printf("Enter name:");
		scanf_s("%s", name, 30);
		printf("Enter surname:");
		scanf_s("%s", surname, 30);
	}
	else
	{
		strcpy(name, (*_user)->name);
		strcpy(surname, (*_user)->surname);
	}
	while (tmp != NULL)
	{
		re_pHead = tmp->_reservation;
		while (tmp->_reservation != NULL)
		{			
			if (strcmp(name, tmp->_reservation->name) == 0 && strcmp(surname, tmp->_reservation->surname) == 0)
			{
				++changer;
				printf("\n%d.", changer);
				convertNprint(&tmp->_reservation, tmp->number, tmp->_reservation->resNumber);	
			}
			tmp->_reservation = tmp->_reservation->pNext;
		}
		tmp->_reservation = re_pHead;
		tmp = tmp->pNext;
	}
	*_rooms = ro_pHead;
	free(name);
	free(surname);
	if (changer != 0)
		return ifYouStay;
	printf("\nCan't find your reservation.");
	return ifYouStay;
}