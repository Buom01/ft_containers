/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:49:40 by badam             #+#    #+#             */
/*   Updated: 2021/10/25 14:24:47 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stdexcept>
# include <cmath>
# include "utils.hpp"
# include "core.hpp"
# include "vector_iterator.hpp"


namespace ft
{

template< class T, class Alloc = std::allocator<T> >
class vector: public ft::core< T, Alloc, T, vector_iterator<T>, vector_iterator<const T> >
{
	typedef vector																	_self;
	typedef	ft::core< T, Alloc, T, vector_iterator<T>, vector_iterator<const T> >	_parent;


	using typename _parent::_item;
	using typename _parent::_item_ptr;

	public:
		using typename _parent::value_type;
		using typename _parent::allocator_type;
		using typename _parent::reference;
		using typename _parent::const_reference;
		using typename _parent::pointer;
		using typename _parent::const_pointer;
		using typename _parent::iterator;
		using typename _parent::const_iterator;
		using typename _parent::reverse_iterator;
		using typename _parent::const_reverse_iterator;
		using typename _parent::difference_type;
		using typename _parent::size_type;

	protected:
		size_type	_capacity;
		pointer		_content;

		void		_ensure_capacity(size_type n)
		{
			if (_capacity < n)
				reserve(n);
		}

		void		_extend_size(size_type n)
		{
			if (_parent::_size + n > _capacity)
				_ensure_capacity(_parent::_size + n);
		}

		void		_memmove(_item_ptr dst, _item_ptr src, size_type n)
		{
			if (dst < src)
			{
				while(n--)
				{
					_parent::_alloc->construct(dst++, *src);
					_parent::_alloc->destroy(src++);
				}
			}
			else if (dst > src)
			{
				src += n - 1;
				dst += n - 1;
				while(n--)
				{
					_parent::_alloc->construct(dst--, *src);
					_parent::_alloc->destroy(src--);
				}
			}
		}

		size_type	_get_iterator_index(iterator pos)
		{
			return (pos.getElem() ? pos.getElem() - _content : _parent::_size);
		}

		void		_autoupdate(void)
		{
			if (_parent::_size)
				_parent::_update(_content + 0, _content + _parent::_size - 1);
			else
				_parent::_update(NULL, NULL);
		}

		void		_init(const allocator_type &alloc, size_type capacity = 10)
		{
			_capacity = 0;
			_content = NULL;
			_parent::_init(alloc);
			_ensure_capacity(capacity);
		}

	public:
		explicit vector(const allocator_type &alloc = allocator_type())
		{
			_init(alloc);
		};

		explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type &alloc = allocator_type())
		{
			_init(alloc, n);
			insert(*_parent::_end, n, val);
		};

		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type())
		{
			_init(alloc);
			insert(*_parent::_end, first, last);
		};

		vector(const vector &x): _parent(x)
		{
			_init(x.get_allocator());
			*this = x;
		};

		virtual	~vector(void)
		{
			if (_content)
			{
				while (_parent::_size)
					_parent::_alloc->destroy(_content + --_parent::_size);
				_parent::_alloc->deallocate(_content, _capacity);
			}
		};

		_self	&operator=(const vector &ref)
		{
			iterator	it;

			if (this == &ref)
				return (*this);

			assign(ref.begin(), ref.end());

			return (*this);
		};

		size_type	max_size(void) const
		{
			return (_parent::_max_size());
		}

		void		resize(size_type n, T val = T())
		{
			iterator	it	= *_parent::_begin;

			while (n && it != *_parent::_end)
			{
				--n;
				++it;
			}
			if (n)
				insert(*_parent::_end, n, val);
			else
				erase(it, *_parent::_end);
		}

		size_type	capacity() const
		{
			return (_capacity);
		}

		void		reserve(size_type n)
		{
			size_type	i			= 0;
			pointer		oldcontent	= _content;

			if (n > max_size())
				throw std::length_error("n");
			if (n + 10 > _capacity && n < _capacity)
				return ;

			_content = _parent::_alloc->allocate(n, oldcontent);
			while (i < _parent::_size)
			{
				_parent::_alloc->construct(_content + i, oldcontent[i]);
				_parent::_alloc->destroy(oldcontent + i);
				++i;
			}
			if (oldcontent)
				_parent::_alloc->deallocate(oldcontent, _capacity);
			_capacity = n;
			_autoupdate();
		}

		reference		operator[](size_type n)
		{
			return (_content[n]);
		}

		const_reference	operator[](size_type n) const
		{
			return (_content[n]);
		}

		reference		at(size_type n)
		{
			if (n < 0 || n >= _parent::_size)
				throw std::out_of_range("n");

			return (_content[n]);
		} 

		const_reference	at(size_type n) const
		{
			if (n < 0 || n >= _parent::_size)
				throw std::out_of_range("n");

			return (_content[n]);
		} 

		reference		front(void)
		{
			return (*_parent::_front);
		}

		const_reference	front(void) const
		{
			return (*_parent::_front);
		}

		reference		back(void)
		{
			return (*_parent::_back);
		}

		const_reference	back(void) const
		{
			return (*_parent::_back);
		}

		pointer			data()
		{
			return (_content);
		}

		const_pointer	data() const
		{
			return (_content);
		}

		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last)
		{
			clear();
			insert(*_parent::_end, first, last);
		}

		void	assign(size_type n, const value_type &val)
		{
			clear();
			insert(*_parent::_end, n, val);
		}

		void	push_back(const value_type &val)
		{
			insert(*_parent::_end, val);
		}

		void	pop_back(void)
		{
			erase(--(this->end())); 
		}

		iterator	insert(iterator position, const value_type &val)
		{
			size_type	position_index	= _get_iterator_index(position);

			insert(position, 1, val);

			return (ft::advance(this->begin(), position_index));
		}

		void		insert(iterator position, size_type n, const value_type &val)
		{
			size_type	position_index	= _get_iterator_index(position);
			size_type	i				= 0;

			_extend_size(n);

			if (position_index < _parent::_size)
				_memmove(_content + position_index + n, _content + position_index, _parent::_size - position_index);
			while (i < n)
				_parent::_alloc->construct(_content + position_index + i++, val);

			_parent::_size += n;
			_autoupdate();
		}

		template <class InputIterator>
		void		insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			size_type	n				= static_cast<size_type>(ft::distance<InputIterator>(first, last));
			size_type	position_index	= _get_iterator_index(position);
			size_type	i				= 0;

			_extend_size(n);

			if (position_index < _parent::_size)
				_memmove(_content + position_index + n, _content + position_index, _parent::_size - position_index);
			while (i < n)
				_parent::_alloc->construct(_content + position_index + i++, *(first++));

			_parent::_size += n;
			_autoupdate();
		}

		iterator	erase(iterator first, iterator last)
		{
			size_type	first_index	= _get_iterator_index(first);
			size_type	last_index	= _get_iterator_index(last);
			size_type	n			= last_index - first_index;
			size_type	i			= n;
			
			while (i)
				_parent::_alloc->destroy(_content + first_index + --i);
			if (_parent::_size > last_index)
				_memmove(_content + first_index, _content + last_index, _parent::_size - last_index);

			_parent::_size -= n;
			_autoupdate();

			reserve(_parent::_size);

			return (ft::advance(this->begin(), first_index));
		}

		iterator	erase(iterator position)
		{
			return (erase(position, ft::advance(position, 1)));
		}

		void		swap(_self &x)
		{
			_parent::_swap_pointer(&_capacity, &x._capacity);
			_parent::_swap_pointer(&_content, &x._content);
			_parent::_swap(x);
		}

		void		clear(void)
		{
			erase(this->begin(), this->end());
		}

		allocator_type	get_allocator(void) const
		{
			return (_parent::_get_allocator());
		}
};

template< class T, class Alloc >
void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
{
	lhs.swap(rhs);
}

}

#endif
