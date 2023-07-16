#include"Schedule.h"

//default constructor
Schedule::Schedule()
{
	scheduleId = 0;
	shuttleNo =0;		
	source = "\0";
	destination = "\0";
}

//get shuttle id
int Schedule::getShuttleNo()
{
	return this->shuttleNo;
}
	
//set shuttle id	
void Schedule::setShuttleNo(int n)
{
	this->shuttleNo=n;
}

//get source
string Schedule::getSource()
{
	return this->source;
}

//set source
void Schedule::setSource(string pick)
{
	this->source=pick;
}

//get destination
string Schedule::getDestination()
{
	return this->destination;
}

//set destination		
void Schedule::setDestination(string drop)
{
	this->destination=drop;
}



















