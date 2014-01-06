#include <playtest/playtest.h>

TEST_SUITE(TestPointers)
{
	UNIT_TEST(PointerIsNull)
	{
		void* pointer = NULL;
		ASSERT_NULL(pointer);
	}

	UNIT_TEST(PointerIsNotNull)
	{
		int someValue = 0;
		void* pointer = (void*)((int*)&someValue);
		ASSERT_NOT_NULL(pointer);
	}
}
