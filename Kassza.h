#pragma once
#include "Film.h"

class Kassza
{
	Film **filmek;
	int filmCounter;
	Film **kolcsonzott;
	int kolcsonzottCounter;
public:
	Kassza();
	virtual ~Kassza();
	void listMovies();
	void getRentPrice(int id);
	void addMovie(Film* film);
};

