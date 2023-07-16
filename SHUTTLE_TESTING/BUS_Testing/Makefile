all: testBus

testBus:  Bus_Def.o Validation_def.o Check_Bus.o TestBus.o
	g++ Shuttle.h Bus.h Bus_Def.cpp  Check_Bus.cpp TestBus.cpp -lcppunit -o testBus


Bus_Def.o: Bus_Def.cpp
		g++ -c Bus.h Bus_Def.cpp

Check_Bus.o: Check_Bus.cpp
		g++ -c Bus.h Check_Bus.cpp


TestBus.o: TestBus.cpp
		g++ -c TestBus.cpp

clean:
	rm *.o
	rm *.gch
