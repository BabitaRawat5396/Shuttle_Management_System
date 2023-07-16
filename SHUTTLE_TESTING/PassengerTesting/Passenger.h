#include"Person.h"

class Passenger:public Person
{
	public:
		//setters
		void setPassengerId(int);
		
		//getters
		int getPassengerId();
		
		//constructors
		Passenger();
		Passenger(int, string,string, int, char, long int , string, int, int, int);
		
		//manipulation functions
		void addNewPassenger();
		void deletePassenger();
		void blockPassenger();
		void listDetails();
		int checkPassenger(int = 0);
		void modifyPassenger();
		int generatePassId();

	private:
		int passengerId;
		Validation vald;
};


//class for passenger menu
class PassengerMenu
{
	public:
		void passengerMenu(int);
		PassengerMenu();
			
	private:
		int userChoice;
		int wrongChoice;
		
		
};


//class login
class PassengerLogin
{
	private:
		string email;
		string password;
		PassengerMenu pass_menu;
		Validation valid;
		
	public:
		//setter
		void setEmailId(string);
		void setPassword(string);
		
		//getter
		string getEmailId();
		string getPassword();
		
		//login password
		
		void passengerLogin();
};


class PassengerTravelDetails
{
	public:
		//Getters
		int getRouteId();
		int getPassengerId();
		string getPickPoint();
		string getDropPoint();
		
		//Setters
		void setRouteId(int);
		void setPassengerId(int);
		void setPickPoint(string);
		void setDropPoint(string);
		
		
	private:
		int routeId;
		int passengerId;
		string pickPoint;
		string dropPoint;
};


class Booking
{
	public:
		//Booking();
		
		void newBooking(int=0);
		void listPreviousBooking(int = 0);
		int generateBookingId();
		
		int getBookingId();
		void setBookingId();
		
	private:
		int bookingId;
		Validation valid;

};












