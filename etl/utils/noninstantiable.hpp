#ifndef __NONINSTANTIABLE_HPP__
#define __NONINSTANTIABLE_HPP__

#include "noncopyable.hpp"

namespace etl {

namespace utils {

/**
  * \brief Defines a non-instantiable class.
  */
class noninstantiable : private noncopyable
{
protected:
	noninstantiable() = delete;
	~noninstantiable() = delete;
};

} //utils

} //etl

#endif //__NONINSTANCIABLE_HPP__
