#include"Shuttle.h"
#include"Admin.h"
#include"Bus.h"
#include"Driver.h"
#include"Route.h"
#include"Passenger.h"
#include"Schedule.h"

void Menu::Factory(int type)
{
	if(type == BUS_OPERATION)
	{
		
		menu = new BusMenu();
	}
	
	else if(type == ROUTE_OPERATION)
	{
		menu = new RouteMenu();
	}
	
	else if(type == PASSENGER_OPERATION)
	{
		menu = new AdminPassMenu();
	}
	
	else if(type == DRIVER_OPERATION)
	{
		menu = new DriverMenu();
	}
	
	else if(type == SCHEDULE_OPERATION)
	{
		menu = new ScheduleMenu();
	}
	
	else
	{
		menu = NULL;
	}
	
}

Menu* Menu::getInstance()
{
	return menu;
}

Menu::~Menu()
{

	if(menu)
	{
		delete menu;
		menu = NULL;
	}
	
}


















































void BusMenu::routeMenu()
{

}
void BusMenu::adminPassMenu()
{

}
void BusMenu::driverMenu()
{

}
void BusMenu::scheduleMenu()
{

}


void RouteMenu::busMenu()
{
	
}
void RouteMenu::adminPassMenu()
{

}
void RouteMenu::driverMenu()
{

}
void RouteMenu::scheduleMenu()
{

}


void AdminPassMenu::busMenu()
{
	
}
void AdminPassMenu::routeMenu()
{

}

void AdminPassMenu::driverMenu()
{

}
void AdminPassMenu::scheduleMenu()
{

}
void DriverMenu::busMenu()
{
	
}
void DriverMenu::routeMenu()
{

}
void DriverMenu::adminPassMenu()
{

}
void DriverMenu::scheduleMenu()
{

}void ScheduleMenu::busMenu()
{
	
}
void ScheduleMenu::routeMenu()
{

}
void ScheduleMenu::adminPassMenu()
{

}
void ScheduleMenu::driverMenu()
{

}


void Menu::busMenu()
{
	
}
void Menu::routeMenu()
{

}
void Menu::adminPassMenu()
{

}
void Menu::driverMenu()
{

}
void Menu::scheduleMenu()
{

}


