//Header File for Shuttle

//including file guards
#ifndef SHUTTLE_H
#define SHUTTLE_H


//including header files
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<set>
#include<vector>
#include<limits>
#include<regex>

using namespace std;

//macros for login
#define ADMIN_LOGIN 1
#define PASSENGER_LOGIN 2
#define EXIT_LOGIN 0

//macros for passenger menu
#define CHECK_ROUTE_BY_DEST 1
#define NEW_BOOKING 2
#define CHECK_PREV_BOOKING 3
#define CHECK_PROFILE 4
#define EXIT_PM 0

//macros for the admin operations on passenger details
#define ADD_PASSENGER 1
#define CHECK_PASSENGER 2
#define MODIFY_PASSENGER 3
#define DELETE_PASSENGER 4
#define LIST_DETAILS_PASSENGER 5
#define EXIT_APM 0

//macros for bus menu class
#define ADD_BUS 1
#define REMOVE_BUS 2
#define MODIFY_BUS 3
#define LIST_BUS 4
#define EXIT_BUS 0

//macros for modify Schedule
#define SHUTTLE_NO 1
#define PICK_POINT 2
#define DROP_POINT 3
#define START_TIME 4
#define END_TIME 5
#define DATE 6
#define EXIT_MOD_SCH 0

//macros for schedule menu
#define ADD_SCHEDULE 1
#define DELETE_SCHEDULE 2
#define MODIFY_SCHEDULE 3
#define LIST_SCHEDULE 4
#define EXIT_SCHEDULE 0

//macros for the route
#define ADD_ROUTE 1
#define MODIFY_ROUTE 2
#define DELETE_ROUTE 3
#define EXIT_ROUTE 0

//macros for admin menu
#define BUS_OPERATION 1
#define ROUTE_OPERATION 2
#define PASSENGER_OPERATION 3
#define DRIVER_OPERATION 4
#define SCHEDULE_OPERATION 5 
#define EXIT_OPERATION 0

//driver menu macros
#define ADD_DRIVER	1
#define LIST_DRIVER	2
#define MODIFY_DRIVER	3
#define DELETE_DRIVER	4
#define CHECK_DRIVER	5
#define EXIT_DRIVER	0

//defining namespace for global functions
namespace global
{
	int checkBus(int);
	int checkSourceDestination(string, string);
	int checkBlockPassenger(int=0);
}


using namespace global;
//class main menu

//for factory class
class Menu
{
	public:
		void Factory(int);
		Menu* getInstance();
		virtual void busMenu();
		virtual void routeMenu();
		virtual void adminPassMenu();
		virtual void driverMenu();
		virtual void scheduleMenu();
		~Menu();
	private:
		Menu *menu;
};

class MainMenu
{
	public:
		MainMenu();
		void mainMenu();
		
	private:
		int userChoice;
		int wrongChoice;
};



//class validation

class Validation
{
	public:
		int uniquePan(string);
		int mobileValidation(long int);
		int emailValidation(string);
		int nameValidation(string);
		int passValidation(string);
		int passengerIdValidation(int);
		int genderValidation(char);
		int ageValidation(int);
		int idValidation(int);
		int dobValidation(string);
		int timeValidation(int, int);
		int dateValidation(string);
		
		
		//bus attributes validation functions
		int busNoValidation(string);
		int RCNoValidation(string);
		int vehicleInsValidation(string);
		int totalSeatsValidation(int);
		int bookedSeatsValidation(int);
		
				
		
		//TN 01 N 5377	//2 characters(State Code/ RTO Code) - 2 digits(District code) - 2 characters - 4 digit unique number		//10Characters - string		
		//AA123456C //format is two prefix letters, six digits and one suffix letter
		
		int licenseNoValidation(string);
		
};

//class Date
class Date
{
	public:
		//getters
		int getDay();
		int getMonth();
		int getYear();
		//setters
		void setDay(int);
		void setMonth(int);
		void setYear(int);
		//display date function
		void displaDate();
		//constructors
		Date();
		Date(int, int, int);
		
	private:
		int day, month, year;
};



//class Time
class Time
{
	private:
		int hours, minutes, seconds;
	public:
		Time();
		Time(int,int,int);
		void display();
		void accept();
		int getHours();
		void setHours(int);
		int getMinutes();
		void setMinutes(int);
		int getSeconds();
		void setSeconds(int);
};


//ending file guards
#endif




