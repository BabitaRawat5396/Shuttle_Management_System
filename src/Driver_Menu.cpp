#include"Driver.h"


DriverMenu::DriverMenu()
{
	this->userChoice = -1;
	this->wrongChoice = -1;
}

//fuction to display the driver menu

void DriverMenu::driverMenu()
{
	
	
	string busNo, panNo, licenseNo;
	int driverid;
	Driver driver;//creating object of class Driver
	
	do
	{
		system("clear");
		//formatting
		cout<<"\n\n";
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<right<<setw(115)<<"D R I V E R   M E N U"<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
			
		cout<<setw(70)<<" "<<"[1] Add Driver\n\n";
		cout<<setw(70)<<" "<<"[2] List Details Of Driver\n\n";
		cout<<setw(70)<<" "<<"[3] Modify Driver Details\n\n";
		cout<<setw(70)<<" "<<"[4] Delete Driver\n\n";
		cout<<setw(70)<<" "<<"[5] Exit :: \n"<<endl<<endl;
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
			case ADD_DRIVER:
			
				driver.addDriver();
				system("clear");
				break;
			case LIST_DRIVER:
			
				driver.listDriver();
				system("clear");
				break;
			
			case MODIFY_DRIVER:
			
				driver.modifyDriver();
				system("clear");
				break;
		
			case DELETE_DRIVER:
			
				driver.deleteDriver();
				system("clear");
				break;
			
		
			case EXIT_DRIVER:
				this->wrongChoice = 0;
				
			
			default:
				cout<<"\n\n\tYou entered wrong choice want to select again::\
					\n\t\t[1] Yes\
					\n\t\t[0] No"<<endl;
				
				cout<<"\n\t\t\t\tEnter the choice::\t";
				
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
	}while(this->wrongChoice != 0);
	
	return;
	
}
	
	
