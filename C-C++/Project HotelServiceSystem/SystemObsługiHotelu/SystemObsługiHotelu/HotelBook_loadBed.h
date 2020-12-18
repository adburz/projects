/**@file*/
#ifndef HOTELBOOK_LOADBED
#define HOTELBOOK_LOADBED
#include "HotelBook_main.h"

/**
	Funkcja czyta informacje od uzytkownika ilu osobowy chcialby pokoj oraz sprawdza poprawnosc wpisanej liczby.
	@param _rooms lista pokoi.
	@param bed_count pozadana ilosc lozek w pokoju.

*/
int loadBed(struct room **_rooms, int *bed_count);
/**
	Funkcja laduje z wejscia liczbe lozek, jaka chcialby miec uzytkownik w pokoju.
	@param _rooms lista pokoi.
	@param bed_count pozadana ilosc lozek w pokoju.
*/
int bedCount(struct room **_rooms, int *bed_count);

#endif