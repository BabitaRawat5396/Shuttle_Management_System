//This file contains Function Definition of ADD Schedule  and generate Schedule ID

//Schedule Header file is included
#include"Schedule.h"


//This function returns nothing but adds Schedule details to the database. While taking input from the user, this function validates it and checks whether it already exists or not.
void Schedule::addSchedule()
{
	system("cls");

	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"A D D   S C H E D U L E"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	int flag = 0;
	int cont_choice, num=0, count =0;
	
		
	//Creating the object of ofstream class
	ofstream out;
	out.open("./DataBaseFiles/Schedule_Details.txt", ios::app);		//Opening the file in append mode
	
	//Checking if file is openned or Not
	if(!out.is_open())
	{
		cout<<"\n\t\t\t\t\tCannot open File";
		return;
	}
	
	//Do While loop for Entering multiple records 
	do
	{
		//generating Schedule Id 
		this->scheduleId = generateScheduleId();
		//writing shuttle number in file
		out<<this->scheduleId<<",";
			
		
		//--------------------------------------------------------------Taking Shuttle No from Admin------------------------------------------
		do
		{
			cout<<"\n\t\t\t\t\tShuttle Number :: ";
			cin>>this->shuttleNo;
			
			//Checking if user is giving correct input
			while(1)
			{
				cout<<endl;

				if(!cin.fail())	//If user has entered correct input, the loop will break
				{
					break;
				}
				else
				{
					cin.clear();	//Clearing the Buffer
					cin.ignore(numeric_limits<streamsize>::max(),'\n');	//this will ignore all the characters from buffer until it won't find new line
					cout<<"\n\t\t\t\t\tPlease enter correct Number::\t";
					cin>>this->shuttleNo;
				}
			}
			//check bus
			num = checkBus(this->shuttleNo);
			
			//shuttle validation
			if(this->vald.idValidation(this->shuttleNo) == 1 && num == 1)
			{
				//writing shuttle number in file
				out<<this->shuttleNo<<",";
				flag =1;
				num = 0;
			}
			
			
			//if shuttle number is already exists
			else if(this->vald.idValidation(this->shuttleNo) == 1 && num == 0)
			{
				cout<<"\n\t\t\t\t\tThis Shuttle Number does not belong to any Bus."<<endl;
				flag = 0;
				
			}
			
			//if shuttle number is wrong
			else if(this->vald.idValidation(this->shuttleNo) == 0)
			{
				cout<<"\n\t\t\t\t\tINVALID SHUTTLE NO...!!!!\n";//if invalid
				flag = 0;
				num = 0;
			}
			
		}while(flag!=1);
		
		cin.ignore();	//to input string after accepting integer value this is used to empty the buffer
		
		
		//--------------------------------------Taking Source and Destination from Admin----------------------------------------------
		do
		{
			cout<<"\n\t\t\t\t\tEnter the Source point :: ";
			getline(cin,this->source);
			
			cout<<"\n\t\t\t\t\tEnter the Destination point :: ";
			getline(cin,this->destination);
			
			//source destination validation
			num = checkSourceDestination(this->source, this->destination);
			
			if(num==1)
			{	
				//writing Source file	
				out<<this->source<<",";
				
				//writing destination file			
				out<<this->destination<<",";
				num = 0;
				flag = 1;
			}
			else
			{
				cout<<"\n\t\t\t\t\tSource and Destination point does not belong to any route"<<endl;
				flag = 0;
			}
		}while(flag != 1);
		
		//----------------------------------------------------Taking Start Time from Admin----------------------------------------------------------
		do
		{
			cout<<"\n\t\t\t\t\tEnter the start time :: Hour :: ";
			int hour;
			cin>>hour;
			
			//Checking if user is giving correct input
			while(1)
			{
				cout<<endl;

				if(!cin.fail())	//If user has entered correct input, the loop will break
				{
					break;
				}
				else
				{
					cin.clear();	//Clearing the Buffer
					cin.ignore(numeric_limits<streamsize>::max(),'\n');	//this will ignore all the characters from buffer until it won't find new line
					cout<<"\n\t\t\t\t\tPlease enter valid number::\t";
					cin>>hour;
				}
			}
			this->startTime.setHours(hour);
			
			cout<<"\n\t\t\t\t\t\t\t\tMinute :: ";
			int minute;
			cin>>minute;
			
			//Checking if user is giving correct input
			while(1)
			{
				cout<<endl;

				if(!cin.fail())	//If user has entered correct input, the loop will break
				{
					break;
				}
				else
				{
					cin.clear();	//Clearing the Buffer
					cin.ignore(numeric_limits<streamsize>::max(),'\n');	//this will ignore all the characters from buffer until it won't find new line
					cout<<"\n\t\t\t\t\tPlease enter valid number::\t";
					cin>>minute;
				}
			}
			this->startTime.setMinutes(minute);
			//time validation
			num = vald.timeValidation(this->startTime.getHours(), this->startTime.getMinutes());
			
			if(num == 1)
			{
				out<<this->startTime.getHours()<<":"<<this->startTime.getMinutes()<<":"<<"00"<<",";
				flag = 1;
			}
			
			else
			{
				cout<<"\n\t\t\t\t\tPlease Enter the correct time.";
				flag = 0;
			}
		}while(flag != 1);
		
		
		//------------------------------------------------------------Taking End Time from Admin----------------------------------------------------
		do
		{
			cout<<"\n\t\t\t\t\tEnter the end time    :: Hour :: ";
			int hour;
			cin>>hour;
			
			//Checking if user is giving correct input
			while(1)
			{
				cout<<endl;

				if(!cin.fail())	//If user has entered correct input, the loop will break
				{
					break;
				}
				else
				{
					cin.clear();	//Clearing the Buffer
					cin.ignore(numeric_limits<streamsize>::max(),'\n');	//this will ignore all the characters from buffer until it won't find new line
					cout<<"\n\t\t\t\t\tPlease enter valid number::\t";
					cin>>hour;
				}
			}
			this->endTime.setHours(hour);
			
			cout<<"\n\t\t\t\t\t\t\t\tMinute :: ";
			int minute;
			cin>>minute;
			
			//Checking if user is giving correct input
			while(1)
			{
				cout<<endl;

				if(!cin.fail())	//If user has entered correct input, the loop will break
				{
					break;
				}
				else
				{
					cin.clear();	//Clearing the Buffer
					cin.ignore(numeric_limits<streamsize>::max(),'\n');	//this will ignore all the characters from buffer until it won't find new line
					cout<<"\n\t\t\t\t\tPlease enter valid number::\t";
					cin>>minute;
				}
			}
			this->endTime.setMinutes(minute);
			
			//time validation
			num = vald.timeValidation(this->endTime.getHours(), this->endTime.getMinutes());
			
			if(num == 1)
			{
				out<<this->endTime.getHours()<<":"<<this->endTime.getMinutes()<<":"<<"00"<<",";
				flag = 1;
			}		
			else
			{
				cout<<"\n\t\t\t\t\tPlease Enter the correct time.";
				flag = 0;
			}
		
		}while(flag != 1);
		
		//------------------------------------------------------Taking Date from Admin----------------------------------------------------------------
		
		num = 0;	//Resetting num variable to Check Date
		do	//Taking date from Admin
		{
			cout<<"\n\t\t\t\t\tEnter Date (DD/MM/YYYY):: ";
			
			string date;
			cin>>date;
			
			int check = checkScheduleDate(date);	//Check if date is not more than 2 next two days from today
			int valid = vald.dateValidation(date);
			
			if(valid == 0)
			{
				flag =0;
				cout<<"\n\t\t\t\t\tPlease enter the date in the given format\n";
			}
			else if(check == -1)
			{
				flag =0;
				cout<<"\n\t\t\t\t\tYou have entered an outdated date......\n\t\t\t\t\tDates between today and the following two days must be entered\n";
			}	
			else if(check == 0)
			{
				flag =0;
				cout<<"\n\t\t\t\t\tDate Cannot be exceeded....\n\t\t\t\t\tDates between today and the following two days must be entered\n";
			}
			else
			{
				out<<date;
				flag =1;
			}
		}while(flag != 1);
						
		//asking if user want to enter more details
		cout<<"\n\t\t\t\t\tDo u want to Continue (1/0) :: ";
		cin>>cont_choice;
	
	
	}while(cont_choice!=0);
	
	cout<<endl<<endl;
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(100)<<"Data Inserted Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	return;
	
}

int Schedule::generateScheduleId()
{
	int id;
	string sche_in, line;
	
	ifstream in;
	in.open("./DataBaseFiles/Schedule_Details.txt");
	
	if(!in.is_open())//if file is not open
	{
		cout<<"Cannot open file"<<endl;
		return 0;
	}
	
	while(getline(in,line))
	{
		stringstream ss(line);
		
		getline(ss, sche_in,',');
		id = stoi(sche_in);
	}
	
	in.close();
	
	return id+1;
}













