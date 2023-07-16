//Function Definition of ADD Passenger

//Schedule Header file is included
#include"Schedule.h"

//This function returns 1 if the date is less than the next two dates, otherwise it returns 0.
int Schedule::checkScheduleDate(string date)
{
	//---------------updating history and Schedules--------------------------------
	
	//creating vector of string to store temp variables
	vector<string> v;
	
	//Creating set variable to store old schedule records which have passed today's date
	set<vector<string>> sche_prev_rec;
	
	//Creating set variable to store schedule records from today's next two dates
	set<vector<string>> sche_next_rec;	
	
	//temp variables
	int day, month, year;
	int i;	//Variable used in for loop
	
	string word, line;
	
	// get current date and time  (Number of seconds since January 1,1900)
	time_t now = time(0); 
	 tm* ltm = localtime(&now);  	
	 
	 //Storing today's date in diff variables
	int t_year = 1900 + ltm->tm_year;	//  year  
    	int t_month = 1 + ltm->tm_mon;	 //month
    	int t_day = ltm->tm_mday;		 //day  
	
	//Creating the object of an ifstream 
	ifstream in;
	in.open("./DataBaseFiles/Schedule_Details.txt");
	
	
	//Checking if file is openned or Not
	if(!in.is_open())
	{
		cout<<"\n\t\t\t\t\tCannot open File";
		return 0;
	}
	
	 //Reading attributes
	while(getline(in,line))
	{
		
		stringstream ss(line);	//creating the stream of the line of the file
		
		getline(ss, word,',');	//Reading the Schedule Id from the file
		v.push_back(word);
		
		getline(ss,word,',');	//Reading Shuttle no
		v.push_back(word);
		
		getline(ss,word,',');	//Reading Pick Point
		v.push_back(word);
		
		getline(ss, word,',');	//Reading Drop Point
		v.push_back(word);
		
		getline(ss, word,',');	//Reading Start Time
		v.push_back(word);
		
		getline(ss, word,',');	//Reading End Time
		v.push_back(word);
		
		getline(ss, word,',');	//Reading Date
		v.push_back(word);
		
		//creating the stream of the line of the file
		stringstream dt(word);
		string str;
		
		//Reading day from the word that is representing date 
		getline(dt, str, '/');
		day = stoi(str);
		
		//Reading month 
		getline(dt, str, '/');
		month = stoi(str);
			
		//Reading Year
		getline(dt, str, '/');
		year = stoi(str);	
		
		//Checking if there are any schedule that has passed today's date will get stored in the set of vector of string 
		if(	(t_year > year) || (t_year == year && t_month  > month) || (t_year == year && t_month  == month && t_day > day)	)
		{
			sche_prev_rec.insert(v);
		}
		
		else
		{
			sche_next_rec.insert(v);
		}
		v.clear();			
	}
	
	//-------Writing old schedule to the file containing history of schedules-----------
	
	//Creating the out stream object
	ofstream out;
	
	//Opening the File
	out.open("./DataBaseFiles/schedule_history.txt",ios::app);
	
	//Check if file is opened or not
	if(!out.is_open())
	{
		cout<<"\n\t\t\t\t\tERROR: Cannot File Found";
	}
	
	//For loop to write Data into file
	for( auto it = sche_prev_rec.begin(); it!= sche_prev_rec.end(); it++)
	{
		for(i =0; i < (*it).size() - 1; i++)
		{
			out<<(*it)[i]<<",";	// Writing comma seperated
		}
		out<<(*it)[i]<<"\n";	//Ending each line with New Line
	}
	
	//Closing the File
	out.close();
	
	//-------Writing rest schedule to file containing details of schedule for 2 days only-----------
	
	//Opening the File
	out.open("./DataBaseFiles/Schedule_Details.txt");
	
	//Check if file is opened or not
	if(!out.is_open())
	{
		cout<<"\n\t\t\t\t\tERROR: Cannot File Found";
	}
	
	//For loop to write Data into file
	for( auto it = sche_next_rec.begin(); it!= sche_next_rec.end(); it++)
	{
		for(i =0; i < (*it).size() - 1; i++)
		{
			out<<(*it)[i]<<",";	// Writing comma seperated
		}
		out<<(*it)[i]<<"\n";	//Ending each line with New Line
	}
	
	//Closing the File
	out.close();
	
	//---------to check if the passed date is not more than next 2 days from today------------------
	
	//creating the stream of the line of the file
	stringstream dt(date);
	string str;
		
	//Reading day from the word that is representing date 
	getline(dt, str, '/');
	day = stoi(str);
		
	//Reading month 
	getline(dt, str, '/');
	month = stoi(str);
			
	//Reading Year
	getline(dt, str, '/');
	year = stoi(str);
	
	//if date entered is less than today's date this if loop will run
	if(	(t_year > year) || (t_year == year && t_month  > month) || (t_year == year && t_month  == month && (t_day) >day)	)
	{
		return -1;
	}
	//if date entered is greater than today's date this if loop will run
	if(	(t_year > year) || (t_year == year && t_month  > month) || (t_year == year && t_month  == month && (t_day+2) <day)	)
	{
		return 0;
	}
	//this will return 1 if date is correct
	return 1;
}


