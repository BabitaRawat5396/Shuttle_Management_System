#include"Person.h"


class Driver:public Person 
{
	public:
		//getter for all private members
		int getDriverId();
		
		string getPanNo();// get driver PAN Number
		
		string getLicenseNo();
		
		
		//setter for all private members
		void setDriverId(int);
		
		void setPanNo(string);
		
		void setLicenseNo(string);
		
		
		
		//function to perform on driver details
		//return type int status check: 1 = removed:: 0 = not able to remove
		
		void addDriver();
		
		void listDriver();
			
		void modifyDriver();
			
		void deleteDriver();
		
		int checkDriver(int);
		
		int generateDriverId();
		
		Driver();
		Driver(int,string,string,string,string,int,char,long int,string,int,int,int);
			
		
		
		
	private:
		int driverid;
		string panNo;//driver PAN Number
		string licenseNo;//driver license Number
		Validation vald;

};

class DriverMenu:public Menu
{
	public:
		
		DriverMenu();
		//BusMenu(int,int); //inacse parameterized constructor required
		void driverMenu(); //displays menu to manipulate bus database
		virtual void busMenu();
		virtual void routeMenu();
		virtual void adminPassMenu();
		virtual void scheduleMenu();
	
	private:
		int userChoice = -1;
		int wrongChoice = -1;
		
};








