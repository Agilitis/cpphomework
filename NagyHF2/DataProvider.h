#pragma once
#include "Film.h"

class DataProvider
{
	Film** filmek;
	int filmCounter;
	int* kolcsonzott;
	int kolcsonzottCounter;
	void addMovie(Film* film);


public:
	DataProvider() { 
		filmek = NULL; 
		kolcsonzott = NULL;
	};
	~DataProvider();
	Film** getMovies();
	int* getKolcsonzott();
	void addRentedMovie(int id);
	int getKolcsonzottCounter();
	int getFilmCounter();
};
