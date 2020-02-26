/**@file*/
#ifndef USER_LOGING
#define USER_LOGING


#include "Core.h"
#define adminLogged 1
#define userLogged 2


/**
	Lista jednokierunkowa uzytkownikow ladowana odpowiednio danymi administratorow lub uzytkownikow.
	@param login zaszyfrowany login uzytkownika wczytywany z pliku tekstowego.
	@param password zaszyfrowane haslo uzytkownika wczytywane z pliku tekstowego.
	@param name imie uzytkownika.
	@param surname nazwisko uzytkownika.
	@param isAdmin zmienna typu bool mowiaca o tym czy uzytkownik jest administratorem czy tez nie.
*/
 struct user						
{									
	char *login;					
	char *password;
	char *name;
	char *surname;
	bool isAdmin;

	struct user *pNext;
};

/*!
*	Funkcja sprawdza poprawnosc logowania. 
*	@param _user wskaznik na glowe uzytkownikow.
*	@param result zmienna mowiaca o tym czy w argumentach funkcji main zostal podany user czy admin.
*/
int user_logging(struct user **_user, int result);
/*
*	Funkcja ³aduje dane do struktury user. Sprawdza czy ma ladowac dane z pliku admin czy user.
*	@param _user lista uzytkownikow.
*/
int user_load(struct user **_user);
/*
*	Funkcja loguj¹ca. Sprawdzaj¹ca czy wpisany login i has³o sa poprawne.
*	@param _user lista uzytkownikow.
*/
int user_log_check(struct user **_user);

/*!
*	Funkcja szyfruje wprowadzone dane przy pomocy szyfru Vigenere i porownuje je z zaszyfrowanymi wczesniej danymi z pliku. 
*	Funkcja szyfruje slowa przy pomocy statycznego slowa klucz zapisanego w programie.
*	@param logWord slowo wejsciowe, np. login
*/
void dataCipher(char *logWord);


#endif