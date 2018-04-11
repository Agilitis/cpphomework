#include "DokumentumFilm.h"

DokumentumFilm::DokumentumFilm()
{
}

DokumentumFilm::DokumentumFilm(String title, int price, int length, int rating, int year, String genre, int id)
{
	this->rentingPrice = price;
	this->title = title;
	this->length = length;
	this->year = year;
	this->rating = rating;
	this->id = id;
	this->genre = genre;
}
DokumentumFilm::~DokumentumFilm()
{

}


