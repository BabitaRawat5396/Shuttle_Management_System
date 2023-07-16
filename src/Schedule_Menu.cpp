//Function Definition of Schedule Menu

//Schedule Header file is included
#include"Schedule.h"


ScheduleMenu::ScheduleMenu()
{
	this->userChoice = -1;
	this->wrongChoice = 1;
}


//This function returns nothing but Show the operations related to Schedule.
void ScheduleMenu::scheduleMenu()
{
	do
	{
		cout<<endl<<endl<<endl<<endl;
		
		Schedule sc;//object of schedule class
	system("cls");

	
		//formatting
		cout<<"\n\n";
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<right<<setw(120)<<"S C H E D U L E   M E N U"<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		
		cout<<setw(70)<<" "<<"[1] Add Schedule\n\n";
		cout<<setw(70)<<" "<<"[2] Delete Schedule\n\n";
		cout<<setw(70)<<" "<<"[3] Modify Schedule\n\n";
		cout<<setw(70)<<" "<<"[4] List Schedule\n\n";
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
				cout<<"Enter Valid Number::\t";
				continue;
			}
		}
		switch(this->userChoice)
		{
			case ADD_SCHEDULE:
				
				sc.addSchedule();
				break;
				
			case DELETE_SCHEDULE:
				
				sc.deleteSchedule();
				break;
				
			case MODIFY_SCHEDULE:
				
				sc.modifySchedule();
				break;
				
			case LIST_SCHEDULE:
				sc.listSchedule();
				break;
				
				
			case EXIT_SCHEDULE:
				wrongChoice = 0;
				break;
				
			default:
				
				cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<"\n\n\t\t\t\t\tYou entered wrong choice want to select again::\
					\n\t\t\t\t\t[1] Yes\
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
	}while(wrongChoice == 1);
	
	return;

}
