#include"Shuttle.h"

//validation for Id
int Validation::idValidation(int id)
{
	int n = 0;
	while(id>0)
	{
		n++;
		id = id/10;
	}
	if (n==5)
	{
		return 1;
	}
	return 0;
}

//time validation 
int Validation::timeValidation(int hour, int minute)
{
	if((hour >= 0 && hour <= 24) && (minute >=0 && minute <= 60))
	{
		return 1;
	}
	return 0;
}


//validation for unique pan number

int Validation::uniquePan(string str)
{
	
	int n = str.length();
	if(n != 10)
	{
		return 0;
	}	
	bool specialChar = false;
   	string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
   	
   	for (int i = 0; i < n; i++) 
   	{
   		size_t special = str.find_first_not_of(normalChars);
      	
      		if (special != string::npos)
      		{
        	 	specialChar = true;
        	}
        }
        
        if(specialChar)
        {
        	return 0;
        }
        
        ifstream in;//opening file
        in.open("./DataBaseFiles/Driver_details.txt");//open the file
        
        string line, word;
        
        while(getline(in, line))//accessing the line from 
        {
        	stringstream ss(line);// creating the stream of the line
        	getline(ss, word, ',');//accessing 
        	getline(ss, word, ',');//accessing pan number
        	if(word == str)
        	{
        		return 0;
        		break;
        	}
        	else
        	{
        		continue;
        	}
        }
        
        
   	return 1;
}


//validation for mobile
int Validation::mobileValidation(long int mob)
{
	int n=0;
	while(mob>0)
	{
		n++;
		mob = mob/10;
	}
	
	if(n == 10)//mobile number must be of 10 digits
	{
		return 1;
	}
	
	return 0;
	
}

//dob validation
int Validation::dobValidation(string dob)
{
	stringstream ss(dob);
	string str;
	int day, month, year;
	
	getline(ss, str, '/');
	day = stoi(str);
	
	getline(ss, str, '/');
	month = stoi(str);
	
	getline(ss, str, '/');
	year = stoi(str);
	
	if(year>=1965 && year<=2002) 
    	{
        	//check month
		if(month>=1 && month<=12)
		{
		    //check days
		    if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)) // To check months with 31 days
		        return 1;
		        
		    else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11)) // To check months with 30 days
		        return 1;
		        
		    else if((day>=1 && day<=28) && (month==2)) //To check month with 28 days 
		        return 1;
		        
		    else if(day==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0))) //To check month with 29 days in a leapyear
		        return 1;
		    else
		        return 0;
		}
		else
		    return 0;
    	}
    	else
    		return 0;
    		
	return 1;
}




//validation for the email
int Validation::emailValidation(string email)
{
	
	string str = "@CAPGEMINI.COM";
	int n = str.length();
	int len = email.length();
	
	if(len <= n)
	{
		return 0;
	}
	int a = len -n;
	int index = 0;
	while(a <= len-1)
	{
		if(str.at(index) != email.at(a))
		{
			return 0;
		}
		index++;
		a++;
	}
	
	return 1;
	
}

//validation for name
int Validation::nameValidation(string name)
{
	int n = name.length()-1;
	while(n >=0)
	{
		char c = name.at(n);
		if(!((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z')))
		{
			return 0;
		}
		n--;
	}
	return 1;
}

//validation for the password
int Validation::passValidation(string pass)
{

	int n = pass.length();
	
   	// Checking lower alphabet in string
   	int i,number,special,capital,small;
        number=special=capital=small=0;
        
        for(i=0;i<n;i++)
        {
            if(pass[i]>='0' && pass[i]<='9')
            	number=1;
            if(pass[i]>='a' && pass[i]<='z')
            	small=1;
            if(pass[i]>='A' && pass[i]<='Z')
            	capital=1;
            if(pass[i]=='@' || pass[i]=='#' || pass[i]=='$' || pass[i]=='%' || pass[i]=='*')
            	special=1;
        }
        if(number==0 || special==0 || capital==0 || small==0 || n<8)
        	return 0;
        else
        	return 1;
   	
}


//validation for the gender
int Validation::genderValidation(char gender)
{
	if(gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
	{
		return 1;
	}
	return 0;
}


//validation for the age
int Validation::ageValidation(int age)
{
	if(age > 18 && age < 57)
	{
		return 1;
	}
	return 0;
}



//date validation
int Validation::dateValidation(string date)
{
	stringstream ss(date);
	string str;
	int day, month, year;
	
	getline(ss, str, '/');
	day = stoi(str);
	
	getline(ss, str, '/');
	month = stoi(str);
	
	getline(ss, str, '/');
	year = stoi(str);
	
	if(year>=1965 && year<=2022) 
    	{
        	//check month
		if(month>=1 && month<=12)
		{
		    //check days
		    if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)) // To check months with 31 days
		        return 1;
		        
		    else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11)) // To check months with 30 days
		        return 1;
		        
		    else if((day>=1 && day<=28) && (month==2)) //To check month with 28 days 
		        return 1;
		        
		    else if(day==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0))) //To check month with 29 days in a leapyear
		        return 1;
		    else
		        return 0;
		}
		else
		    return 0;
    	}
    	else
    		return 0;
    		
	return 1;
}

