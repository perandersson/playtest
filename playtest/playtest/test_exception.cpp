#include "test_exception.h"
#include "unit_test.h"
using namespace playtest;

TestException::TestException(UnitTest* test, const char* file, const char* message, long line)
	: mTest(test), mFile(file), mMessage(message), mLine(line)
{}

TestException::~TestException()
{}
