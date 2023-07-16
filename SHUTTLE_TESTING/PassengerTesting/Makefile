all: testPassenger

testPassenger: Person_Def.o Passenger_Def.o Validation_def.o Check_Passenger.o Date.o TestPassenger.o
	g++ Shuttle.h Person.h Passenger.h Person_Def.cpp Passenger_Def.cpp Validation_def.cpp Check_Passenger.cpp Date.cpp TestPassenger.cpp -lcppunit -o testPassenger

Date.o: Date.cpp
		g++ -c Shuttle.h Date.cpp

Person_Def.o: Person_Def.cpp
		g++ -c Person.h Person_Def.cpp

Passenger_Def.o: Passenger_Def.cpp
		g++ -c Passenger.h Passenger_Def.cpp

Check_Passenger.o: Check_Passenger.cpp
		g++ -c Passenger.h Check_Passenger.cpp

Validation_def.o: Validation_def.cpp
		g++ -c Shuttle.h Validation_def.cpp

TestPassenger.o: TestPassenger.cpp
		g++ -c TestPassenger.cpp

clean:
	rm *.o
	rm *.gch
