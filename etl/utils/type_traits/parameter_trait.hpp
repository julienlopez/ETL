#ifndef __PARAMETER_TRAIT_HPP__
#define __PARAMETER_TRAIT_HPP__

#include "namespace_type_traits.hpp"

#include <type_traits>

BEGIN_NAMESPACE_ETL

BEGIN_NAMESPACE_UTILS

BEGIN_NAMESPACE_TYPE_TRAITS

template<class T>
struct parameter_trait {
	using type = typename std::conditional<std::is_pointer<T>::value, T, typename std::add_lvalue_reference<T>::type>::type;
};

template<class T>
struct const_parameter_trait {
	using type = typename parameter_trait<typename std::add_const<T>::type>::type;
};

END_NAMESPACE_TYPE_TRAITS

END_NAMESPACE_UTILS

END_NAMESPACE_ETL

#endif //__PARAMETER_TRAIT_HPP__
