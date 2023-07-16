
#include"Passenger.h"

//function to delete the data of the passenger
void Passenger::deletePassenger()
{
	system("cls");

	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"D E L E T E    P A S S E N G E R"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	//variable for storing the id from the user
	int flag, i,check, valid, choice ;
	
	int n;	//passenger Id
	
	do
	{
		
		cout<<"\n\t\t\t\t\tEnter the Passenger Id that you want to Delete\t";	
		cin>>n;
		
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
				cin>>n;
			}
		}
		
		flag =0;
		
		check = checkPassenger(n);
		valid = vald.idValidation(n);
		
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
	
	
	cout<<endl<<endl;
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
		
		//if the id is equal to the file and we want to delete it
		if(n == stoi(word))
		{
			flag = 1; //to check data is present
			v.clear();//cleaning the vector
			continue;//skipping that entry thatwe want to delete
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
	
	if(flag == 0)
	{
		cout<<"\n\n\t\t\t\t\tThe given passenger id does not present in Database."<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		return;
	}
	
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
	for(auto it = details.begin(); it!= details.end(); ++it)
	{
		
		for(i=0; i<7; i++) 	//for(int i=0; i<(*it).size(); ++i)
		{
			out<<(*it)[i]<<",";//writing data into the file
		}
		out<<(*it)[i]<<"\n";//writing the newline into the file    
	}
	
	//closing the  file
	out.close();
	
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"Passenger Record Deleted Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	char chh;
	cout<<"\n\t\t\t\t\tEnter any key to conitnue::\t";
	cin>>chh;
	
	
}



























