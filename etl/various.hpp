#ifndef __ETL_VARIOUS_HPP__
#define __ETL_VARIOUS_HPP__

namespace etl {
	
// class template BaseType
	template<class T> struct BaseType {
		typedef T type;
	};
	
	template<class T> struct BaseType<T*> {
		typedef T type;
	};
	
	template<class T> struct BaseType<const T*> {
		typedef T type;
	};
	
	template<class T> struct BaseType<T&> {
		typedef T type;
	};
	
	template<class T> struct BaseType<const T&> {
		typedef T type;
	};

// class template Int2Type
// Converti chaque constante en un type
// Utilisation: Int2Type<v> where v is a compile-time constant integral
// Defines 'value', an enum that evaluates to v

    template <int v>
    struct Int2Type
    {
        enum { value = v };
    };
    
// class template Type2Type
// Converts each type into a unique, insipid type
// Utilisation: Type2Type<T> où T est un type
// Definit le type OriginalType qui correspond à T

    template <typename T>
    struct Type2Type
    {
        typedef T OriginalType;
    };

}

#endif
