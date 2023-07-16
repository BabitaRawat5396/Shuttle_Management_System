#include"Shuttle.h"

//--------------------------------------------Date Class Constructor and Setter or getter methods----------------------------------------

//default constructor //by default
Date::Date()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}


//parametrized constructor
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}


//setter for day
void Date::setDay(int day)
{
	this->day = day;
}


//setter for month
void Date::setMonth(int month)
{
	this->month = month;
}


//setter for year
void Date::setYear(int year)
{
	this->year = year;
}


//getter for day
int Date::getDay()

{
	return this->day;
}

//getter for month
int Date::getMonth()
{
	return this->month;
}


//getter fot year
int Date::getYear()
{
	return this->year;
}




















