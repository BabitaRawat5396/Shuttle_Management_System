#include"Admin.h"
#include"Passenger.h"

//this function is for the menu of admin operation on passenger details
void AdminPassMenu::adminPassMenu()
{
	Passenger passenger;//creating passenger object of passenger

	do
	{
	system("cls");

		cin.ignore();
		//formatting
		cout<<"\n\n";
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<right<<setw(130)<<"A D M I N   O P E A R T I O N    O N    P A S S E N G E R"<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	

		cout<<setw(70)<<" "<<"[1] Add New Passenger\n\n";
		cout<<setw(70)<<" "<<"[2] Check Passenger\n\n";
		cout<<setw(70)<<" "<<"[3] Modify Passenger Details\n\n";
		cout<<setw(70)<<" "<<"[4] Remove Passenger\n\n";
		cout<<setw(70)<<" "<<"[5] List Passengers Details\n\n";
		cout<<setw(70)<<" "<<"[0] Exit\n\n";
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl<<endl;
		cout<<setw(70)<<" "<<"Enter your choice:: \t";
			
		//accepting user choice
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
				cout<<endl<<setw(70)<<" "<<"Enter the correct Choice::\t";
				continue;
			}
		}
		
		switch(this->userChoice)
		{
			case ADD_PASSENGER:
			
				passenger.addNewPassenger();//calling add passenger functiom
				break;
				
			case CHECK_PASSENGER:
			
				passenger.checkPassenger();//calling check passenger function
				break;
				
			case MODIFY_PASSENGER:
			
				passenger.modifyPassenger();//calling modify passenger
				break;
				
			case DELETE_PASSENGER:
			
				passenger.deletePassenger();//calling delete passenger function
				break;
				
			case LIST_DETAILS_PASSENGER:
			
				passenger.listDetails();//calling list details function of passenger class
				break;
				
			case EXIT_APM:
			
				wrongChoice = 2;
				return;
				
				
			default:
				cout<<setw(70)<<" "<<"You entered wrong choice want to select again::\n\n";
				cout<<setw(70)<<" "<<"[1] Yes\n\n";
				cout<<setw(70)<<" "<<"[0] No\n\n";
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl<<endl;
				cout<<setw(70)<<" "<<"Enter your choice :: \t";
				cin>>this->wrongChoice;
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
						cout<<setw(70)<<" "<<"Enter the correct Choice::\t";
						continue;
					}
				}
				
		}
		
		
	}while(wrongChoice == 1);
	
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	return;
}























