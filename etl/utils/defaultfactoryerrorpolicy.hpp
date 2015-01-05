#ifndef __DEFAULTFACTORYERRORPOLICY_HPP__
#define __DEFAULTFACTORYERRORPOLICY_HPP__

#include "type_traits/parametertrait.hpp"

#include <cassert>
#include <stdexcept>

BEGIN_NAMESPACE_ETL

BEGIN_NAMESPACE_UTILS

template<class IdentifierType, class ProductType>
class exception_factory_error_policy
{
public:
	class Exception : public std::exception
	{
	public:
        Exception(typename const_parameter_trait<IdentifierType>::type id) : std::exception(), m_unknownId(id)
		{}
		
		virtual const char* what()
		{
            return "Unknown type given to the factory.";
		}
		
        typename const_parameter_trait<IdentifierType>::type getId() const
		{
			return m_unknownId;
		}
		
	private:
		IdentifierType m_unknownId;
	};
	
protected:
    static ProductType onUnknownType(typename const_parameter_trait<IdentifierType>::type id)
	{
		throw Exception(id);
	}
};

template<class IdentifierType, class ProductType>
class assertion_factory_error_policy
{
protected:
	static ProductType onUnknownType(typename const_parameter_trait<IdentifierType>::type id)
	{
		assert(0 && "Unknown type given to the factory.");
	}

};

END_NAMESPACE_UTILS

END_NAMESPACE_ETL

#endif //__DEFAULTFACTORYERRORPOLICY_HPP__
