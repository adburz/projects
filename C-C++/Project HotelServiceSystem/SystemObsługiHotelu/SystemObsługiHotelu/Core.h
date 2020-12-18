/**@file*/
#ifndef CORE
#define CORE


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <math.h>

#include "HotelBook_main.h"
#include "HotelRooms.h"
#include "User_loging.h"
#include "HotelReadSave.h"
#include "MiscellaneousFunctions.h"
#include "Print.h"
#include "Reservation.h"

#define ifYouStay 8
#define outMenu 10
#define extraBed_state 2
#define printOnName_state 3
#define deleteRoom_state 4
#define eraseReservation_state 5
#define printBookedRooms_state 6
#define adminMenu 1
#define userMenu 2
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"


/**
	Funkcja sprawdza poprawnoœæ wejsciowych argumentów.
	@param argc ilosc wchodzacych parametrow
	@param argv[] argumenty wchodzace
*/
int checkArguments(int argc, char *argv[]);

/**
	G³owna funkcja zajmujaca siê logowaniem, odczytem danych oraz ich zapisem. 
	Funkcja obsluguje stany programu, ktore uzytkownik wybiera dzieki menu.
	@param logResult parametr informujacy, czy loguje sie uzytkownik czy administrator.
*/
void systemH(int logResult);

/**
	Funkcja zapisujaca dane dotyczace pokoi do pliku tekstowego.
	@param _rooms lista pokoi do zapisu
*/
int systemClose(struct room **_rooms);

/**
	Funkcja chroniaca przed wyciekami pamieci. Jej zadaniem jest zwolnienie zaalokowanej pamieci.
	@param _rooms lista pokoi do uwolnienia
	@param _user lista uzytkownikow do uwolnienia
*/
void system_clear(struct room **_rooms, struct user **_user);

/**
	Funkcja majaca za zadanie zapytanie uzytkownika czy chce pozostac w obecnym stanie, czy tez chce przejsc do glownego menu.
	@param changer funkcja przyjmuje numer poprzedniego stanu. Jezeli uzytkownik chce pozostac w stanie, changer sie nie zmienia.
	Natomiast jezeli chce wrocic do menu, wartosc changer zmienia sie na 0, czyli numer stanu menu.
*/
int ifWantToStay(int *changer);

/**
	Funkcja wypisujaca na ekran menu dla odpowiedniego uzytkownika.
	@param user zmienna mowiaca o tym czy uzytkownik to administrator czy zwykly uzytkownik.
*/
void printMenu(int user);

/**
	Funkcja usuwa liste uzytkownikow.
	@param _user wskaznik na glowe listy uzytkownikow.
*/
void clearUser(struct user **_user);

#endif