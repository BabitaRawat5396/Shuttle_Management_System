//Headre File for Schedule 

//Including Shuttle Header File
#include"Shuttle.h"

//Class Definition for schedule
class Schedule
{
	public:
		//Default Constructor
		Schedule();
		
		//Getter and Setter for Shuttle No
		int getShuttleNo();
		void setShuttleNo(int);
		
		//Getter and Setter for Source
		string getSource();
		void setSource(string);
		
		//Getter and Setter for Destination
		string getDestination();
		void setDestination(string);
		
		//Generating Schedule Id
		int generateScheduleId();
		
		//Checking Schedule If it is old from today's date
		int checkScheduleDate(string);
		
		//Checking Schedule
		int checkSchedule(int=0);
		
		//Add Schedule Function Declaration
		void addSchedule();
		
		//List Schedule Function Declaration
		void listSchedule();
		
		//Modify Schedule Function Declaration
		void modifySchedule();
		
		//DeleteSchedule Function Declaration
		void deleteSchedule();
				
	private:
		int scheduleId;
		int shuttleNo;		
		Time startTime;
		Time endTime;
		string source;
		string destination;
		Date dt;
		Validation vald;
};



//class for admin menu
class ScheduleMenu:public Menu
{
	public:
		void scheduleMenu();
		virtual void busMenu();
		virtual void routeMenu();
		virtual void adminPassMenu();
		virtual void driverMenu();
		//virtual void scheduleMenu();
		
		//Constructor
		ScheduleMenu();
		
	private:
		int userChoice;
		int wrongChoice;
		
		
};

