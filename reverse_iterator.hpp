/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:47:07 by badam             #+#    #+#             */
/*   Updated: 2021/09/27 12:57:31 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{

template< class Iterator >
class reverse_iterator: public Iterator
{
	typedef reverse_iterator	_self;

	protected:
		using typename Iterator::_item_ptr;
		using typename Iterator::_core;
	
	public:
		using typename Iterator::difference_type;
	
	public:
		reverse_iterator(void): Iterator()
		{};

		reverse_iterator(const _core &src): Iterator(src)
		{};

		reverse_iterator(_item_ptr *front, _item_ptr *back, _item_ptr elem): Iterator(front, back, elem)
		{};

		virtual	~reverse_iterator(void)
		{};
		

		_self	&operator++(void)
		{
			return dynamic_cast<_self &>(Iterator::operator--());
		};

		_self	operator++(int)
		{
			_self	tmp(*this);

			++(*this);
			return (tmp);
		};

		_self	&operator--(void)
		{
			return dynamic_cast<_self &>(Iterator::operator++());
		};

		_self	operator--(int)
		{
			_self	tmp(*this);

			--(*this);
			return (tmp);
		};

		_self	&operator+=(difference_type n)
		{
			return dynamic_cast<_self &>(Iterator::operator-=(n));
		};

		_self	&operator-=(difference_type n)
		{
			return dynamic_cast<_self &>(Iterator::operator+=(n));
		};

		_self	&operator+(difference_type n) const
		{
			return dynamic_cast<_self &>(Iterator::operator-(n));
		};

		_self	&operator-(difference_type n) const
		{
			return dynamic_cast<_self &>(Iterator::operator+(n));
		};

		bool	operator<=(const _self &ref) const
		{
			return (Iterator::operator>=(ref));
		};

		bool	operator<(const _self &ref) const
		{
			return (Iterator::operator>(ref));
		};

		bool	operator>=(const _self &ref) const
		{
			return (Iterator::operator<=(ref));
		};

		bool	operator>(const _self &ref) const
		{
			return (Iterator::operator<(ref));
		};
};

}

#endif

