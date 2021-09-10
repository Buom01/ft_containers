/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:47:07 by badam             #+#    #+#             */
/*   Updated: 2021/07/22 02:06:20 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{

template< class Iterator >
class reverse_iterator: public Iterator
{
	typedef reverse_iterator<Iterator>	_self;
	
	public:
		_self	&operator++(void)
		{
			Iterator::operator--();

			return (*this);
		};

		_self	operator++(int)
		{
			_self	tmp(*this);

			Iterator::operator--();
			return (tmp);
		};

		_self	&operator--(void)
		{
			Iterator::operator++();

			return (*this);
		};

		_self	operator--(int)
		{
			_self	tmp(*this);

			Iterator::operator++();
			return (tmp);
		};
};

}

#endif

