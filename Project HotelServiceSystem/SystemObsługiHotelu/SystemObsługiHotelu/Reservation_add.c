#include "Reservation_add.h"

void addAtTheEnd(struct reservation **searchRes, struct reservation **pHead, time_t wt_f, time_t wt_t, char *name, char *surname)
{
	int resNum = findLastResNumber(&(*pHead));
	struct reservation *newRes = (struct reservation*)calloc(1, sizeof(struct reservation));
	newRes->extra_bed = false;
	newRes->t_from = wt_f;
	newRes->t_to = wt_t;
	newRes->resNumber = ++resNum;
	newRes->name = (char*)calloc(strlen(name) + 1, sizeof(char));
	strcpy(newRes->name, name);
	newRes->surname = (char*)calloc(strlen(surname) + 1, sizeof(char));
	strcpy(newRes->surname, surname);

	printf("\nNumber of your reservation: %d", newRes->resNumber);
	(*searchRes)->pNext = newRes;
	newRes->pNext = NULL;
}
void addBetween(struct reservation **pHead, struct reservation **searchRes, time_t wt_f, time_t wt_t, char *name, char *surname)
{
	int resNum = findLastResNumber(&(*pHead));
	struct reservation *newRes = (struct reservation*)calloc(1, sizeof(struct reservation));
	newRes->extra_bed = false;
	newRes->t_from = wt_f;
	newRes->t_to = wt_t;
	newRes->resNumber = ++resNum;
	newRes->name = (char*)calloc(strlen(name) + 1, sizeof(char));
	strcpy(newRes->name, name);
	newRes->surname = (char*)calloc(strlen(surname) + 1, sizeof(char));
	strcpy(newRes->surname, surname);

	printf("\nNumber of your reservation: %d", newRes->resNumber);
	newRes->pNext = (*searchRes)->pNext;
	(*searchRes)->pNext = newRes;
}
void addNew(struct reservation **searchRes, time_t wt_f, time_t wt_t, char *name, char *surname)
{
	int res_number = 1;
	struct reservation *newRes = (struct reservation*)calloc(1, sizeof(struct reservation));
	newRes->extra_bed = false;
	newRes->t_from = wt_f;
	newRes->t_to = wt_t;
	newRes->resNumber = res_number;
	newRes->name = (char*)calloc(strlen(name) + 1, sizeof(char));
	strcpy(newRes->name, name);
	newRes->surname = (char*)calloc(strlen(surname) + 1, sizeof(char));
	strcpy(newRes->surname, surname);

	printf("\nNumber of your reservation: %d", newRes->resNumber);
	(*searchRes) = newRes;
	(*searchRes)->pNext = NULL;
}
void addOnBegining(struct reservation **searchRes, time_t wt_f, time_t wt_t, char *name, char *surname)
{
	int res_number = findLastResNumber(&(*searchRes));

	struct reservation *newRes = (struct reservation*)calloc(1, sizeof(struct reservation));
	newRes->extra_bed = false;
	newRes->t_from = wt_f;
	newRes->t_to = wt_t;
	newRes->resNumber = ++res_number;
	newRes->name = (char*)calloc(strlen(name) + 1, sizeof(char));
	strcpy(newRes->name, name);
	newRes->surname = (char*)calloc(strlen(surname) + 1, sizeof(char));
	strcpy(newRes->surname, surname);

	printf("\nNumber of your reservation: %d", newRes->resNumber);
	

	newRes->pNext = (*searchRes);
	(*searchRes) = newRes;
}