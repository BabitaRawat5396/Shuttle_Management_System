//Header File for Route Class

#include"Shuttle.h"
/*
	To use user-defined datatypes into stack, we have to override < operator, that can compare two values of that type. If this is not present, it cannot compare two objects, so the set cannot store data in sorted order, so will raise an exception.

*/

class Route
{
	private:
	        int routeId;
	        int shuttleNo;
	        string source;
	        string destination;
	    	Validation val;
	public:
		//Constructor
		Route();
		
		
		//Setters
		void setRouteId(int);
		void setShuttleNo(int);
		void setSource(string);
		void setDestination(string);
		
		
		//Getters
		int getRouteId();
		int getShuttleNo();
		string getSource();
		string getDestination();
		
		
		
		
		//Route Operations Function Declaration
		void addRoute();
		void deleteRoute();
		void modifyRoute();
		int checkRouteById(int = 0);
		void checkRouteByDest();
		void listRoute();
		int generateRouteId();
};


class RouteMenu:public Menu
{
	public:
		//constructor
		RouteMenu();
		
		//Menu function for Route
		void routeMenu();
		virtual void busMenu();
		//virtual void routeMenu();
		virtual void adminPassMenu();
		virtual void driverMenu();
		virtual void scheduleMenu();
		
	private:
		int userChoice;
		int wrongChoice;
		
		
};



