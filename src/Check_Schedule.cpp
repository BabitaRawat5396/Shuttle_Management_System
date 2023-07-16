#include"Schedule.h"

//this function is used to check the schedule date that not exceeds 2 days from now
int Schedule::checkSchedule(int id)
{
	int flag = 0;
	
	//object of ifstream
	ifstream in;
	//opening of file
	in.open("./DataBaseFiles/Schedule_Details.txt");
	
	if(!in.is_open())
	{
		cout<<"\n\t\t\t\tERROR: Data Can not be Fetched"<<endl;
		return 0;
	}
	
	string line;
	string scheduleId, shuttleId, pick, drop, startTime, endTime, date;
	
	while(getline(in, line))
	{
		stringstream ss(line);
		getline(ss, scheduleId, ',');
		
		if(id == stoi(scheduleId) && id != 0)	//This if Block is to check if Schedule Id Exist or Not
		{
			in.close();
			return 1;
		}
		if(id == stoi(scheduleId) && id == 0)	//This if block runs to Find Schedule if id is not passed By Passenger
		{
			flag = 1;
			cout<<setw(17)<<"Schedule Id"<<setw(17)<<"Shuttle No"<<setw(17)<<"Source"<<setw(25)<<"Destination"<<setw(20)<<"Start Time"<<setw(20)<<"End Time"<<"date"<<endl<<endl;
			
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
	}	
	
	in.close();
	
	if(flag == 1)	//This will run only if Schedule Details are printed
	{
		cout<<"\n\n\t\t\t\t**********************************************************************************************************"<<endl;
		cout<<endl<<endl;
	}
	
	return 0;
}


