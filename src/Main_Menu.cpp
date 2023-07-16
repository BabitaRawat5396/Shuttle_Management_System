#include"Passenger.h"
#include"Admin.h"

MainMenu::MainMenu()
{
	this->userChoice = -1;
	this->wrongChoice = -1;
}



//function for main menu to display the menu for user login
void MainMenu::mainMenu()
{
	AdminLogin ALogin;//creating object of admin login
	PassengerLogin passLogin;//creating object of passenger login
	
	
	do
	{
		system("clear");
	
		//formatting
		cout<<"\n\n";
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<right<<setw(115)<<"W E L C O M E  T O  S H U T T L E"<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl<<endl;
		
		
		//menu for login
		cout<<setw(70)<<" "<<"[1] Login as Admin"<<endl<<endl;
		
		cout<<setw(70)<<" "<<"[2] Login as Passenger"<<endl<<endl;
		
		cout<<setw(70)<<" "<<"[0] Exit"<<endl<<endl;
		
		cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;

		cout<<setw(90)<<"Enter the choice::\t";
		//cin>>this->userChoice;//user choice
		
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
				cout<<"Enter the correct Choice::\t";
				continue;
			}
		}
	
	
		switch(this->userChoice)
		{
			case ADMIN_LOGIN:
				
				ALogin.Admin_Login();//calling admin login
				break;
				
			case PASSENGER_LOGIN:
				
				passLogin.passengerLogin();//calling the passenger login
				break;
				
			case EXIT_LOGIN:
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl<<endl;
				cout<<setw(90)<<"Thanks For Visiting"<<endl<<endl;
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl<<endl;
				exit(0);
				
			default:
				cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl<<endl;
				cout<<setw(70)<<" "<<"You entered wrong choice want to select again::"<<endl<<endl;
				cout<<setw(70)<<" "<<"[1] Yes"<<endl<<endl;
				cout<<setw(70)<<" "<<"[0] No"<<endl<<endl;
				
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl<<endl;
				cout<<setw(90)<<"Enter the choice::\t";
				cin>>this->wrongChoice;
		}
	
	}while(wrongChoice == 1);//ending do while
	

	cout<<endl<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl<<endl;
	cout<<setw(110)<<"Thanks For Visiting"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl<<endl;
}










