#include"Passenger.h"

//this function is used to check the passenger beased on some condition
// if it is called for validation purpose then id != 0 otherwise id == 0 by default 

int Passenger::checkPassenger(int id)
{
	//system("clear");
	
	//formatting
	
	if(id == 0)
	{
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	  	cout<<setw(125)<<"C H E C K   P A S S E N G E R   D E T A I L S"<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		
	}
	
	int n = id;
	
	
	if(id == 0)//if id ==0 ask for id
	{
		
		cout<<"\n\t\t\t\t\tEnter the Passenger ID::\t";
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
				cout<<"\n\t\t\t\t\tEnter the Valid Number::\t";
				continue;
			}
		}		
	}
	
	
	ifstream in;
	in.open("Passenger_details.txt");
	
	
	if(!in.is_open())//if file is not opened
	{
		cout<<"\n\t\t\t\t\tData Can not be Fetched"<<endl;
	}
	
	
	
	string line;//for storing the one line of the file
	string pid, firstName, lastName, age, gender, phone, email, dob;//for storing the attributes of the passenger file
	
	while(getline(in, line))//traversing the file
	{
		stringstream ss(line);//creating stream of the line using string stream 
		
		getline(ss, pid, ',');//getting id from the line
		
		if(n == stoi(pid) && id != 0)//checking of id == pid
		{
			in.close();//close the file
			return 1;//return 1
		}
		if(n == stoi(pid) && id == 0)//if not hen fine passenger
		{
				cout<<setw(30)<<""<<setw(18)<<"Passenger Id"<<setw(17)<<"First Name"<<setw(17)<<"Last Name"<<setw(10)<<"Age"<<setw(10)<<"Gender"<<setw(14)<<"Phone No"<<setw(17)<<"Email ID"<<setw(19)<<"DOB"<<endl<<endl;
			
			cout<<setw(28)<<"";
		
		
			cout<<"\t     ";
			//reading the id from the file
			
			cout<<setw(18)<<left<<pid;
			
			//reading first name from the file
			getline(ss, firstName,',');
			cout<<setw(19)<<firstName;
			
			
			//reading last name from the file
			getline(ss, lastName,',');
			cout<<setw(16)<<lastName;

			//reading age from the file
			getline(ss, age,',');
			cout<<setw(8)<<age;
			
			//reading gender from the file
			getline(ss, gender,',');
			cout<<setw(10)<<gender;
			
			//reading phone from the file
			getline(ss, phone,',');
			cout<<setw(17)<<phone;
			
			//reading email from the file
			getline(ss, email,',');
			cout<<setw(24)<<email;
			
			//reading dob from the file
			getline(ss, dob,',');
			cout<<setw(17)<<dob;
			
			//for newline
			cout<<endl;
			break;
		}
	}	
	if(id == 0)
	{
		
		char ch;
		cout<<"\n\t\t\t\t\tEnter any key.........";
		cin>>ch;
	
	}
	
	
	//cout<<endl<<endl;
	return 0;
}


