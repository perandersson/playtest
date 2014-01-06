#include "unit_test.h"
#include "test_suite.h"
using namespace playtest;

UnitTest::UnitTest(const char* name, const char* file, const long line)
	: mName(name), mFile(file), mLine(line)
{
}

UnitTest::~UnitTest()
{
}
