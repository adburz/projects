/**@file*/
#ifndef HOTELREADSAVE
#define HOTELREADSAVE


#include "Core.h"

/**
	Funkcja zapisuj¹ca listê pokoi do pliku. Funkcja zapisuje imiê i nazwisko najemcy, numer pokoju, ilu osobowy jest to pokoj
	oraz czy zosta³o dodane dodatkowe ³ó¿ko oraz date w formacie unixowym od i do.
	@param _hotel lista pokoi.
*/
int rooms_save(struct room **_hotel);
/**
	Funkcja laduje liste pokoi z pliku.
	@param _room lista pokoi
*/
int load_rooms(struct room **_room);
#endif 