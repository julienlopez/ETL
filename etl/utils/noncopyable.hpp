#ifndef __NONCOPYABLE_HPP__
#define __NONCOPYABLE_HPP__

namespace etl {

namespace utils {

struct noncopyable
{
	noncopyable(const noncopyable&) = delete;

	noncopyable& operator=(const noncopyable&) = delete;
	
protected:
	noncopyable() noexcept = default;
	
	~noncopyable() noexcept = default;

	noncopyable(noncopyable&&) noexcept  = default;

	noncopyable& operator=(noncopyable&&) noexcept  = default;
};

} //utils

} //etl

#endif //__NONCOPYABLE_HPP__

