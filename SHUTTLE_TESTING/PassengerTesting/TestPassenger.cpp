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

#include "Passenger.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

//Test Class For Passenger Declaration 
class PassengerTest : public CppUnit::TestFixture 
{
	//Creating a Suite for passenger test class
	CPPUNIT_TEST_SUITE( PassengerTest ); 
	CPPUNIT_TEST( testPassengerId );
	
	
	//Ending the suite for passenger test class
	CPPUNIT_TEST_SUITE_END();

	public:
	    void setUp(void);
	    void tearDown(void);

	protected:
	    void  testPassengerId(void);

};
//-----------------------------------------------------------------------------
CPPUNIT_TEST_SUITE_REGISTRATION( PassengerTest); 

 // Note 5
// method to test check passenger is returning correct value
void PassengerTest::testPassengerId()
{ 
	// Create a Passenger object
	Passenger pass;

	//Note 6
	//Sunny Cases
	CPPUNIT_ASSERT_EQUAL( 1 , pass.checkPassenger(23454));
	CPPUNIT_ASSERT_EQUAL( 1 , pass.checkPassenger(23452));
	

	//Rainy Cases
	CPPUNIT_ASSERT_EQUAL( 0 , pass.checkPassenger(12345));
	CPPUNIT_ASSERT_EQUAL( 0 , pass.checkPassenger(15648));
	
}


void PassengerTest::setUp(void)
{

}

void PassengerTest::tearDown(void)
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
    ofstream xmlFileOut("cppPassengerResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
