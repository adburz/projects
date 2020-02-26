/**@file*/
#ifndef HOTELREADSAVE
#define HOTELREADSAVE


#include "Core.h"

/**
	Funkcja zapisuj�ca list� pokoi do pliku. Funkcja zapisuje imi� i nazwisko najemcy, numer pokoju, ilu osobowy jest to pokoj
	oraz czy zosta�o dodane dodatkowe ��ko oraz date w formacie unixowym od i do.
	@param _hotel lista pokoi.
*/
int rooms_save(struct room **_hotel);
/**
	Funkcja laduje liste pokoi z pliku.
	@param _room lista pokoi
*/
int load_rooms(struct room **_room);
#endif 