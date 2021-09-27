/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:49:04 by badam             #+#    #+#             */
/*   Updated: 2021/09/24 22:05:45 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_HPP
# define CORE_HPP

# include "reverse_iterator.hpp"


namespace ft
{

template<
	class T, class Alloc, class Item, class Iterator, class ConstIterator
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
		typedef	ConstIterator							const_iterator;
		typedef	ft::reverse_iterator<iterator>			reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef	std::ptrdiff_t							difference_type;
		typedef	std::size_t								size_type;

	protected:
		typedef	Item		_item;
		typedef	_item*		_item_ptr;
		typedef core		_self;

		allocator_type			*_alloc;
		iterator				*_begin;
		const_iterator			*_cbegin;
		iterator				*_end;
		const_iterator			*_cend;
		reverse_iterator		*_rbegin;
		const_reverse_iterator	*_crbegin;
		reverse_iterator		*_rend;
		const_reverse_iterator	*_crend;
		size_type				_size;
		_item_ptr				_front;
		_item_ptr				_back;

		void		_init(const allocator_type &alloc)
		{
			_alloc		= &((allocator_type &)(alloc));  // May change that
			_begin		= new iterator(&_front, &_back, NULL);
			_cbegin		= new const_iterator(&_front, &_back, NULL);
			_end 		= new iterator(&_front, &_back, NULL);
			_cend		= new const_iterator(&_front, &_back, NULL);
			_rbegin		= new reverse_iterator(&_front, &_back, NULL);
			_crbegin	= new const_reverse_iterator(&_front, &_back, NULL);
			_rend		= new reverse_iterator(&_front, &_back, NULL);
			_crend		= new const_reverse_iterator(&_front, &_back, NULL);
			_size		= 0;
			_front		= NULL;
			_back		= NULL;
		}

		void		_destroy()
		{
			delete _begin;
			delete _cbegin;
			delete _rbegin;
			delete _crbegin;
			delete _end;
			delete _cend;
			delete _rend;
			delete _crend;
		}

	public:
		core()
		{};

	protected:
		core(const core &)
		{};

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
			delete _cbegin;
			_cbegin = new const_iterator(&_front, &_back, newfront);
		}

		void		_update_back(_item_ptr newback)
		{
			_back = newback;
			delete _rbegin;
			_rbegin = new reverse_iterator(&_front, &_back, newback);
			delete _crbegin;
			_crbegin = new const_reverse_iterator(&_front, &_back, newback);
		}

		void		_update(_item_ptr newfront, _item_ptr newback)
		{
			_front = newfront;
			_back = newback;

			delete _begin;
			_begin = new iterator(&_front, &_back, newfront);
			delete _cbegin;
			_cbegin = new const_iterator(&_front, &_back, newfront);
			delete _rbegin;
			_rbegin = new reverse_iterator(&_front, &_back, newback);
			delete _crbegin;
			_crbegin = new const_reverse_iterator(&_front, &_back, newback);
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
			_swap_pointer(&_cbegin, &x._cbegin);
			_swap_pointer(&_end, &x._end);
			_swap_pointer(&_cend, &x._cend);
			_swap_pointer(&_rbegin, &x._rbegin);
			_swap_pointer(&_crbegin, &x._crbegin);
			_swap_pointer(&_rend, &x._rend);
			_swap_pointer(&_crend, &x._crend);
			_swap_pointer(&_size, &x._size);
			_swap_pointer(&_front, &x._front);
			_swap_pointer(&_back, &x._back);
		}

		allocator_type	_get_allocator(void) const
		{
			return (*_alloc);
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
