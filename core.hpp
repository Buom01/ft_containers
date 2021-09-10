/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:49:04 by badam             #+#    #+#             */
/*   Updated: 2021/09/07 16:22:37 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_HPP
# define CORE_HPP

# include <iostream>
# include <string>
# include <limits>

# include "reverse_iterator.hpp"


namespace ft
{

template<
	class T, class Alloc, class Item, class Iterator
>
class	core
{
	public:
		typedef	T										value_type;
		typedef	Alloc									allocator_type;
		typedef	T&										reference;
		typedef	const T&								const_reference;
		typedef	T*										pointer;
		typedef	const T*								const_pointer;
		typedef	Iterator								iterator;
		//typedef	ft::const_iterator<Iterator>			const_iterator;
		typedef	ft::reverse_iterator<Iterator>			reverse_iterator;
		//typedef	ft::const_reverse_iterator<Iterator>	const_reverse_iterator;
		typedef	std::ptrdiff_t							difference_type;
		typedef	std::size_t								size_type;

	protected:
		typedef	Item								_item;
		typedef	_item*								_item_ptr;
		typedef core< T, Alloc, Item, Iterator >	_self;

		allocator_type			*_alloc;
		iterator				*_begin;
		iterator				*_end;
		iterator				*_rbegin;
		iterator				*_rend;
		size_type				_size;
		_item_ptr				_front;
		_item_ptr				_back;

		void		_init(const allocator_type &alloc)
		{
			_alloc = &((allocator_type &)(alloc));  // May change that
			_begin = new iterator(&_front, &_back, NULL);
			_end = new iterator(&_front, &_back, NULL);
			_rbegin = new iterator(&_back, &_front, NULL, true);
			_rend = new iterator(&_back, &_front, NULL, true);
			_size = 0;
			_front = NULL;
			_back = NULL;
		}

	public:
		core()
		{};

	protected:
		core(const core &src)
		{
			*this = src;
		};

	public:
		virtual	~core(void)
		{
			_destroy();
		};

	protected:
		template <class ptr>
		void	_swap_pointer(ptr *a, ptr *b)
		{
			ptr	tmp;

			tmp = *a;
			*a = *b;
			*b = tmp;
		}

		void		_update_front(_item_ptr newfront)
		{
			_front = newfront;
			delete _begin;
			_begin = new iterator(&_front, &_back, newfront);
		}

		void		_update_back(_item_ptr newback)
		{
			_back = newback;
			delete _rbegin;
			_rbegin = new iterator(&_back, &_front, newback, true);
		}

		void		_update(_item_ptr newfront, _item_ptr newback)
		{
			_front = newfront;
			_back = newback;

			delete _begin;
			_begin = new iterator(&_front, &_back, newfront);
			delete _rbegin;
			_rbegin = new iterator(&_back, &_front, newback, true);
		}


		size_type	_max_size(void) const
		{
			return (_alloc->max_size());
			//return (std::numeric_limits<size_type>::max());
		}

		void			_swap(_self &x)
		{
			_swap_pointer(&_alloc, &x._alloc);
			_swap_pointer(&_begin, &x._begin);
			_swap_pointer(&_end, &x._end);
			_swap_pointer(&_rbegin, &x._rbegin);
			_swap_pointer(&_rend, &x._rend);
			_swap_pointer(&_size, &x._size);
			_swap_pointer(&_front, &x._front);
			_swap_pointer(&_back, &x._back);
		}

		void	_destroy()
		{
			delete _begin;
			delete _rbegin;
			delete _end;
			delete _rend;
		}

		allocator_type	_get_allocator(void) const
		{
			// may review that and usage of allocator in all code
			allocator_type	allocator;

			return (allocator);
		}

	public:
		bool			empty(void) const
		{
			return (_size == 0);
		}

		size_type		size(void) const
		{
			return (_size);
		}
};

}

#endif
