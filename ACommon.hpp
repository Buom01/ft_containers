/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:49:04 by badam             #+#    #+#             */
/*   Updated: 2021/03/28 00:51:24 by badam            ###   ########.fr       */
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

	private:
		typedef		Iterator<Category, T, Alloc> _iterator;
		typedef		struct s_commonItem<T>		 _item;

	protected:
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
			_end = new _iterator(this, NULL);
			_begin = new _iterator(this, NULL);
			_size = 0;
			_front = NULL;
			_back = NULL;
		};

		ACommon(const ACommon &src)
		{
			*this = src;
		};

		virtual	~ACommon(void)
		{
			_item	*item = _front;
			_item	*next = NULL;

			delete _begin;
			delete _end;
			//delete _rbegin;
			//delete _rend;

			if (_front)
			{
				while (next != _front)
				{
					next = item->next;
					delete item->content;
					delete item;
					item = next;
				}
			}
		};


		ACommon	&operator=(const ACommon &ref)
		{
			if (this == &ref)
				return (*this);

			_end = new _iterator(ref.end());
			_begin = new _iterator(ref.begin());
			_front = NULL;
			_back = NULL;

			// Should also copy the content along the size
			// can use assign ?

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
				_front = item;
			}
			else
			{
				_front = item;
				_back = item;
				item->next = item;
				item->prev = item;
			}
		}
};

#endif
