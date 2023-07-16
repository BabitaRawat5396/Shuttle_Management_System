#include"Passenger.h"

//Add Passenger function
void Passenger::addNewPassenger()
{
	system("cls");

	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"A D D   P A S S E N G E R"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	string str;
	long int phone;
	char ch;
	
	//values for user choices and validations
	int n, val=0, value, flag;
	//writting
	fstream out, pout; //define the purpose of reading or writing in case of fstream
	
	
	//opening file in append mode
	out.open("./DataBaseFiles/Passenger_details.txt", ios::app);
	pout.open("./DataBaseFiles/Passenger_login.txt", ios::app);
	
	if(!out.is_open())//if file is not open
	{
		cout<<"\n\t\t\t\t\tCan not open file"<<endl;
		return;
	}
	
	do
	{
		
		value = this->generatePassId();
		out<<value<<",";
			
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter First Name::\t";
			cin>>str;
			
			
			//name validation
			val = vald.nameValidation(str);
			
			if(val ==0)//if invalid
			{
				
				cout<<"\n\t\t\t\t\tInvalid First Name, Please Enter The Correct Name."<<endl;
			}
			else
			{
				out<<str<<",";
			}
			
		}while(val != 1);
		val =0; //resetting
		
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Last Name::\t";
			cin>>str;
						
			//name validation
			val = vald.nameValidation(str);
			
			if(val ==0)//if invalid
			{
				cout<<"\n\t\t\t\t\tInvalid Last Name, Please Enter The Correct Name."<<endl;
			}
			else//if valid
			{
				out<<str<<",";
			}
			
		}while(val != 1);
		val =0; //resetting
		
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Age::\t";
			
			while(1)
			{
				cin>>value;
				if(!cin.fail())//user choice
				{
					break;
				}
				else
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout<<"Enter valid number::\t";
					continue;
				}
			}
			
						
			//age validation
			val = vald.ageValidation(value);
			
			if(val ==0)//if age invalid
			{
				cout<<"\n\t\t\t\t\tInvalid Age, Please Enter The Correct Age."<<endl;
			}
			else//if valid
			{
				out<<value<<",";
			}
			
		}while(val != 1);
		val =0; //resetting
		
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Gender::\t";
			cin>>ch;
			
			
			//gender validation
			val = vald.genderValidation(ch);
			
			if(val ==0)//if gender invalid
			{
				cout<<"\n\t\t\t\t\tInvalid Gender, Please Enter The Correct Gender."<<endl;
			}
			else//if valid
			{
				out<<ch<<",";
			}
			
		}while(val != 1);
		
		val =0; //resetting
		
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Phone Number::\t";
			
			while(1)
			{
				cin>>phone;
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
			
			
			
			//phone validation
			val = vald.mobileValidation(phone);
			
			if(val ==0)//if mobile is invalid
			{
				cout<<"\n\t\t\t\t\tInvalid Phone Number, Please Enter The Correct Phone Number."<<endl;
			}
			else//if valid
			{
				out<<phone<<",";
			}
			
		}while(val != 1);
		val  =0; //resetting
		
		
		
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Passenger Email::\t";
			cin>>str;
			//converting to upper case
			for(int i=0; i<str.length(); i++)
			{
				str.at(i) = toupper(str.at(i));
			}
			
			
			//email validation
			val = vald.emailValidation(str);
			
			if(val ==0)//if email validation failed
			{
				cout<<"\n\t\t\t\t\tInvalid Email Id, Please Enter The Correct Email Id."<<endl;
			}
			else//if valid
			{
				out<<str;
				out<<",";//adding new line after all data entered
				pout<<str;
				pout<<",";
			}
			
		}while(val != 1);
		val = 0;
		
		
		//for password
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Password::\t";
			cin>>str;
			
			//password validation
			val = vald.passValidation(str);
			
			if(val ==0)//if password validation failed
			{
				cout<<"\n\t\t\t\t\tInvalid Password, Please Enter The Correct Password."<<endl;
			}
			else//if valid
			{
				pout<<str;
				pout<<"\n";//adding new line after all data entered
			}
			
		}while(val != 1);
		val = 0;
		
		
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Passenger Date of Birth::\t";
			cin>>str;//accepting dob from user
			
			
			//email validation
			val = vald.dobValidation(str);
			
			if(val ==0)//if email validation failed
			{
				cout<<"\n\t\t\t\t\tInvalid DOB, Please Enter The Correct DOB."<<endl;
			}
			else//if valid
			{
				out<<str;
				out<<"\n";//adding new line after all data entered
			}
			
		}while(val != 1);
		
		
		
		cout<<"\n\t\t\t\t\tDo u want to Continue::(1/0)\t";//asking to enter more route
		cin>>n;
		cout<<endl<<endl;
		
	}while(n!=0);
	
	
	cout<<endl<<endl;
	
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(100)<<"Data Inserted Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	char chh;
	cout<<"\n\t\t\t\t\tEnter any key to continue::\t";
	cin>>chh;
	
	
	out.close();
	
}

//function to generate passenger id
int Passenger::generatePassId()
{
	int id;
	string pass_id, line;
	
	ifstream in;
	in.open("./DataBaseFiles/Passenger_details.txt");
	
	if(!in.is_open())//if file is not open
	{
		cout<<"\n\t\t\t\t\tCannot open file"<<endl;
		return 0;
	}
	
	while(getline(in,line))
	{
		stringstream ss(line);
		
		getline(ss, pass_id,',');
		id = stoi(pass_id);
	}
	
	in.close();
	
	return id+1;
}




