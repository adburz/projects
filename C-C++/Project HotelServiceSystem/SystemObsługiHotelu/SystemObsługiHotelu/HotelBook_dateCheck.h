/**@file*/
#ifndef HOTELBOOK_DATECHECK
#define HOTELBOOK_DATECHECK
#include "HotelBook_main.h"

/**
	Funkcja sprawdzajaca czy podany termin jest wolny. Jezeli jest, dodaje rezerwacje do listy w odpowiednim miejscu.
	@param _rooms lista pokoi.
	@param _user lista uzytkownikow.
	@param bed_count pozadana ilosc lozek w pokoju.
	@param wt_f czas zapisany w formacie unixowym od kiedy uzytkownik chce zarezerwowac pokoj.
	@param wt_t czas zapisany w formacie unixowym do kiedy uzytkownik chce zarezerwowac pokoj.

*/
int dateCheck(struct room **_rooms, struct user **_user, int *bed_count, time_t wt_f, time_t wt_t);

/**
	Funkcja wyszukuje pierwszy pokoj z iloscia lozek pozadana przez uzytkownika.
	@param _rooms lista pokoi.
	@param bed_count pozadana ilosc lozek w pokoju.
*/
struct room *findRoom(struct room **_rooms, int *bed_count);

#endif