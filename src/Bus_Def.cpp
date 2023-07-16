#include"Bus.h"
using namespace std;


//default constructor
Bus::Bus()
{
	int shuttleNo =0;
	string busNo = "\0";
	string RCNo = "\0";	//vehicle Registration Certificate Number
	string vehicleIns = "\0";	//vehicle Insurance Number
	int totalSeats = 30;
	int bookedSeats = 8;
}


//parameterized constructor
Bus::Bus( int shuttleNo, string busNo, string RCNo, string vehicleIns, int totalSeats, int bookedSeats )
{
	this->busNo = busNo;
	this->shuttleNo = shuttleNo;
	this->RCNo = RCNo; //vehicle Registration Certificate Number
	this->vehicleIns = vehicleIns;
	this->totalSeats = totalSeats;
	this->bookedSeats = bookedSeats;
}


// g e t t  e r  for all private members


int Bus::getShuttleNo()
{
	return this->shuttleNo;
}


string Bus::getBusNo()
{
	return this->busNo;
}



string Bus::getRCNo()
{
	return this->RCNo;
}



string Bus::getVehicleIns()
{
	return this->vehicleIns;
}



int Bus::setTotalSeats()
{
	return this->totalSeats;
}



int Bus::setBookedSeats()
{
	return this->bookedSeats;
}




// s e t t e r  for all private members


void Bus::setShuttleNo(int shuttleNo)
{
	this->shuttleNo = shuttleNo;
	
}


void Bus::setBusNo(string busNo)
{
	this->busNo = busNo;
}



void Bus::setRCNo(string RCNo)
{
	this->RCNo = RCNo; //vehicle Registration Certificate Number
	
}



void Bus::setVehicleIns( string vehicleIns)
{
	this->vehicleIns = vehicleIns;

}



void Bus::setTotalSeats(int totalSeats)
{
	this->totalSeats = totalSeats;
	
}



void Bus::setBookedSeats(int bookedSeats)
{
	this->bookedSeats = bookedSeats;
}


//function to generate shuttle number
int Bus::genShuttleNo()
{
	ifstream in;
	in.open("./DataBaseFiles/Bus_details.txt");
	
	int id;
	string line, word;
	while(getline(in, line))
	{
		stringstream ss(line);
		getline(ss, word, ',');
		id = stoi(word);
	}
	
	return (id+1);
	

}

