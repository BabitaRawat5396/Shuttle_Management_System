//function defination for check driver


#include"Driver.h"

//function used to check the driver  by driver id
int Driver::checkDriver(int driver_id)
{
	
	ifstream in;//creating the object of ifstream
	in.open("./DataBaseFiles/driver_details.txt");//opeing the file
	
	if(!in.is_open())//if file is not opened
	{
		cout<<"\n\t\t\t\t\tData Can not be Fetched"<<endl;
	}
	
	string line;//for storing the line of the file
	
	//for strong the details of the variables
	string DRIVERID;
	while(getline(in, line))//traversing through the file
	{
		stringstream ss(line);//creating the stream of the line
		getline(ss, DRIVERID, ',');//finding the driver id from file
		if(driver_id == stoi(DRIVERID))//if equals the close the file and retun 1
		{
			in.close();
			return 1;
		}
		
	}
	
	in.close();//closing the file
	
	cout<<endl<<endl;
	return 0;
}
