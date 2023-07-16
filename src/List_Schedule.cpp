//Function Definition of LIST Schedule Details

//Schedule Header file is included
#include"Schedule.h"

//This function returns nothing but List the details of all the Schedules in the database. 
void Schedule::listSchedule()
{
	
	system("clear");
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"S C H E D U L E    D E T A I  L S "<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	ifstream in;//creating the object
	in.open("./DataBaseFiles/Schedule_Details.txt");//opeining the file
	
	if(!in.is_open())//if not opened
	{
		cout<<"\n\t\t\t\t\tData can not be fetched"<<endl;
	}
	
	//variables to store the data from the file
	string line, word;
	string scheduleId, shuttleId, pick, drop, startTime, endTime,date;
	int n=1;
	
	
	cout<<setw(38)<<"S.NO."<<setw(17)<<"schedule Id"<<setw(17)<<"Shuttle No"<<setw(17)<<"Source"<<setw(25)<<"Destination"<<setw(18)<<"Start Time"<<setw(19)<<"End Time"<<setw(16)<<"Date"<<endl<<endl;
	while(getline(in, line))
	{
		cout<<right<<setw(35)<<n++;
		
		stringstream ss(line);
		
		cout<<"\t\t";
		//reading the Schedule ID from the file
		getline(ss, scheduleId,',');
		cout<<setw(15)<<left<<scheduleId;
		
		//reading Shuttle No from the file
		getline(ss, shuttleId,',');
		cout<<setw(20)<<shuttleId;
		
		//reading Source from the file
		getline(ss, pick,',');
		cout<<setw(20)<<pick;
		
		//reading Destination from the file
		getline(ss, drop,',');
		cout<<setw(20)<<drop;
		
		//reading Start Time from the file
		getline(ss, startTime,',');
		cout<<setw(20)<<startTime;
		
		//reading End Time from the file
		getline(ss, endTime,',');
		cout<<setw(20)<<endTime;		
		
		//reading date from the file
		getline(ss, date,',');
		cout<<setw(20)<<date;		
		
		//for newline
		cout<<endl;
		
	}
	//closing the file
	in.close();
	
	
	
	//Formatting
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	char ch;
	cout<<"\n\t\t\t\t\tEnter any key.........";
	cin>>ch;
	
	
	return;
}




















