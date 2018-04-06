#include "Film.h"


Film::Film() {};
Film::Film(String title, int price, int length, int rating)
{
	this->rentingPrice = price;
	this->title = title;
	this->length = length;
	this->rating = rating;
}


Film::~Film()
{

}

String Film::getTitle()
{
	return title;
}




