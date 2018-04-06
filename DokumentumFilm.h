#pragma once
#include "Film.h"
class DokumentumFilm :
	public Film
{
public:
	DokumentumFilm(String title, int price, int length, int rating);

	DokumentumFilm();
	~DokumentumFilm();
};



