/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:49:04 by badam             #+#    #+#             */
/*   Updated: 2021/07/13 13:42:19 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_HPP
# define CORE_HPP

# include <iostream>
# include <string>
# include <limits>


namespace ft
{

template< class T, class Alloc, class Item, class Iterator >
class	core
{
	public:
		typedef	T									value_type;
		typedef	Alloc								allocator_type;
		typedef	T&									reference;
		typedef	const T&							const_reference;
		typedef	T*									pointer;
		typedef	const T*							const_pointer;
		typedef Iterator<reference, false>			iterator;
		typedef Iterator<const_reference, false>	const_iterator;
		typedef Iterator<reference, true>			reverse_iterator;
		typedef Iterator<const_reference, true>		const_reverse_iterator;
		typedef	std::ptrdiff_t						difference_type;
		typedef	std::size_t							size_type;

	protected:
		typedef	Item<T>						_item;

		allocator_type	*_alloc;
		iterator		*_begin;
		iterator		*_end;
		iterator		*_rbegin;
		iterator		*_rend;
		size_type		_size;
		_item			*_front;
		_item			*_back;

		void		_init(const allocator_type &alloc)
		{
			_alloc = &alloc;
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

		bool			empty(void) const
		{
			return (_size == 0);
		}

		size_type		size(void) const
		{
			return (_size);
		}


	protected:
		void		_update_front(_item *newfront)
		{
			_front = newfront;
			delete _begin;
			_begin = new iterator(&_front, &_back, newfront);
		}

		void		_update_back(_item *newback)
		{
			_back = newback;
			delete _rbegin;
			_rbegin = new iterator(&_back, &_front, newback, true);
		}

		void		_update(_item *newfront, _item *newback)
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
			return (_alloc::max_size());
			//return (std::numeric_limits<size_type>::max());
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
};

}

#endif
