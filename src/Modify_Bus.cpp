
#include"Bus.h"


//this function is for modifying the details of the bus in database
void Bus::modifyBus()
{
	//variabbles for user choice
	int id, flag = 0, check ;
	Bus bus;
	int  choice, val =0, wrong = -1;
	Validation vald;
	//variables to store the details of particular line from the file
	string word, line, total;
	
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<"\n\t\t\t\t\tEnter the Shuttle Number that you want to Modify: \t";	
	
	cin>>id;
	check = global::checkBus(id);
	
	//craeting object of if stream and opening file for read
	ifstream in;
	in.open("./DataBaseFiles/Bus_details.txt");
	
	//creating the set of vectors to store the data from the file 
	set<vector<string>> details;
	
	//creating vector to store the temporary line of the file
	vector<string> v;
	
	
	if (check == 0)
	{
		cout<<"\n\t\t\t\t\tBus id doesn't exist";
		return;
	}
	
	
	//while loop to traverse the file
	while(getline(in, line))
	{
		//creating the stream of the line of the file
		stringstream ss(line);//to craete a stream of a string
		
		//reading the shuttleNo from the file
		getline(ss, word,',');
		
		//if the id is equal to the file and we want to modify it
		if(id == stoi(word))
		{
			
			cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						
						//menu to choose
			cout<<"\n\t\t\t\t\tEnter your choice\
				\n\t\t\t\t\t[1] Bus Number\
				\n\t\t\t\t\t[2] Registration Cetificate Number\
				\n\t\t\t\t\t[3] Vehicle Insurance Number\
				\n\t\t\t\t\t[4] Total Seats in bus\
				\n\t\t\t\t\t[5] Booked Seats in bus\
				\n\t\t\t\t\t[0] Exit"<<endl<<endl;
				
			cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
			
			cout<<"\n\n\t\t\t\t\tEnter Choice::\t";
			cin>>choice;
						
				switch(choice)
				{
					case BUSNO:
						v.push_back(word);//pushing back the element in to the vector
						//reading first name
						getline(ss, word,',');
						do
						{
							cout<<"\n\t\t\t\t\tEnter the Bus Number::\t";
							
							cin>>this->busNo;
							
							//to convert all the characters into capital letters
							for(int i=0; i<this->busNo.length(); i++)
							{
								this->busNo.at(i) = toupper(this->busNo.at(i));
							}
							
							val = vald.busNoValidation(this->busNo);
							if(val == 1)
							{
								v.push_back(this->busNo);
								
								//reading RCNo from the file
								getline(ss, word,',');
								v.push_back(word);

								//reading Vehicle Insurance from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading totalSeats from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading bookedSeats from the file
								getline(ss, word,',');
								v.push_back(word);
								
								break;
								
							}
							else
							{
								cout<<"\n\n\t\t\t\t\tINVALID BUS NUMBER...!! FORMAT :: XX00XX0000 \n";//if invalid
								val = 0;
							}
							
							
						}while(val != 1);
						break;
						
					case RCNO:
						v.push_back(word);//pushing back the element in to the vector
						
						//reading busNo
						getline(ss, word,',');
						
						v.push_back(word);//pushing the first name
						
						//reading RCNo
						getline(ss, word,',');
						do
						{
							cout<<"\n\t\t\t\t\tEnter the RCNo::\t";
							
							cin>>this->RCNo;
							
							//to convert all the characters into capital letters
							for(int i=0; i<this->RCNo.length(); i++)
							{
								this->RCNo.at(i) = toupper(this->RCNo.at(i));
							}
							
							val = vald.RCNoValidation(this->RCNo);
							if(val == 1)
							{
								v.push_back(this->RCNo);
								
								
								//reading Vehicle Insurance from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading totalSeats from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading bookedSeats from the file
								getline(ss, word,',');
								v.push_back(word);
								
								break;
							}
							else
							{
								cout<<"\n\n\t\t\t\t\tINVALID Registration Certificate NUMBER...!!!!\n";	//if invalid
								val = 0;
							}
							
							
						}while(val != 1);
						break;
						
						break;
					case V_INS:
						v.push_back(word);//pushing back the element in to the vector
						
						//reading bus no from the file
						getline(ss, word,',');
						v.push_back(word);
						
						//reading RCNo from the file
						getline(ss, word,',');
						v.push_back(word);

						//reading Vehicle Insurance from the file
						
						getline(ss, word, ',');
						do
						{
							cout<<"\n\t\t\t\t\tEnter Vehicle Insurance Number::\t";
							
							cin>>this->vehicleIns;
							
							//to convert all the characters into capital letters
							for(int i=0; i<this->vehicleIns.length(); i++)
							{
								this->vehicleIns.at(i) = toupper(this->vehicleIns.at(i));
							}
							
							val = vald.vehicleInsValidation(this->vehicleIns);
							if(val == 1)
							{
								v.push_back(this->vehicleIns);
															
								
								
								//reading totalSeats from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading bookedSeats from the file
								getline(ss, word,',');
								v.push_back(word);
								
								break;
							}
							else
							{
								cout<<"\n\n\t\t\t\t\tINVALID VEHICLE INSURANCE NO...!!	FORMAT :: XX000000X \n";//if invalid
								val = 0;
							}
			
						}while(val != 1);
						break;
						
						break;
					case T_SEATS:
						v.push_back(word);//pushing back the element in to the vector
						//reading busNo
						getline(ss, word,',');
						v.push_back(word);
						//reading rc no
						getline(ss, word,',');
						v.push_back(word);
						//reading vehicle Ins
						getline(ss, word, ',');
						v.push_back(word);
						//reading total number of seats
						getline(ss, word, ',');
						do
						{
							cout<<"\n\t\t\t\t\tEnter Total Number Of Seats::\t";
							while(1)
							{
								cin>>this->totalSeats;
								if(!cin.fail())//user choice
								{
									break;
								}
								else
								{
									cin.clear();
									cin.ignore();
									cout<<"\n\n\t\t\t\t\tEnter Proper Number of Booked Seats::\t";
									continue;
								}
							}
							val = vald.totalSeatsValidation(this->totalSeats);
							if(val == 1)
							{
								v.push_back(to_string(this->totalSeats));
															
								//reading bookedSeats from the file
								getline(ss, word,',');
								v.push_back(word);
								
								break;
							}
							else
								cout<<"\n\t\t\t\t\tInvalid total seats !!! Enter Number between 20 to 45\n";
							
						}while(val != 1);
						break;
						
					case B_SEATS:
						v.push_back(word);//pushing back the element in to the vector
						//reading busNo 
						getline(ss, word,',');
						v.push_back(word);//pushing the busNo
						//reading rcNo
						getline(ss, word,',');
						v.push_back(word);
						//reading vehicleIns
						getline(ss, word, ',');
						v.push_back(word);
						//reading total Seats
						getline(ss, total, ',');
						v.push_back(total);
						//reading bookedSeats
						getline(ss, word, ',');
						
						do
						{
							cout<<"\n\t\t\t\t\tEnter the number of boooked Seats:\t";
							
							while(1)
							{
								cin>>this->bookedSeats;
								if(!cin.fail())//user choice
								{
									break;
								}
								else
								{
									cin.clear();
									cin.ignore();
									cout<<"\n\n\t\t\t\t\tEnter Proper Number of Booked Seats::\t";
									continue;
								}
							}
							
							val = vald.bookedSeatsValidation(this->bookedSeats,stoi(total));
							if(val == 1)
							{
								v.push_back(to_string(this->bookedSeats));
								
								break;
							}
							else
								cout<<"\n\t\t\t\t\tInvalid number of booked seats !!! \n";
								
						}while(val != 1);
						break;
						
						
					case EXIT:
						wrong = 2;
						break;
					default:
						cout<<"\n\n\t\t\t\t\tEntered wrong choice\
							\n\n\t\t\t\t[1] Want to choose again\
							\n\n\t\t\t\t[2] Exit \n";
						
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
									cin.ignore();
									cout<<"\n\n\t\t\t\t\tEnter valid Number ::\t";
									continue;
								}
							}
						
						
				} //switch case
				
			cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
			
			
			
			details.insert(v);
			v.clear();
			continue;
		}
		
		v.push_back(word);//pushing back the element in to the vector
		
		//reading busNO from the file
		getline(ss, word,',');
		v.push_back(word);
		
		
		//reading rcno from the file
		getline(ss, word,',');
		v.push_back(word);

		//reading v_ins from the file
		getline(ss, word,',');
		v.push_back(word);
		
		//reading t_seats from the file
		getline(ss, word,',');
		v.push_back(word);
		
		//reading b_seats from the file
		getline(ss, word,',');
		v.push_back(word);
		
		
		details.insert(v);//inserting the fully vector in the set
		
		v.clear();//clearing the vector to store the nexr line of the file
	}
	//clsing the file and data is stored into the file
	in.close();
	
	
	//creating the object of ofstream to write data into the file
	ofstream out;
	out.open("./DataBaseFiles/Bus_details.txt");//opening the file
	
	
	//method 1
	/*
	set<vector<string>>::iterator it;
	for(it = details.begin(); it != details.end(); ++it)
	{
		//logic
	}	
	*/
	
	//method 2 using auto keyword
	for(auto it = details.begin(); it != details.end(); ++it)
	{
		
		for(int i=0; i<5; i++) 	//for(int i=0; i<(*it).size(); ++i)
		{
			out<<(*it)[i]<<","; //writing data into the file
		}
		out<<(*it)[5]<<"\n";//writing the newline into the file    
	}
	
	//closing the data into the file
	in.close();
	
	
	
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<"\n\n\t\t\t\t\tBus Details Updated Successfully"<<endl<<endl;
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;

}




















