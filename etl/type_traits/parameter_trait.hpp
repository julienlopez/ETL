/*
     Copyright (C) 2001-2011 Dynalogic

*/

#ifndef PARAMETER_TRAIT_H
#define PARAMETER_TRAIT_H

#include <boost/type_traits.hpp>

namespace etl {

namespace type_traits {

template<class T> struct parameter_trait {
	typedef typename boost::conditional<boost::is_pointer<T>::value, T, typename boost::add_reference<T>::type>::type type;
};

template<class T> struct const_parameter_trait {
	typedef typename parameter_trait<typename boost::add_const<T>::type>::type type;
};

}
}

#endif //PARAMETER_TRAIT_H
