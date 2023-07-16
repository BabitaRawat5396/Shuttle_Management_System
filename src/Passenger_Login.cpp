//Passenger Login
#include"Passenger.h"

//this function is for passenger login
void PassengerLogin::passengerLogin()
{
	//user choices
	int ch;	
	int flag,flag2;
	
	
	
	system("cls");

	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"P A S S E N G E R   L O G I N"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
			
	while(1)
	{
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter your email Id ::\t";
			cin>>this->email;//accepting email id from user
			
			//to upper case
			for(int i=0; i<this->email.length(); i++)
			{
				this->email.at(i) = toupper(this->email.at(i));
			}
			
			//email validation
			if(this->valid.emailValidation(this->email))//id validation
			{
				flag=1;
			}
			else//if not valid
			{	//if email is invalid
				printf("\n\t\t\t\t\tINVALID EMAIL ID...!!!!\n");
				flag = 0;
				
			}
			
		}while(flag!=1);
		
		flag = 0; //resetting the flag variable
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter your password::\t";
			cin>>this->password;
			
			//password validation
			if(this->valid.passValidation(this->password))
			{
				flag=1;
			}
			else
			{
				//if password if invalid
				printf("\n\t\t\t\t\tINVALID PASSWORD...!!!!\n");
				
				flag = 0;
			}
		}while(flag!=1);
		
		//creating object of ifstream class
		ifstream in;
		in.open("./DataBaseFiles/Passenger_login.txt");
		
		//checking the file is opened or not
		if(!in.is_open())
		{
			cout<<"\n\t\t\t\t\tERROR: Cannot open File";
			return;
		}
		
		//creating variables to read data from file and store the data
		string myString;
		string line;

		flag = 0; //resetting flag
		flag2 = 0;//for password validation
		int flag3 = 0; //for blocked passenger
		//reading the data from the file
		while(getline(in,line))
		{
			stringstream ss(line);
			getline(ss,myString,',');
			if(myString == email )
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
			cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
			cout<<"\n\t\t\t\t\tYou enterd wrong Email_Id and Password.\n";
			cout<<"\n\t\t\t\t\t>[1]Do you want to login again?\n";
			cout<<"\n\t\t\t\t\t>[2]Do you want to leave this page?\n"<<endl<<endl;
			cout<<"\n\t\t\t\t\tEnter your Choice::\t";
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
					cout<<"\n\t\t\t\t\tEnter the correct Choice::\t";
					continue;
				}
			}
			
			if(ch == 2)
			{

				return;
			}
		
		}
		else
		{
			break;
		}
	}
	
	ifstream in;
	in.open("./DataBaseFiles/Passenger_details.txt");
	string line, pid, word;
	
	
	while(getline(in, line))//traversing the file
	{
		stringstream ss(line);//creating stream of the line using string stream 
		
		getline(ss, pid, ',');//getting id from the line
		
		
		//reading first name from the file
		getline(ss, word,',');			
			
		//reading last name from the file
		getline(ss, word,',');		
	
		//reading age from the file
		getline(ss, word,',');		
			
		//reading gender from the file
		getline(ss, word,',');		
			
		//reading phone from the file
		getline(ss, word,',');		
			
		//reading email from the file
		getline(ss, word,',');	
		
		if(word == email)
		{
			
			break;
		}	
		
		
	}
	
	int check = 1;
	check = global::checkBlockPassenger(stoi(pid));
	
	char chh;
	
	if(check == 1)
	{
		cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<"\n\t\t\t\t\tYou are blocked By Admin. Contact Admin for more info....\n\n";
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		
		cout<<"\n\t\t\t\t\tEnter any key to continue...\t";
		cin>>chh;
		return;
	}
	
	cout<<endl<<endl;
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(100)<<"Logged In Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	cout<<"\n\t\t\t\t\tEnter any key to continue...\t";
	cin>>chh;
	
	pass_menu.passengerMenu(stoi(pid));
	
	return;
	
}
