#include "..\gtest.h"

#include "..\..\Headers\TPolinom.h"

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom classObj);
}

TEST(TPolinom, polinom_after_creating_is_empty)
{
	TPolinom classObj;
	EXPECT_TRUE(classObj.IsEmpty());
}

TEST(TPolinom, can_add_monom)
{
	TPolinom classObj;
	TMonom m(1, 1, 1, 1);
	classObj.AddMonom(m);
	ASSERT_EQ(classObj, "1*x^1*y^1*z^1");
}

TEST(TPolinom, can_copy_polinom)
{
	TPolinom classObj;
	classObj.AddMonom(TMonom(1, 1, 1, 1));
	classObj.AddMonom(TMonom(2, 1, 1, 1));
	TPolinom copy(classObj);
	ASSERT_EQ(copy, "1*x^1*y^1*z^1+1*x^2*y^1*z^1");
}

TEST(TPolinom, can_sum_polinom)
{
	TPolinom classObj;
	classObj.AddMonom(TMonom(1, 1, 1, 1));
	classObj.AddMonom(TMonom(2, 1, 1, 1));

	TPolinom classObj1;
	classObj1.AddMonom(TMonom(1, 1, 1, 1));
	classObj1.AddMonom(TMonom(2, 1, 1, -1));

	classObj = classObj + classObj1;
	ASSERT_EQ(classObj, "2*x^1*y^1*z^1");
}

TEST(TPolinom, can_mul_by_const)
{
	TPolinom classObj;
	classObj.AddMonom(TMonom(1, 1, 1, 1));
	classObj.AddMonom(TMonom(1, 2, 1, 1));

	classObj = classObj * 2;
	ASSERT_EQ(classObj, "2*x^1*y^1*z^1+2*x^2*y^1*z^1");
}