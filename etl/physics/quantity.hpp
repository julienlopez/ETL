#ifndef __QUANTITY_HPP__
#define __QUANTITY_HPP__

#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/placeholders.hpp>
#include <etl/type_traits/parameter_trait.hpp>

namespace etl {

namespace physics {

//base dimensions
typedef boost::mpl::vector_c<int, 1, 0, 0, 0, 0, 0, 0> mass;
typedef boost::mpl::vector_c<int, 0, 1, 0, 0, 0, 0, 0> length;
typedef boost::mpl::vector_c<int, 0, 0, 1, 0, 0, 0, 0> time;
typedef boost::mpl::vector_c<int, 0, 0, 0, 1, 0, 0, 0> charge;
typedef boost::mpl::vector_c<int, 0, 0, 0, 0, 1, 0, 0> temperature;
typedef boost::mpl::vector_c<int, 0, 0, 0, 0, 0, 1, 0> intensity;
typedef boost::mpl::vector_c<int, 0, 0, 0, 0, 0, 0, 1> amount_of_substance;

typedef boost::mpl::vector_c<int, 0, 0, 0, 0, 0, 0, 0> scalar;

//composite dimensions:
typedef boost::mpl::vector_c<int, 0, 1, -1, 0, 0, 0, 0> velocity; // m/t
typedef boost::mpl::vector_c<int, 0, 1, -2, 0, 0, 0, 0> acceleration; // m/t²
typedef boost::mpl::vector_c<int, 1, 1, -1, 0, 0, 0, 0> momentum; // ml/t
typedef boost::mpl::vector_c<int, 1, 1, -2, 0, 0, 0, 0> force; // ml/(t²)

/**
* \brief class representing a physical quantity, with a value and a dimension.
*/
template<typename DIMENSION = scalar, typename T = double>
struct quantity
{
	explicit quantity(typename etl::type_traits::const_parameter_trait<T>::type x): m_value(x)
	{}

	T value() const
	{
		return m_value;
	}

	template<class OTHER_DIMENSION>
	quantity(const quantity<OTHER_DIMENSION, T>& q): m_value(q.value())
	{
		static_assert(boost::mpl::equal<DIMENSION, OTHER_DIMENSION>::type::value, "dimensions must be the same");
	}

	T m_value;
};

//arithmetic operators
template<class D, class T>
quantity<D, T> operator+(const quantity<D, T>& q1, const quantity<D, T>& q2)
{
	return quantity<D, T>(q1.value() + q2.value());
}

template<class D, class T>
quantity<D, T> operator-(const quantity<D, T>& q1, const quantity<D, T>& q2)
{
	return quantity<D, T>(q1.value() - q2.value());
}

template<class D1, class D2> struct multiply_dimensons :
    boost::mpl::transform<D1, D2, boost::mpl::plus<boost::mpl::placeholders::_1, boost::mpl::placeholders::_2>> {};

template<class D1, class D2, class T>
quantity<typename multiply_dimensons<D1, D2>::type, T> operator*(const quantity<D1, T>& q1, const quantity<D2, T>& q2)
{
	return quantity<typename multiply_dimensons<D1, D2>::type, T>(q1.value() * q2.value());
}

template<class D1, class D2> struct divide_dimensons :
    boost::mpl::transform<D1, D2, boost::mpl::minus<boost::mpl::placeholders::_1, boost::mpl::placeholders::_2>> {};

template<class D1, class D2, class T>
quantity<typename divide_dimensons<D1, D2>::type, T> operator/(const quantity<D1, T>& q1, const quantity<D2, T>& q2)
{
	return quantity<typename divide_dimensons<D1, D2>::type, T>(q1.value() * q2.value());
}

}
}

#endif

