#include <iostream>
#include <stdio.h>
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
		int movieId;
		std::cin >> movieId;
		if (kassza.rentMovie(movieId)) {
			std::cout << "sikeres kolcsonzes!" << std::endl;
		}
		break;

	case 3:
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

