#include"Shuttle.h"
using namespace std;


class Bus
{
	public:
		Bus();
		Bus(int, string, string, string, int, int);
		
		//getter for all private members
		int getShuttleNo();
		string getBusNo();
		string getRCNo();
		string getVehicleIns();
		int setTotalSeats();
		int setBookedSeats();
		
		//setter for all private members
		
		
		void setShuttleNo(int);
		void setBusNo(string);
		void setRCNo(string);
		void setVehicleIns(string);
		void setTotalSeats(int);
		void setBookedSeats(int);
		
		
		//function to perform on bus details
		
		void addBus();		//to add bus details to database 
		void deleteBus();	//to delete bus details from database	parameter:: int shuttleNo;
		void modifyBus();	//to modify bus details in the database	parameter:: int shuttleNo
		void listBus();			//to list all the bus details in database
		int genShuttleNo();	//generates shuttle number
		
		
	private:
		int shuttleNo;
		string busNo;	//bus Plate number
		string RCNo; //vehicle Registration Certificate Number
		string vehicleIns;  //vehicle Insurance Number
		int totalSeats;
		int bookedSeats;
		
};


class BusMenu
{
	public:
		
		BusMenu();
		//BusMenu(int,int); //inacse parameterized constructor required
		void busMenu(); //displays menu to manipulate bus database
	
	private:
		int userChoice;
		int wrongChoice;
		Bus bus;
		
};
