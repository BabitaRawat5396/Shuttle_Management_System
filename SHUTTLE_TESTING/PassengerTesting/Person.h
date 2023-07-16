//Including File gaurds

#ifndef PERSON_H
#define PERSON_H
 

#include"Shuttle.h"
//class Person

class Person
{
	public:
                //setter methods
		void setPhone(long int);
		void setGender(char);		
		void setAge(int);	
		void setFirstName(string);
		void setLastName(string);
		void setEmail(string);
		
		
		//getter methods
		long int getPhone();
		string getFirstName();
		string getLastName();
		int getAge();
		char getGender();
		string getEmail();
		
		
		//defualt and parametrized constructor
		Person();
		Person(string,string, int, char, long int , string, int, int, int);
		
		
		Date bdate;	
		Validation vald;
		
	private:
		string firstName;
		string lastName;
		int age;
		char gender;
		long int phone;
		string email;
		
};

#endif 
//end of file gaurd











