#include <playtest/playtest.h>

TEST_SUITE(TestBoolean)
{
	UNIT_TEST(IsTrue)
	{	
		const bool Boolean = true;
		ASSERT_TRUE(Boolean);
	}
	
	UNIT_TEST(IsFalse)
	{	
		const bool Boolean = false;
		ASSERT_FALSE(Boolean);
	}
}
