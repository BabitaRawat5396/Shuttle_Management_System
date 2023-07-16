//Function definition  Route Class

#include"Route.h"


//add Route function
void Route::addRoute()
{

	system("cls");

	
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"A D D   R O U T E"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	int flag = 0;
	int cont_choice, check = 0;
	
	//creating the object of ofstream class
	ofstream out;
	out.open("./DataBaseFiles/Route.txt", ios::app);//opeining the file in append mode
	
	//if file is not open
	if(!out.is_open())
	{
		cout<<"\n\t\t\t\t\tCannot open File";
		return;
	}
	
	do
	{
		//Writing generate route id into file
		out<<this->generateRouteId()<<",";  
		
		do
		{
			cout<<"\n\t\t\t\t\tShuttle Number of Bus :: ";
			
			while(1)
			{
				cin>>this->shuttleNo;
				if(!cin.fail())//user choice
				{
					break;
				}
				else
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout<<"\n\t\t\t\t\t\tEnter Valid Number::\t";
					continue;
				}
			}
			
			check = global::checkBus(this->shuttleNo);
			//shuttle validation
			if(this->val.idValidation(this->shuttleNo) && check == 1)
			{
				flag =1;
			}
			else if(check == 0)
			{
				cout<<"\n\t\t\t\t\tSHUTTLE NO Does Not Exist...!!!!\n";//if invalid
				flag = 0;
			}
			else
			{
				cout<<"\n\t\t\t\t\tINVALID SHUTTLE No.\n";
				flag = 0;
			}
			
		}while(flag!=1);
		
		
		
		//writing shuttle number in file
		out<<this->shuttleNo<<",";
		
		//writing the source 
		cout<<"\n\t\t\t\t\tSource :: ";
		cin>>this->source;
		out<<this->source<<",";
		
		cin.ignore();
		//writing destination file
		cout<<"\n\t\t\t\t\tDestination :: ";
		cin>>this->destination;
		out<<this->destination<<"\n";
		
		//asking if user want to enter more details
		cout<<"\n\t\t\t\t\tDo u want to Continue::(1/0) ::\t";
		
		while(1)
		{
			cin>>cont_choice;
			if(!cin.fail())//user choice
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"\n\t\t\t\t\t\tEnter the valid number::\t";
				continue;
			}
		}
		
	
	
	}while(cont_choice!=0);

	out.close();
	
	
	cout<<endl<<endl;
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"Data Inserted Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	char chh;
	cout<<"\n\t\t\t\t\tEnter any Key to continue::\t";
	cin>>chh;
	
	
	return;
	
}


//function to generate Route ID
int Route::generateRouteId()
{
	int id;
	string route_id, line;
	
	ifstream in;
	in.open("./DataBaseFiles/Route.txt");
	
	if(!in.is_open())//if file is not open
	{
		cout<<"\n\t\t\t\t\tCannot open file"<<endl;
		return 0;
	}
	
	while(getline(in,line))
	{
		stringstream ss(line);
		
		getline(ss, route_id,',');
		id = stoi(route_id);
	}
	
	in.close();
	
	return id+1;
}










