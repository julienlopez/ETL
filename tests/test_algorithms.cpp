#include <etl/utils/algorithms.hpp>
#include <etl/utils/functional.hpp>

#include <gtest/gtest.h>

TEST(TestAlgorithms, SplitContainers)
{
	std::vector<int> vec1 = {1, 2, 5, 3, 4, 0, 8, 9, 11, 7};
	std::vector<int> vec2;
	const auto original_size = vec1.size();
	auto is_even = [](int i){ return i%2 == 0; };
	etl::utils::algorithms::split_container(vec1, vec2, is_even);
	ASSERT_EQ(original_size, vec1.size() + vec2.size());
	ASSERT_EQ(vec1.size(), std::count_if(begin(vec1), end(vec1), etl::utils::functional::negator<bool, int>(is_even)));
	ASSERT_EQ(vec2.size(), std::count_if(begin(vec2), end(vec2), is_even));
}