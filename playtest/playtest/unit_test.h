#pragma once
#ifndef _PLAYTEST_UNIT_TEST_H_
#define _PLAYTEST_UNIT_TEST_H_

#include <string>

namespace playtest
{
	class TestSuite;

	//
	// Base class for the unit tests run in the test framework
	class UnitTest
	{
	public:
		UnitTest(const char* name, const char* file, const long line);
		virtual ~UnitTest();

	public:
		//
		// @return The name of the unit test
		inline const std::string& GetName() const {
			return mName;
		}

		//
		// @return The filename where the unit test is located
		inline const std::string& GetFile() const {
			return mFile;
		}

		//
		// @return The line where the unit test begins
		inline long GetLine() const {
			return mLine;
		}

	public:
		//
		// Run this test inside the supplied test suite
		// @param suite The test suite
		virtual void Run(TestSuite* suite) = 0;

	private:
		const std::string mName;
		const std::string mFile;
		const long mLine;
	};
}

#endif
