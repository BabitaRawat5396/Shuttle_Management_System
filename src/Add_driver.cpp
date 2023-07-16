#include"Driver.h"

//Add Passenger function
void Driver::addDriver()
{	


	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"A D D    D R I V E R"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	string str,license,pan;
	long int phone;
	char ch;
	int n, val=0, value, flag;
	//writting
	fstream out; //define the purpose of reading or writing in case of fstream
	
	//opening file in append mode
	out.open("./DataBaseFiles/driver_details.txt", ios::app);
	
	
	if(!out.is_open())//if file is not open
	{
		cout<<"Can not open file"<<endl;
		return;
	}
	
	do
	{	value = this->generateDriverId();
		out<<value<<",";
	
		
		do
		{
			
			cout<<"\n\t\t\t\tEnter driver pan no::\t";
			cin>>pan;
			this->setPanNo(pan);
			
			//pan no validation
			val = vald.uniquePan(this->getPanNo());
			
			
			if(val == 0)//if pan NO. is invalid
			{
				cout<<"\n\t\t\t\tInvalid pan NO., Please Enter The Correct Pan NO."<<endl;
			}
			
			else//if valid
			{
				out<<this->getPanNo()<<",";
			}
			
		}while(val != 1);
		val =0;
		
		
		do
		{
			
			cout<<"\n\t\t\t\tEnter driver license no::\t";
			cin>>license;
			this->setLicenseNo(license);
			
			//license no validation
			val = vald.licenseNoValidation(this->getLicenseNo());
			
			
			if(val == 0)//if license NO. is invalid
			{
				cout<<"\n\t\t\t\tInvalid license NO. , Please Enter The Correct license NO. "<<endl;
			}
			
			else//if valid
			{
				out<<this->getLicenseNo()<<",";
			}
			
		}while(val != 1);
		val =0;
		
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter First Name::\t";
			cin>>str;
			this->setFirstName(str);//accepting first name from user
			
			//name validation
			val = vald.nameValidation(this->getFirstName());
			if(val ==0)//if invalid
			{
				cout<<"\n\t\t\t\t\tInvalid First Name, Please Enter The Correct Name."<<endl;
			}
			else
			{
				out<<this->getFirstName()<<",";
			}
			
		}while(val != 1);
		val =0; //resetting
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Last Name::\t";
			cin>>str;
			this->setLastName(str);//accepting last name from user
			
			//name validation
			val = vald.nameValidation(this->getLastName());
			
			if(val ==0)//if invalid
			{
				cout<<"\n\t\t\t\t\tInvalid Last Name, Please Enter The Correct Name."<<endl;
			}
			else//if valid
			{
				out<<this->getLastName()<<",";
			}
			
		}while(val != 1);
		val =0; //resetting
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Age::\t";
			while(1)
			{
				
				cin>>value;
				this->setAge(value);//accepting age from user
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
			val = vald.ageValidation(this->getAge());
			
			if(val ==0)//if age invalid
			{
				cout<<"\n\t\t\t\t\tInvalid Age, Please Enter The Correct Age."<<endl;
			}
			else//if valid
			{
				out<<this->getAge()<<",";
			}
			
		}while(val != 1);
		val =0; //resetting
		
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Gender::\t";
			cin>>ch;
			this->setGender(ch);//accepting gender from user
			
			//gender validation
			val = vald.genderValidation(this->getGender());
			
			if(val ==0)//if gender invalid
			{
				cout<<"\n\t\t\t\t\tInvalid Gender, Please Enter The Correct Gender."<<endl;
			}
			else//if valid
			{
				out<<this->getGender()<<",";
			}
			
		}while(val != 1);
		
		val =0; //resetting
		
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Phone Number::\t";
			
			while(1)
			{
				
				cin>>phone;
				this->setPhone(phone);//accepting phone from user
			
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
			val = vald.mobileValidation(this->getPhone());
			
			if(val ==0)//if mobile is invalid
			{
				cout<<"\n\t\t\t\t\tInvalid Phone Number, Please Enter The Correct Phone Number."<<endl;
			}
			else//if valid
			{
				out<<this->getPhone()<<",";
			}
			
		}while(val != 1);
		val  =0; //resetting
		
		
		
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter driver Email::\t";
			cin>>str;
			//converting to upper case
			for(int i=0; i<str.length(); i++)
			{
				str.at(i) = toupper(str.at(i));
			}
			
			this->setEmail(str);//accepting email from user
			
			//email validation
			val = vald.emailValidation(this->getEmail());
			
			if(val ==0)//if email validation failed
			{
				cout<<"\n\t\t\t\t\tInvalid Email Id, Please Enter The Correct Email Id."<<endl;
			}
			else//if valid
			{
				out<<this->getEmail();
				out<<",";//adding new line after all data entered
			}
			
		}while(val != 1);
		val = 0;
		
		do
		{
			
			cout<<"\n\t\t\t\t\tEnter Driver Date of Birth::\t";
			cin>>str;//accepting DOB from user
			
			
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
	
	cout<<"\n\t\t\t\t\tNote down the driver Id:: \t"<<this->getDriverId()<<endl;
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(100)<<"Data Inserted Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	out.close();
	
}




