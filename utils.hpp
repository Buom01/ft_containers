/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:50:18 by badam             #+#    #+#             */
/*   Updated: 2021/10/25 14:51:09 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

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

}

#endif