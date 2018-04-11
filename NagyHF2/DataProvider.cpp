#include "DataProvider.h"
#include "Kassza.h"
#include "AkcioFilm.h"
#include "FantasyFilm.h"
#include "DokumentumFilm.h"
#include <fstream>





DataProvider::~DataProvider()
{
}

Film** DataProvider::getMovies()
{
	if (filmek == NULL) {


		std::fstream filmFile("filmek.txt");
		//menetrend betoltese a "filmek.txt" fajlbol
		if (filmFile.is_open()) {
			String genre("");
			String title("");
			int price;
			int length;
			int rating;
			int year;
			int id;
			while (!filmFile.eof()) {
				filmFile >> genre >> title >> price >> length >> rating >> year >> id;
				if (strcmp(genre.c_str(), "action") == 0) {
					addMovie(new AkcioFilm(title, price, length, rating, year, genre, id));

				}
				else if (strcmp(genre.c_str(), "fantasy") == 0) {
					addMovie(new FantasyFilm(title, price, length, rating, year, genre, id));
				}
				else if (strcmp(genre.c_str(), "document") == 0) {
					addMovie(new DokumentumFilm(title, price, length, rating, year, genre, id));
				}
			}
		}
		else std::cout << "Couldn't open filmek.txt\n";
		filmFile.close();
	}
	return filmek;

		
}

void DataProvider::addMovie(Film * film)
{
	if (filmCounter == 0) {
		filmCounter++;
		filmek = new Film*[filmCounter];
		filmek[0] = film;
	}
	else {
		filmCounter++;
		Film** tmp = new Film*[filmCounter];
		for (int i = 0; i < filmCounter -1 ; i++) {
			tmp[i] = filmek[i];
		}
		tmp[filmCounter -1 ] = film;
		delete[] filmek;
		filmek = tmp;
	}

}

int* DataProvider::getKolcsonzott()
{
	if (kolcsonzott == NULL) {
		std::fstream filmFile("kolcsonzott.txt");
		if (filmFile.is_open()) {
			int id;
			while (!filmFile.eof()) {
				filmFile >> id;
				addRentedMovie(id);
			}
		}
		else std::cout << "Couldn't open kolcsonzott.txt\n";
		filmFile.close();
		
	}
	
	return kolcsonzott;
}

void DataProvider::addRentedMovie(int id)
{

	if (kolcsonzottCounter == 0) {
		kolcsonzottCounter++;
		kolcsonzott = new int[kolcsonzottCounter];
		kolcsonzott[0] = id;
	}
	else {
		kolcsonzottCounter++;
		int* tmp = new int[kolcsonzottCounter];

		for (int i = 0; i < kolcsonzottCounter -1 ; i++) {
			tmp[i] = kolcsonzott[i];
		}

		tmp[kolcsonzottCounter - 1] = id;
		delete[] kolcsonzott;
		kolcsonzott = tmp;

	}

	std::fstream filmfile("kolcsonzott.txt");
	if (filmfile.is_open()) {
		for (int i = 0; i < kolcsonzottCounter; i++) {
			filmfile << kolcsonzott[i] << std::endl;
		}
	}
	else std::cout << "couldn't open kolcsonzott.txt\n";
	filmfile.close();
}

int DataProvider::getKolcsonzottCounter()
{
	return kolcsonzottCounter;
}

int DataProvider::getFilmCounter()
{

	return filmCounter;
}


