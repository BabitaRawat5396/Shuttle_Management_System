#include"Passenger.h"

//function to check if the passenger is blocked or not
int global::checkBlockPassenger(int id)
{
	int n = id;
	
	
	ifstream out;//object of ofstream
	out.open("./DataBaseFiles/Blocked_Passenger.txt");//opening the file
	
	if(!out.is_open())//if file is not opened
	{
		cout<<"\n\t\t\t\tData Can not be Fetched"<<endl;
	}
	
	
	string line;//for storing the one line of the file
	string pid;//for storing the attributes of the passenger file
	
	while(getline(out, line))//traversing the file
	{
		stringstream ss(line);//creating stream of the line using string stream 
		
		getline(ss, pid, ',');//getting id from the line
		
		if(n == stoi(pid) && id != 0)//checking of id == pid
		{
			out.close();//close the file
			return 1;//return 1
		}
		
	}	
	
	return 0;
}








