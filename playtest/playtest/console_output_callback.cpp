#include "console_output_callback.h"
#include <iostream>
#include <sstream>
using namespace playtest;

ConsoleOutputCallback::ConsoleOutputCallback()
	: mSuccess(true)
{
}

ConsoleOutputCallback::~ConsoleOutputCallback()
{
}

void ConsoleOutputCallback::Begin()
{
	std::cout << std::endl << "STARTS RUNNING TESTS" << std::endl;
	std::cout << std::endl;
}

void ConsoleOutputCallback::End()
{
}

void ConsoleOutputCallback::BeginTestSuite(const TestSuite* suite)
{
	std::cout << "[" << suite->GetName() << "]" << std::endl;
}
		
void ConsoleOutputCallback::EndTestSuite(const TestSuite* suite)
{
	std::cout << std::endl;
}
		
void ConsoleOutputCallback::BeginUnitTest(const TestSuite* suite, const UnitTest* test)
{
	std::cout << "\tRunning: " << test->GetName();
}

void ConsoleOutputCallback::EndUnitTest(const TestSuite* suite, const UnitTest* test)
{
	if(mFailures.empty()) {
		std::cout << " (OK)" << std::endl;
	} else {
		std::cout << " (FAILED) " << std::endl;
		for(size_t i = 0; i < mFailures.size(); ++i) {
			std::cout << mFailures[i] << std::endl;
		}
	}
	mFailures.clear();
}

void ConsoleOutputCallback::TestFailure(const TestSuite* suite, const UnitTest* test, const char* file, const char* message, long line)
{
	std::stringstream ss;
	ss << "\t" << message << ":" << std::endl << "\t" << file << "(" << line << ")";
	mFailures.push_back(ss.str());
	mSuccess = false;
}

bool ConsoleOutputCallback::Success() const
{
	return mSuccess;
}
