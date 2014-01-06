#pragma once
#ifndef _PLAYTEST_CONSOLE_OUTPUT_CALLBACK_H_
#define _PLAYTEST_CONSOLE_OUTPUT_CALLBACK_H_

#include "test_callback.h"
#include <vector>
#include <string>

namespace playtest
{
	class ConsoleOutputCallback : public ITestCallback
	{
	public:
		ConsoleOutputCallback();
		virtual ~ConsoleOutputCallback();

	public:
		virtual void Begin();
		virtual void End();
		virtual void BeginTestSuite(const TestSuite* suite);
		virtual void EndTestSuite(const TestSuite* suite);
		virtual void BeginUnitTest(const TestSuite* suite, const UnitTest* test);
		virtual void EndUnitTest(const TestSuite* suite, const UnitTest* test);
		virtual void TestFailure(const TestSuite* suite, const UnitTest* test, const char* file, const char* message, long line);
		virtual bool Success() const;

	private:
		std::vector<std::string> mFailures;
		bool mSuccess;
	};
}

#endif
