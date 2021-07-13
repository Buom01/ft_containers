/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:23:55 by badam             #+#    #+#             */
/*   Updated: 2021/07/13 13:42:19 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ITERATOR_HPP
# define CORE_ITERATOR_HPP

# include <iterator>

# include "core.hpp"


namespace ft
{

template< class Category, class T, class Alloc, class Item, class Iterator>
class	core;

template< class Category, class T, class Alloc, class Item>
class	iterator: public std::iterator<Category, T>
{
	protected:
		typedef	Item			_item;
		typedef	std::size_t		_size_type;

		_item	**_front;
		_item	**_back;
		_item 	*_elem;
		bool	_reversed;

	public:
		iterator(void)
		{
			_front = NULL;
			_back = NULL;
			_elem = NULL;
			_reversed = false;
		};

		iterator(const iterator &src)
		{
			*this = src;
		};

		iterator(_item **front, _item **back, _item *elem, bool reversed = false)
		{
			_front = front;
			_back = back;
			_elem = elem;
			_reversed = reversed;
		};

		virtual	~iterator(void)
		{
		};


		iterator	&operator=(const iterator &ref)
		{
			if (this != &ref)
			{
				_front = ref.getFront();
				_back = ref.getBack();
				_elem = ref.getElem();
				_reversed = ref.getReversed();
			}

			return (*this);
		};

		bool		operator==(const iterator &ref)
		{
			return (ref.getElem() == _elem);
		};

		bool		operator!=(const iterator &ref)
		{
			return (ref.getElem() != _elem);
		};

		_item	*getElem(void) const
		{
			return (_elem);
		};

		_item	**getElemPtr(void)
		{
			return (&_elem);
		};

		_item	**getFront(void) const
		{
			return (_front);
		};

		_item	**getBack(void) const
		{
			return (_back);
		};

		bool	getReversed(void) const
		{
			return (_reversed);
		};
};

}

#endif
