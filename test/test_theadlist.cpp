#include "gtest.h"

#include "..\Headers\THeadList.h"

TEST(THeadList, can_create_headlist)
{
	ASSERT_NO_THROW(THeadList<int> classObj);
}

TEST(THeadList, headlist_after_creating_is_empty)
{
	THeadList<int> classObj;
	EXPECT_TRUE(classObj.IsEmpty());
}

TEST(THeadList, can_insert_first)
{
	THeadList<int> classObj;
	classObj.InsFirst(2);
	EXPECT_FALSE(classObj.IsEmpty());
}

//TEST(THeadList, can_insert_last)
//{
//	THeadList<int> classObj;
//	classObj.InsLast(2);
//	EXPECT_FALSE(classObj.IsEmpty());
//}

//TEST(THeadList, can_delete_first)
//{
//	THeadList<int> classObj;
//	classObj.InsFirst(2);
//	classObj.DelFirst();
//	EXPECT_TRUE(classObj.IsEmpty());
//}
//
//TEST(THeadList, can_delete_current)
//{
//	THeadList<int> classObj;
//	classObj.InsCurr(2);
//	classObj.DelCurr();
//	EXPECT_TRUE(classObj.IsEmpty());
//}
//
//TEST(THeadList, can_get_current_value)
//{
//	THeadList<int> classObj;
//	classObj.InsCurr(2);
//	ASSERT_EQ(2, classObj.GetCurrVal());
//}