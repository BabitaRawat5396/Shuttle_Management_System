//Modify Route

#include"Route.h"

//this function is for modifying the details of the root
void Route::modifyRoute()
{
	system("cls");
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"M O D I F Y  R O U T E"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				
				
	
	//variabbles for user choice
	int ch, wrong = 2, flag = 0, route_id, i,choice;
	string myString;
	
	//variables to store the details of particular line from the file
	string line, word;
	
	int check, valid;
	
	//Taking Schedule ID from user to delete record
	do
	{
		
		
		cout<<"\n\t\t\t\t\tEnter the route Id::\t";//asking for the route id
		cin>>route_id;
		
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
				cin>>route_id;
			}
		}
		flag =0;
		
		check = checkRouteById(route_id);
		valid = val.idValidation(route_id);
		
		if(check == 0 || valid == 0)
		{
			if(valid == 0)
			{
				cout<<"\n\t\t\t\t\t ERROR: Invalid Id\n";
			}
			else
			{
				cout<<"\n\t\t\t\t\tRoute Id Does Not Exist\n";
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
	
	//creating the set of vector class
	set <vector<string>> route_record;
	
	//creating vector
	vector<string> v;
	
	ifstream in;//creating object of if stream
	
	in.open("./DataBaseFiles/Route.txt");//opening the file
	
	if(!in.is_open())//if file is not open
	{
		cout<<"\n\t\t\t\t\tCannot open file"<<endl;
		return;
	}
	
	//while loop to traverse the file
	while(getline(in, line))
	{
		//creating the stream of the line of the file
		stringstream ss(line);
		
		//reading the Route Id from the file
		getline(ss, word,',');
		
		//If the id is equal to the file 
		if(to_string(route_id) == word)
		{
			flag = 1;
			do
			{
				system("clear");
	
				//formatting
				cout<<"\n\n";
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<right<<setw(115)<<"M O D I F Y  R O U T E"<<endl<<endl;
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				
				
				cout<<"\n\t\t\t\t\tWhat details you want to Update\n\
					\n\t\t\t\t\t[1] Change Pick Point\n\
					\n\t\t\t\t\t[2] Change Drop Point\n\
					\n\t\t\t\t\t[3] Exit"<<endl<<endl;
				
				cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<"\n\n\t\t\t\t\t\t Enter the choice: \t";
				
				cin>>choice;
				
				switch(choice)
				{
					case 1:
						
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
						
						route_record.insert(v);
						
						v.clear();
						break;
						
					case 2:
						
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
						
						route_record.insert(v);
						v.clear();
						break;
					
					case 3:
						in.close();
						exit(0);	//Exit Option
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
	
		v.push_back(word);	//Pushing back Route ID
							
		getline(ss,word,',');	//Reading Shuttle no
		v.push_back(word);
		
							
		getline(ss, word,',');	//Reading pick Point
		v.push_back(word);	//Pushing pick Point
							
		getline(ss, word,',');	//Reading drop Point
		v.push_back(word);	//Pushing drop Point
							
		route_record.insert(v);
		v.clear();
	}
	
	//Closing the file
	in.close();	
	
	ofstream out;//creating object of the ofstream
	out.open("./DataBaseFiles/Route.txt");	//opeining the file
	
	if(!out.is_open())//if not open
	{
		cout<<"\n\t\t\t\tCannot open file"<<endl;
		return;
	}
	
	//iterating throgh the set and writing data to the file
	for(auto it = route_record.begin(); it != route_record.end(); ++it)
	{
		//writing data to the file
		for(int i=0; i<3; i++)
		{
			out<<(*it)[i]<<',';
		}
		out<<(*it)[3]<<'\n';
		  
	}
	
	out.close();//closing the file
	
	cout<<endl<<endl;
	
	
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"Route Modified Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	char chh;
	cout<<"\n\t\t\t\t\tEnter any Key to continue::\t";
	cin>>chh;
	
	return;
}

