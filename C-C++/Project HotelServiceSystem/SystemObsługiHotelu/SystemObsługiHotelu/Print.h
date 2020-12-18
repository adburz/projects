/**@file*/
#ifndef USER_PRINT
#define USER_PRINT

#include "Core.h"

/**
	Funkcja wypisuje na standardowe wyjscie przekonwerowana date z formatu unixowego.
	@param res rezerwacja dla ktorej ma byc wyprintowana data.
	@param roNumber numer pokoju.
	@param reNumber numer rezerwacji.
*/
void convertNprint(struct reservation **res, int roNumber, int reNumber);

/**
*	Funkcja konwertuje date w formacie unixowym na zwykla. Wypisuje date w potocznym formacie na standardowe wyjscie.
*	@param time czas w formacie unixowym, ktory funkcja konwertuje.
*/
void printDate(time_t time);

/**
*	Funkcja wypisuje na standardowe wyjscie rezerwacje dla danego uzytkownika. W przypadku zalogowanego administratora, funkcja prosi o dane
*	dla ktorych ma wypisac rezerwacje.
*	@param _rooms lista pokoi.
*	@param _user aktualnie zalogowany uzytkownik.
*/
int printOnName(struct room **_rooms, struct user **_user);

#endif 
