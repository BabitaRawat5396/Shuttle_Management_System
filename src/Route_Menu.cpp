//Function definitions for Route Class
//including udt header files
#include"Route.h"

RouteMenu::RouteMenu()
{
	this->userChoice = -1;
	this->wrongChoice = 1;
}

//this function is used to display the menu for the route related opeartions
void RouteMenu::routeMenu()
{
	Route rt;
	do
	{
		
		system("clear");
		
		//formatting
		cout<<"\n\n";
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<right<<setw(115)<<"R O U T E    M E N U"<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
			
		cout<<setw(70)<<" "<<"[1] Add New Route for Bus\n\n";
		cout<<setw(70)<<" "<<"[2] Modify Route Details\n\n";
		cout<<setw(70)<<" "<<"[3] Delete Route Details\n\n";
		cout<<setw(70)<<" "<<"[0] Exit"<<endl<<endl;
		
		cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl<<endl;
		cout<<setw(70)<<" "<<"Enter Choice ::\t";
			
		cin>>this->userChoice;
		
		switch(this->userChoice)
		{
			case ADD_ROUTE:
				rt.addRoute();//calling add route function
				break;
				
			case MODIFY_ROUTE:
				rt.modifyRoute();//calling modify route function 
				break;
				
			case DELETE_ROUTE:
				rt.deleteRoute();//calling delete function
				break;
				
			case EXIT_ROUTE:
				this->wrongChoice = 0;
				break;
				
			default:
				
				cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<"\n\n\t\t\t\t\tYou entered wrong choice want to select again::\n\n\
					\n\t\t\t\t\t[1] Yes\n\n\
					\n\t\t\t\t\t[0] No"<<endl<<endl;
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
	
	}while(this->wrongChoice == 1);
	
	
	return;
	
}











