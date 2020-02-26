/**@file*/
#ifndef MISCELLANEOUS_FUNCTIONS
#define MISCELLANEOUS_FUNCTIONS

#include "Core.h"

#define printResInfo 3
#define deleteRes 5
#define printBrooms 6
#define quit 7

/**
*	Funkcja czysci ze standardowego wejscia wszystkie pozostale znaki. Pozwala pozbyc sie wprowadzanego znaku '\0'
*	dzieki czemu mozna uniknac niechcianych bledow.
*/
void clear(void);

/**
*	Funkcja sprawdza czy opcja wybrana przez uzytkownika zgadza sie z tymi wysietlonymi w menu.
*	@param changer zmienna wybrana przez uzytkownika
*	@param user_head aktualnie zalogowany uzytkownik. Administrator posiada wiecej opcji niz zwykly uzytkownik.
*/
void checkInMenuOption(int *changer, struct user **user_head);

/**
*	Funkcja ma za zadanie sprawdzac czy numer pokoju ktory ma zostac wypisany na ekran juz nie zostal wypisany.
*	@param typesOfRoom tablica przechowujaca typy pokoi ktore sie juz pojawily.
*	@param bedNumber ilosc lozek w aktualnie obslugiwanym pokoju.
*/
int thereWereThisNumber(int typesOfRoom[], int bedNumber);
#endif