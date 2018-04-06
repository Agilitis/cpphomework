#include "DokumentumFilm.h"

DokumentumFilm::DokumentumFilm()
{
}

DokumentumFilm::DokumentumFilm(String title, int price, int length, int rating)
{
	this->rentingPrice = price;
	this->title = title;
	this->length = length;
	this->rating = rating;
}
DokumentumFilm::~DokumentumFilm()
{

}


