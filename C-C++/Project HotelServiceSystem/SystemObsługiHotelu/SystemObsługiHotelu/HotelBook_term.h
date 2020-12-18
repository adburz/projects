/**@file*/
#ifndef HOTELBOOK_TERM
#define HOTELBOOK_TERM
#include "HotelBook_main.h"

/**
	Funckcja wczytuj¹ca pozadany termin do bufora.
	@param _rooms lista pokoi.
	@param wanted_time_from pozadany czas przez uzytkownika od kiedy chcialby zarezerwowac pokoj.
	@param wanted_time_to pozadany czas przez uzytkownika do kiedy chcialby zarezerwowac pokoj.
	@param dd_f zmienna odpowiedzialna za "dzien od" rezerwacji.
	@param mm_f zmienna odpowiedzialna za "miesiac od" rezerwacji.
	@param yy_f zmienna odpowiedzialna za "rok od" rezerwacji.
	@param dd_t zmienna odpowiedzialna za "dzien do" rezerwacji.
	@param mm_t zmienna odpowiedzialna za "miesiac do" rezerwacji.
	@param yy_t zmienna odpowiedzialna za "rok do" rezerwacji.
*/
int loadTerm(struct room **_rooms, time_t *wanted_time_from, time_t *wanted_time_to, int *dd_f, int *mm_f, int *yy_f, int *dd_t, int *mm_t, int *yy_t);

/**
	Funkcja zmieniajaca date na unixowa.
	@param wanted_time zwracany czas, uzupeniony o odpowiednia wartosc zwiazana z data ktora przyjmuje funkcja
	@param day dzien wchodzacy do funkcji
	@param month miesiac wchodzacy do funkcji
	@param year rok wchodzacy do funkcji
*/
void toEpoch(time_t *wanted_time, int *day, int *month, int *year);
/**
	Funkcja czyta ze standardowego wejscia date w formacie dd/mm/yy.
	@param dd_f dzien od kiedy uzytkownik chce zarezerwowac pokoj.
	@param mm_f miesiac od kiedy uzytkownik chce zarezerwowac pokoj.
	@param yy_f rok od kiedy uzytkownik chce zarezerwowac pokoj.
	@param dd_t dzien od kiedy uzytkownik chce zarezerwowac pokoj.
	@param mm_t miesiac od kiedy uzytkownik chce zarezerwowac pokoj.
	@param yy_t rok od kiedy uzytkownik chce zarezerwowac pokoj.
*/
int readingData(int *dd_f, int *mm_f, int *yy_f, int *dd_t, int *mm_t, int *yy_t);

/**
	Funkcja sprawdza poprawnosc wpisanej daty. W przypadku wprowadzenia daty w innym formacie niz dd/mm/yy lub daty ktorej nie da sie
	przerobic na date w formacie unixowym, funkcja zwraca blad.
	@param day dzien do sprawdzenia.
	@param month miesiac do sprawdzenia.
	@param year rok do sprawdzenia.
*/
int dateValidation(int *day, int *month, int *year);

#endif