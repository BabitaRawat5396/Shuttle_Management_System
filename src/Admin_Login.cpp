#include"Admin.h"

//function admin login form login class
void AdminLogin::Admin_Login()
{
	system("cls");

	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"A D M I N   L O G I N"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	int ch;//for choice of user
	
	int flag, flag2;//for wrong choice
	
	while(1)
	{
		do
		{
		
			cout<<"\n\t\t\t\t\t\tEnter your email Id ::\t";
			cin>>this->email;
			
			for(int i=0; i<this->email.length(); i++)
			{
				this->email.at(i) = toupper(this->email.at(i));
			}
	
			//email validation
			if(this->valid.emailValidation(this->email))
			{
				flag=1;
			}
			else
			{	//if email is invalid
				printf("\n\t\t\t\t\t\tINVALID EMAIL ID...!!!!\n");
				flag = 0;
			}
		}while(flag!=1);
		
		flag = 0; //resetting the falg variable
		do
		{
			cout<<"\n\t\t\t\t\t\tEnter your password::\t";
			cin>>this->password;
			
			//password validation
			if(this->valid.passValidation(this->password))
			{
				flag=1;
			}
			else
			{
				//if password if invalid
				printf("\n\t\t\t\t\t\tINVALID PASSWORD...!!!!\n");
				flag = 0;
			}
		}while(flag!=1);
		
		//creating object of ofstream class
		ifstream in;
		in.open("./DataBaseFiles/Admin_Login.txt");
		
		//checking the file is opened or not
		if(!in.is_open())
		{
			cout<<"\n\t\t\t\t\t\tERROR: Cannot open file";
			return;
		}
		
		//creating variables to read data from file and store the data
		string myString;
		string line;
		flag = 0; //resetting flag
		flag2 = 0;//for password validation
		//reading the data from the file
		while(getline(in,line))
		{
			stringstream ss(line);
			getline(ss,myString,',');
			if(myString == this->email )
				flag = 1;
			getline(ss,myString,',');
			if(myString == this->password)
				flag2 = 1;
				
		}
		//closing the file
		in.close();
		
		//for wrong credentials
		if(flag==0 || flag2 ==0)
		{
			cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
			printf("\n\t\t\t\t\t\tYou have entered wrong Email_Id and Password.\n");
			printf("\n\t\t\t\t\t\t>[1]Do you want to login again?\n");
			printf("\n\t\t\t\t\t\t>[2]Do you want to leave this page?\t");
			//suer choice
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
					cout<<"\n\t\t\t\t\t\tEnter the correct Choice::\t";
					continue;
				}
			}
			if(ch == 2)
			{
				cout<<endl<<endl;
				cout<<endl<<endl;
				
				//formatting
				cout<<"\n\n";
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<setw(100)<<"Logged In Successfully"<<endl<<endl;
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
				exit(0);
			}
		
		}
		else
		{
			break;
		}
	}
	cout<<endl<<endl;
	cout<<endl<<endl;
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(100)<<"Logged In Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	this->admin_menu.adminMenu();
}

