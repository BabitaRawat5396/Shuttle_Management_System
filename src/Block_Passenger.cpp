//including the passenger .h header file
#include"Passenger.h"

//function to block the passenger
void Passenger::blockPassenger()
{
	system("cls");

	
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"BLOCK PASSENGER"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	//creating object of ofstream
	fstream out;
	out.open("./DataBaseFiles/Blocked_Passenger.txt");//opening the file	
	
	int n, flag = 0, ch;
	
	do
	{
		cout<<"\n\t\t\t\t\tEnter Passenger Id that you want to block::\t";
		//asking the passenger id
		while(1)
		{
			cin>>n;
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
	
		int flag = vald.idValidation(n);//id validating
	
		if(flag == 1)//if valid
		{
			out<<n<<',';
			
			cout<<endl<<endl;
			
			//formatting
			cout<<"\n\n";
			cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
			cout<<setw(100)<<"Passenger Blocked  Successfully"<<endl<<endl;
			cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		}
		else//if not valid
		{
			cout<<"\n\t\t\t\t*******************************************************************************"<<endl;
			printf("\n\t\t\t\tYou enterd wrong Email_Id and Password.\n");
			printf("\n\t\t\t\t>[1]Do you want to login again?");
			printf("\n\t\t\t\t>[2]Do you want to leave this page?\t");
			while(1)
			{
				cin>>ch;
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
			
		
			if(ch == 2)//to leave
			{
				cout<<"\n\t\t\t\t----------------------------------------------------------------------------"<<endl;
				printf("\n\t\t\tThanks for Visiting.\n\n");
				cout<<"\n\t\t\t\t----------------------------------------------------------------------------"<<endl;
				return;
			}
		}
		
	}while(flag != 1);//if flagg is not equal to 1
	
	
	return;
	
	
}


