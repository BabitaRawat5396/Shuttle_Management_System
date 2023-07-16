#include"Shuttle.h"

//default constructor
Time::Time()
{
	hours=0;
	minutes=0;
	seconds=0;
}


//parametrized constructor
Time::Time(int hours,int minutes,int seconds)
{
	this->hours=hours;
	this->minutes=minutes;
	this->seconds=seconds;
}

//getter for hours
int Time::getHours()
{
	return this->hours;
}

//setter for hours
void Time::setHours(int hours)
{
	this->hours=hours;
}

//getter for minutes
int Time::getMinutes()
{
	return this->minutes;
}

//setter for minutes
void Time::setMinutes(int minutes)
{
	this->minutes=minutes;
}

//getter for seconds
int Time::getSeconds()
{
	return this->seconds;
}

//setter for seconds
void Time::setSeconds(int seconds)
{
	this->seconds=seconds;
}

//accepting from the suer
void Time::accept()
{
	cout<<"Enter Time: ";
	cin>>this->hours>>this->minutes>>this->seconds;
}

//displaying the time
void Time::display()
{
	cout<<"Time = "<<this->hours<<":"<<this->minutes<<":"<<this->seconds<<endl;
}
