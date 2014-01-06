#pragma once
#ifndef _PLAYTEST_REPOSITORY_H_
#define _PLAYTEST_REPOSITORY_H_

#include <list>

namespace playtest
{
	class TestSuite;
	class UnitTest;

	typedef std::list<TestSuite*> TestSuiteList;

	//
	// 
	class Repository
	{
	protected:
		Repository();

	public:
		~Repository();

	public:
		//
		// @return A singleton instance of the test repository. Used by the unit test engine
		//	to store all the unit test instances to be executed.
		static Repository& Get();

	public:
		//
		// Adds a unit test in the supplied suite
		//
		// @param suiteName The name of the test suite
		// @param unitTest
		void AddUnitTest(const char* suiteName, UnitTest* unitTest);

		//
		// @return A list of all test suites
		inline const TestSuiteList& GetTestSuites() const {
			return mTestSuites;
		}

	private:
		TestSuiteList mTestSuites;
	};
}

#endif
