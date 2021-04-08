/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:49:04 by badam             #+#    #+#             */
/*   Updated: 2021/04/08 23:10:07 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACOMMON_HPP
# define ACOMMON_HPP

# include <iostream>
# include <string>


template< class T >
struct s_commonItem
{
	T					*content;
	struct s_commonItem	*next;
	struct s_commonItem *prev;
};


template< class Category, class T, class Alloc >
class	Iterator;

template< class Category, class T, class Alloc >
class	ACommon
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
		typedef		Iterator<Category, T, Alloc> _iterator;
		typedef		struct s_commonItem<T>		 _item;

		_iterator	*_begin;
		_iterator	*_end;
		_iterator	*_rbegin;
		_iterator	*_rend;
		size_type	_size;
		_item		*_front;
		_item		*_back;

	public:
		ACommon(void)
		{
			_begin = new _iterator(&_back, NULL);
			_end = new _iterator(&_back, NULL);
			_size = 0;
			_front = NULL;
			_back = NULL;
		};

		ACommon(const ACommon &src)
		{
			_begin = NULL;
			_front = NULL;
			*this = src;
		};

		virtual	~ACommon(void)
		{
			_clear(true);
		};


		ACommon	&operator=(const ACommon &ref)
		{
			if (this == &ref)
				return (*this);

			if (_begin)
			{
				delete _begin;
				delete _end;
			}
			_begin = new _iterator(ref.begin());
			_end = new _iterator(ref.end());

			// should free old list and assign new one
			// along the size
			// can use assign ?
			// may use ease and iter over content with _push_back
			_front = NULL;
			_back = NULL;
			_size = ref.size();

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
			//delete _rbegin;
			//_rbegin = new _iterator(&_front, newback, true);
		}

		void		_update(_item *newfront, _item *newback)
		{
			_front = newfront;
			_back = newback;

			delete _begin;
			_begin = new _iterator(&_back, newfront);
			//delete _rbegin;
			//_rbegin = new _iterator(&_front, newback, true);
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
				delete _front;
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
				delete _back;
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

		// may handle reverse differently
		_iterator	_insert(_iterator position, const T &val)
		{
			_item	*next = position.getElem();
			_item	*prev = next->prev;
			_item	*item = _allocate(val);

			item->next = next;
			item->prev = prev;
			prev->next = item;
			next->prev = item;

			++_size;

			//may refresh front / back

			return (--position);
		}

		void		_insert(_iterator position, size_type n, const T &val)
		{
			while (n--)
				insert(position, val);
		}

		template <class InputIterator>
		void		_insert(_iterator position, InputIterator first, InputIterator last)
		{
			InputIterator	it	= first;

			while (it != last)
			{
				_insert(position, *it);
				++it;
			}
		}

		_iterator	_erase(_iterator position)
		{
			_iterator	next_it	= _iterator(position);

			++next_it;

			if (position.getElem() == _begin->getElem())
				_pop_front();
			else if (position.getElem() == _rbegin->getElem())
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

		// may handle reverse differently
		_iterator	_erase(_iterator first, _iterator last)
		{
			_iterator	prev_it	= _iterator(first);
			
			--prev_it;

			{
				_item		*next	= last.getElem()->next;
				_item		*prev	= first.getElem()->prev;

				next->prev = prev;
				prev->next = next;
			}

			{
				_iterator	it		= first;
				_iterator	next	= first;

				while (it != last)
				{
					++next;
					_delete(*it);
					--_size;
					it = next;
				}
			}

			// may refresh front / back

			return (prev_it);
		}

		// swap

		void	_clear(bool	destroy = false)
		{
			_item	*item = _front;
			_item	*next = NULL;

			delete _begin;
			//delete _rbegin;
			if (destroy)
			{
				delete _end;
				//delete _rend;
			}
			else
			{
				_begin = new _iterator(&_back, NULL);
				//_rbegin = new _iterator(&_back, NULL);
			}

			if (_front)
			{
				while (next != _front)
				{
					next = item->next;
					_delete(item);
					item = next;
				}
			}

			_size = 0;
		}

		allocator_type	_get_allocator(void) const
		{
			// may review that
			allocator_type	allocator;

			return (allocator);
		}
};

#endif
