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
	String mainDirector;
public:
	Film();
	Film(String title, int price, int length, int rating);
	~Film();
	String getTitle();
};

