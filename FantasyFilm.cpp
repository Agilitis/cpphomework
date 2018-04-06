#include "FantasyFilm.h"



FantasyFilm::FantasyFilm()
{
}

FantasyFilm::FantasyFilm(String title, int price, int length, int rating)
{
	this->rentingPrice = price;
	this->title = title;
	this->length = length;
	this->rating = rating;
}

FantasyFilm::~FantasyFilm()
{
}
