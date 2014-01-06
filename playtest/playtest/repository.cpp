#include "repository.h"
#include "test_suite.h"
using namespace playtest;

Repository::Repository()
{
}

Repository::~Repository()
{
}

Repository& Repository::Get()
{
	static Repository r;
	return r;
}

void Repository::AddUnitTest(const char* suiteName, UnitTest* unitTest)
{
	TestSuiteList::iterator it = mTestSuites.begin();
	TestSuiteList::iterator end = mTestSuites.end();
	for(; it != end; ++it) {
		TestSuite* suite = *it;
		if(suite->GetName() == std::string(suiteName)) {
			suite->AddUnitTest(unitTest);
			return;
		}
	}

	TestSuite* suite = new TestSuite(std::string(suiteName));
	mTestSuites.push_back(suite);
	suite->AddUnitTest(unitTest);
}
