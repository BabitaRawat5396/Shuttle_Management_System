//Function definition for Checking existance of pick point and drop point
#include"Shuttle.h"

//check route by the source and destination 
int global::checkSourceDestination(string pick, string drop)
{
	int n=0;
	
	ifstream in;//creating the object
	in.open("./DataBaseFiles/Route.txt");	//opening the file
	
	if(!in.is_open())//if file is not open
	{
		cout<<"Data Can not be Fetched"<<endl;
		return 0;
	}
	
	string line;//for storing the line from the file
	
	string rid, S_no, source, dest; //for strong the details of the line
	
	while(getline(in, line))
	{
		stringstream ss(line);//for creating the stream of the line
		//extracting the data from the stream of line
		getline(ss, rid, ',');
		getline(ss, S_no, ',');
		getline(ss, source, ',');
		getline(ss, dest, ',');
		if(source == pick && dest == drop)
		{
			in.close();//closing the file
			return 1;
		}
	}
	in.close();//closing the file
	
	return 0;
}
