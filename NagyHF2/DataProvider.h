#pragma once
#include "Film.h"
#include "User.h"
class DataProvider
{
	Film** filmek;
	int filmCounter;
	User** kolcsonzott;
	int kolcsonzottCounter;
	void addMovie(Film* film);


public:
	DataProvider() { 
		filmek = NULL; 
		kolcsonzott = NULL;
	};
	~DataProvider();
	Film** getMovies();
	User** getKolcsonzott();
	void addRentedMovie(User* user);
	int getKolcsonzottCounter();
	int getFilmCounter();
};
