//List Previous Bookings
#include"Passenger.h"

//function to display the previous booking of the passenger
void Booking::listPreviousBooking(int id)
{
	system("cls");

	
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"P r e v i o u s   B o o k i n g"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	
	int pas_id = id,temp;//variables for user cghoice
	
	//variables to store the data of the file
	string line, book_id,pass_id, route_id, pick_point, drop_point;
	int flag = 0,n=1;
	
	ifstream in;//creating object of ifstream
	in.open("./DataBaseFiles/Booking_History.txt");
	
	//if file is not opened
	if(!in.is_open())
	{
		cout<<"\n\t\t\t\t\tCannot open File";
		exit(0);
	}
	//menu for previous bookings
	cout<<setw(45)<<"S.NO."<<setw(17)<<"Booking ID"<<setw(17)<<"Passenger Id"<<setw(13)<<"RouteId"<<setw(15)<<"Source"<<setw(20)<<"Destination"<<endl<<endl;
	
	
	
	//traversing in the file
	while(getline(in,line))
	{
		stringstream ss(line);
		
		getline(ss,book_id,',');
		getline(ss, pass_id,',');
		getline(ss, route_id,',');
		getline(ss, pick_point,',');
		getline(ss, drop_point,',');
		temp = stoi(pass_id);
		if(temp == pas_id)
		{
			flag = 0; 
			cout<<right<<setw(42)<<n++;
			cout<<"\t\t";
			cout<<setw(15)<<left<<book_id;
			cout<<setw(15)<<pass_id;
			cout<<setw(15)<<route_id;
			cout<<setw(20)<<pick_point;
			cout<<setw(20)<<drop_point;
			//for newline
			cout<<endl;
		}
	}
	
	if( flag == 1 )
	{
		cout<<"\n\t\t\t\t\tPassenger Id Not Found";
		
	}
	in.close();
	
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	char key;
	cout<<"\n\t\t\t\t\tEnter any key to continue................";
	cin>>key;
	
	
	return; 
}

