#include "AkcioFilm.h"



AkcioFilm::AkcioFilm(String title, int price, int length, int rating, int year, String genre, int id)
{
	this->rentingPrice = price;
	this->title = title;
	this->genre = genre;
	this->length = length;
	this->id = id;
	this->year = year;
	this->rating = rating;
}


AkcioFilm::~AkcioFilm()
{
}
