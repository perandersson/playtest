#pragma once
#ifndef _PLAYTEST_TEST_CALLBACK_H_
#define _PLAYTEST_TEST_CALLBACK_H_

#include "test_suite.h"
#include "unit_test.h"

namespace playtest
{
	//
	// 
	class ITestCallback
	{
	public:
		virtual ~ITestCallback() {}

	public:
		//
		// Method invoked when the test application begins it's execution
		virtual void Begin() = 0;

		//
		// Method invoked when the test application ends it's execution
		virtual void End() = 0;

		//
		// Method invoked when a test suite begins it's execution
		// @param suite
		virtual void BeginTestSuite(const TestSuite* suite) = 0;
		
		//
		// Method invoked when a test suite has completed it's execution
		// @param suite
		virtual void EndTestSuite(const TestSuite* suite) = 0;

		//
		// Method invoked when a unit test begins it's execution
		// @param suite
		// @param test
		virtual void BeginUnitTest(const TestSuite* suite, const UnitTest* test) = 0;

		//
		// Method invoked when a unit test has completed it's execution
		//
		// @param suite
		// @param test
		virtual void EndUnitTest(const TestSuite* suite, const UnitTest* test) = 0;

		//
		// Method invoked when a unit test fails.
		virtual void TestFailure(const TestSuite* suite, const UnitTest* test, const char* file, const char* message, long line) = 0;

		//
		// @return
		virtual bool Success() const = 0;
	};
}

#endif
