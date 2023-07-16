//Definitions for class PassengerTravelDetails
#include"Passenger.h"

//Getters
int PassengerTravelDetails::getRouteId()
{
	return this->routeId;
}

int PassengerTravelDetails::getPassengerId()
{
	return this->passengerId;
}

string PassengerTravelDetails::getPickPoint()
{
	return this->pickPoint;
}

string PassengerTravelDetails::getDropPoint()
{
	return this->dropPoint;
}

	
//Setters
void PassengerTravelDetails::setRouteId(int rId)
{
	this->routeId = rId;
}

void PassengerTravelDetails::setPassengerId(int pId)
{
	this->passengerId = pId;
}

void PassengerTravelDetails::setPickPoint(string pick)
{
	this->pickPoint = pick;
}

void PassengerTravelDetails::setDropPoint(string drop)
{
	this->dropPoint = drop;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
