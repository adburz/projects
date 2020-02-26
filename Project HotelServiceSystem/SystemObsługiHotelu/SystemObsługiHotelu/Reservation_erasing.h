/**@file*/
#ifndef RESERVATION_ERASING
#define RESERVATION_ERASING

#include "Reservation.h"

/**
*	Funkcja ktorej zadaniem jest usuniecie zazadanej rezerwacji przez uzytkownika.
*	@param _rooms lista pokoi.
*	@param _user aktualnie zalogowany uzytkownik.
*/
int eraseReservation(struct room **_rooms, struct user **_user);

/**
*	Funkcja usuwa liste rezerwacji.
*	@param res wskaznik na glowe rezerwacji do usuniecia.
*/
void clearReservations(struct reservation **res);
/**
*	Funkcja usuwa pierwsza rezerwacje z listy. Zwraca wskaznik na nastepny element.
*	@param _res wskaznik na glowe listy do usuniecia.
*/
struct reservation *deleteFirstRes(struct reservation **_res);
/**
*	Funkcja usuwa pojedyncza rezerwacje.
*	@param _res rezerwacja do usuniecia.
*/
void freeReservation(struct reservation **_res);

/**
	Funkcja znajduje rezerwacje do usuniecia z listy rezerwacji.
	@param _user aktualnie zalogowany uzytkownik.
	@param _res wskaznik na liste rezerwacji.
	@param reNumber numer poszukiwanej rezerwacji w liscie.
*/
int findResIfNotFirst(struct user **_user, struct reservation **_res, int reNumber);
#endif
