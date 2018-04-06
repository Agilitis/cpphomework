#include <fstream>
#include "Kassza.h"



Kassza::Kassza()
{
}


Kassza::~Kassza()
{

}

void Kassza::listMovies()
{
	for (int i = 0; i < filmCounter; i++)
	{
		std::cout << filmek[i]->getTitle() << std::endl;
	}
}



void Kassza::getRentPrice(int id)
{

}

void Kassza::addMovie(Film* film) 
{
	if (filmCounter == 0) {
		filmCounter++;
		filmek = new Film*[filmCounter];
		filmek[0] = film;
	}
	else {
		filmCounter++;
		Film** tmp = new Film*[filmCounter];
		for (int i = 0; i < filmCounter - 1; i++) {
			tmp[i] = filmek[i];
		}
		tmp[filmCounter - 1] = film;
		delete[] filmek;
		filmek = tmp;
	}
}



