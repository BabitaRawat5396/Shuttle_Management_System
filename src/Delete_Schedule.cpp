//Function Definition of DELETE Schedule

//Including Schedule Header File 
#include"Schedule.h"


//This function returns nothing but deletes Schedule details from the database. 
void Schedule::deleteSchedule()
{
	
	//Creating set variable to store each record of Schedule 
	set<vector<string>> sche_record;
	
	//Creating vector of strings to store temporary attributes of schedule class 
	vector<string> v;
	
	//Variables for for loop
	int i, flag = 0,choice;
	
	int schedule_id;
	cout<<endl<<endl;
	
	//Taking Schedule ID from user to delete record
	do
	{
		system("clear");
	
		//formatting
		cout<<"\n\n";
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<setw(115)<<"D E L E T E   S C H E D U L E"<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		
		//Taking Schedule ID from user to delete record
		cout<<"\n\n\t\t\t\t\tEnter Schedule Id you want to delete :: ";
		cin>>schedule_id;
		
		
		while(1)
		{
			if(!cin.fail())//user choice
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"\n\t\t\t\t\tPlease Enter a valid Number::\t";
				cin>>schedule_id;
			}
		}
		flag =0;
		
		int check = checkSchedule(schedule_id);
		int valid = vald.idValidation(schedule_id);
		
		if(check == 0 || valid == 0)
		{
			if(valid == 0)
			{
				cout<<"\n\t\t\t\t\t ERROR: Invalid Id\n";
			}
			else
			{
				cout<<"\n\t\t\t\t\tSchedule Id Does Not Exist\n";
			}
			flag = 1;
			
			cout<<"\n\t\t\t\t\tDo You Want to Enter again?\n\
			\n\t\t\t\t\t[1] Continue\n\
			\n\t\t\t\t\t[2] Exit :: ";
			
			cin>>choice;
			
			if(choice == 2)
				return;
		}
		
	}while(flag !=0);
	
	
	//Creating in stream object to read file
	ifstream in;
	
	//Opening file 
	in.open("./DataBaseFiles/Schedule_Details.txt");
	
	//Checking if file is opened or not
	if(!in.is_open())
	{
		cout<<"\n\t\t\t\t\tERROR: File Cannot Opened";
		return;
	}
	
	//variables to store whole line of file and each attributes
	string line, word;
	
	//Storing All the records in the set of vector of strings
	while(getline(in,line))
	{
		stringstream ss(line);
		
		//Storing Schedule ID
		getline(ss,word,',');
		v.push_back(word);
		
		//Once Id is matched, Skipping the data read for this record
		if(schedule_id == stoi(word))
		{
			flag = 1; //to check data is present
			v.clear();//cleaning the vector
			continue;
		}
		
		//Storing Shuttle No
		getline(ss,word,',');
		v.push_back(word);
		
		//Storing Pick Up Point
		getline(ss,word,',');
		v.push_back(word);
		
		//Storing Drop Point
		getline(ss,word,',');
		v.push_back(word);
		
		//Storing StartTime
		getline(ss,word,',');
		v.push_back(word);
		
		//Storing End Time
		getline(ss,word,',');
		v.push_back(word);
		
		//Storing Date
		getline(ss,word,',');
		v.push_back(word);

		//Storing Single Record In set sche_record
		sche_record.insert(v);

		v.clear();

	}
	
	//Closing the file
	in.close();
	
	//Creating the out stream object
	ofstream out;
	
	//Opening the File
	out.open("./DataBaseFiles/Schedule_Details.txt");
	
	//Check if file is opened or not
	if(!out.is_open())
	{
		cout<<"\nERROR: Cannot File Found";
	}
	
	//For loop to write Data into file
	for( auto it = sche_record.begin(); it!= sche_record.end(); it++)
	{
		for(i =0; i < (*it).size() - 1; i++)
		{
			out<<(*it)[i]<<",";	// Writing comma seperated
		}
		out<<(*it)[i]<<"\n";	//Ending each line with New Line
	}
	
	//Closing the File
	out.close();
	
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"Schedule Record Deleted Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	char chh;
	cout<<"\n\t\t\t\t\tEnter any key to continue\t";
	cin>>chh;
	
}