//*******************************bus attributes validation function defionitions*************************************************

//bus number validation function
//TN 01 NW 5377	- 2 characters(State Code/ RTO Code) - 2 digits(District code) - 2 characters - 4 digit unique number
int Validation::busNoValidation(string busNo)
{


	// Regex to check valid bus number
    const regex pattern("^[A-Z]{2}[0-9]{2}[A-Z]{2}[0-9]{4}$");
                        
 
    // If the bus number is empty return 0
    if (busNo.empty())
    {
        return 0;
    }
 
    // Return true if bus number matched the ReGex
    if (regex_match(busNo, pattern))
    {
        return 1;
    }
    else 
        return 0;
 
}
	
	
	
/*	 if(pass[i]>='0' && pass[i]<='9')
		    	number=1;
		    if(pass[i]>='a' && pass[i]<='z')
		    	small=1;
		    if(pass[i]>='A' && pass[i]<='Z')
		    	capital=1;
		    if(pass[i]=='@' || pass[i]=='#' || pass[i]=='$' || pass[i]=='%' || pass[i]=='*')
		    	special=1;
		}
		if(number==0 || special==0 || capital==0 || small==0 || n<8)
			return 0;
		else
			return 1;



	int n, flag=0;
	n= busNo.length();
	
	if( (busNo[0]>='A' && busNo[0]<='Z')  ||  ( busNo[1]>='A' && busNo[1]<='Z' ) )
          	flag++;
	if(busNo[2]==[0-9] && busNo[3]==[0-9])
          	flag++;
	if(  (busNo[4]=='[A-Z]' && busNo[5]=='[A-Z]')  ||  ( busNo[4]=='[a-z]' && busNo[5]=='[a-z]' )   )
          	flag++;
	if( busNo[6]==[0-9] && busNo[7]==[0-9] && busNo[8]==[0-9] && busNo[9]==[0-9] )
          	flag++;
	
	
	
	if( flag == 4 && n==10)
		return 1;
	else
		return 0;
	*/
		
	
	

/*
REGEX::	^[A-Z]{2}\s[0-9]{2}\s[A-Z]{2}\s[0-9]{4}$


^ means start of string
[A-Z]{2} means 2 characters in the range of A through Z
\s means white space
[0-9]{2} means 2 characters in the range of 0 through 9
\s means white space
[A-Z]{2} means 2 characters in the range of A through Z
\s means white space
[0-9]{4} means 4 characters in the range of 0 through 9
$ means end of string
*/

	
				
		
// Registration Certificate Validtion fuction
//10Characters - string
int Validation::RCNoValidation(string pass)
{
	int number = 0, capital = 0;
	int n= pass.length();
	
	for(int i=0;i<n;i++)
        {
            if(pass[i]>='0' && pass[i]<='9')
            	number=1;
            
            if(pass[i]>='A' && pass[i]<='Z')
            	capital=1;
           
        }
        if(number==1 &&  capital==1 && n==10)
        	return 1;
        else
        	return 0;
	
}





//vehicle insurance validation function
//AA123456C //format is two prefix letters, six digits and one suffix letter
int Validation::vehicleInsValidation(string vehicleIns)
{
	
	// If the bus number is empty return 0
	if (vehicleIns.empty())
	{
        	return 0;
	}

	ifstream in;
	in.open("./DataBaseFiles/Bus_details.txt");
	
	if(!in.is_open())
	{
		cout<<"\n\t\t\t\t\t\tERROR: File Cannot opened";
		return 0;
	}
	
	string line, str;
	while(getline(in,line))
	{
		stringstream ss(line);
		
		getline(ss,str,',');
		getline(ss,str,',');
		getline(ss,str,',');
		getline(ss,str,',');
		if(vehicleIns == str)
		{
			in.close();
			return 0;
		}
		
	}
	in.close();
	
	// Regex to check valid bus number
	const regex pattern("^[A-Z]{2}[0-9]{6}[A-Z]{1}$");
                        
	// Return true if bus number matched the ReGex
	if (regex_match(vehicleIns, pattern))
	 {
		return 1;
	 }
	 else 
		return -1;
	
	
}


int Validation::totalSeatsValidation(int t_seats)
{

	if(t_seats> MINSEAT && t_seats < MAXSEAT)
		return 1;
	else
		return 0;


}


int Validation::bookedSeatsValidation(int b_seats, int t_seats)
{
	if( b_seats > 0 && b_seats < t_seats )
		return 1;
	else
		return 0;
}


//FuNCTION TO VALIDATE DRIVER LICENSE NUMBER
		
int Validation::licenseNoValidation(string str)
{
    // Regex to check valid driving license number
    const regex pattern("[A-Z]{2}[0-9]{2}[0-9]{7}");
                        
 
    // If the driving license number is empty return 0
    if (str.empty())
    {
        return 0;
    }
 
    // Return true if driving license number matched the ReGex
    if (regex_match(str, pattern))
    {
        return 1;
    }
    else {
        return 0;
    }
}
 









