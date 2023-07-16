#include"Passenger.h"

//Function definition for New Bookings of Passenger
void Booking::newBooking(int id)
{
	system("cls");

	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(115)<<"N E W   B O O K I N G"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	//variables to store the data from the file and user choices
	int ch, bookId, routeId, val, flag=0, bid;
	string pick,drop;
	string line;
	string pass_id, book_id, route_id, pick_point, drop_point, shuttle_no;

	//checking if passenger is blocked or not
	flag = global::checkBlockPassenger(id);//inglobal namespace
	if(flag == 1)
	{
		cout<<"\n\t\t\t\t\tYou are blocked by Admin. Contact Admin for more info"<<endl<<endl;
		return;
	}
	
	do
	{
		//menu to use source and destination
		cout<<"\n\t\t\t\t\t[1] Use existing pick-up point\n\
			\n\t\t\t\t\t[2] Change the pick-up point\n\
			\n\t\t\t\t\t[3] Exit :: \n";
		cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<"\n\t\t\t\t\tEnter your choice::\t";
		while(1)
		{
			cin>>ch;
			if(!cin.fail())//user choice
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"\n\t\t\t\t\tEnter the correct Choice::\t";
				continue;
			}
		}
		
		
		ifstream in;//creating objects of ifstream and ofstream
		ofstream out;
		
		
		switch(ch)
		{
			case 1:
				//menu to chhose the drop point
				cout<<"\n\t\t\t\t\t[1] Use existing drop point\n\
					\n\t\t\t\t\t[2] Change drop point \n\
					\n\t\t\t\t\t[3] Exit :: \n";
				cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<"\n\t\t\t\t\tEnter your choice::\t";
				while(1)
				{
					cin>>ch;
					if(!cin.fail())//user choice
					{
						break;
					}
					else
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout<<"\n\t\t\t\t\tEnter the correct Choice::\t";
						continue;
					}
				}
				
				
				if(ch == 1)
				{
					in.open("./DataBaseFiles/Booking_History.txt");//opening the file
					
					if(!in.is_open())//if file is not open
					{
						cout<<"\n\t\t\t\t\tERROR: Cannot open file"<<endl;
						return;
					}
					//traversing though file
					while(getline(in,line))
					{
						stringstream ss(line);
						
						//storing the data in variables
						getline(ss, book_id,',');
						getline(ss, pass_id,',');
						getline(ss, route_id,',');
						getline(ss, pick_point,',');
						getline(ss, drop_point,',');
						
						//if id validated
						if(id == stoi(pass_id))
						{
							routeId = stoi(route_id);
							pick = pick_point;
							drop = drop_point;
						}
					}
					in.close();//closing the file
					
					out.open("./DataBaseFiles/Booking_History.txt",ios::app);
		
					if(!out.is_open())
					{
						cout<<"\n\t\t\t\t\tCannot open file"<<endl;
						return;
					}
					
					//writing data into the file
					
					bid = this->generateBookingId();
					if(bid == 0)
					{
						out.close();
						return;
					}
					out<<bid<<",";
					out<<id<<",";
					out<<routeId<<",";
					out<<pick<<",";
					out<<drop<<"\n";
					
					out.close();//closing the file
					
					cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
					cout<<setw(115)<<"BOOKED  SUCCESSFULLY. . . . . "<<endl<<endl;
					cout<<setw(112)<<"Your Booking id is ::\t"<<bid<<endl;
					cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
					
					char chh;
					cout<<"\n\t\t\t\t\tEnter any key to continue............";
					cin>>chh;
					
					return;
				}
				else
				{
					cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
					
					//asking the drop point
					cout<<"\n\t\t\t\t\tEnter Drop Point ::\t";
					cin.ignore();
					getline(cin,drop);
					
					in.open("./DataBaseFiles/Booking_History.txt");//opening the file
					
					if(!in.is_open())//closing the file
					{
						cout<<"\n\t\t\t\t\tCannot open file"<<endl;
						return;
					}
					
					//traversing the file
					while(getline(in,line))
					{
						stringstream ss(line);
						
						//storing the data in variables
						getline(ss, book_id,',');
						getline(ss, pass_id,',');
						getline(ss, route_id,',');
						getline(ss, pick_point,',');
						getline(ss, drop_point,',');
						
						//if id validates
						if(id == stoi(pass_id))
						{
							pick = pick_point;
						}
					}
					
					in.close();//closing the file
					
					
					in.open("./DataBaseFiles/Route.txt");//opening the file
					string str;
					
					//traversing through the file
					while(getline(in,line))
					{
						//creating stream of the class
						stringstream ss(line);
						
						//getting data from the file
						getline(ss, route_id,',');
						getline(ss, shuttle_no,',');
						getline(ss, pick_point,',');
						getline(ss, drop_point,',');
						
						//if points validates
						if(drop == drop_point && pick == pick_point)
						{
							routeId = stoi(route_id);
							flag = 1;
							break;
						}
					}
					
					in.close();//closing the file
					
					if (flag == 1)
					{
						//opening the file in append mode
						out.open("./DataBaseFiles/Booking_History.txt",ios::app);
		
						//if file is not opened
						if(!out.is_open())
						{
							cout<<"Cannot open file"<<endl;
							return;
						}
						
						//writing data into the files
						bid = this->generateBookingId();
						if(bid == 0)
						{
							out.close();
							return;
						}
						out<<bid<<",";
						out<<id<<",";
						out<<routeId<<",";
						out<<pick<<",";
						out<<drop<<"\n";
						
						out.close();//closing the file
						
						cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						cout<<setw(115)<<"BOOKED  SUCCESSFULLY. . . . . "<<endl<<endl;
						cout<<setw(112)<<"Your Booking id is ::\t"<<bid<<endl;
						cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						
						char chh;
						cout<<"\n\t\t\t\t\tEnter any key to continue............";
						cin>>chh;
					
						return;
					}
					else
					{
						cout<<"\n\t\t\t\t\tNo route between pick Point and Drop Point ";
						cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						
						
						char chh;
						cout<<"\n\t\t\t\t\tEnter any key to continue............";
						cin>>chh;
						
						return;
					}
				}
				
				break;
				
			case 2:
				cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
					
				//entring the pick point
				cout<<"\n\t\t\t\t\tEnter Pick up Point ::\t" ;
				cin.ignore();
				getline(cin, pick);
				
				//menu to chhose the drop point
				cout<<"\n\t\t\t\t\t[1] Use existing drop point\n\
					\n\t\t\t\t\t[2] Change drop point \n\
					\n\t\t\t\t\t[3] Exit :: \n";
				cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				
				cout<<"\n\t\t\t\t\tEnter your choice::\t";
				while(1)
				{
					cin>>ch;
					if(!cin.fail())//user choice
					{
						break;
					}
					else
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout<<"\n\t\t\t\t\tEnter the correct Choice::\t";
						continue;
					}
				}
				
				
				if(ch == 1)
				{
					//opening the file
					in.open("./DataBaseFiles/Booking_History.txt");
					
					if(!in.is_open())//closing the file
					{
						cout<<"\n\t\t\t\t\tCannot open file"<<endl;
						return;
					}
					
					//reading the lines from the file
					while(getline(in,line))
					{
						//creating the stream of the line
						stringstream ss(line);
						
						//storing the data in variables
						getline(ss, book_id,',');
						getline(ss, pass_id,',');
						getline(ss, route_id,',');
						getline(ss, pick_point,',');
						getline(ss, drop_point,',');
						
						
						//if id validates
						if(id == stoi(pass_id))
						{
							drop = drop_point;
						}
					}
					
					in.close();//closing the file
					
					//opening the file 
					in.open("./DataBaseFiles/Route.txt");
					
					if(!in.is_open())//if file is not opened
					{
						cout<<"\n\t\t\t\t\tCannot open file"<<endl;
						return;
					}
					
					//traversing the file line by line
					while(getline(in,line))
					{
						//creating the stream of the line
						stringstream ss(line);
						
						//storing the data in variables 
						getline(ss, route_id,',');
						getline(ss, shuttle_no,',');
						getline(ss, pick_point,',');
						getline(ss, drop_point,',');
						
						//if points are validates
						if(drop == drop_point && pick == pick_point)
						{
							routeId = stoi(route_id);
							flag = 1;
							break;
						}
					}
					
					in.close();//closing the files
					
					if (flag == 1)
					{
						//opening the files
						out.open("./DataBaseFiles/Booking_History.txt",ios::app);
		
						if(!out.is_open())//if file is not opened
						{
							cout<<"\n\t\t\t\t\tCannot open file"<<endl;
							return;
						}
						
						//writing data into the file						
						bid = this->generateBookingId();
						if(bid == 0)
						{
							out.close();
							return;
						}
						out<<bid<<",";
						out<<id<<",";
						out<<routeId<<",";
						out<<pick<<",";
						out<<drop<<"\n";
						
						out.close();//closing the file
							
						cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						cout<<setw(115)<<"BOOKED  SUCCESSFULLY. . . . . "<<endl<<endl;
						cout<<setw(112)<<"Your Booking id is ::\t"<<bid<<endl;
						cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
					
						char chh;
						cout<<"\n\t\t\t\t\tEnter any key to continue............";
						cin>>chh;
						
						return;
						
					}
					else
					{
						cout<<"\n\t\t\t\t\tNO route Between Pick Point and Drop Point";
						cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						
						char chh;
						cout<<"\n\t\t\t\t\tEnter any key to continue............";
						cin>>chh;
						
						return;
					}
				}
				else
				{
					//asking for the drop point
					cout<<"\n\t\t\t\t\tEnter Drop Point::\t";
					cin.ignore();
					getline(cin, drop);
					
					//opining the file
					in.open("./DataBaseFiles/Route.txt");
					
					if(!in.is_open())
					{
						cout<<"\n\t\t\t\t\tCannot open file"<<endl;
						return;
					}
					
					//traversing the file
					while(getline(in,line))
					{
						stringstream ss(line);//creating the stream of the line
						
						
						//storing the data into the files
						getline(ss, route_id,',');
						getline(ss, shuttle_no,',');
						getline(ss, pick_point,',');
						getline(ss, drop_point,',');
						
						//if points validates
						if(drop == drop_point && pick == pick_point)
						{
							routeId = stoi(route_id);
							flag = 1;
							break;
						}
					}
					
					in.close();
					
					if (flag == 1)
					{
						//if file is openend
						out.open("./DataBaseFiles/Booking_History.txt",ios::app);
						
						//if file is not openend
						if(!out.is_open())
						{
							cout<<"\n\t\t\t\t\tCannot open file"<<endl;
							return;
						}
						
						//writing data into the files
						bid = this->generateBookingId();
						if(bid == 0)
						{
							out.close();
							return;
						}
						out<<bid<<",";
						out<<id<<",";
						out<<routeId<<",";
						out<<pick<<",";
						out<<drop<<"\n";
						
						out.close();//closing the files
							
						cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						cout<<setw(115)<<"BOOKED  SUCCESSFULLY. . . . . "<<endl<<endl;
						cout<<setw(112)<<"Your Booking id is ::\t"<<bid<<endl;
						cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
					
						char chh;
						cout<<"\n\t\t\t\t\tEnter any key to continue............";
						cin>>chh;
						
						return;
					}
					else
					{
						cout<<"\n\t\t\t\t\tPick Point and Drop Point are not available ";
						
						cout<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						
						char chh;
						cout<<"\n\t\t\t\t\tEnter any key to continue............";
						cin>>chh;
						
						return;
					}
					in.close();//closing the file
				}
				
				break;
			
			case 3:
				return;	
			default:
				//for wrong choice
				cout<<"\n\t\t\t\t\tEntered wrong choice\n\
					\n\t\t\t\t\t[1] Want to choose again\n\
					\n\t\t\t\t\t[2] Exit \n";
				cout<<"\n\t\t\t\t\tEnter your choice::\t";
				while(1)
				{
					cin>>val;
					if(!cin.fail())//user choice
					{
						break;
					}
					else
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout<<"\n\t\t\t\t\tEnter the correct Choice::\t";
						continue;
					}
				}
				if(val == 2)
				{
					return;				
				}
		
		}
	}while(val!=1);
	
}

//generating the booking id
int Booking::generateBookingId()
{
	int id;
	string pass_id, book_id, route_id, pick_point, drop_point, line;
	
	ifstream in;
	in.open("./DataBaseFiles/Booking_History.txt");
	
	if(!in.is_open())//if file is not open
	{
		cout<<"\n\t\t\t\t\tCannot open file"<<endl;
		return 0;
	}
	while(getline(in,line))
	{
		stringstream ss(line);
		
		
		getline(ss, book_id,',');
		getline(ss, pass_id,',');
		getline(ss, route_id,',');
		getline(ss, pick_point,',');
		getline(ss, drop_point,',');
		
		id = stoi(book_id);
	}
	in.close();
	
	return id+1;
}





