/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:49:04 by badam             #+#    #+#             */
/*   Updated: 2021/11/28 14:13:34 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_HPP
# define CORE_HPP

# include <limits>
# include "reverse_iterator.hpp"


namespace ft
{

template< class T, class Alloc, class Item, class Iterator, class ConstIterator >
class	core
{
	public:
		typedef				T										value_type;
		typedef				Alloc									allocator_type;
		typedef	typename	Alloc::reference						reference;
		typedef	typename	Alloc::const_reference					const_reference;
		typedef	typename	Alloc::pointer							pointer;
		typedef	typename	Alloc::const_pointer					const_pointer;
		typedef				Iterator								iterator;
		typedef				ConstIterator							const_iterator;
		typedef				ft::reverse_iterator<iterator>			reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef				std::ptrdiff_t							difference_type;
		typedef				std::size_t								size_type;

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
			_alloc		= &(const_cast<allocator_type &>(alloc));
			_size		= 0;
			_front		= NULL;
			_back		= NULL;
			_begin		= new iterator(_front, _back, NULL);
			_cbegin		= new const_iterator(_front, _back, NULL);
			_end 		= new iterator(_front, _back, NULL);
			_cend		= new const_iterator(_front, _back, NULL);
			_rbegin		= new reverse_iterator(_front, _back, NULL);
			_crbegin	= new const_reverse_iterator(_front, _back, NULL);
			_rend		= new reverse_iterator(_front, _back, NULL);
			_crend		= new const_reverse_iterator(_front, _back, NULL);
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
		iterator	_get_iterator(_item_ptr elem)
		{
			return (iterator(_front, _back, elem));
		}

		const_iterator	_get_const_iterator(_item_ptr elem) const
		{
			return (const_iterator(_front, _back, elem));
		}

		iterator	_get_reverse_iterator(_item_ptr elem)
		{
			return (reverse_iterator(_front, _back, elem));
		}

		const_iterator	_get_const_reverse_iterator(_item_ptr elem) const
		{
			return (const_reverse_iterator(_front, _back, elem));
		}

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
			_update(newfront, _back);
		}

		void		_update_back(_item_ptr newback)
		{
			_update(_front, newback);
		}

		void		_update(_item_ptr newfront, _item_ptr newback)
		{
			_front = newfront;
			_back = newback;

			delete _begin;
			_begin = new iterator(_front, _back, _front);
			delete _cbegin;
			_cbegin = new const_iterator(_front, _back, _front);

			delete _end;
			_end = new iterator(_front, _back, NULL);
			delete _cend;
			_cend = new const_iterator(_front, _back, NULL);

			delete _rbegin;
			_rbegin = new reverse_iterator(_front, _back, _back);
			delete _crbegin;
			_crbegin = new const_reverse_iterator(_front, _back, _back);

			delete _rend;
			_rend = new reverse_iterator(_front, _back, NULL);
			delete _crend;
			_crend = new const_reverse_iterator(_front, _back, NULL);

		}


		size_type	_max_size(unsigned long long max = std::numeric_limits<difference_type>::max() / sizeof(_item)) const
		{
			std::allocator<_item>	max_size_allocator;
			size_type	max_size_value	= max_size_allocator.max_size();
			
			if (max < static_cast<unsigned long long>(max_size_value))
				return (max);
			else
				return (max_size_value);
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

		iterator				begin(void)
		{
			return (*_begin);
		};

		const_iterator			begin(void) const
		{
			return (*_cbegin);
		};

		iterator				end(void)
		{
			return (*_end);
		}

		const_iterator			end(void) const
		{
			return (*_cend);
		}

		reverse_iterator		rbegin(void)
		{
			return (*_rbegin);
		};

		const_reverse_iterator	rbegin(void) const
		{
			return (*_crbegin);
		};

		reverse_iterator		rend(void)
		{
			return (*_rend);
		}

		const_reverse_iterator	rend(void) const
		{
			return (*_crend);
		}
};



template< class T, class Alloc, class Item, class Iterator, class ConstIterator >
bool	operator==(const ft::core<T, Alloc, Item, Iterator, ConstIterator> &lhs, const ft::core<T, Alloc, Item, Iterator, ConstIterator> &rhs)
{
	ConstIterator	lit	= lhs.begin();
	ConstIterator	rit	= rhs.begin();

	if (lhs.size() != rhs.size())
		return (false);
	
	while (lit != lhs.end() || rit != rhs.end())
	{
		if (*lit != *rit)
			return (false);
		
		++lit;
		++rit;
	}
	
	return (true);
}

template< class T, class Alloc, class Item, class Iterator, class ConstIterator >
bool	operator!=(const ft::core<T, Alloc, Item, Iterator, ConstIterator> &lhs, const ft::core<T, Alloc, Item, Iterator, ConstIterator> &rhs)
{
	return (!(lhs == rhs));
}


template< class T, class Alloc, class Item, class Iterator, class ConstIterator >
bool	operator<(const ft::core<T, Alloc, Item, Iterator, ConstIterator> &lhs, const ft::core<T, Alloc, Item, Iterator, ConstIterator> &rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class T, class Alloc, class Item, class Iterator, class ConstIterator >
bool	operator<=(const ft::core<T, Alloc, Item, Iterator, ConstIterator> &lhs, const ft::core<T, Alloc, Item, Iterator, ConstIterator> &rhs)
{
	return (!(rhs < lhs));
}

template< class T, class Alloc, class Item, class Iterator, class ConstIterator >
bool	operator>(const ft::core<T, Alloc, Item, Iterator, ConstIterator> &lhs, const ft::core<T, Alloc, Item, Iterator, ConstIterator> &rhs)
{
	return (!(lhs <= rhs));
}

template< class T, class Alloc, class Item, class Iterator, class ConstIterator >
bool	operator>=(const ft::core<T, Alloc, Item, Iterator, ConstIterator> &lhs, const ft::core<T, Alloc, Item, Iterator, ConstIterator> &rhs)
{
	return (!(lhs < rhs));
}

}

#endif
