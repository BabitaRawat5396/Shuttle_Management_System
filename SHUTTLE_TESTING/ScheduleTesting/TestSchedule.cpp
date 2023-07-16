#include <bits/stdc++.h>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "Schedule.h"

using namespace CppUnit;
using namespace std;


//Test Class For Schedule Declaration 
class ScheduleTest : public CPPUNIT_NS::TestFixture 
{
	//Creating a Suite for Schedule test class
	CPPUNIT_TEST_SUITE( ScheduleTest); 
	CPPUNIT_TEST( testScheduleId );
	CPPUNIT_TEST( testScheduleDate );
	//Ending the suite for Schedule test class
	CPPUNIT_TEST_SUITE_END();
		
	public:	
		void setUp();
		void tearDown();	
	protected:
		void testScheduleId();
		void testScheduleDate();
};



// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( ScheduleTest); 
// method to test check Schedule by Id is returning correct value
void ScheduleTest::testScheduleId()
{ 
	// Create a Schedule object
	Schedule schedule;

	//Note 6
	//Sunny Cases
	CPPUNIT_ASSERT_EQUAL( 1 , schedule.checkSchedule(78993));
	CPPUNIT_ASSERT_EQUAL( 1 , schedule.checkSchedule(78994));
	//Rainy Cases
	CPPUNIT_ASSERT_EQUAL( 0 , schedule.checkSchedule(12345));
	CPPUNIT_ASSERT_EQUAL( 0 , schedule.checkSchedule(00000));	
}

// method to test check Schedule by date returning correct value
void ScheduleTest::testScheduleDate()
{ 
	// Create a Schedule object
	Schedule schedule;
	//Note 6
	//sunny cases
	CPPUNIT_ASSERT_EQUAL( 1 , schedule.checkScheduleDate("8/10/2022"));
	CPPUNIT_ASSERT_EQUAL( 1 , schedule.checkScheduleDate("9/10/2022"));
	CPPUNIT_ASSERT_EQUAL( 1 , schedule.checkScheduleDate("10/10/2022"));
	
	//Rainy Cases
	CPPUNIT_ASSERT_EQUAL( 0 , schedule.checkScheduleDate("10/10/2023"));
	CPPUNIT_ASSERT_EQUAL( 0 , schedule.checkScheduleDate("15/10/2024"));
	CPPUNIT_ASSERT_EQUAL( 0 , schedule.checkScheduleDate("13/10/2023"));	
	CPPUNIT_ASSERT_EQUAL( -1 , schedule.checkScheduleDate("10/10/2021"));
	CPPUNIT_ASSERT_EQUAL( -1 , schedule.checkScheduleDate("15/10/2020"));
	CPPUNIT_ASSERT_EQUAL( -1 , schedule.checkScheduleDate("6/10/2022"));	
}

void ScheduleTest::setUp()
{
}

void ScheduleTest::tearDown()
{
}


int main(int argc, char *argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener(&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener(&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("cppScheduleResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
