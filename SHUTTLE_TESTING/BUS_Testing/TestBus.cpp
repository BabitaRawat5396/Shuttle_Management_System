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

#include "Bus.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

//Test Class For Bus Declaration 
class BusTest : public CppUnit::TestFixture 
{
	//Creating a Suite for passenger test class
	CPPUNIT_TEST_SUITE( BusTest ); 
	CPPUNIT_TEST( testBus );
	
	
	//Ending the suite for passenger test class
	CPPUNIT_TEST_SUITE_END();

	public:
	    void setUp(void);
	    void tearDown(void);

	protected:
	    void  testBus(void);

};
//-----------------------------------------------------------------------------
CPPUNIT_TEST_SUITE_REGISTRATION( BusTest); 

 // Note 5
// method to test check passenger is returning correct value
void BusTest::testBus()
{ 
	
	//Note 6
	//Sunny Cases
	CPPUNIT_ASSERT_EQUAL( 1 , checkBus(23454));	//checkBus is global function
	CPPUNIT_ASSERT_EQUAL( 1 , checkBus(23452));
	

	//Rainy Cases
	CPPUNIT_ASSERT_EQUAL( 0 , checkBus(12345));
	CPPUNIT_ASSERT_EQUAL( 0 , checkBus(15648));
	
}


void BusTest::setUp(void)
{

}

void BusTest::tearDown(void)
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
    ofstream xmlFileOut("cppBusResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
