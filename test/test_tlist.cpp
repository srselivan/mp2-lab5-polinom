#include "gtest.h"

#include "..\Headers\TList.h"

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> classObj);
}

TEST(TList, list_after_creating_is_empty)
{
	TList<int> classObj;
	EXPECT_TRUE(classObj.IsEmpty());
}

TEST(TList, can_insert_last)
{
	TList<int> classObj;
	classObj.InsFirst(2);
	EXPECT_FALSE(classObj.IsEmpty());
}

TEST(TList, can_insert_first)
{
	TList<int> classObj;
	classObj.InsLast(2);
	EXPECT_FALSE(classObj.IsEmpty());
}

TEST(TList, can_delete_first)
{
	TList<int> classObj;
	classObj.InsFirst(2);
	classObj.DelFirst();
	EXPECT_TRUE(classObj.IsEmpty());
}

TEST(TList, can_delete_current)
{
	TList<int> classObj;
	classObj.InsCurr(2);
	classObj.DelCurr();
	EXPECT_TRUE(classObj.IsEmpty());
}

TEST(TList, can_get_current_value)
{
	TList<int> classObj;
	classObj.InsCurr(2);
	ASSERT_EQ(2, classObj.GetCurrVal());
}