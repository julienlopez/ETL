#ifndef __ETL_FUNCTIONAL_HPP__
#define __ETL_FUNCTIONAL_HPP__

#include <functional>

namespace etl
{
	
	namespace utils
	{
	
		namespace functional
		{
			/**
			 * @brief a small helper object to easily negate a predicate
			 **/
			template<class RESULT, class ... Args>
			class negator
			{
			public:
				using function_t = std::function<RESULT(Args...)>;
				negator(function_t&& fct): m_fct(std::forward<function_t>(fct))
				{}
				
				bool operator()(const Args& ... args) const
				{
					return !m_fct(args...);
				}
			private:
				function_t m_fct;
			};
			
			template<class RESULT, class ... Args>
			negator<RESULT, Args ...> negate(RESULT(*fct)(Args...))
			{
				return negator<RESULT, Args ...>(fct);
			}
			
		} //functional
		
	} //utils
	
} //etl

#endif //__ETL_FUNCTIONAL_HPP__