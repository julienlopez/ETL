#ifndef __NONINSTANCIABLE_HPP__
#define __NONINSTANCIABLE_HPP__

#include "noncopiable.hpp"

BEGIN_NAMESPACE_ETL

BEGIN_NAMESPACE_UTILS

/**
  * \brief Defines a non-instantiable class.
  */
class noninstantiable : private noncopiable
{
protected:
	noninstantiable() = delete;
};

END_NAMESPACE_UTILS

END_NAMESPACE_ETL

#endif //__NONINSTANCIABLE_HPP__
