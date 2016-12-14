#include"iostream"
#include <fstream>
#include <iostream>
#include <sstream>
#include<vector>
#include <algorithm> 
#include <math.h> 
#include"Command.h"
#include"UnitTest.h"
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include<cppunit/XmlOutputter.h>
#include <cppunit/extensions/HelperMacros.h>
#include <assert.h>
#include "windows.h" 

using namespace std;


/*
int CompressData(const BYTE* abSrc, int nLenSrc, BYTE* abDst, int nLenDst)
{
z_stream zInfo = { 0 };
zInfo.total_in = zInfo.avail_in = nLenSrc;
zInfo.total_out = zInfo.avail_out = nLenDst;
zInfo.next_in = (BYTE*)abSrc;
zInfo.next_out = abDst;

int nErr, nRet = -1;
nErr = deflateInit(&zInfo, Z_DEFAULT_COMPRESSION); // zlib function
if (nErr == Z_OK) {
nErr = deflate(&zInfo, Z_FINISH);              // zlib function
if (nErr == Z_STREAM_END) {
nRet = zInfo.total_out;
}
}
deflateEnd(&zInfo);    // zlib function
return(nRet);
}
*/
int main(int argc, char *argv[])
{

	//ifstream infile(argv[1]);


	ifstream infile("abc.txt");
	if (!infile.is_open()) {
		cout << "Could not open file\n";

	}

	string num[40][3];


	while (infile.good())
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 3; j++) {

				infile >> num[i][j];
			}

		}

	}

	double valueArr[40][3];

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 3; j++) {
			valueArr[i][j] = atof(num[i][j].c_str());

		}
	}

	Command c;

	c.distanceCalculate(valueArr);



	CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();
	CppUnit::TextUi::TestRunner runner;

	std::ofstream fs("Result.txt");
	CppUnit::XmlOutputter*outputter = new CppUnit::XmlOutputter(&runner.result(), fs);
	runner.setOutputter(outputter);

	runner.addTest(suite);
	bool wasSucessful = runner.run();

	return wasSucessful ? 0 : 1;


}

void UnitTest::testMinDis() {


}
void UnitTest::testLine1() {

	Command c;

	CPPUNIT_ASSERT(0, c.getLine1());

}
void UnitTest::testLine2() {

	Command c;

	CPPUNIT_ASSERT(22, c.getLine2());
}


