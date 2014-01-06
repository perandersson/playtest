#pragma once
#ifndef _PLAYTEST_TEST_EXCEPTION_H_
#define _PLAYTEST_TEST_EXCEPTION_H_

#include <exception>
#include <string>

namespace playtest
{
	class UnitTest;

	//
	// Base class for test failures inside the test framework
	class TestException : public std::exception
	{
	public:
		TestException(UnitTest* test, const char* file, const char* message, long line);
		~TestException();

		//
		// @return The unit test where the exception originates from
		inline const UnitTest* GetTest() const {
			return mTest;
		}

		//
		// @return The filename where the exception originates from
		inline const std::string& GetFile() const {
			return mFile;
		}

		//
		// @return The exception message
		inline const std::string& GetMessage() const {
			return mMessage;
		}

		//
		// @return The line where the exception is thrown from
		inline long GetLine() const {
			return mLine;
		}

	private:
		const UnitTest* mTest;
		const std::string mFile;
		const std::string mMessage;
		const long mLine;
	};
}

#endif
