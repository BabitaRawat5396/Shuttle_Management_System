
#include"Passenger.h"
#include"Route.h"

PassengerMenu::PassengerMenu()
{
	this->userChoice = -1;
	this->wrongChoice = -1;
}

//function to display the passenger menu and passenger operations
void PassengerMenu::passengerMenu(int id)
{
	Passenger passen;
	Route route;
	Booking booking;
	do
	{
		system("cls");

		//formatting
		cout<<"\n\n";
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<right<<setw(115)<<"P A S S E N G E R   M E N U"<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
			
		cout<<setw(70)<<" "<<"[1] Check Routes by Destinations\n\n";
		cout<<setw(70)<<" "<<"[2] New Booking\n\n";
		cout<<setw(70)<<" "<<"[3] Check Previous Booking\n\n";
		cout<<setw(70)<<" "<<"[0] Exit :: \n"<<endl<<endl;
		cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<"\n\t\t\t\t\tEnter your choice::\t";
			
		
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
				cout<<"\n\t\t\t\t\tEnter the correct Choice::\t";
				continue;
			}
		}
		
		
		switch(this->userChoice)
		{
			case 1:
				
				route.checkRouteByDest();
				system("clear");
				break;
				
			case 2:
				booking.newBooking(id);
				system("clear");
				break;
				
			case 3:
				booking.listPreviousBooking(id);
				system("clear");
				break;
				
			case 4:
				//passen.checkPassenger(id);
				system("clear");
				break;
				
			case 0:
				cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<"\n\n\t\t\t\t\tThanks For Visiting"<<endl<<endl;
				exit(0);
				
			default:
				cout<<"\n\n\tYou entered wrong choice want to select again::\
					\n\t\t[1] Yes\
					\n\t\t[0] No"<<endl;
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
						cout<<"\n\t\t\t\t\tEnter the correct Choice::\t";
						continue;
					}
				}		
		}
	}while(wrongChoice != 0);
	
	return;
	
}























