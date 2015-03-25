#ifndef __ETL_ALGORITHMS_HPP__
#define __ETL_ALGORITHMS_HPP__

#include <algorithm>

#include "functional.hpp"

namespace etl
{
	
	namespace utils
	{
	
		namespace algorithms
		{
			template<class CONTAINER1, class CONTAINER2, class FUNCTOR>
			void split_container(CONTAINER1& c1, CONTAINER2& c2, FUNCTOR fct)
			{
				std::copy_if(begin(c1), end(c1), std::back_inserter(c2), fct);
				auto it = std::remove_if(begin(c1), end(c1), fct);
				c1.erase(it, end(c1));
			}
		} //algorithms
		
	} //utils
	
} //etl

#endif //__ETL_ALGORITHMS_HPP__