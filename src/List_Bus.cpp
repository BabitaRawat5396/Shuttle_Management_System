//Function Definition for List Bus Details

//#include"Shuttle.h"
#include"Bus.h"

using namespace std;
//function to list the details of the bus
void Bus::listBus()
{
	
	//to clear the screen
	system("cls");

	cout<<endl<<endl<<endl<<endl;
	
	//object of ifstream class to read the data
	ifstream in;
	in.open("./DataBaseFiles/Bus_details.txt");//opening the file
	
	//if file is not opened
	if(!in.is_open())
	{
		cout<<"\n\t\t\t\tCannot open File";
		exit(0);
	}
	
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<" B U S   D E T A I L S "<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;

	cout<<setw(38)<<"SR No."<<setw(25)<<"Shuttle Number"<<setw(20)<<"Bus Number"<<setw(20)<<"RC Number"<<setw(35)<<"Vehicle inssurance Number"<<setw(15)<<"Total Seats"<<setw(15)<<"Booked Seats"<<endl<<endl;

	
	//strings to store the data from the files
	string line;
	
	//bus details data members
	string suhttleNo, busNo, RCNo, VehicleIns, totalSeats, bookedSeats;
	
	int n = 1;
	 
	//while loop to read data from the file
	while(getline(in,line))
	{
		//printing serial number
		cout<<setw(38)<<n++;
		
		stringstream ss(line);
		//cout<<"\t\t";
		
		//reading the shuttle number from the file
		getline(ss, suhttleNo,',');
		cout<<setw(25)<<suhttleNo;
		
		//reading the bus number from the file
		getline(ss, busNo,',');
		cout<<setw(20)<<busNo;
		
		//reading RC Number from the file
		getline(ss, RCNo,',');
		cout<<setw(20)<<RCNo;
		
		//reading vehicle Insurance Number from the file
		getline(ss, VehicleIns,',');
		cout<<setw(35)<<VehicleIns;
		
		//reading total number of seats fin bus rom the file
		getline(ss, totalSeats,',');
		cout<<setw(15)<<totalSeats;
		
		//reading vehicle boOked number of seats from the file
		getline(ss, bookedSeats,',');
		cout<<setw(15)<<bookedSeats;
		
		
		//for newline
		cout<<endl;
		
		
	}
		
	//closing the file
	in.close();
	
	
	char ch;
	cout<<"\n\n\n\t\t\t\t\tEnter any key.........";
	cin>>ch;
	
	//FORMATTING
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	return;
	
}
