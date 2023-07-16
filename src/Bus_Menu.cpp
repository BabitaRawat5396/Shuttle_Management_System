#include"Bus.h"


#define ADD_BUS	1
#define DELETE_BUS 2
#define MODIFY_BUS 3
#define LIST_BUS 4

#define ADD_BUS		1
#define REMOVE_BUS	2
#define MODIFY_BUS	3
#define LIST_BUS	4



//default constructor
BusMenu::BusMenu()
{
	userChoice = -1;
	wrongChoice = -1;
}


//defining busMenu() function to call menu regarding bus details mnanipulation
//function to disply bus menu
void BusMenu::busMenu()
{
	string busNo,  RCNo;
	int shuttleNo, vehicleIns;
	Bus bus;
	
	do
	{
			system("clear");
			//formatting
			cout<<"\n\n";
			cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
			cout<<right<<setw(115)<<" B U S   M E N U "<<endl<<endl;
			cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				
			cout<<setw(70)<<" "<<"[1] Add Bus Details\n\n";
			cout<<setw(70)<<" "<<"[2] Delete Bus Details\n\n";
			cout<<setw(70)<<" "<<"[3] Modify Bus Details\n\n";
			cout<<setw(70)<<" "<<"[4] List Bus Details\n\n";
			cout<<setw(70)<<" "<<"[0] Exit :: \n"<<endl<<endl;
			cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
			cout<<"\n\t\t\t\t\tEnter your choice::\t";
		
		
		/*cout<<"\n\t----------------------------Bus Menu-------------------"<<endl;
		cout<<"\n\t[1] Add Bus Details\
			\n\t[2] Delete Bus Details\
			\n\t[3] Modify Bus Details\
			\n\t[4] List Bus Details\
			\n\t[0] Exit"<<endl;*/
			
		cin>>this->userChoice;
		
		switch(this->userChoice)
		{
			case ADD_BUS:

				bus.addBus();
				
				break;
				
			case DELETE_BUS:

				
				bus.deleteBus();
				
				break;
			
			case MODIFY_BUS:
				
				bus.modifyBus();
				
				break;
			case LIST_BUS:

				bus.listBus();
				
				break;
			case EXIT_BUS:
					this->wrongChoice == 1;
			default:	
				cout<<"\n\n\tYou entered wrong choice want to select again::\
						\n\t\t[1] Yes\
						\n\t\t[0] No"<<endl;
				cout<<"\n\t\t\t\t\tEnter your choice::\t";
				cin>>this->wrongChoice;
		
		}
		
		
		
	}while(this->wrongChoice != 1);
	
	//*************************************************** ADD CODE FOR BACK TO MAIN MENU ************************************************
		
		
	
	
}



