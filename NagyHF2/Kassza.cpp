#include <fstream>
#include "Kassza.h"
#include "Film.h"
#include "DataProvider.h"
#include "AkcioFilm.h"
#include "DokumentumFilm.h"
#include "FantasyFilm.h"

Kassza::Kassza()
{
}


Kassza::~Kassza()
{

}

void Kassza::listMovies()
{
	Film** filmek = _dataProvider.getMovies();
	int filmCounter = _dataProvider.getFilmCounter();

	for (int i = 0; i < filmCounter; i++)
	{
		std::cout << filmek[i]->getTitle() << std::endl;
	}
}

void Kassza::listMoivesByTitle()
{
	Film** filmek = _dataProvider.getMovies();
	int filmCounter = _dataProvider.getFilmCounter();

	Film* tmpPointer = NULL;
	for (int i = 0; i < filmCounter - 1; i++)
	{
		if (strcmp(filmek[i]->getTitle().c_str(), filmek[i + 1]->getTitle().c_str()) > 0) {
			tmpPointer = filmek[i];
			filmek[i] = filmek[i + 1];
			filmek[i + 1] = tmpPointer;
			i = 0;
		}
	}
	for (int i = 0; i < filmCounter; i++) {
		std::cout << filmek[i]->getTitle() << filmek[i]->getId() << std::endl;
	}
}


void Kassza::listMoviesByGenre()
{
	Film** filmek = _dataProvider.getMovies();
	int filmCounter = _dataProvider.getFilmCounter();
	for (int i = 0; i < filmCounter; i++)
	{
		if (strcmp(filmek[i]->getGenre().c_str(), "action") == 0) {
			std::cout << filmek[i]->getTitle() << "(" << filmek[i]->getGenre() << ")" << filmek[i]->getId() << std::endl;
		}
	}
	for (int i = 0; i < filmCounter; i++)
	{
		if (strcmp(filmek[i]->getGenre().c_str(), "fantasy") == 0) {
			std::cout << filmek[i]->getTitle() << "(" << filmek[i]->getGenre() << ")" << filmek[i]->getId() << std::endl;
		}
	}
	for (int i = 0; i < filmCounter; i++)
	{
		if (strcmp(filmek[i]->getGenre().c_str(), "document") == 0) {
			std::cout << filmek[i]->getTitle() << "(" << filmek[i]->getGenre() << ")" << filmek[i]->getId() << std::endl;
		}
	}


}

void Kassza::listMoviesByYear()
{
	Film* tmpPointer = NULL;
	Film** filmek = _dataProvider.getMovies();
	int filmCounter = _dataProvider.getFilmCounter();

	for (int i = 0; i < filmCounter - 1; i++)
	{
		if (filmek[i]->getYear() > filmek[i + 1]->getYear()) {
			tmpPointer = filmek[i];
			filmek[i] = filmek[i + 1];
			filmek[i + 1] = tmpPointer;
			i = 0;
		}
	}
	for (int i = 0; i < filmCounter; i++) {
		std::cout << filmek[i]->getTitle() << filmek[i]->getId() << std::endl;
	}

}



void Kassza::getRentPrice(int id)
{

}



bool Kassza::rentMovie(int id, String nev, int date)
{

	if (isMovieAvailable(id)) 
	{
		_dataProvider.addRentedMovie(new User(id, date, nev));
		return true;
	}
		return false;
}

bool Kassza::isMovieAvailable(int id)
{

	User** kolcsonzott = _dataProvider.getKolcsonzott();
	int kolcsonzottCounter = _dataProvider.getKolcsonzottCounter();
	for (int i = 0; i < kolcsonzottCounter; i++) {
		if (kolcsonzott[i]->getFilmId() == id) {
			return false;
		}
	}
	return true;
}





