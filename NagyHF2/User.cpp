#include "User.h"








int User::getFilmId()
{
	return filmId;
}


int User::getDate()
{
	return date;
}

String User::getNev()
{
	return nev;
}

User::User(int filmId, int date, String nev)
{
	this->nev = nev;
	this->date = date;
	this->filmId = filmId;
}

User::~User()
{
}
