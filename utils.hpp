/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:50:18 by badam             #+#    #+#             */
/*   Updated: 2021/12/17 20:05:51 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <utility>

namespace ft
{

template<class T>
struct remove_const {
	typedef T type;
};

template<class T>
struct remove_const<const T> {
	typedef typename remove_const<T>::type type;
};

// template<class T1, class T2>
// struct remove_const< pair<T1, const T2> > {
// 	typedef typename remove_const< pair<T1, T2> >::type type;
// };

template <class T, T v>
struct integral_constant {
	static const T value = v;
	typedef T value_type;
	typedef integral_constant<T,v> type;
	operator const T() { return v; }
};

template <class T>
struct is_integral: integral_constant<bool, false> {};

template <>
struct is_integral<bool>: integral_constant<bool, true> {};

template <>
struct is_integral<char>: integral_constant<bool, true> {};

template <>
struct is_integral<wchar_t>: integral_constant<bool, true> {};

template <>
struct is_integral<signed char>: integral_constant<bool, true> {};

template <>
struct is_integral<short int>: integral_constant<bool, true> {};

template <>
struct is_integral<int>: integral_constant<bool, true> {};

template <>
struct is_integral<long int>: integral_constant<bool, true> {};

template <>
struct is_integral<long long int>: integral_constant<bool, true> {};

template <>
struct is_integral<unsigned char>: integral_constant<bool, true> {};

template <>
struct is_integral<unsigned short int>: integral_constant<bool, true> {};

template <>
struct is_integral<unsigned int>: integral_constant<bool, true> {};

template <>
struct is_integral<unsigned long int>: integral_constant<bool, true> {};

template <>
struct is_integral<unsigned long long int>: integral_constant<bool, true> {};


template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };


template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}


template <class InputIterator>
InputIterator	advance(InputIterator it, typename InputIterator::difference_type n)  // may use "+=" and "-="
{
	if (n > 0)
	{
		while (n--)
			++it;
	}
	else
		while (n++)
			--it;
			
	return (it);
}

template <class InputIterator>
typename InputIterator::difference_type	distance(InputIterator first, InputIterator last)  // may use iterator diff when possible
{
	typename InputIterator::difference_type	i	= 0;

	while (first++ != last)
		++i;
	
	return i;
}


template< class Arg1, class Arg2, class Result >
struct binary_function
{
	typedef	Result	result_type;
	typedef	Arg1		first_argument_type;
	typedef	Arg2		second_argument_type;
};

template< class T >
struct less: binary_function< T, T, bool >
{
	bool operator()( const T& lhs, const T& rhs ) const
	{
		return lhs < rhs;
	}
};


template <class T1, class T2>
struct pair
{
	typedef	typename	remove_const<T1>::type	T1_core;
	typedef	typename	remove_const<T2>::type	T2_core;
	
	T1	first;
	T2	second;

	pair(void)
	{
	};

	pair(const T1 &x, const T2 &y): first(x), second(y)
	{
	};

	pair(const pair<T1_core, T2_core> &p): first(p.first), second(p.second)
	{
	};

	pair	&operator=(const pair<T1_core, T2_core> &ref)
	{
		if (this != &ref)
		{
			first = ref.first;
			second = ref.second;
		}

		return (*this);
	}
};

template< class T1, class T2 >
bool	operator==(const ft::pair<T1,T2> &lhs,const ft::pair<T1,T2> &rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template< class T1, class T2 >
bool	operator!=(const ft::pair<T1,T2> &lhs,const ft::pair<T1,T2> &rhs)
{
	return (!(lhs == rhs));
}

template<class T1, class T2>
bool	operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	if (lhs.first < rhs.first)
		return (true);
	else if (lhs.first > rhs.first)
		return (false);
	else
		return (lhs.second < rhs.second);
}

template<class T1, class T2>
bool	operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	return (!(rhs < lhs));
}

template<class T1, class T2>
bool	operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	return (!(lhs <= rhs));
}

template<class T1, class T2>
bool	operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	return (!(lhs < rhs));
}

template <class T1, class T2>
pair<T1, T2>	make_pair(T1 t, T2 u)
{
	pair<T1, T2>	elem(t, u);

	return (elem);
}

/*
**	ft::pair and std::pair mixing
*/

template< class T1, class T2 >
bool	operator==(const std::pair<T1,T2> &lhs,const ft::pair<T1,T2> &rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template< class T1, class T2 >
bool	operator!=(const std::pair<T1,T2> &lhs,const ft::pair<T1,T2> &rhs)
{
	return (!(lhs == rhs));
}

template<class T1, class T2>
bool	operator<(const std::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	if (lhs.first < rhs.first)
		return (true);
	else if (lhs.first > rhs.first)
		return (false);
	else
		return (lhs.second < rhs.second);
}

template<class T1, class T2>
bool	operator<=(const std::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	return (!(rhs < lhs));
}

template<class T1, class T2>
bool	operator>(const std::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	return (!(lhs <= rhs));
}

template<class T1, class T2>
bool	operator>=(const std::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	return (!(lhs < rhs));
}


template< class T1, class T2 >
bool	operator==(const ft::pair<T1,T2> &lhs,const std::pair<T1,T2> &rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template< class T1, class T2 >
bool	operator!=(const ft::pair<T1,T2> &lhs,const std::pair<T1,T2> &rhs)
{
	return (!(lhs == rhs));
}

template<class T1, class T2>
bool	operator<(const ft::pair<T1, T2> &lhs, const std::pair<T1, T2> &rhs)
{
	if (lhs.first < rhs.first)
		return (true);
	else if (lhs.first > rhs.first)
		return (false);
	else
		return (lhs.second < rhs.second);
}

template<class T1, class T2>
bool	operator<=(const ft::pair<T1, T2> &lhs, const std::pair<T1, T2> &rhs)
{
	return (!(rhs < lhs));
}

template<class T1, class T2>
bool	operator>(const ft::pair<T1, T2> &lhs, const std::pair<T1, T2> &rhs)
{
	return (!(lhs <= rhs));
}

template<class T1, class T2>
bool	operator>=(const ft::pair<T1, T2> &lhs, const std::pair<T1, T2> &rhs)
{
	return (!(lhs < rhs));
}

}

#endif