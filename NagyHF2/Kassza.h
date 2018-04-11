#pragma once
#include "DataProvider.h"
#include "Film.h"
class Kassza
{
	DataProvider _dataProvider;
public:
	Kassza();
	virtual ~Kassza();
	void listMovies();
	void listMoivesByTitle();
	void listMoviesByGenre();
	void listMoviesByYear();
	void getRentPrice(int id);
	bool rentMovie(int id);
	bool isMovieAvailable(int id);
	
	
};

