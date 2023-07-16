#include"Route.h"
//function used to check the route by id
int Route::checkRouteById(int id)
{
	system("cls");

	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(100)<<"R O U T E"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	int n = id;//storing the id
	if(id == 0)//if id == 0 the ask for the id
	{
		cout<<"\n\t\t\t\t\tEnter the Route Id to check the Route::\t";
		cin>>n;//accepting the id from user or admin
		
	}
	
	ifstream in;//creating the object of ifstream
	in.open("./DataBaseFiles/Route.txt");//opeing the file
	
	if(!in.is_open())//if file is not opened
	{
		cout<<"\n\t\t\t\t\tData Can not be Fetched"<<endl;
	}
	
	string line;//for storing the line of the file
	string rid, S_no, source, dest;//for strong the details of the variables
	
	while(getline(in, line))//traversing through the file
	{
		stringstream ss(line);//creating the stream of the line
		getline(ss, rid, ',');//finding the id
		if(n == stoi(rid) && id != 0)//if equals the close the file and retun 1
		{
			in.close();
			return 1;
		}
		if(n == stoi(rid) && id == 0)//else display the details for the particular id
		{
			cout<<"\t\tRoute id    Shuttle Number     Source       Destination"<<endl;
			cout<<"\t\t";
			getline(ss, S_no, ',');
			getline(ss, source, ',');
			getline(ss, dest, ',');
			cout<<rid<<"     "<<S_no<<"      "<<source<<"     "<<dest<<endl;
		}
	}
	
	in.close();//closing the file
	
	cout<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	return 0;
}



//function to check the route by desination
void Route::checkRouteByDest()
{
	system("clear");
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"ROUTE"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cin.ignore();
	//variables for the user choices
	string start, end;
	int n = 1, flag =0;
	
	//accepting the start point
	cout<<"\n\t\t\t\t\tEnter the Start Point of Route::\t";	
	getline(cin, start);
	
	
	//accepting the end point
	cout<<"\n\n\t\t\t\t\tEnter the End Point of Route::\t\t";	
	getline(cin, end);
	
	
	//creating object of ifstream
	ifstream in;
	in.open("./DataBaseFiles/Route.txt");
	
	//if file is not opened
	if(!in.is_open())
	{
		cout<<"\n\t\t\t\t\tData Can not be Fetched"<<endl;
		return;
	}
	
	//variables to store the data of the file
	string line;
	string rid, S_no, source, dest;
	
	cout<<endl<<endl<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	cout<<setw(38)<<"S.NO."<<setw(17)<<"Route Id"<<setw(17)<<"Shuttle No"<<setw(17)<<"Source"<<setw(25)<<"Destination"<<endl<<endl;
	
	//traversing through the file
	while(getline(in, line))
	{
		stringstream ss(line);//creating the stream of the line
		getline(ss, rid, ',');
		getline(ss, S_no, ',');
		getline(ss, source, ',');
		getline(ss, dest, ',');
		if(source == start && dest == end)//printing the data on screen
		{
			flag = 1;
			cout<<right<<setw(35)<<n++;
			cout<<"\t\t";
			cout<<setw(15)<<left<<rid;
			cout<<setw(20)<<S_no;
			cout<<setw(20)<<source;
			cout<<setw(20)<<dest;
			//for newline
			cout<<endl;
		}
	}
	in.close();//closing the file
	if(flag == 0)
	{
		cout<<"\\n\t\t\t\t\tRoute Not Found ";
	}
	
	cout<<endl<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	char chh;
	cout<<"\n\t\t\t\t\tPress any key to continue...\t";
	cin>>chh;
	
	
	return;
}
