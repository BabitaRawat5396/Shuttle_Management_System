#include"Passenger.h"

//function to list the details of the passenger
void Passenger::listDetails()
{
	
	
	system("clear");
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"P A S S E N G E R    D E T A I L S"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	//object of ifstream class to read the data
	ifstream in;
	in.open("./DataBaseFiles/Passenger_details.txt");//opening the file
	
	//if file is not opened
	
	if(!in.is_open())
	{
		
		cout<<"\n\t\t\t\tCannot open File";
		exit(0);
	}
	
	cout<<setw(38)<<"S.NO."<<setw(18)<<"Passenger Id"<<setw(17)<<"First Name"<<setw(17)<<"Last Name"<<setw(10)<<"Age"<<setw(10)<<"Gender"<<setw(14)<<"Phone No"<<setw(17)<<"Email ID"<<setw(19)<<"DOB"<<endl<<endl;
	
	//strings to store the data from the files
	
	string line;
	string id, firstName, lastName, age, gender, phone, email, dob;
	int n = 1;
	 
	 //while loop to read data from the file
	while(getline(in,line))
	{
		cout<<setw(35)<<right<<n++;
		stringstream ss(line);//to craete a stream of a string
		
		cout<<"\t     ";
		//reading the id from the file
		getline(ss, id,',');
		cout<<setw(18)<<left<<id;
		
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
		
		
	}
	//closing the file
	in.close();
	
	
	char ch;
	cout<<"\n\t\t\t\t\tEnter any key.........";
	cin>>ch;
	
	//Formatting
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	return;
	
}

