#include <playtest/playtest.h>

TEST_SUITE(TestFailure)
{
	UNIT_TEST(FailureNotReached)
	{
		int value = 10;
		if(value != 10)
			ASSERT_FAIL("Should not get here!");
	}

	UNIT_TEST(FailureReached)
	{
		try {
			ASSERT_FAIL("Fail message");
		} catch(playtest::TestException& e) {
			ASSERT_EQUALS(e.GetMessage(), std::string("Fail message"));
			ASSERT_TRUE(e.GetFile().find("test_failure.cpp") != std::string::npos);
			ASSERT_NOT_NULL(e.GetTest());
			return;
		}
	}
}
