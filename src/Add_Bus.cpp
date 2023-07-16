//Function for adding bus details for bus.txt database manipulation
#include"Bus.h"

//for reference
/*
	
	int shuttleNo;
	string busNo;
	string RCNo; //vehicle Registration Certificate Number
	string vehicleIns;
	int totalSeats;
	int bookedSeats;

	int busNoValidation(string);
	int RCNoValidation(string);
	int vehicleInsValidation(string);
*/


//add Bus function to add bus details to the database
void Bus::addBus()
{
	system("cls");
	int flag = 0;
	int choice, valid =0;
	int seat=0;
	
	//creating the object of validation class to call validation 
	Validation val;
	
	//creating the object of ofstream class
	ofstream out;
	out.open("./DataBaseFiles/Bus_details.txt", ios::app);//opeining the file in append mode
	
	//if file is not open
	if(!out.is_open())
	{
		cout<<"\n\n\t\t\t\t\tCannot open File";
		exit(0);
	}
	
	do
	{
		
		cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<right<<setw(115)<<"A D D   B U S"<<endl<<endl;
		cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		
		//1	shuttleNo(to be generated)
		
		
		this->shuttleNo = genShuttleNo();
		//writing shuttle number in file
		out<<this->shuttleNo<<",";
		
		
		
		//2	busNo
		do
		{
			cout<<"\n\n\t\t\t\t\tBus Number :: ";
			cin>>this->busNo;
			
			//to convert all the characters into capital letters
			for(int i=0; i<this->busNo.length(); i++)
			{
				this->busNo.at(i) = toupper(this->busNo.at(i));
			}
			
			//busNo validation
			if(val.busNoValidation(this->busNo))	//if valid
			{
				flag =1;
			}
			else
			{
				cout<<"\n\n\t\t\t\t\tINVALID BUS NUMBER...!! FORMAT :: XX00XX0000 \n";//if invalid
				flag = 0;
			}
		}while(flag!=1);
		
		
		//writing bus number in file
		out<<this->busNo<<","; 
		
		
		//3	RCNo
		
		do
		{
			cout<<"\n\n\t\t\t\t\tRegistration Certificate Number of Bus(10 letters) :: ";
			cin>>this->RCNo;
			
			//to convert all the characters into capital letters
			for(int i=0; i<this->RCNo.length(); i++)
			{
				this->RCNo.at(i) = toupper(this->RCNo.at(i));
			}
			
			//shuttle validation
			if(val.RCNoValidation(this->RCNo))	//if valid
			{
				flag =1;
			}
			else
			{
				cout<<"\n\n\t\t\t\t\tINVALID Registration Certificate NUMBER...!!!!\n";	//if invalid
				flag = 0;
			}
		}while(flag!=1);
		
		
		
		//writing RC number in file
		out<<this->RCNo<<",";
		
		//4	vehicleIns
		
		do
		{
			cout<<"\n\n\t\t\t\t\tVehicle Insurance Number of Bus :: ";
			cin>>this->vehicleIns;
			
			//to convert all the characters into capital letters
			for(int i=0; i<this->vehicleIns.length(); i++)
			{
				this->vehicleIns.at(i) = toupper(this->vehicleIns.at(i));
			}
			
			int check = val.vehicleInsValidation(this->vehicleIns);
			//shuttle validation
			if(check == 1)	//if valid
			{
				flag =1;
			}
			else if(check == -1)
			{
				cout<<"\n\n\t\t\t\t\tINVALID VEHICLE INSURANCE NO...!!	FORMAT :: XX000000X \n";//if invalid
				flag = 0;
			}
			else
			{
				cout<<"\n\n\t\t\t\t\tVehicle Insurance already exist\n";
				flag =0;
			}	
		}while(flag!=1);
		
		
		
		//writing vehicle insurance number in file
		out<<this->vehicleIns<<",";
		
		
		//5 total seats
		
		
		do	
		{	
			cout<<"\n\n\t\t\t\t\tTotal Number of Seats in Bus :: \t";
			valid=0;
			while(1)

			{
				cout<<endl;
				cin>>totalSeats;
				if(!cin.fail())//user choice
				{
					break;
				}
				else
				{
					cin.clear();
					cin.ignore();
					cout<<"\n\n\t\t\t\t\tEnter Total Number of Seats in Bus ::\t";
					continue;
				}
			}
			
			if(val.totalSeatsValidation(this->totalSeats) )
				valid =1;
			else
				cout<<"\n\t\t\t\t\tInvalid total seats !!! Enter Number between 20 to 45\n";
			
		}while(valid!=1);
		
		
		//writing TOTAL NUMBER OF SEATS in file
		out<<this->totalSeats<<",";
		
		
		//6 booked seats
		
		do
		{
			cout<<"\n\n\t\t\t\t\tNumber of Booked Seats in Bus :: \t";
				while(1)
				{
					cout<<endl;
					cin>>seat;
					if(!cin.fail())//user choice
					{
						break;
					}
					else
					{
						cin.clear();
						cin.ignore();
						cout<<"\n\n\t\t\t\t\tEnter Proper Number of Booked Seats::\t";
						continue;
					}
				}
			
			if( val.bookedSeatsValidation(seat,this->totalSeats) && (seat <= this->totalSeats) )
			{
				
				valid =1;
			}
			else
				cout<<"\n\n\t\t\t\t\tINVALID ENTRY!! should be less than "<< this->totalSeats;
				
				
			
		}while(valid!=1);
		
		//writing vehicle insurance number in file
		out<<seat<<endl;
		
		//asking if user want to enter more details
		cout<<"\n\n\t\t\t\t\tDo u want to Continue::(1/0) :: ";
		cin>>choice;
	
	
	}while(choice!=0);	//entered all the bus detaios correctly

	out.close();	//closing ofstream object
	
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<"\n\n\t\t\t\t\tBus Details Added Successfully!!"<<endl<<endl;
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
} // addbus
