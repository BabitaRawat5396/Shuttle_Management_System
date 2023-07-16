//Function Definition for check Bus

#include"Shuttle.h"

//function to check the bus
int global::checkBus(int shuttle_no)
{

	
	ifstream in;//creating the object for check us
	in.open("./DataBaseFiles/Bus_details.txt");//opening the file
	
	if(!in.is_open())//if not open
	{
		cout<<"\n\t\t\t\tCannot open file"<<endl;
		return 0;
	}
	
	string shuttleNo;	//Plate No
	string line;//to store the line of the file
	
	while(getline(in,line))
	{
		stringstream ss(line);//creating the stream of the line
					
		getline(ss, shuttleNo,',');//extracting the shuttle number from the file
		
		if(to_string(shuttle_no) == shuttleNo)
		{
			in.close();
			return 1;
		}
	}
	in.close();//closing the file
	
	return 0;
}

