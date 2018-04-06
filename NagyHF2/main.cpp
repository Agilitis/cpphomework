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

void handleMenuInput(int menuPicker, Kassza kassza) {
	switch (menuPicker) {
	case 1:
		kassza.listMovies();
		break;
	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	}
};

Kassza initKassza()
{
	Kassza kassza;
	std::fstream filmFile("filmek.txt");
	//menetrend betoltese a "filmek.txt" fajlbol
	if (filmFile.is_open()) {
		String genre("");
		String title("");
		int price;
		int length;
		int rating;
		while (!filmFile.eof()) {
			filmFile >> genre >> title >> price >> length >> rating;
			if (strcmp(genre.c_str(), "action") == 0) {
				kassza.addMovie(new AkcioFilm(title, price, length, rating));
			}
			else if (strcmp(genre.c_str(), "fantasy") == 0) {
				kassza.addMovie(new FantasyFilm(title, price, length, rating));
			}
			else if (strcmp(genre.c_str(), "document") == 0) {
				kassza.addMovie(new DokumentumFilm(title, price, length, rating));
			}
		}
	}
	else std::cout << "Couldn't open filmek.txt\n";
	filmFile.close();
	return kassza;
}


int main() {

	printMenu();
	Kassza kassza = initKassza();
	int menuPicker;
	while (true) {
		std::cin >> menuPicker;
		handleMenuInput(menuPicker, kassza);
		printMenu();
	}

	system("pause");
}

