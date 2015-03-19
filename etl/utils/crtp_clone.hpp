#ifndef __CRTP_CLONE_HPP__
#define __CRTP_CLONE_HPP__

namespace etl {

namespace utils {

template<class Derived, class Base>
struct crtp_clone : Base
{
    template<class... Arg>
    crtp_clone(Arg&&... arg): Base(std::forward<Arg>(arg)...)
    { }

public:
    virtual Base* clone() const
    {
        return new Derived(static_cast<Derived const&>(*this));
    }
};

} //utils

} //etl

#endif

