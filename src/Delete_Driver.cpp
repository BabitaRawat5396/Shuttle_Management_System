// function defination for deleting the driver 


#include"Driver.h"

//function to delete the data of the passenger
void Driver::deleteDriver()
{
	system("cls");

	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"D E L E T E    D R I V E R"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	//variable for soring the id from the user
	int flag, i, valid, choice ;
	
	int n;	//passenger Id
	
	
	do
	{
		
		cout<<"\n\t\t\t\t\tEnter the Driver Id that you want to Delete\t";	
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
		
		
		
		
		valid = vald.idValidation(n);
		
		if(valid == 0)
		{
			cout<<"\n\t\t\t\t\t ERROR: Invalid Id\n";
			
			
			flag = 1;
			
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
	
	
	cout<<endl<<endl;
	
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
		
		//if the id is equal to the one present in file  and we want to delete it
		if(n == stoi(word))
		{
			flag = 1; //to check data is present
			v.clear();//cleaning the vector
			continue;//skipping that entry that we want to delete
		}
		
		v.push_back(word);//pushing back the element in to the vector
		
		//reading PAN No name from the file
		getline(ss, word,',');
		v.push_back(word);
		
		//reading license No from the file
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
		
		details.insert(v);//inserting the fully vector in the set
		
		v.clear();//clearing the vector to store the nexr line of the file
	}
	//clsing the file and data is stored into the file
	in.close();
	
	if(flag == 0)
	{
		cout<<"\n\n\t\t\t\t\tThe given driver id does not present in Database."<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		return;
	}
	
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
	//method using auto keyword
	for(auto it = details.begin(); it!= details.end(); ++it)
	{
		
		for(i=0; i<9; i++) 	//for(int i=0; i<(*it).size(); ++i)
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
	cout<<setw(115)<<"Driver Record Deleted Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	char chh;
	cout<<"\n\t\t\t\t\tEnter any Key::\t";
	cin>>chh;
	
	
}



























