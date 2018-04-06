#include "AkcioFilm.h"



AkcioFilm::AkcioFilm(String title, int price, int length, int rating)
{
	this->rentingPrice = price;
	this->title = title;
	this->length = length;
	this->rating = rating;
}


AkcioFilm::~AkcioFilm()
{
}
