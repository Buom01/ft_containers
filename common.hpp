/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:49:04 by badam             #+#    #+#             */
/*   Updated: 2021/05/18 17:13:25 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_HPP
# define COMMON_HPP

# include <iostream>
# include <string>


namespace ft
{

template< class T >
struct s_common_item
{
	T					*content;
	struct s_common_item	*next;
	struct s_common_item	*prev;
};


template< class Category, class T, class Alloc >
class	iterator;

template< class Category, class T, class Alloc >
class	common
{
	public:
		typedef	T				value_type;
		typedef	Alloc			allocator_type;
		typedef	T&				reference;
		typedef	const T&		const_reference;
		typedef	T*				pointer;
		typedef	const T*		const_pointer;
		typedef	std::ptrdiff_t	difference_type;
		typedef	std::size_t		size_type;

	protected:
		typedef		iterator<Category, T, Alloc>	_iterator;
		typedef		struct s_common_item<T>			_item;

		_iterator	*_begin;
		_iterator	*_end;
		_iterator	*_rbegin;
		_iterator	*_rend;
		size_type	_size;
		_item		*_front;
		_item		*_back;

		void		_init(const allocator_type &alloc = allocator_type())
		{
			(void)alloc;  // May use it too

			_begin = new _iterator(&_back, NULL);
			_end = new _iterator(&_back, NULL);
			_rbegin = new _iterator(&_back, NULL, true);
			_rend = new _iterator(&_back, NULL, true);
			_size = 0;
			_front = NULL;
			_back = NULL;
		}

	public:
		common()
		{};

	protected:
		common(const common &src)
		{
			*this = src;
		};

	public:
		virtual	~common(void)
		{
			_clear(true);
		};


		common	&operator=(const common &ref)
		{
			_iterator	it;

			if (this == &ref)
				return (*this);

			_clear();

			it = ref.begin();
			while(it != ref.end())
			{
				_push_back(*it);
				++it;
			}

			return (*this);
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
		_item		*_allocate(const_reference val)
		{
			_item	*item	= new _item;

			item->content = new T(val);  // should respect allocator
			return (item);
		}

		void		_delete(_item *item)
		{
			delete item->content;
			delete item;
		}

		void		_update_front(_item *newfront)
		{
			_front = newfront;
			delete _begin;
			_begin = new _iterator(&_back, newfront);
		}

		void		_update_back(_item *newback)
		{
			_back = newback;
			delete _rbegin;
			_rbegin = new _iterator(&_front, newback, true);
		}

		void		_update(_item *newfront, _item *newback)
		{
			_front = newfront;
			_back = newback;

			delete _begin;
			_begin = new _iterator(&_back, newfront);
			delete _rbegin;
			_rbegin = new _iterator(&_front, newback, true);
		}


		size_type	_max_size(void) const
		{
			return (2^(64-sizeof(value_type))-1);
		}

		void 		_push_front(const_reference val)
		{
			_item	*item = _allocate(val);

			if (_front)
			{
				item->next = _front;
				item->prev = _back;
				_back->next = item;
				_front->prev = item;
				_update_front(item);
			}
			else
			{
				item->next = item;
				item->prev = item;
				_update(item, item);
			}
			++_size;
		}

		void 		_push_back(const_reference val)
		{
			_item	*item = _allocate(val);

			if (_back)
			{
				item->next = _front;
				item->prev = _back;
				_back->next = item;
				_front->prev = item;
				_update_back(item);
			}
			else
			{
				item->next = item;
				item->prev = item;
				_update(item, item);
			}
			++_size;
		}

		void		_pop_front(void)
		{
			_item	*newfront;

			if (_front)
			{
				newfront = _front->next;
				_delete(_front);
				if (newfront == _back)
				{
					_update(NULL, NULL);
				}
				else
				{
					newfront->prev = _back;
					_back->next = newfront;
					_update_front(newfront);
				}
			}
			--_size;
		}

		void 		_pop_back(void)
		{
			_item	*newback;

			if (_back)
			{
				newback = _back->prev;
				_delete(_back);
				if (newback == _front)
				{
					_update(NULL, NULL);
				}
				else
				{
					newback->next = _front;
					_front->prev = newback;
					_update_back(newback);
				}
			}
			--_size;
		}

		_iterator	_insert(_iterator next, const_reference val)
		{
			_iterator	prev	= next;
			--prev;

			if (!_end || next == *_end)
				_push_back(val);
			else if (prev == *_begin)
				_push_front(val);
			else
			{
				_item	*item	= _allocate(val);

				prev.getElem()->next = item;
				next.getElem()->prev = item;
				item->next = next.getElem();
				item->prev = prev.getElem();
				++_size;
			}

			return (--next);
		}

		_iterator	_insert(_iterator position, size_type n, const_reference val)
		{
			if (n)
				while (n--)
					position = _insert(position, val);

			return (position);
		}

		template <class InputIterator>
		_iterator	_insert(_iterator position, InputIterator first, InputIterator last)
		{
			InputIterator	it	= last;

			while (it-- != first)
				position = _insert(position, *it);

			return (position);
		}

		_iterator	_erase(_iterator position)
		{
			_iterator	next_it	= _iterator(position);

			++next_it;

			if (position.getElem() == _front)
				_pop_front();
			else if (position.getElem() == _back)
				_pop_back();
			else
			{
				_item		*next	= position.getElem()->next;
				_item		*prev	= position.getElem()->prev;

				next->prev = prev;
				prev->next = next;

				_delete(position.getElem());
				--_size;
			}

			return (next_it);
		}

		_iterator	_erase(_iterator first, _iterator last)
		{
			_iterator	it		= first;
			_iterator	it_prev	= first;
			
			--it_prev;
			if (it_prev.getElem() == last.getElem())
				it_prev = *_end;

			while (it != last)
				it = _erase(it);

			return (it_prev);
		}

		void	_swap(common &x)
		{
			{
				size_type	tmp;

				tmp = _size;
				_size = x._size;
				x._size = _size;
			}
			{
				_item	*xfront	= x._front;
				_item	*xback	= x._back;

				x._update(_front, _back);
				_update(xfront, xback);
			}


			// should swap the allocator too if propagate_on_container_swap
			// https://www.cplusplus.com/reference/memory/allocator_traits/#types
		}

		void	_clear(bool	destroy = false)
		{
			_item	*item = _front;
			_item	*next = NULL;

			if (_front)
			{
				while (next != _front)
				{
					next = item->next;
					_delete(item);
					item = next;
				}
			}

			if (destroy)
			{
				delete _begin;
				delete _rbegin;
				delete _end;
				delete _rend;
			}
			else
				_update(NULL, NULL);

			_size = 0;
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
