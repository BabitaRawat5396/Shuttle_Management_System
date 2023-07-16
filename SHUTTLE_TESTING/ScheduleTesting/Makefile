all: testSchedule

testSchedule: Schedule_Def.o Validation_def.o time_def.o Check_Schedule.o Check_Sche_Date.o Date.o TestSchedule.o
	g++ Shuttle.h Schedule.h Validation_def.cpp Check_Schedule.cpp Check_Sche_Date.cpp Date.cpp time_def.cpp TestSchedule.cpp -lcppunit -o testSchedule

Date.o: Date.cpp
		g++ -c Shuttle.h Date.cpp

Schedule_Def.o: Schedule_Def.cpp
		g++ -c Schedule.h Schedule_Def.cpp

Check_Schedule.o: Check_Schedule.cpp
		g++ -c Passenger.h Check_Schedule.cpp

Check_Sche_Date.o: Check_Sche_Date.cpp
		g++ -c Schedule.h Check_Sche_Date.cpp

Validation_def.o: Validation_def.cpp
		g++ -c Shuttle.h Validation_def.cpp

time_def.o: time_def.cpp
		g++ -c time_def.cpp

TestSchedule.o: TestSchedule.cpp
		g++ -c TestSchedule.cpp

clean:
	rm *.o
	rm *.gch
