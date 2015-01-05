#include <etl/utils/type_traits/parameter_trait.hpp>

#include <type_traits>

using etl::utils::type_traits::parameter_trait;
using etl::utils::type_traits::const_parameter_trait;

struct Test
{
    Test() = default;
    Test(const Test&) = default;
};

static_assert(std::is_same<parameter_trait<int>::type, int&>::value, "parameter_trait<int>::type == int&");
static_assert(std::is_same<parameter_trait<int*>::type, int*>::value, "parameter_trait<int*>::type == int*");

static_assert(std::is_same<parameter_trait<Test>::type, Test&>::value, "parameter_trait<Test>::type == Test&");
static_assert(std::is_same<parameter_trait<Test*>::type, Test*>::value, "parameter_trait<Test*>::type == Test*");