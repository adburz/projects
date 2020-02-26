/**@file*/
#ifndef RESERVATION_ADD
#define RESERVATION_ADD

#include "Reservation.h"

/**
*	Funkcja dodaje rezerwacje na koncu listy.
*	@param searchRes zmienna poprzednia wzgledem nowododanej. Na jej podstawie wyznaczone jest miejsce dla nowej rezerwacji.
*	@param wt_f czas w formacie unixowym od kiedy obowiazuje rezerwacja.
*	@param wt_t czas w formacie unixowym do kiedy obowiazuje rezerwacja.
*	@param name imie najemcy
*	@param surname nazwisko najemcy
*/
void addAtTheEnd(struct reservation **searchRes, struct reservation **pHead, time_t wt_f, time_t wt_t, char *name, char *surname);

/**
*	Funkcja dodaje rezerwacje do pustej listy.
*	@param searchRes wskaznik na pusta liste rezerwacji, ktora zostanie uzupelniona o nowy element.
*	@param wt_f czas w formacie unixowym od kiedy obowiazuje rezerwacja.
*	@param wt_t czas w formacie unixowym do kiedy obowiazuje rezerwacja.
*	@param name imie najemcy
*	@param surname nazwisko najemcy
*/
void addNew(struct reservation **searchRes, time_t wt_f, time_t wt_t, char *name, char *surname);

/**
*	Funkcja dodaje rezerwacje miedzy elementami listy. 
*	@param pHead wskaznik na glowe listy rezerwacji. Uzywany aby okreslic numer nowej rezerwacji.
*	@param searchRes zmienna poprzednia wzgledem nowododanej. Na jej podstawie wyznaczone jest miejsce dla nowej rezerwacji.
*	@param wt_f czas w formacie unixowym od kiedy obowiazuje rezerwacja.
*	@param wt_t czas w formacie unixowym do kiedy obowiazuje rezerwacja.
*	@param name imie najemcy
*	@param surname nazwisko najemcy
*/
void addBetween(struct reservation **pHead, struct reservation **searchRes, time_t wt_f, time_t wt_t, char *name, char *surname);

/**
*	Funkcja dodaje rezerwacje na poczatku listy.
*	@param searchRes zmienna wskazujaca na glowe listy rezerwacji.
*	@param wt_f czas w formacie unixowym od kiedy obowiazuje rezerwacja.
*	@param wt_t czas w formacie unixowym do kiedy obowiazuje rezerwacja.
*	@param name imie najemcy
*	@param surname nazwisko najemcy
*/
void addOnBegining(struct reservation **searchRes, time_t wt_f, time_t wt_t, char *name, char *surname);

#endif 

