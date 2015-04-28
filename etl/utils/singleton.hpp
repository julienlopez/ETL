#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

#include "noncopyable.hpp"

namespace etl {

namespace utils {

template<class T> class singleton : public noncopyable {
public:
    static T& instance() {
        static T i;
        return i;
    }

protected:
    singleton() {}
};

} //utils

} //etl

#endif // __SINGLETON_HPP__
