#include <etl/utils/noncopyable.hpp>

struct Test : private etl::utils::noncopyable
{};

int main()
{
	Test t1;
	Test t2 = t1;
	
	Test t3;
	t3 = t1;
}