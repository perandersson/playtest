#pragma once
#ifndef _PLAYTEST_TEST_SUITE_H_
#define _PLAYTEST_TEST_SUITE_H_

#include <string>
#include <list>
#include <vector>

namespace playtest
{
	class UnitTest;
	class ITestCallback;

	class TestSuite
	{
		typedef std::list<UnitTest*> UnitTests;

	public:
		//
		// @param name The name of this test suite
		TestSuite(const std::string& name);
		~TestSuite();

		//
		// Run all tests located in this test-suite
		//
		// @param callback
		void RunUnitTests(ITestCallback* callback);

		//
		// Add a unit test into this test-suite
		//
		// @param test The unit test we want to add into this test suite
		void AddUnitTest(UnitTest* test);

		//
		// @return The name of this test suite
		inline const std::string& GetName() const {
			return mName;
		}

	private:
		UnitTests mUnitTests;
		std::string mName;
	};
}

#endif
