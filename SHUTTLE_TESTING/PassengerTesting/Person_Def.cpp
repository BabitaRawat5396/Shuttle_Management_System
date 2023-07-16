#include"Person.h"
//------------------------------Setter  for  Person  class------------------------------------------------

//setter for phone
void Person::setPhone(long int phone)
{
	int n = vald.mobileValidation(phone);
	if(n==1)
	{
		this->phone = phone;
		return;
	}
	cout<<"\n\t\t\t\tInvalid Phone Number"<<endl;
	
	
}

//setter for gender
void Person::setGender(char gender)
{
	int n = vald.genderValidation(gender);
	if(n==1)
	{
		this->gender = gender;
		return;
	}
	cout<<"\n\t\t\t\tInvalid Gender"<<endl;
	
	
}		

//setter for age
void Person::setAge(int age)
{
	int n = vald.ageValidation(age);
	if(n==1)
	{
		this->age = age;
		return;
	}
	cout<<"\n\t\t\t\tInvalid Age"<<endl;
	
	
}	

//setter for first name
void Person::setFirstName(string firstName)
{
	int n = vald.nameValidation(firstName);
	if(n==1)
	{
		this->firstName = firstName;
		return;
	}
	cout<<"\n\t\t\t\tInvalid First Name"<<endl;
	
	
}

//setter for last name
void Person::setLastName(string lastName)
{
	int n = vald.nameValidation(lastName);
	if(n==1)
	{
		this->lastName = lastName;
		return;
	}
	cout<<"\n\t\t\t\tInvalid Last Name"<<endl;
	
	
}

void Person::setEmail(string str)
{
	int n = vald.emailValidation(str);
	if(n==1)
	{
		this->email = str;
		return;
	}
	cout<<"\n\t\t\t\tInvalid Email"<<endl;
	
	
}	
//----------------------------Getters  for  Person  class -------------------------------
	
//getter for phone
long int Person::getPhone()
{
	return this->phone;
}

//getter for first name
string Person::getFirstName()
{
	return this->firstName;
}

//getter for last name
string Person::getLastName()
{
	return this->lastName;
}



//getter for age
int Person::getAge()
{
	return this->age;
}

//getter for gender
char Person::getGender()
{
	return this->gender;
}

string Person::getEmail()
{
	return this->email;
}

//------------------------Constructors  for  Person  class-------------------------

//default constructor
Person::Person()
{
	this->phone = 0;
	this->firstName = "\0";
	this->lastName = "\0";
	this->age = 0;
	this->gender = '\0';
	this->email = "\0";
	
	
}

//parametrized constructor

Person::Person(string firstName,string lastName, int age, char gender, long int phone, string email ,int day,int month,int year):bdate(day, month, year)
{
	
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->gender = gender;
	this->phone = phone;
	this->email = email;
	
}






















