#include"Route.h"

//default constructor
Route::Route()
{
	routeId = 0;
	shuttleNo = 0;
	source = "\0";
	destination = "\0";
}

//setters
void Route::setRouteId(int routeId)
{
	this->routeId = routeId;
}

void Route::setShuttleNo(int shuttle_no)
{
	this->shuttleNo = shuttle_no;
}

void Route::setSource(string source)
{
	this->source = source;
}

void Route::setDestination(string destination)
{
	this->destination = destination;
}

//getters
int Route::getRouteId()
{
	return this->routeId;
}

int Route::getShuttleNo()
{
	return this->shuttleNo;
}

string Route::getSource()
{
	return this->source;
}

string Route::getDestination()
{
	return this->destination;
}

