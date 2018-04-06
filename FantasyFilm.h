#pragma once
#include "Film.h"
class FantasyFilm :
	public Film
{
public:
	FantasyFilm(String title, int price, int length, int rating);

	FantasyFilm();
	~FantasyFilm();
};

