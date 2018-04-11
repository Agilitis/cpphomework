#pragma once
#include <iostream>
#include "String.h"
class Film
{
protected:
	int rentingPrice;
	String title;
	int id;
	int rating;
	int length;
	int year;
	String genre;
	String mainDirector;
public:
	Film();
	Film(String title, int price, int length, int rating, String genre, int id);
	~Film();
	String getTitle();
	String getGenre();
	int getYear();
	int getId();
};

