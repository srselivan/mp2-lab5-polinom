#include "gtest.h"

#include "..\Headers\TPolinom.h"

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
	ASSERT_EQ(classObj.ToString(), "1*x^1*y^1*z^1");
}

TEST(TPolinom, can_copy_polinom)
{
	TPolinom classObj;
	classObj.AddMonom(TMonom(1, 1, 1, 1));
	classObj.AddMonom(TMonom(1, 2, 1, 1));
	TPolinom copy(classObj);
	ASSERT_EQ(copy.ToString(), "1*x^2*y^1*z^1+1*x^1*y^1*z^1");
}

TEST(TPolinom, can_sum_polinom)
{
	TPolinom classObj;
	classObj.AddMonom(TMonom(1, 1, 1, 1));
	classObj.AddMonom(TMonom(2, 1, 1, 1));

	TPolinom classObj1;
	classObj1.AddMonom(TMonom(-1, 1, 1, 1));
	classObj1.AddMonom(TMonom(2, 1, 1, 1));

	classObj = classObj + classObj1;
	ASSERT_EQ(classObj.ToString(), "4*x^1*y^1*z^1");
}

TEST(TPolinom, can_sub_polinom)
{
	TPolinom classObj;
	classObj.AddMonom(TMonom(1, 8, 4, 1));
	classObj.AddMonom(TMonom(24, 1, 6, 2));
	classObj.AddMonom(TMonom(-165, 5, 2, 1));

	TPolinom classObj1;
	classObj1.AddMonom(TMonom(1, 8, 4, 1));
	classObj1.AddMonom(TMonom(24, 1, 6, 2));
	classObj1.AddMonom(TMonom(-165, 5, 2, 1));

	classObj =classObj - classObj1;
	ASSERT_EQ(classObj.ToString(), "");
}

TEST(TPolinom, can_mul_by_const)
{
	TPolinom classObj;
	classObj.AddMonom(TMonom(1, 1, 1, 1));
	classObj.AddMonom(TMonom(2, 2, 3, 4));

	classObj = classObj * 2;
	ASSERT_EQ(classObj.ToString(), "4*x^2*y^3*z^4+2*x^1*y^1*z^1");
}