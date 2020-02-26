/**@file*/
#ifndef RESERVATION
#define RESERVATION

#include "Core.h"
#include "Reservation_erasing.h"
#include "Reservation_add.h"

/**
	Struktura reservation. 
	@param resNumber numer rezerwacji.
	@param name imie najemcy.
	@param surname nazwisko najemcy.
	@param extra_bed zmienna informujaca czy dla rezerwacji zostalo przydzielone dodatkowe lozko.
	@param t_from czas w formacie unixowym od kiedy wynajety jest pokoj.
	@param t_to czas w formacie unixowym do kiedy wynajety jest pokoj.
*/
struct reservation
{
	int resNumber;
	char *name;
	char *surname;
	bool extra_bed;

	time_t t_from;
	time_t t_to;

	struct reservation *pNext;
};

/**
	Funkcja zwraca numer ostatniej rezerwacji, aby przypisac odpowiedni numer nowej.
	@param _reservation rezerwacja
*/
int findLastResNumber(struct reservation **_reservation);
/**
	Funkcja porownujaca imie i nazwisko chcacego usunac rezerwacje z imieniem i nazwiskiem przypisanym do rezerwacji. 
	@param _user uzytkownik chcacy usunac rezerwacje
	@param _rooms pokoj dla ktorego
*/
int compareUserNames(struct user **_user, struct reservation **_reservation);

#endif 