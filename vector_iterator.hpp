/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:12:54 by badam             #+#    #+#             */
/*   Updated: 2021/07/13 13:55:32 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "core_iterator.hpp"
# include "vector.hpp"


namespace ft
{

template< class T, class Alloc >
class	vector_iterator: public iterator<std::random_access_iterator_tag, T, Alloc, *T>
{
	typedef vector_iterator<T, Alloc>	_self;

	using typename _parent::_size_type;


	public:
		vector_iterator	&operator++(void)
		{
			++_parent::_item;

			return (*this);
		};

		vector_iterator	operator++(int)
		{
			_self	tmp(*this);

			++(*this);
			return (tmp);
		};

		vector_iterator	&operator--(void)
		{
			--_parent::_item;

			return (*this);
		};

		vector_iterator	operator--(int)
		{
			_self	tmp(*this);

			--(*this);
			return (tmp);
		};

		T			&operator*(void)
		{
			return (*_parent::_elem);
		};

		const T		&operator*(void) const
		{
			return (*_parent::_elem);
		};

		T			&operator->(void)
		{
			return (*_parent::_elem);
		};

		const T		&operator->(void) const
		{
			return (*_parent::_elem);
		};

		// + - += -= <= < >= > [n] operators

		_size_type	getIndex(void)
		{
			return (_parent::_elem - *_parent::_begin);
		}
}
}

#endif

