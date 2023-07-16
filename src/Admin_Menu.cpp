//Admin Menu
//includeing UDT header files

#include"Admin.h"

AdminMenu::AdminMenu()
{
	this->userChoice = -1;
	this->wrongChoice = 0;
}

//this function is displaying the menu for the admin operations
void AdminMenu::adminMenu()
{
	do
	{
				
		/*
		RouteMenu rm;//creating object for the Route menu
		AdminPassMenu apm;//object of admin paseenger menu
		ScheduleMenu sm;	//object of Schedule menu
		BusMenu bm;
		*/
	system("cls");

	
		//formatting
		cout<<"\n\n";
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<right<<setw(115)<<"A D M I N   M E N U"<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
		cout<<setw(70)<<" "<<"[1] Bus Related Operations"<<endl<<endl;
		cout<<setw(70)<<" "<<"[2] Route Related Operations\n\n";
		cout<<setw(70)<<" "<<"[3] Passenger Related Operations\n\n";
		cout<<setw(70)<<" "<<"[4] Driver Related Operations\n\n";
		cout<<setw(70)<<" "<<"[5] Schedule Related Operations\n\n";
		cout<<setw(70)<<" "<<"[0] Exit"<<endl<<endl;
		
		cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl<<endl;
		cout<<setw(70)<<" "<<"Enter Choice ::\t";
		
		while(1)
		{
			cin>>this->userChoice;
			if(!cin.fail())//user choice
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"\n\t\t\t\t\t\tEnter the valid number::\t";
				continue;
			}
		}
		
		if(this->userChoice == 0)
		{
			return;
		}
		
		Menu fadmin;
		Menu *menu;
		
		switch(this->userChoice)
		{
			case BUS_OPERATION:
				fadmin.Factory(BUS_OPERATION);
				menu = fadmin.getInstance();
				menu->busMenu();
				break;
				
			case ROUTE_OPERATION:
				fadmin.Factory(ROUTE_OPERATION);
				menu = fadmin.getInstance();
				menu->routeMenu();
				break;
				
			case PASSENGER_OPERATION:
				fadmin.Factory(PASSENGER_OPERATION);
				menu = fadmin.getInstance();				
				menu->adminPassMenu();
				break;
				
			case DRIVER_OPERATION:
				fadmin.Factory(DRIVER_OPERATION);
				menu = fadmin.getInstance();
				menu->driverMenu();
				break;
				
			case SCHEDULE_OPERATION:
				fadmin.Factory(SCHEDULE_OPERATION);
				menu = fadmin.getInstance();
				menu->scheduleMenu();
				break;
				
			case EXIT_ADMIN_MENU:
				wrongChoice = 0;
				break;
				
			default:
			
				cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<"\n\n\t\t\t\t\tYou entered wrong choice want to select again::\
					\n\t\t\t\t\t[1] Yes\n\
					\n\t\t\t\t\t[0] No"<<endl;
				cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<"\n\t\t\t\t\tEnter your choice::\t";
				
				while(1)
				{
					cin>>this->wrongChoice;
					if(!cin.fail())//user choice
					{
						break;
					}
					else
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout<<"\n\t\t\t\t\tEnter valid Number::\t";
						continue;
					}
				
				}
		
		
		}
		
	
	}while(wrongChoice != 0);
	
	
}


