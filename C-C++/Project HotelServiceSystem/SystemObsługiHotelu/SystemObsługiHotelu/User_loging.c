#include "User_loging.h"

int user_load(struct user **_user)
{
	struct user *pHead = *_user;
	FILE *in_data;
	if ((*_user)->isAdmin == true)
	{
		in_data = fopen("admin_data.txt", "r");
	}
	else
	{
		in_data = fopen("user_data.txt", "r");
	}
	if (in_data)
	{
		char *tmp;
		char *log_data = (char*)calloc(100, sizeof(char));
		struct user *new_user = NULL;
		while (fscanf(in_data, "%s", log_data) != EOF)
		{
			tmp = strtok(log_data, ".");
			(*_user)->login = (char*)calloc(1, strlen(tmp) * sizeof(char) + 1);
			strcpy((*_user)->login, tmp);

			tmp = strtok(NULL, ";");
			(*_user)->password = (char*)calloc(1, strlen(tmp) * sizeof(char) + 1);
			strcpy((*_user)->password, tmp);

			tmp = strtok(NULL, ".");
			(*_user)->name = (char*)calloc(1, strlen(tmp) * sizeof(char) + 1);
			strcpy((*_user)->name, tmp);

			tmp = strtok(NULL, "\n");
			(*_user)->surname = (char*)calloc(1, strlen(tmp) * sizeof(char) + 1);
			strcpy((*_user)->surname, tmp);

			new_user = (struct user*)calloc(1, sizeof(struct user));
			(*_user)->pNext = new_user;
			*_user = (*_user)->pNext;
		}
		(*_user)->pNext = NULL;
		free(log_data);
		*_user = pHead;
		return 1;
	}
	else
	{
		printf("Can't open file with user data.");
		return 0;
	}
}

int user_log_check(struct user **_user)
{
	struct user *pHead = *_user;
	char logingWord[25];
	printf("Enter your username:");
	scanf_s("%s", logingWord, 20);
	clear();
	dataCipher(&logingWord);
	while ((*_user)->pNext != NULL)
	{
		if (strcmp(logingWord, (*_user)->login) == 0)							//checking username
		{
			memset(logingWord, 0, sizeof(logingWord));							//clearing array
			printf("Username is correct.\nEnter your password:");
			scanf_s("%s", logingWord, 20);
			clear();
			dataCipher(&logingWord);
			if (strcmp(logingWord, (*_user)->password) == 0)					//checking password
			{
				printf("Your password is correct.");
				Sleep(900);										//clearing console, and moving into menu
				system("cls");
				return 1;
			}
			else
			{
				printf("Your password is incorrect.");
				Sleep(900);
				*_user = pHead;
				return 0;
			}
		}
		else
		{
			(*_user) = (*_user)->pNext;		//finding correct user
		}
	}
	*_user = pHead;
	printf("Your username is incorrect.");
	return 0;
}
void dataCipher(char *logWord)
{
	int i, j;
	char key[] = "VONFABBCZ";
	//zamiana na duze litery
	for (i = 0, j = 0; i < strlen(logWord); i++)
	{
		if (logWord[i] != ' ')
		{
			logWord[j] = toupper(logWord[i]);
			j++;
		}
	}
	logWord[j] = '\0';
	//szyfrowanie
	for (int i = 0; i < strlen(logWord); i++)
	{
		logWord[i] = (logWord[i] - 'A' + key[i % (strlen(key))] - 'A') % 26 + 'A';
	}
}

int user_logging(struct user **_user, int result)
{
	if (result == adminLogged)				//u¿ytkownik jest adminem
		(*_user)->isAdmin = true;
	else
		(*_user)->isAdmin = false;
	if (user_load(&(*_user)))				//loading structure user with data from file
	{	
		if (user_log_check(&(*_user)))
			return 1;
	}
	return 0;
}
