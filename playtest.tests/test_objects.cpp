#include <playtest/playtest.h>

TEST_SUITE(TestObjects)
{
	class MyObject
	{
	public:
		MyObject(int val) : mValue(val) {}
		~MyObject() {}

		//
		// "operator ==" is required for ASSERT_EQUALS to work
		inline bool operator == (const MyObject& other) const {
			return mValue == other.mValue;
		}

		//
		// "operator !=" is required for the ASSERT_NO_EQUALS to work
		inline bool operator != (const MyObject& other) const {
			return mValue != other.mValue;
		}

	private:
		int mValue;
	};

	UNIT_TEST(ObjectsHaveTheSameValue)
	{
		const int value = 1011;
		const MyObject obj1(value);
		const MyObject obj2(value);

		ASSERT_EQUALS(obj1, obj2);
	}
	
	UNIT_TEST(ObjectsAsPointersHaveTheSameValue)
	{
		const int value = 1011;
		MyObject* obj1 = new MyObject(value);
		MyObject* obj2 = new MyObject(value);

		ASSERT_EQUALS(*obj1, *obj2);
		delete obj1;
		delete obj2;
	}

	UNIT_TEST(ObjectsHaveNotTheSameValue)
	{
		const MyObject obj1(101);
		const MyObject obj2(102);

		ASSERT_NOT_EQUALS(obj1, obj2);
	}

	UNIT_TEST(ObjectsAsPointersHaveNotTheSameValue)
	{
		MyObject* obj1 = new MyObject(101);
		MyObject* obj2 = new MyObject(102);

		ASSERT_NOT_EQUALS(*obj1, *obj2);
		delete obj1;
		delete obj2;
	}
}
