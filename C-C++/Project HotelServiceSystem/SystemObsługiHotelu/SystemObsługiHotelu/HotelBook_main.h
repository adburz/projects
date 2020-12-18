/**@file*/
#ifndef HOTELBOOK
#define HOTELBOOK

#include "Core.h"
#include "HotelBook_dateCheck.h"
#include "HotelBook_loadBed.h"
#include "HotelBook_term.h"


#define returnToMenu 0
#define goToDateCheck 3
#define goToLoadBed 2

/**
	Struktura niezbedna do korzystania z czasu unixowego.
*/
struct tm t;

/**
	Funkcja umozliwiajaca zarezerwowaæ pokoj dla zalogowanego u¿ytkownika/administratora.
	@param _rooms lista pokoi.
	@param _user aktualnie zalogowany uzytkownik.
*/
int book_room(struct room **_rooms, struct user **_user);

/**
	Funkcja majaca za zadanie dowiedzenie sie od uzytkownika, czy ten chce wrocic do glownego menu, czy tez chce wykonac
	kolejna rezerwacje.
	@param loopBreaker zmienna konczaca petle while.
*/
int getBack(int *loopBreaker);
#endif