#pragma once
#include "Film.h"
class AkcioFilm :
	public Film
{
public:
	AkcioFilm(String title, int price, int length,int rating, int year, String genre, int id);
	~AkcioFilm();
};

