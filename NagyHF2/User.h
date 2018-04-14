#pragma once
#include "String.h"
class User
{
	String nev;
	int filmId;
	int date;
public:
	int getFilmId();
	int getDate();
	String getNev();
	User(int filmId, int date, String nev);
	~User();
};

