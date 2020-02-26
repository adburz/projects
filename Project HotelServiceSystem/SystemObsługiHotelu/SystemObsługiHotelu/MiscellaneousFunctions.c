#include "MiscellaneousFunctions.h"


void clear(void)
{
	while (getchar() != '\n');
}

void checkInMenuOption(int *changer, struct user **user_head)
{
	if ((*user_head)->isAdmin)
	{
		if (*changer >= 0 && *changer <= 7)
		{
			if (*changer == 7)
				return;
			return;
		}
		*changer = 0;
		return;
	}
	else
	{
		if (*changer >= 0 && *changer <= 5)
		{
			if (*changer == 2) {
				*changer = printResInfo;
				return;
			}
			else if (*changer == 3) {
				*changer = deleteRes;
				return;
			}
			else if (*changer == 4) {
				*changer = printBrooms;
				return;
			}
			else if (*changer == 5) {
				*changer = quit;
				return;
			}
		}
	}
}

int thereWereThisNumber(int typesOfRoom[], int bedNumber)
{
	for (int i = 0; i < 10; i++)
	{
		if (typesOfRoom[i] == bedNumber)
			return 0;
	}
	return 1;
}