#include <playtest/playtest.h>

TEST_SUITE(TestString)
{
	UNIT_TEST(StringEquals)
	{
		const std::string hello_world("Hello World");
		ASSERT_EQUALS(hello_world, std::string("Hello World"));
	}

	UNIT_TEST(StringNotEquals)
	{
		const std::string hello_world("Other Value");
		ASSERT_NOT_EQUALS(hello_world, std::string("Hello World"));
	}
}
