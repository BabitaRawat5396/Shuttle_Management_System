#include"Passenger.h"

//setter for passenger id
void Passenger::setPassengerId(int passengerId)
{
	this->passengerId = passengerId;
}

//getter for passenger id
int Passenger::getPassengerId()
{
	return this->passengerId;
}
		
//default constructors
Passenger::Passenger()
{
	passengerId = 0;
}

//parametrized constructor
Passenger::Passenger(int passengerId, string firstName, string lastName, int age, char gender, long int phone, string email, int day, int month, int year):Person(firstName, lastName, age, gender, phone, email, day, month, year)
{
	this->passengerId = passengerId;
}
		

