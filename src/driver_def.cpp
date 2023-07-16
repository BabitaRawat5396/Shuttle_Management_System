#include"Driver.h"

//setter for all private member

//setter for DRIVER ID
void Driver::setDriverId(int driverid)
{
	this->driverid= driverid;
}
//setter for Pan no.
void Driver::setPanNo(string panNo)
{
	this->panNo= panNo;
}
//setter for License number
void Driver::setLicenseNo(string licenseNo)
{
	this->licenseNo= licenseNo;
}


//getter for all private members

//getter for passenger id
int Driver::getDriverId()
{
	return this->driverid;
}
		
//getter for driver PAN Number
string Driver::getPanNo()
{
	return this->panNo;
}
		
//getter for driver License Number
string Driver::getLicenseNo()
{
	return this->licenseNo;
}

	
//default constructor
Driver::Driver()
{		
	
	driverid =  0;
	panNo = "\0";//driver PAN Number
	licenseNo = "\0";//driver license Number
	
}

//parametrized constructor
Driver::Driver(int driverid, string panNo, string licenseNo, string firstName, string lastName, int age, char gender, long int phone, string email, int day, int month, int year):Person(firstName, lastName, age, gender, phone, email, day, month, year)
{
	this->driverid= driverid;
	this->panNo= panNo;
	this->licenseNo= licenseNo;
	
}
//function to generate passenger id
int Driver::generateDriverId()

{
	int id;
	string dri_id, line;
	
	ifstream in;
	in.open("./DataBaseFiles/driver_details.txt");
	
	if(!in.is_open())//if file is not open
	{
		cout<<"\n\t\t\t\t\tCannot open file"<<endl;
		return 0;
	}
	
	while(getline(in,line))
	{
		stringstream ss(line);
		
		getline(ss, dri_id,',');
		id = stoi(dri_id);
	}
	
	in.close();
	
	return id+1;
}


		

