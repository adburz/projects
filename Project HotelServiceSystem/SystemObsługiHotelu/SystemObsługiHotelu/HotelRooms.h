/**@file*/
#ifndef HOTELROOMS
#define HOTELROOMS


#include "Core.h"
/**
	Struktura room.
	@param number numer pokoju.
	@param bed_number ilosc lozek znajdujacych sie w pokoju.
	@param _reservation wskaznik na liste rezerwacji
	@param pNext wskaznik na nastepny pokoj 
*/
struct room
{
	int number;
	int bed_number;

	struct reservation *_reservation;
	struct room *pNext;
};

/**
	Funkcja umo¿liwiaj¹ca dodanie dostawki przez administratora.
	@param _rooms lista pokoi.
*/
int extraBed(struct room **_rooms);

/**
	Funkcja zwracajaca adres reserwacji na podstawie numeru pokoju oraz numeru rezerwacji.
	@param _rooms lista pokoi.
	@param roomNumber numer szukanego pokoju
	@param reservationNumber numer szukanej rezerwacji
*/
struct reservation *fRoomByReNum(struct room **_rooms, int roomNumber, int reservationNumber);

/**
	Funkcja pozwalaj¹ca usun¹æ pokoj tylko przez administratora.
	@param _rooms lista pokoi
*/
int deleteRoom(struct room **_rooms);

/**
	Funkcja wypisuje na ekran wszystkie zarezerwowane pokoje wraz z terminami.
	@param _rooms lista pokoi.
*/
int printBookedRooms(struct room **_rooms);

#endif