#include "FantasyFilm.h"



FantasyFilm::FantasyFilm()
{
}

FantasyFilm::FantasyFilm(String title, int price, int length, int rating, int year, String genre, int id)
{
	this->rentingPrice = price;
	this->id = id;
	this->title = title;
	this->length = length;
	this->genre = genre;
	this->rating = rating;
	this->year = year;
}

FantasyFilm::~FantasyFilm()
{
}
