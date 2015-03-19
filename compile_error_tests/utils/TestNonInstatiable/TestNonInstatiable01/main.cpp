#include <etl/utils/noninstantiable.hpp>

struct Test : private etl::utils::noninstantiable
{};

int main()
{
	Test t1;
}