/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:50:18 by badam             #+#    #+#             */
/*   Updated: 2021/09/21 16:16:39 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{

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



template <class InputIterator>
InputIterator	advance(InputIterator it, typename InputIterator::difference_type n)  // safe way. Maye use "+=" and "-="
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
typename InputIterator::difference_type	distance(InputIterator first, InputIterator last)  // using the universal way. May calculate ptr diff if possible
{
	typename InputIterator::difference_type	i	= 0;

	while (first++ != last)
		++i;
	
	return i;
}

}

#endif