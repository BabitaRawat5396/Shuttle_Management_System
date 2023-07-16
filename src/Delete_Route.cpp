#include"Route.h"

//function to delete the data of the route
void Route::deleteRoute()
{
	system("cls");
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(115)<<"D E L E T E  R O U T E"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	//variable for soring the id from the user
	int n, flag = 0, i;
	
	
	cout<<"\n\t\t\t\t\tEnter the Route Id that you want to delete::\t";	
	cin>>n;
	
	//craeting object of if stream and opening file for read
	ifstream in;
	in.open("./DataBaseFiles/Route.txt");
	
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
		
		//reading Shuttle Number from the file
		getline(ss, word,',');
		v.push_back(word);
		
		
		//reading Source from the file
		getline(ss, word,',');
		v.push_back(word);

		//reading Desitnation from the file
		getline(ss, word,',');
		v.push_back(word);
		
		details.insert(v);//inserting the fully vector in the set
		
		v.clear();//clearing the vector to store the nexr line of the file
	}
	
	//clsing the file and data is stored into the file
	in.close();
	
	if(flag == 0)
	{
		cout<<"\n\n\t\t\t\t\tThe given Route id does not present in Database."<<endl<<endl;
		cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
		
		char chh;
		cout<<"\n\t\t\t\t\tEnter any Key to continue::\t";
		cin>>chh;
		return;
	}
	
	//creating the object of ofstream to write data into the file
	ofstream out;
	out.open("./DataBaseFiles/Route.txt");//opening the file
	
	
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
		for(i=0; i<3; i++) 	//for(int i=0; i<(*it).size(); ++i)
		{
			out<<(*it)[i]<<",";//writing data into the file
		}
		out<<(*it)[i]<<"\n";//writing the newline into the file   
	

	
	}
	
	//closing the data into the file
	out.close();
	
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	
	//formatting
	cout<<"\n\n";
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	cout<<setw(100)<<"Route Record Deleted Successfully"<<endl<<endl;
	cout<<setw(30)<<" "<<setfill('*')<<setw(150)<<"*"<<setfill(' ')<<endl<<endl;
	
	
	char chh;
	cout<<"\n\t\t\t\t\tEnter any Key to continue::\t";
	cin>>chh;
	
	return;
	
}





















