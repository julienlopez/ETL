#ifndef PIMPL_HPP
#define PIMPL_HPP

#include "deep_ptr.hpp"

BEGIN_NAMESPACE_ETL

BEGIN_NAMESPACE_UTILS

template <class Impl> class pimpl
{
protected:
	template <class... Args> pimpl(Args&&... args) : m_ptr(new Impl(std::forward<Args>(args)...))
	{
	}

	pimpl() : m_ptr(new Impl)
	{
	}

	~pimpl() = default;

	pimpl(const pimpl&) = default;
    pimpl(pimpl&&) = default;

	pimpl& operator=(const pimpl&) = default;
    pimpl& operator=(pimpl&&) = default;

	Impl& get()
	{
		return *m_ptr;
	}

	const Impl& get() const
	{
		return *m_ptr;
	}

private:
	utils::deep_ptr<Impl> m_ptr;
};

END_NAMESPACE_UTILS

END_NAMESPACE_ETL

#endif // PIMPL_HPP
