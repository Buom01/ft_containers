/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:47:07 by badam             #+#    #+#             */
/*   Updated: 2021/09/24 21:21:19 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{

template< class Iterator, class ForcedIterator, class ForcedConstIterator >
class reverse_iterator: public Iterator
{
	typedef reverse_iterator	_self;
	typedef	std::size_t			_size_type;
	typedef	std::ptrdiff_t		_difference_type;

	typedef	ft::reverse_iterator<ForcedIterator, ForcedIterator, ForcedConstIterator>		_forced_reverse_vector_iterator;
	typedef	ft::reverse_iterator<ForcedConstIterator, ForcedIterator, ForcedConstIterator>	_forced_const_reverse_vector_iterator;

	using typename Iterator::_item_ptr;
	
	public:
		reverse_iterator(void): Iterator()
		{};

		reverse_iterator(const reverse_iterator &src): Iterator(src)
		{};

		reverse_iterator(_item_ptr *front, _item_ptr *back, _item_ptr elem): Iterator(front, back, elem)
		{};


		_self	&operator=(const _forced_reverse_vector_iterator &ref)  // Should patch theses
		{
			if (this != (static_cast<const void *>(&ref)))
			{
				Iterator::_front = ref.getFront();
				Iterator::_back = ref.getBack();
				Iterator::_elem = ref.getElem();
			}

			return (*this);
		};

		_self	&operator=(const _forced_const_reverse_vector_iterator &ref)  // Should patch theses
		{
			if (this != (static_cast<const void *>(&ref)))
			{
				Iterator::_front = ref.getFront();
				Iterator::_back = ref.getBack();
				Iterator::_elem = ref.getElem();
			}

			return (*this);
		};

		_self	&operator++(void)
		{
			return dynamic_cast<_self &>(Iterator::operator--());
		};

		_self	operator++(int mock)
		{
			return dynamic_cast<_self>(Iterator::operator--(mock));
		};

		_self	&operator--(void)
		{
			return dynamic_cast<_self &>(Iterator::operator++());
		};

		_self	operator--(int mock)
		{
			return dynamic_cast<_self>(Iterator::operator++(mock));
		};

		_self	&operator+=(_difference_type n)
		{
			return dynamic_cast<_self &>(Iterator::operator-=(n));
		};

		_self	&operator-=(_difference_type n)
		{
			return dynamic_cast<_self &>(Iterator::operator+=(n));
		};

		_self	&operator+(_difference_type n) const
		{
			return dynamic_cast<_self &>(Iterator::operator-(n));
		};

		_self	&operator-(_difference_type n) const
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

