#include "Core.h"

int checkArguments(int argc, char *argv[])
{
	if (argc == 2)
	{
		char *tmp = argv[1];
		if (strcmp(tmp, "-a") == 0)
		{
			printf("You've logged as an admin\n");
			return 1;
		}
		else if (strcmp(tmp, "-u") == 0)
		{
			printf("You've logged as an user\n");
			return 2;
		}
		else
		{
			printf("Wrong arguments!\n");
			return 0;
		}
	}
	printf("Error. Insert one argument!\n");
	return 0;

}
void systemH(int logResult)
{
	struct user *user_head = (struct user*)calloc(1, sizeof(struct user));
	int logging;
	logging = user_logging(&user_head, logResult);
	if (logging)									//je¿eli logowanie przesz³o bez zarzutu
	{
		struct room *_hotel = NULL;
		int loadResult = load_rooms(&_hotel);
		if (loadResult)
		{
			int changerA = 0, changerB = 0, loopBreaker = 10;
			do
			{
				switch (changerA)
				{
				case 0:											//state menu
					system("cls");
					if (user_head->isAdmin == true)				//admin menu
						printMenu(adminMenu);
					else
						printMenu(userMenu);
					scanf_s("%d", &changerA, 1);
					checkInMenuOption(&changerA, &user_head);
					clear();
					system("cls");
					break;
				case 1:
					changerA = book_room(&_hotel, &user_head);
					break;
				case 2:
					changerB = extraBed_state;
					changerA = extraBed(&_hotel);
					break;
				case 3:
					changerB = printOnName_state;
					changerA = printOnName(&_hotel, &user_head);
					break;
				case 4:
					changerB = deleteRoom_state;
					changerA = deleteRoom(&_hotel);
					break;
				case 5:
					changerB = eraseReservation_state;
					changerA = eraseReservation(&_hotel, &user_head);
					break;
				case 6:
					changerA = printBookedRooms(&_hotel);
					break;
				case 7:
					changerA = systemClose(&_hotel);
					break;
				case 8:
					changerA = ifWantToStay(changerB);
					break;
				}
			} while (changerA != loopBreaker);
		}
		system_clear(&_hotel, &user_head);
	}
	else
		clearUser(&user_head);
	return;
}

int systemClose(struct room **_rooms)
{
	int result = rooms_save(&(*_rooms));
	if (!result)
		return ifYouStay;
	return outMenu;
}

void system_clear(struct room **_rooms, struct user **_user)
{
	struct room *roTmp = *_rooms;
	struct user *usTmp = *_user;
	while (*_rooms != NULL)
	{
		roTmp = *_rooms;
		if (roTmp->_reservation != NULL)
		{
			clearReservations(&roTmp->_reservation);
		}
		*_rooms = (*_rooms)->pNext;
		free(roTmp);
		roTmp = NULL;
	}
	clearUser(&(*_user));
}

int ifWantToStay(int *changer)
{
	char result;
	printf("\nWould you like to get back into main menu(1) or repeat process(2)?:");
	result = getc(stdin);
	clear();
	if (result == '2')
		return changer;
	return 0;
}
void printMenu(int user)
{
	if (user == adminMenu)
	{
		printf("==================================\n"
			" MENU:"
			"\n\n1. Book room\n2. Add extra bed"
			"\n3. Print name informations\n4. Delete room"
			"\n5. Delete reservation\n6. Print booked rooms"
			"\n\n7. Quit"
			"\n==================================\n");
	}
	else if (user == userMenu)
	{
		printf("==================================\n"
			" MENU:"
			"\n\n1. Book room"
			"\n2. Print the reservation information\n"
			"3. Delete reservation\n4. Print booked rooms"
			"\n\n5. Quit"
			"\n==================================\n");
	}

}

void clearUser(struct user **_user)
{
	struct user *usTmp = *_user;
	while (*_user != NULL)
	{
		usTmp = *_user;
		*_user = (*_user)->pNext;

		free(usTmp->name);
		free(usTmp->surname);
		free(usTmp->login);
		free(usTmp->password);
		free(usTmp);
		usTmp = NULL;
	}
}