#include "HotelBook_term.h"

int loadTerm(struct room **_rooms, time_t *wanted_time_from, time_t *wanted_time_to, int *dd_f, int *mm_f, int *yy_f, int *dd_t, int *mm_t, int *yy_t)
{
	int result = readingData(&dd_f, &mm_f, &yy_f, &dd_t, &mm_t, &yy_t);
	if (result)
	{
		*wanted_time_from = 0;
		*wanted_time_to = 0;
		toEpoch(&(*wanted_time_to), &dd_t, &mm_t, &yy_t);
		toEpoch(&(*wanted_time_from), &dd_f, &mm_f, &yy_f);
		if (*wanted_time_from > *wanted_time_to)
		{
			printf("You made mistake. Try again.");
			return 0;
		}
		return goToLoadBed;
	}
	return 0;

}
void toEpoch(time_t *wanted_time, int *day, int *month, int *year)
{
	t.tm_year = (*year) - 1900;
	t.tm_mon = (*month) - 1;
	t.tm_mday = (*day);
	t.tm_hour = 12;
	t.tm_min = 0;
	t.tm_sec = 0;
	t.tm_isdst = -1;

	(*wanted_time) = mktime(&t);
}
int readingData(int *dd_f, int *mm_f, int *yy_f, int *dd_t, int *mm_t, int *yy_t)
{
	int result = 0;
	printf("Enter date - from (format: DD/MM/YYYY ): ");
	scanf("%d/%d/%d", &(*dd_f), &(*mm_f), &(*yy_f));
	clear();
	result = dateValidation(&(*dd_f), &(*mm_f), &(*yy_f));
	if (result)
	{

		printf("Enter date - to (DD/MM/YYYY format): ");
		scanf("%d/%d/%d", &(*dd_t), &(*mm_t), &(*yy_t));
		clear();

		result = dateValidation(&(*dd_f), &(*mm_f), &(*yy_f));
		if (result)
			return 1;

	}
	return 0;
}
int dateValidation(int *day, int *month, int *year)
{
	if ((*year) >= 1900 && (*year) <= 9999)
	{
		//check month
		if ((*month) >= 1 && (*month) <= 12)
		{
			//check days
			if (((*day) >= 1 && (*day) <= 31) && ((*month) == 1 || (*month) == 3 || (*month) == 5 || (*month) == 7 || (*month) == 8 || (*month) == 10 || (*month) == 12))
			{
				printf("Date is valid.\n");
				return 1;
			}
			else if (((*day) >= 1 && (*day) <= 30) && ((*month) == 4 || (*month) == 6 || (*month) == 9 || (*month) == 11))
			{
				printf("Date is valid.\n");
				return 1;
			}
			else if (((*day) >= 1 && (*day) <= 28) && ((*month) == 2))
			{
				printf("Date is valid.\n");
				return 1;
			}
			else if ((*day) == 29 && (*month) == 2 && ((*year) % 400 == 0 || ((*year) % 4 == 0 && (*year) % 100 != 0)))
			{
				printf("Date is valid.\n");
				return 1;
			}
			else
			{
				printf("Date is invalid.\n");
				return 0;
			}
		}
		else
		{
			printf("Date is invalid.\n");
			return 0;
		}
	}
	printf("Date is invalid.\n");
	return 0;
}