#ifndef __NONCOPIABLE_HPP__
#define __NONCOPIABLE_HPP__

#include "namespace_utils.hpp"

BEGIN_NAMESPACE_ETL

BEGIN_NAMESPACE_UTILS

class noncopiable
{
protected:
	noncopiable() = default;

	noncopiable(const noncopiable&) = delete;

	noncopiable& operator=(const noncopiable&) = delete;

	noncopiable(noncopiable&&) = default;

	noncopiable& operator=(noncopiable&&) = default;
};

END_NAMESPACE_UTILS

END_NAMESPACE_ETL

#endif //__NONCOPIABLE_HPP__

