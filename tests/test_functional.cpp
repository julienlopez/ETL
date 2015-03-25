#include <etl/utils/functional.hpp>

#include <gtest/gtest.h>

TEST(TestFunctional, NegatorWithLambda)
{
	auto is_even = [](int i){ return i%2 == 0; };
	EXPECT_TRUE(is_even(2));
	EXPECT_FALSE(is_even(3));
	auto is_odd = etl::utils::functional::negator<bool, int>(is_even);
	EXPECT_FALSE(is_odd(2));
	EXPECT_TRUE(is_odd(3));
}

namespace
{
	bool is_even_fct(int i)
	{
		return i % 2 == 0;
	}
}

TEST(TestFunctional, NegatorWithFreeFunction)
{
	auto is_odd = etl::utils::functional::negator<bool, int>(&is_even_fct);
	EXPECT_FALSE(is_odd(2));
	EXPECT_TRUE(is_odd(3));
}

TEST(TestFunctional, NegatorWithFreeFunctionAndLValueInt)
{
	auto is_odd = etl::utils::functional::negator<bool, int>(&is_even_fct);
	const int i = 2;
	EXPECT_FALSE(is_odd(i));
	EXPECT_TRUE(is_odd(3));
}

TEST(TestFunctional, NegateWithFreeFunction)
{
	auto is_odd = etl::utils::functional::negate(&is_even_fct);
	EXPECT_FALSE(is_odd(2));
	EXPECT_TRUE(is_odd(3));
}

TEST(TestFunctional, NegatorWithFunctorObject)
{
	struct is_even_functor
	{
		bool operator()(int i) const
		{
			return i % 2 == 0;
		}
	};
	EXPECT_TRUE(is_even_functor()(2));
	EXPECT_FALSE(is_even_functor()(3));
	auto is_odd = etl::utils::functional::negator<bool, int>(is_even_functor());
	EXPECT_FALSE(is_odd(2));
	EXPECT_TRUE(is_odd(3));
}