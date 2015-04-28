#ifndef __DEFAULTFACTORYERRORPOLICY_HPP__
#define __DEFAULTFACTORYERRORPOLICY_HPP__

#include "type_traits/parameter_trait.hpp"

#include <cassert>
#include <stdexcept>

namespace etl {

namespace utils {

template<class IdentifierType, class ProductType>
class exception_factory_error_policy
{
public:
	class Exception : public std::exception
	{
	public:
        Exception(typename type_traits::const_parameter_trait<IdentifierType>::type id) : std::exception(), m_unknownId(id)
		{}
		
		virtual const char* what()
		{
            return "Unknown type given to the factory.";
		}
		
        typename type_traits::const_parameter_trait<IdentifierType>::type getId() const
		{
			return m_unknownId;
		}
		
	private:
		IdentifierType m_unknownId;
	};
	
protected:
    static ProductType* onUnknownType(typename type_traits::const_parameter_trait<IdentifierType>::type id)
	{
		throw Exception(id);
        return nullptr;
	}
};

template<class IdentifierType, class ProductType>
class assertion_factory_error_policy
{
protected:
    static ProductType onUnknownType(typename type_traits::const_parameter_trait<IdentifierType>::type)
	{
		assert(0 && "Unknown type given to the factory.");
	}

};

} //utils

} //etl

#endif //__DEFAULTFACTORYERRORPOLICY_HPP__
