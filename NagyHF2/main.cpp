#include <iostream>
#include <stdio.h>
#include <ctime>
#include <fstream>
#include "Kassza.h"
#include "String.h"
#include "AkcioFilm.h"
#include "FantasyFilm.h"
#include "DokumentumFilm.h"




void printMenu() {
	std::cout << "1. Filmek listazasa" << std::endl;
	std::cout << "2. Film kiadasa" << std::endl;
	std::cout << "3. Film visszavetele" << std::endl;
	std::cout << "4. Film elerhetosege" << std::endl;


}
void printListMenu() {
	std::cout << "1. Filmek mufaj szerint" << std::endl;
	std::cout << "2. Filmek nev szerint" << std::endl;
	std::cout << "3. Filmek datum szerint" << std::endl;


}

void handleListMenuInput(int menuPicker, Kassza& kassza) {
	switch (menuPicker) {
	case 1:
		kassza.listMoviesByGenre();
		break;
	case 2:
		kassza.listMoivesByTitle();
		break;
	case 3:
		kassza.listMoviesByYear();
		break;
	}
}

void handleMenuInput(int menuPicker, Kassza& kassza) {
	String nev;
	int movieId;
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	switch (menuPicker) {
	case 1:
		printListMenu();
		switch (menuPicker) {
		case 1:
			std::cin >> menuPicker;
			handleListMenuInput(menuPicker, kassza);
		}
		break;
	case 2:
		std::cout << "Adja meg a film azonositojat: ";
		std::cin >> movieId;
		std::cout << "Adja meg a kolcsonzo kereszt nevet: ";
		std::cin >> nev;
		if (kassza.rentMovie(movieId, nev, now->tm_yday*24*60*60+now->tm_hour*60*60+now->tm_min*60+now->tm_sec)) {
			std::cout << "Sikeres kolcsonzes!" << std::endl;
		}
		else {
			std::cout << "Sikertelen kolcsonzes!" << std::endl;

		}
		break;

	case 3:
		std::cout << "Adja meg a film azonositojat: ";
		std::cin >> movieId;
		break;

	case 4:
		std::cout << "Adja meg a film azonositojat: ";
		std::cin >> movieId;
		if (kassza.isMovieAvailable(movieId)) {
			std::cout << "Elerheto!" << std::endl;
		}
		else {
			std::cout << "Nem erheto el!" << std::endl;
		}
		break;

	}
};


int main() {

	printMenu();
	Kassza kassza;
	int menuPicker;
	while (true) {
		std::cin >> menuPicker;
		handleMenuInput(menuPicker, kassza);
		printMenu();
	}

	system("pause");
}

