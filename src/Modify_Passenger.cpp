
#include"Passenger.h"

//function to modify the details of the passenger
void Passenger::modifyPassenger()
{
	system("clear");
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(120)<<"M O D I F Y   D E T A I L S"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	//variable for soring the choice from the user
	int  choice, val, id, wrong = 2,flag =0, check, valid;
	
	do
	{
		
		cout<<"\n\t\t\t\t\tEnter the Passenger Id that you want to Modify\t";	
		cin>>id;
		
		while(1)
		{
			if(!cin.fail())//user choice
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"\n\t\t\t\t\tPlease Enter a valid Number::\t";
				cin>>id;
			}
		}
		
		flag =0;
		
		check = checkPassenger(id);
		valid = vald.idValidation(id);
		
		if(check == 0 || valid == 0)
		{
			if(valid == 0)
			{
				cout<<"\n\t\t\t\t\t ERROR: Invalid Id\n";
			}
			else
			{
				cout<<"\n\t\t\t\t\tPassenger Id Does Not Exist\n";
			}
			flag = 1;
			
			cout<<"\n\t\t\t\t\tDo You Want to Enter again?\n\
			\n\t\t\t\t\t[1] Continue\n\
			\n\t\t\t\t\t[2] Exit :: ";
			
			cin>>choice;
			
			if(choice == 2)
				return;
		}
		
	}while(flag !=0);
	
	//craeting object of if stream and opening file for read
	ifstream in;
	in.open("./DataBaseFiles/Passenger_details.txt");
	
	//strings to store the line of file and each word of the line
	string line, word;
	
	//creating the set of vectors to store the data from the file 
	set<vector<string>> details;
	
	//creating vector to store the temporary line of the file
	vector<string> v;
	
	//while loop to traverse the file
	while(getline(in, line))
	{
		//creating the stream of the line of the file
		stringstream ss(line);//to craete a stream of a string
		
		//reading the id from the file
		getline(ss, word,',');
		
		//if the id is equal to the file and we want to modify it
		if(to_string(id) == word)
		{
			do
			{
				system("clear");
				cout<<"\n\n";
				//formatting
				cout<<"\n\n";
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<right<<setw(115)<<"M O D I F Y   P A S S E N G E R"<<endl<<endl;
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				
				cout<<"\n\t\t\t\t\tWhat details you want to Update"<<endl<<endl;
				cout<<"\n\t\t\t\t\t[1] First Name of Passenger"<<endl;
				cout<<"\n\t\t\t\t\t[2] Last Name of Passenger"<<endl;
				cout<<"\n\t\t\t\t\t[3] Age of Passenger"<<endl;
				cout<<"\n\t\t\t\t\t[4] Gender of Passenger"<<endl;
				cout<<"\n\t\t\t\t\t[5] Phone Number of Passenger"<<endl;
				cout<<"\n\t\t\t\t\t[6] Passenger Email ID"<<endl;
				cout<<"\n\t\t\t\t\t[7] Date of Birth of Passenger"<<endl;
				cout<<"\n\t\t\t\t\t[0] Exit "<<endl;
				cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<"\n\n\t\t\t\t\t\t Enter the choice: \t";
				cin>>choice;
				
				switch(choice)
				{
					case 1:
						v.push_back(word);//pushing back the element in to the vector
						//reading first name
						getline(ss, word,',');
						do
						{
							cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
							cout<<"\n\t\t\t\t\tEnter the First Name::\t";
							string name;
							cin>>name;
							val = vald.nameValidation(name);
							if(val == 1)
							{
								v.push_back(name);
								//reading last name from the file
								getline(ss, word,',');
								v.push_back(word);

								//reading age from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading gender from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading phone from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading email from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading dob from the file
								getline(ss, word,',');
								v.push_back(word);
								break;
							}
						}while(val != 1);
						break;
					case 2:
						v.push_back(word);//pushing back the element in to the vector
						//reading first name 
						getline(ss, word,',');
						v.push_back(word);//pushing the first name
						//reading last name
						getline(ss, word,',');
						do
						{
							cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
							cout<<"\n\t\t\t\t\tEnter the Last Name::\t";
							string name;
							cin>>name;
							val = vald.nameValidation(name);
							if(val == 1)
							{
								v.push_back(name);
								
								//reading age from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading gender from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading phone from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading email from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading dob from the file
								getline(ss, word,',');
								v.push_back(word);
								break;
							}
							
						}while(val != 1);
						break;
						
						break;
					case 3:
						v.push_back(word);//pushing back the element in to the vector
						//reading first name 
						getline(ss, word,',');
						v.push_back(word);//pushing the first name
						//reading last name
						getline(ss, word,',');
						v.push_back(word);
						//reading age
						getline(ss, word, ',');
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						do
						{
							cout<<"\n\t\t\t\t\tEnter the Age of Passenger::\t";
							int age;
							cin>>age;
							
							//Checking if user has entered an integer value or not
							while(1)
							{
								if(!cin.fail())//user choice
								{
									break;
								}
								else
								{
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(),'\n');
									cout<<"\n\t\t\t\t\tPlease Enter a valid Number::\t";
									cin>>age;
								}
							}
		
							
							val = vald.ageValidation(age);	//validating age
							if(val == 1)
							{
								v.push_back(to_string(age));
															
								//reading gender from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading phone from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading email from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading dob from the file
								getline(ss, word,',');
								v.push_back(word);
								break;
							}
						}while(val != 1);
						break;
						
						break;
					case 4:
						v.push_back(word);//pushing back the element in to the vector
						//reading first name 
						getline(ss, word,',');
						v.push_back(word);//pushing the first name
						//reading last name
						getline(ss, word,',');
						v.push_back(word);
						//reading age
						getline(ss, word, ',');
						v.push_back(word);
						//reading gender
						getline(ss, word, ',');
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						do
						{
							cout<<"\n\t\t\t\t\tEnter the Gender::\t";
							string gender;
							cin>>gender;
							val = vald.genderValidation(gender.at(0));
							if(val == 1)
							{
								v.push_back(gender);
															
								//reading phone from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading email from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading dob from the file
								getline(ss, word,',');
								v.push_back(word);
								break;
							}
						}while(val != 1);
						break;
						
						break;
					case 5:
						v.push_back(word);//pushing back the element in to the vector
						//reading first name 
						getline(ss, word,',');
						v.push_back(word);//pushing the first name
						//reading last name
						getline(ss, word,',');
						v.push_back(word);
						//reading age
						getline(ss, word, ',');
						v.push_back(word);
						//reading gender
						getline(ss, word, ',');
						v.push_back(word);
						//reading phone
						getline(ss, word, ',');
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						do
						{
							cout<<"\n\t\t\t\t\tEnter Mobile Number::\t";
							int phone;
							cin>>phone;
							
							while(1)
							{
								if(!cin.fail())//user choice
								{
									break;
								}
								else
								{
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(),'\n');
									cout<<"\n\t\t\t\t\tPlease Enter a valid Number::\t";
									cin>>phone;
								}
							}
		
							val = vald.mobileValidation(phone);
							if(val == 1)
							{
								v.push_back(to_string(phone));
								
								
								//reading email from the file
								getline(ss, word,',');
								v.push_back(word);
								
								//reading dob from the file
								getline(ss, word,',');
								v.push_back(word);
								break;
							}
						}while(val != 1);
						break;
						
						break;
					case 6:
						v.push_back(word);//pushing back the element in to the vector
						//reading first name 
						getline(ss, word,',');
						v.push_back(word);//pushing the first name
						//reading last name
						getline(ss, word,',');
						v.push_back(word);
						//reading age
						getline(ss, word, ',');
						v.push_back(word);
						//reading gender
						getline(ss, word, ',');
						v.push_back(word);
						//reading phone
						getline(ss, word, ',');
						v.push_back(word);
						//reading email from line
						getline(ss, word, ',');
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						do
						{
							cout<<"\n\t\t\t\t\tEnter the  Email of Passenger::\t";
							string email;
							cin>>email;
							val = vald.emailValidation(email);
							if(val == 1)
							{
								v.push_back(email);							
								
								//reading dob from the file
								getline(ss, word,',');
								v.push_back(word);
								break;
							}
						}while(val != 1);
						break;
						
						break;
					case 7:
						v.push_back(word);//pushing back the element in to the vector
						//reading first name 
						getline(ss, word,',');
						v.push_back(word);//pushing the first name
						//reading last name
						getline(ss, word,',');
						v.push_back(word);
						//reading age
						getline(ss, word, ',');
						v.push_back(word);
						//reading gender
						getline(ss, word, ',');
						v.push_back(word);
						//reading phone
						getline(ss, word, ',');
						v.push_back(word);
						//reading email from line
						getline(ss, word, ',');
						v.push_back(word);
						//reading dob
						getline(ss, word, ',');
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						do
						{
							cout<<"\n\t\t\t\t\tEnter the Date of Birth(dd/mm/yyyy)::\t";
							string dob;
							cin>>dob;
							val = vald.dobValidation(dob);
							if(val == 1)
							{
								v.push_back(dob);
								
								
								break;
							}
						}while(val != 1);
						break;
						
					case 0:
						wrong = 2;
						break;
					default:
						cout<<"\n\t\t\t\t\t\tEntered wrong choice\n\
							\n\t\t\t\t\t\t[1] Want to choose again\n\
							\n\t\t\t\t\t\t[2] Exit ::\t";
						cin>>wrong;
						break;
				}
			}while(wrong!=2);
			
			details.insert(v);
			v.clear();
			continue;
		}
		
		v.push_back(word);//pushing back the element in to the vector
		
		//reading first name from the file
		getline(ss, word,',');
		v.push_back(word);
		
		
		//reading last name from the file
		getline(ss, word,',');
		v.push_back(word);

		//reading age from the file
		getline(ss, word,',');
		v.push_back(word);
		
		//reading gender from the file
		getline(ss, word,',');
		v.push_back(word);
		
		//reading phone from the file
		getline(ss, word,',');
		v.push_back(word);
		
		//reading email from the file
		getline(ss, word,',');
		v.push_back(word);
		
		//reading dob from the file
		getline(ss, word,',');
		v.push_back(word);
		
		details.insert(v);//inserting the fully vector in the set
		
		v.clear();//clearing the vector to store the nexr line of the file
	}
	//clsing the file and data is stored into the file
	in.close();
	
	
	
	//creating the object of ofstream to write data into the file
	ofstream out;
	out.open("./DataBaseFiles/Passenger_details.txt");//opening the file
	
	
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
	
		for(int i=0; i<7; i++) 	//for(int i=0; i<(*it).size(); ++i)
		{
			out<<(*it)[i]<<","; //writing data into the file
		}
		out<<(*it)[7]<<"\n";//writing the newline into the file    
	}
	
	//closing the data into the file
	out.close();
	
	cout<<endl<<endl;
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"Passenger Details Updated Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	char ch;
	cout<<"\n\n\t\t\t\t\tEnter any key to continue::\t";
	cin>>ch;
	
	
}




















