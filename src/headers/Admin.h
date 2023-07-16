#include"Person.h"

//class Admin
class Admin: public Person
{
	
	public:
			
		//constructors
		Admin();
		Admin(string,string,string, int, char, long int ,int,int,int );
		
				
};


//class for admin menu
class AdminMenu
{
	public:
		void adminMenu();
		AdminMenu();
		
	private:
		int userChoice;
		int wrongChoice;
		
		
};


//class login
class AdminLogin
{
	private:
		string email;
		string password;
		
		AdminMenu admin_menu;
		Validation valid;
	public:
		//setter
		void setEmailId(string);
		void setPassword(string);
		
		//getter
		string getEmailId();
		string getPassword();
		
		//login password
		void Admin_Login();
		
};


class AdminPassMenu:public Menu
{
	public:
		void adminPassMenu();
		virtual void busMenu();
		virtual void routeMenu();
		//virtual void adminPassMenu();
		virtual void driverMenu();
		virtual void scheduleMenu();
		
		
	private:
		int userChoice = -1;
		int wrongChoice = 1;

};














