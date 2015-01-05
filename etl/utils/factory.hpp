#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "singleton.hpp"
#include "defaultfactoryerrorpolicy.hpp"

#include <map>

BEGIN_NAMESPACE_ETL

BEGIN_NAMESPACE_UTILS

/**
 * \class factory factory.hpp utils/factory.hpp
 * \brief The factory class provides a generic factory to create object in a polymorphic setting.
 *
 * The factory works with an AbstractProcuct, a type define as the common interface for all the classes registered in the factory.
 * As new classes inheriting this interface are implemented, they are to be registered to the factory using the registerProduct() method.
 * An id if type IdentifierType is required for each class being registered in the factory.\n
 * This id can later be used to create a new instance of the desired class, using the create() method with the proper id.
 */
template<	class AbstractProduct,
			class IdentifierType,
            class ProductCreator = AbstractProduct(*)(),
			template<typename, class> class FactoryErrorPolicy = assertion_factory_error_policy
			>
class factory : public FactoryErrorPolicy<IdentifierType, AbstractProduct>, public singleton<factory<AbstractProduct, IdentifierType, ProductCreator, FactoryErrorPolicy> >
{
public:
    using error_policy_t = FactoryErrorPolicy<IdentifierType, AbstractProduct>;

    template<class ... Args>
    AbstractProduct create(typename const_parameter_trait<IdentifierType>::type id, Args... args)
	{
		typename AssocMap::const_iterator i = m_associations.find(id);
        if(i != m_associations.end()) return (i->second)(std::forward<Args>(args)...);
        return error_policy_t::onUnknownType(id);
	}
	
    bool registerProduct(typename const_parameter_trait<IdentifierType>::type id, ProductCreator creator)
	{
        return m_associations.insert(typename AssocMap::value_type(id, creator)).second;
	}
	
    bool unregisterProduct(typename const_parameter_trait<IdentifierType>::type id)
	{
		return m_associations.erase(id) == 1;
	}
	
private:
    using assoc_map_t std::map<IdentifierType, ProductCreator>;
	assoc_map_t m_associations;
};

END_NAMESPACE_UTILS

END_NAMESPACE_ETL

#endif
