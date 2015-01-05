#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

#include "noncopiable.hpp"

BEGIN_NAMESPACE_ETL

BEGIN_NAMESPACE_UTILS

template<class T> class singleton : public noncopiable {
public:
    static T& instance() {
        static T i;
        return i;
    }

protected:
    singleton() {}
};

END_NAMESPACE_UTILS

END_NAMESPACE_ETL

#endif // __SINGLETON_HPP__
