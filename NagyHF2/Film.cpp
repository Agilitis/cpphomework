#include "Film.h"


Film::Film() {};
Film::Film(String title, int price, int length, int rating, String genre, int id)
{
 	this->rentingPrice = price;
	this->title = title;
	this->id = id;
	this->length = length;
	this->rating = rating;
	this->genre = genre;
}


Film::~Film()
{

}

String Film::getTitle()
{
	return title;
}

String Film::getGenre() {
	return genre;
}

int Film::getYear()
{
	return year;
}

int Film::getId()
{
	return id;
}




