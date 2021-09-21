/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:50:18 by badam             #+#    #+#             */
/*   Updated: 2021/09/15 12:00:25 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{

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