//function defination for modify driver details.

#include"Driver.h"

//function to modify the details of the driver

void Driver::modifyDriver()
{
	system("clear");
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<right<<setw(120)<<"M O D I F Y   D R I V E R"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	

	//variable for soring the choice from the user
	int  choice, val, id, wrong = 2,flag =0,valid;
	
	do
	{
		
		cout<<"\n\t\t\t\t\tEnter the Driver Id that you want to Modify\t";	
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
		
		
		
		
		valid = vald.idValidation(id);
		
		if(valid == 0)
		{
			cout<<"\n\t\t\t\t\t ERROR: Invalid Id\n";
		
		
		
			
			cout<<"\n\t\t\t\t\tDo You Want to Enter again?\n\
			\n\t\t\t\t\t[1] Continue\n\
			\n\t\t\t\t\t[2] Exit :: ";
				
			cin>>choice;
				
			if(choice == 2)
				return;
		}
		else
		{
			flag = 0;
		}
	 
		
	}while(flag !=0);
	
	
	//craeting object of if stream and opening file for read
	ifstream in;
	in.open("./DataBaseFiles/driver_details.txt");
	
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
		if(id == stoi(word))
		{
			do
			{	system("clear");
				cout<<"\n\n";
				//formatting
				cout<<"\n\n";
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				cout<<right<<setw(115)<<"M O D I F Y   P A S S E N G E R"<<endl<<endl;
				cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				
				
				cout<<"\n\t\t\t\t\tWhat details you want to Update"<<endl<<endl;
				cout<<"\n\t\t\t\t\t[1] Pan Number of Driver"<<endl;
				cout<<"\n\t\t\t\t\t[2] License Number of Driver"<<endl;
				cout<<"\n\t\t\t\t\t[3] First Name of Driver"<<endl;
				cout<<"\n\t\t\t\t\t[4] Last Name of Driver"<<endl;
				cout<<"\n\t\t\t\t\t[5] Age of Driver"<<endl;
				cout<<"\n\t\t\t\t\t[6] Gender of Driver"<<endl;
				cout<<"\n\t\t\t\t\t[7] Phone Number of Driver"<<endl;
				cout<<"\n\t\t\t\t\t[8] Driver Email ID"<<endl;
				cout<<"\n\t\t\t\t\t[9] Date of Birth of Driver"<<endl;
				cout<<"\n\t\t\t\t\t[0] Exit "<<endl;
				
				cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
				
				cout<<"\n\n\t\t\t\t\t\t Enter the choice: \t";
				cin>>choice;
				
				
				switch(choice)
				{
					case 1:
						v.push_back(word);//pushing back the element in to the vector
						//reading PAN Number
						getline(ss, word,',');
						do
						{	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
							cout<<"\n\t\t\t\t\tEnter the Pan Number::\t";
							string pan;
							cin>>pan;
							val = vald.uniquePan(pan);
							if(val == 1)
							{
								v.push_back(pan);
								//reading license no from the file
								getline(ss, word,',');
								v.push_back(word);
								
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
								break;
							}
						}while(val != 1);
						break;
					case 2:
						v.push_back(word);//pushing back the element in to the vector
						//reading PAN Number
						getline(ss, word,',');
						v.push_back(word);//pushing the PAN Number
						//reading license number
						getline(ss, word,',');
						
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						
						do
						{	
							cout<<"\n\t\t\t\t\tEnter the license Number::\t";
							string licenseNo;
							cin>>licenseNo;
							
							
							val = vald.licenseNoValidation(licenseNo);
							if(val == 1)
							{
								v.push_back(licenseNo);
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
								break;
							}
						}while(val != 1);
						break;
					case 3:
						v.push_back(word);//pushing back the element in to the vector
						//reading PAN Number
						getline(ss, word,',');
						v.push_back(word);//pushing the PAN Number
						//reading license number
						getline(ss, word,',');
						v.push_back(word);//pushing the LICENSE Number
						//reading first name
						getline(ss, word,',');
						
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						do
						{	
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
					case 4:
						v.push_back(word);//pushing back the element in to the vector
						//reading PAN Number
						getline(ss, word,',');
						v.push_back(word);//pushing the PAN Number
						//reading license number
						getline(ss, word,',');
						v.push_back(word);//pushing the LICENSE Number
						//reading first name 
						getline(ss, word,',');
						v.push_back(word);//pushing the first name
						//reading last name
						getline(ss, word,',');
						
						cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
						do
						{	
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
						
					case 5:
						v.push_back(word);//pushing back the element in to the vector
						//reading PAN Number
						getline(ss, word,',');
						v.push_back(word);//pushing the PAN Number
						//reading license number
						getline(ss, word,',');
						v.push_back(word);//pushing the LICENSE Number
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
							cout<<"\n\t\t\t\t\tEnter the Age of Driver::\t";
							string age;
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
							
							val = vald.ageValidation(stoi(age));
							if(val == 1)
							{
								v.push_back(age);
															
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
						
						
					case 6:
						v.push_back(word);//pushing back the element in to the vector
						//reading PAN Number
						getline(ss, word,',');
						v.push_back(word);//pushing the PAN Number
						//reading license number
						getline(ss, word,',');
						v.push_back(word);//pushing the LICENSE Number
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
						
						
					case 7:
						v.push_back(word);//pushing back the element in to the vector\
						//reading PAN Number
						getline(ss, word,',');
						v.push_back(word);//pushing the PAN Number
						//reading license number
						getline(ss, word,',');
						v.push_back(word);//pushing the LICENSE Number
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
							cout<<"\n\t\t\t\t\tEnter the Phone Number::\t";
							string phone;
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
		
							val = vald.mobileValidation(stoi(phone));
							if(val == 1)
							{
								v.push_back(phone);
								
								
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
						
						
					case 8:
						v.push_back(word);//pushing back the element in to the vector
						//reading PAN Number
						getline(ss, word,',');
						v.push_back(word);//pushing the PAN Number
						//reading license number
						getline(ss, word,',');
						v.push_back(word);//pushing the LICENSE Number
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
							cout<<"\n\t\t\t\t\tEnter the  Email of Driver::\t";
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
						
						
					case 9:
						v.push_back(word);//pushing back the element in to the vector
						//reading PAN Number
						getline(ss, word,',');
						v.push_back(word);//pushing the PAN Number
						//reading license number
						getline(ss, word,',');
						v.push_back(word);//pushing the LICENSE Number
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
						cout<<"\n\t\t\t\t\t\tEntered wrong choice\
							[1] Want to choose again\
							[2] Exit \t";
						cin>>wrong;
						break;
				}
			
			}while(wrong!=2);
			
			details.insert(v);
			v.clear();
			continue;
		}
		
		v.push_back(word);//pushing back the element in to the vector
		
		//reading PAN Number from the file
		getline(ss, word,',');
		v.push_back(word);//pushing the PAN Number
		
		//reading license number from the file
		getline(ss, word,',');
		v.push_back(word);//pushing the LICENSE Number
		
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
	//closing the file and data is stored into the file
	in.close();
	
	
	
	//creating the object of ofstream to write data into the file
	ofstream out;
	out.open("./DataBaseFiles/driver_details.txt");//opening the file
	
	
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
		
		for(int i=0; i<9; i++) 	//for(int i=0; i<(*it).size(); ++i)
		{
			out<<(*it)[i]<<","; //writing data into the file
		}
		out<<(*it)[9]<<"\n";//writing the newline into the file    
	}
	
	//closing the data into the file
	in.close();
	
	cout<<"\n\n\t\t\t\t\tDriver Details Updated Successfully"<<endl<<endl<<endl;
	cout<<"\n\t\t\t\t****************************************************************************************"<<endl;
	
	char chh;
	cout<<"\n\t\t\t\t\tEnter eny key to continue::\t";
	cin>>chh;
}




















