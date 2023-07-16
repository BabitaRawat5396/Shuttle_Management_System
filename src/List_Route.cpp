//Function Definition for List Details Of Routes

#include"Route.h"

//function to display the details of the route
void Route::listRoute()
{
	
	system("clear");
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"ROUTE  DETAILS"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	//object of ifstream class to read the data
	ifstream in;
	in.open("./DataBaseFiles/Route.txt");//opening the file
	
	//if file is not opened
	if(!in.is_open())
	{
		cout<<"\n\t\t\t\tCannot open File";
		return;
	}

	cout<<setw(38)<<"S.NO."<<setw(17)<<"Route Id"<<setw(17)<<"Shuttle No"<<setw(17)<<"Source"<<setw(25)<<"Destination"<<endl<<endl;
	
	//strings to store the data from the files
	
	string line;
	string route_id, shuttle_no, source, destination;
	
	int n = 1;
	 
	//while loop to read data from the file
	while(getline(in,line))
	{
		
		cout<<right<<setw(35)<<n++;
		
		stringstream ss(line);
		
		cout<<"\t\t";
		//reading the route_id from the file
		getline(ss, route_id,',');
		cout<<setw(15)<<left<<route_id;
		
		//reading shuttle_no from the file
		getline(ss, shuttle_no,',');
		cout<<setw(20)<<shuttle_no;
		
		//reading source from the file
		getline(ss, source,',');
		cout<<setw(20)<<source;
		
		//reading destination from the file
		getline(ss, destination,',');
		cout<<setw(20)<<destination;
		
		
		//for newline
		cout<<endl;
		
		
	}
	
	//closing the file
	in.close();
	
	//Formatting
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
		
	char ch;
	cout<<"\n\t\t\t\t\tEnter any key.........";
	cin>>ch;
	
	
	return;
	
}
