//function to delete bus details from the database for bus data manipulation

#include"Bus.h"

void Bus::deleteBus()
{
	//variable for soring the ubs no from the user
	int flag=0, i;
	int shuttleNo;
	
	
	
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		cout<<"\n\t\t\t\t\tEnter the Shuttle Number that you want to delete: \t";
	
	cin>>shuttleNo;
	
	//creating object of if stream and opening file for read
	ifstream in;
	in.open("./DataBaseFiles/Bus_details.txt");


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
		
		//reading the shuttle number from the file
		getline(ss, word,',');
		
		//if the SHUTTLE number is equal to shuttle no in file and is to be deleted
		if( shuttleNo == stoi(word) )
		{

			flag = 1; 	//to check data is present
			v.clear();	//cleaning the vector
			continue;	//skipping that entry that has to be delete
		}
		//else
		v.push_back(word);//pushing back the element in to the vector
		
		//reading bus Number from the file
		getline(ss, word,',');
		v.push_back(word);
		
		
		//reading RC Number from the file
		getline(ss, word,',');
		v.push_back(word);

		//reading vehicle insurance from the file
		getline(ss, word,',');
		v.push_back(word);
		
		//reading total seats number from the file
		getline(ss, word,',');
		v.push_back(word);
		
		//reading booked seats number from the file
		getline(ss, word,',');
		v.push_back(word);
		
		details.insert(v);	//inserting the vector in the set	//complete line of bus details
		
		v.clear();//clearing the vector to store the next line of the file
	}
	//closing the file after updated data is stored into the set container
	in.close();
	
	if(flag == 0)
	{
		
		
		cout<<"\n\t\t\t\t\tEntered Shuttle Number does not exist in Database<<"<<endl<<endl;
		
		
		return;
	}
	

	
	//creating the object of ofstream to write data into the file
	ofstream out;
	out.open("./DataBaseFiles/Bus_details.txt");//opening the file
	if(!out.is_open())
	{
		cout<<"\n\t\t\t\t\tCannot open File";
		exit(0);
	}

	
	//using auto keyword
	for(auto it = details.begin(); it!= details.end(); it++)
	{

	
		
		for(i=0; i<5; i++) 	//for(int i=0; i<(*it).size(); ++i)	//for( auto i = v ) { out << it->v[i] << "," ; }
		{

			out<<(*it)[i]<<",";	//writing data into the file
		}

		out<<(*it)[i]<<endl;	//writing the newline into the file 

	}
	
	
	
	cout<<"\n\n\t\t\t\t\tBus Details Deleted Successfully"<<endl<<endl;
	cout<<endl<<endl<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	
	//closing file acess to the out object
	out.close();
	
	
}



