//function defination for list dtails of driver

#include"Driver.h"

//function to list the details of the driver
void Driver::listDriver()
{
	
	//to clear the screen
	system("clear");
	
	//formatting
	cout<<"\n\n";
	cout<<setw(15)<<" "<<setfill('*')<<setw(170)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"D R I V E R    D E T A I L S"<<endl<<endl;
	cout<<setw(15)<<" "<<setfill('*')<<setw(170)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	//object of ifstream class to read the data
	ifstream in;
	in.open("./DataBaseFiles/driver_details.txt");//opening the file
	
	//if file is not opened
	
	if(!in.is_open())
	{
		
		cout<<"\n\t\t\t\tCannot open File\n";
		exit(0);
	}
	
	

	cout<<"\n\n";
	cout<<setw(18)<<"S.NO."<<setw(12)<<"Driver Id"<<setw(15)<<"Pan No."<<setw(19)<<"License NO."<<setw(22)<<"First Name"<<setw(15)<<"Last Name"<<setw(8)<<"Age"<<setw(8)<<"Gender"<<setw(15)<<"Phone No"<<setw(15)<<"Email ID"<<setw(23)<<"DOB"<<endl<<endl;
	
	//strings to store the data from the files
	
	string line;
	string id, panNo, licenseNo, firstName, lastName, age, gender, phone, email, dob;
	int n = 1;
	 
	 //while loop to read data from the file
	while(getline(in,line))
	{
		cout<<setw(15)<<right<<n++;
		stringstream ss(line);//to craete a stream of a string
		
		cout<<"\t     ";
		//reading the id from the file
		getline(ss, id,',');
		cout<<setw(18)<<left<<id;
		
		//reading the PAN NUMBER from the file
		getline(ss, panNo,',');
		cout<<setw(17)<<left<<panNo;
		
		//reading the license number from the file
		getline(ss, licenseNo,',');
		cout<<setw(20)<<left<<licenseNo;
		
		//reading first name from the file
		getline(ss, firstName,',');
		cout<<setw(17)<<firstName;
		
		
		//reading last name from the file
		getline(ss, lastName,',');
		cout<<setw(12)<<lastName;

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
		cout<<setw(29)<<email;
		
		//reading dob from the file
		getline(ss, dob,',');
		cout<<setw(21)<<dob;
		
		//for newline
		cout<<endl;
		
		
	}
	

	
	//closing the file
	in.close();
	
	//Formatting
	cout<<endl<<endl<<setw(18)<<" "<<setfill('*')<<setw(170)<<"*"<<setfill(' ')<<endl<<endl;
	
	char chh;
	cout<<"\n\t\t\t\t\tEnter any Key::\t";
	cin>>chh;
	
	return;
	
}


