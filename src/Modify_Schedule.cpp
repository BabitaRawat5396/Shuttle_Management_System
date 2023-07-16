//Function Definition of MODIFY Schedule

#include "Schedule.h"


//This function returns nothing but modify Schedule details to the database. While taking input from the user, this function validates it if required and checks whether it already exists or not and then add it to the file.
void Schedule::modifySchedule()
{
	system("cls");

	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"M O D I F Y    S C H E D U L E"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	string myString, myString2;
	string strr = ":";
	
	//Creating set variable to store each record of Schedule 
	set<vector<string>> sche_record;
	
	//Creating vector of strings to store temporary attributes of schedule class 
	vector<string> v;
	
	//Variables for for loop
	int i, choice,flag,wrong = 2;
	
	int schedule_id, check, valid;

	do
	{
		//Taking Schedule ID from user to delete record
		cout<<"\n\t\t\t\t\tEnter Schedule Id :: ";
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
		
		check = checkSchedule(schedule_id);
		valid = vald.idValidation(schedule_id);
		
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
	
	string line, word;
	
	
	//while loop to traverse the file
	while(getline(in, line))
	{
		//creating the stream of the line of the file
		stringstream ss(line);
		
		//reading the Schedule id from the file
		getline(ss, word,',');
		
		//if the id is equal to the file and we want to delete it
		if(to_string(schedule_id) == word)
		{
			flag = 1;
			do
			{
				system("clear");
				cout<<"\n\n";
				//formatting
				cout<<"\n\n";
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<right<<setw(115)<<"M O D I F Y    S C H E D U L E"<<endl<<endl;
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				
				cout<<"\n\t\t\t\t\tWhat details you want to Update\n\
					\n\t\t\t\t\t[1] Shuttle Number\n\
					\n\t\t\t\t\t[2] Pick Point\n\
					\n\t\t\t\t\t[3] Drop Point\n\
					\n\t\t\t\t\t[4] Start Time\n\
					\n\t\t\t\t\t[5] End Time\n\
					\n\t\t\t\t\t[6] Date\n\
					\n\t\t\t\t\t[0] Exit \n";
				cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<"\n\n\t\t\t\t\t\t Enter the choice: \t";
				cin>>choice;
				
				switch(choice)
				{
					case SHUTTLE_NO:
						
						v.push_back(word);	//Pushing back Schedule ID
						
						getline(ss,word,',');	//Reading Shuttle no
						
						do
						{
							cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
							cout<<"\n\t\t\t\t\tEnter new Shuttle Number :: \t";
							int shuttle_no;
							while(1)
							{
								cin>>shuttle_no;
								if(!cin.fail())//user choice
								{
									break;
								}
								else
								{
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(),'\n');
									cout<<"\n\t\t\t\t\tPlease Enter a valid Number::\t";
									continue;
								}
							}
							
							flag =0;
							
							check = checkBus(shuttle_no);
							valid = vald.idValidation(shuttle_no);
							
							if(check == 0 || valid == 0)
							{
								if(valid == 0)
								{
									cout<<"\n\t\t\t\t\t ERROR: Invalid Id\n";
									
								}
								else
								{
									cout<<"\n\t\t\t\t\tShuttle No Does Not Exist\n";
								}
								flag = 1;
								
							}
							else
							{
								v.push_back(to_string(shuttle_no));
							}
						}while(flag !=0);
						
						
						getline(ss, word,',');	//Reading Pick Point
						v.push_back(word);	//Pushing Pick Point
						
						
						getline(ss, word,',');	//Reading Drop Point
						v.push_back(word);	//Pushing Drop Point
						
						
						getline(ss, word,',');	//Reading start Time
						v.push_back(word);	//Pushing start Time
						
						
						getline(ss, word,',');	//Reading End Time
						v.push_back(word);	//Pushing End Time
						
						
						getline(ss, word,',');	//Reading Date
						v.push_back(word);	//Pushing Date
						
						sche_record.insert(v);
						v.clear();
						break;
					case PICK_POINT:
						
						v.push_back(word);	//Pushing back Schedule ID
						
						getline(ss, word,',');		//Reading Shuttle no
						v.push_back(word);	//Pushing back Shuttle No
						
						getline(ss, word,',');		//Reading Pick Point
						
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						cout<<"\n\t\t\t\t\tEnter new Pick Point :: \t";
						cin.ignore();
						getline(cin,myString);
						v.push_back(myString);
						
						getline(ss, word,',');		//Reading drop Point
						v.push_back(word);	//Pushing drop Point
						
						
						getline(ss, word,',');		//Reading start Time
						v.push_back(word);	//Pushing start Time
						
						
						getline(ss, word,',');		//Reading End Time
						v.push_back(word);	//Pushing End Time
						
						
						getline(ss, word,',');		//Reading Date
						v.push_back(word);	//Pushing Date
						
						sche_record.insert(v);
						
						v.clear();
						break;
						
					case DROP_POINT:
						
						v.push_back(word);	//Pushing back Schedule ID
						
						getline(ss, word,',');		//Reading Shuttle no
						v.push_back(word);	//Pushing back Shuttle No
						
						getline(ss,word,',');		//Reading Pick Point
						v.push_back(word);	//Pushing back Point
						
						getline(ss,word,',');		//Reading drop point
						
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						cout<<"\n\t\t\t\t\tEnter new Drop Point :: \t";
						cin.ignore();
						getline(cin, myString);
						v.push_back(myString);		//Pushing drop Point
						
						
						getline(ss, word,',');		//Reading start Time
						v.push_back(word);	//Pushing start Time
						
						
						getline(ss, word,',');		//Reading End Time
						v.push_back(word);	//Pushing End Time
						
						
						getline(ss, word,',');		//Reading Date
						v.push_back(word);	//Pushing Date
						
						sche_record.insert(v);
						v.clear();
						break;
					case START_TIME:
						
						v.push_back(word);	//Pushing back Schedule ID
						
						getline(ss, word,',');		//Reading Shuttle no
						v.push_back(word);	//Pushing back Shuttle No
						
						getline(ss,word,',');		//Reading Pick Point
						v.push_back(word);	//Pushing back Point
						
						getline(ss,word,',');		//Reading Drop Point
						v.push_back(word);	//Pushing drop Point
						
						
						getline(ss, word,',');		//Reading start Time
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						do
						{
							cout<<"\n\t\t\t\t\tEnter the start time :: Hour :: \t";
							cin>>myString;
							this->startTime.setHours(stoi(myString));
							
							cout<<"\n\t\t\t\t\t\t\t\tMinute :: \t";
							cin>>myString2;
							this->startTime.setMinutes(stoi(myString2));
							
							string a = "00";
							
							//Time validation
							if(vald.timeValidation(this->startTime.getHours(), this->startTime.getMinutes()))
							{
								string startTime = myString + strr+ myString2 +  strr+ a;
								v.push_back(startTime);		//Pushing start Time
								flag = 1;
							}		
							else
							{
								cout<<"\n\t\t\t\t\tPlease Enter the correct time.";
								flag = 0;
							}
						
						}while(flag != 1);

						getline(ss, word,',');		//Reading End Time
						v.push_back(word);	//Pushing End Time
						
						
						getline(ss, word,',');		//Reading Date
						v.push_back(word);	//Pushing Date
						
						sche_record.insert(v);
						v.clear();
						break;
					case END_TIME:
						
						v.push_back(word);	//Pushing back Schedule ID
						
						getline(ss, word,',');		//Reading Shuttle no
						v.push_back(word);	//Pushing back Shuttle No
						
						getline(ss,word,',');		//Reading Pick Point
						v.push_back(word);	//Pushing back Pick Point
						
						getline(ss,word,',');		//Reading Drop Point
						v.push_back(word);	//Pushing drop Point
						
						
						getline(ss, word,',');		//Reading start Time
						v.push_back(word);	//Pushing Start Time

						
						getline(ss, word,',');		//Reading End Time
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						do
						{
							cout<<"\n\t\t\t\t\tEnter the end time :: Hour :: \t";
							cin>>myString;
							this->endTime.setHours(stoi(myString));
							
							cout<<"\n\t\t\t\t\t\t\t      Minute :: ";
							cin>>myString2;
							this->endTime.setMinutes(stoi(myString2));
							
							string a = "00";
							
							//Time Validation
							if(vald.timeValidation(this->endTime.getHours(), this->endTime.getMinutes()))
							{
								string endTime = myString + strr + myString2 +  strr + a;
								v.push_back(endTime);		//Pushing End Time
								flag = 1;
							}		
							else
							{
								cout<<"\n\t\t\t\t\tPlease Enter the correct time.";
								flag = 0;
							}
						
						}while(flag != 1);
						
						
						getline(ss, word,',');	//Reading Date
						v.push_back(word);	//Pushing Date
						
						sche_record.insert(v);
						v.clear();
						break;
					case DATE:
					
						v.push_back(word);	//Pushing back Schedule ID
						
						getline(ss, word,',');		//Reading Shuttle no
						v.push_back(word);	//Pushing back Shuttle No
						
						getline(ss,word,',');		//Reading Pick Point
						v.push_back(word);	//Pushing back Pick Point
						
						getline(ss,word,',');		//Reading Drop Point
						v.push_back(word);	//Pushing Drop Point
						
						
						getline(ss, word,',');		//Reading Start Time
						v.push_back(word);	//Pushing Start Time

						getline(ss, word,',');		//Reading End Time
						v.push_back(word);	//Pushing End Time
						
						getline(ss, word,',');		//Reading Date
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						do
						{
							cout<<"\n\t\t\t\t\tEnter Date (DD/MM/YYYY) :: \t";
							
							string date;
							cin>>date;
							
							flag = 0;	//Resetting flag variable to run the loop until correct date is not entered
							
							check = checkScheduleDate(date);	//Check if date is not more than 2 next two days from today
							valid = vald.dateValidation(date);		//Date validation
							
							if(valid == 0)
							{
								flag =0;
								cout<<"\n\t\t\t\t\tPlease enter the date in the given format\n";
							}
							else if(check == -1)
							{
								flag =0;
								cout<<"\n\t\t\t\t\tYou have entered an outdated date......\n\t\t\t\t\tDates between today and the following two days must be entered\n";
							}	
							else if(check == 0)
							{
								flag =0;
								cout<<"\n\t\t\t\t\tDate Cannot be exceeded....\n\t\t\t\t\tDates between today and the following two days must be entered\n";
							}
							else
							{
								v.push_back(date);
								flag =1;
							}
						}while(flag != 1);
						
						flag = 0;
						sche_record.insert(v);
						v.clear();
						
						break;
					case EXIT_MOD_SCH:
						break;	//Exit Option
					default:
						cout<<"\n\t\t\t\t\tEntered wrong choice\
						\n\t\t\t\t\t[1] Want to choose again\
						\n\t\t\t\t\t[2] Exit \n";
						while(1)
						{
							cin>>wrong;
							if(!cin.fail())//user choice
							{
								break;
							}
							else
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(),'\n');
								cout<<"\n\t\t\t\t\tEnter valid number::\t";
								continue;
							}
						}
				}
						
			}while(wrong !=2);
			
			continue;
		}
	
		v.push_back(word);	//Pushing back Schedule ID
							
		getline(ss,word,',');	//Reading Shuttle no
		v.push_back(word);
		
							
		getline(ss, word,',');	//Reading pick Point
		v.push_back(word);	//Pushing pick Point
							
		getline(ss, word,',');	//Reading drop Point
		v.push_back(word);	//Pushing drop Point
							
							
		getline(ss, word,',');	//Reading start Time
		v.push_back(word);	//Pushing start Time
							
							
		getline(ss, word,',');	//Reading End Time
		v.push_back(word);	//Pushing End Time
							
							
		getline(ss, word,',');	//Reading Date
		v.push_back(word);	//Pushing Date
							
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
		cout<<"\n\t\t\t\t\tERROR: Cannot File Found";
	}
	
	//For loop to write Data into file
	//1st method
	//typename set<vector<string>>::iterator it;
	//2nd method
	
	for(auto it = sche_record.begin(); it != sche_record.end(); it++)
	{
		for(i =0; i <6 ; i++)
		{
			out<<(*it)[i]<<",";	// Writing comma seperated
		}
		out<<(*it)[i]<<"\n";	//Ending each line with New Line
	}
	
	cout<<endl<<endl;
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"Schedule Modified Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	//Closing the File
	out.close();
	
	char key;
	cout<<"\n\t\t\t\t\t\tEnter any key to continue. . . . ";
	cin>>key;
	
}


