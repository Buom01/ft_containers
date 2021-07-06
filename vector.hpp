/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:49:40 by badam             #+#    #+#             */
/*   Updated: 2021/07/06 14:41:58 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ARRAY_HPP
# define CORE_ARRAY_HPP

# include <stdexcept>
# include "core.hpp"
# include "iterator_array.hpp"


namespace ft
{

template< class T, class Alloc >
class vector: public ft::core< T, Alloc, *T, iterator_array>
{
	typedef	ft::core<T, Alloc, *T, iterator_array>	_parent;

	using typename _parent::iterator;
	using typename _parent::_item;
	using typename _parent::allocator_type;
	using typename _parent::reference;
	using typename _parent::const_reference;
	using typename _parent::size_type;

	protected:
		size_type	_capacity;  // Do constructors and init following
		pointer		_content;

		void	_ensure_capacity(size_type n)
		{
			if (_capacity < n)
				reserve(n);
		}

		void	_extend_size(size_type n)
		{
			if (size + n > _capacity)
				_ensurecapacity(size + n + 10);
		}

		template <class ptr>
		void	_swap_pointer(ptr *a, ptr *b)
		{
			ptr	tmp;

			tmp = *a;
			*a = *b;
			*b = tmp;
		}

		void	_init(const allocator_type &alloc, size_type capacity = 10)
		{
			_capacity = 0;
			_content = NULL;
			_parent::_init(alloc);
			_ensure_capacity(capacity);
		}

	public:
		explicit vector(const allocator_type &alloc
							= _parent::allocator_type())
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

		vector(const vector &x)
		{
			_init(allocator_type());
			this = x;
		};

		virtual	~vector(void)
		{
			if (_content)
				// free up there
		};

		core_array	&operator=(const vector &ref)
		{
			iterator	it;

			if (this == &ref)
				return (*this);

			it = ref.begin();
			while(it != ref.end())
			{
				push_back(*it); // may use insert
				++it;
			}

			return (*this);
		};

		iterator	begin(void) const
		{
			return (*_parent::_begin);
		};

		iterator	end(void) const
		{
			return (*_parent::_end);
		}

		iterator	rbegin(void) const
		{
			return (*_parent::_rbegin);
		};

		iterator	rend(void) const
		{
			return (*_parent::_rend);
		}

		size_type	max_size(void) const
		{
			return (_parent::_max_size());
		}

		void		resize(size_type n, T val = T())
		{
			_iterator	it	= *_parent::_begin;

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
			size_type	i = 0;
			if (n <= _capacity)
				return ;
			if (n > max_size())
				throw new std::length_error("n");

			oldcontent = _content;
			_content = _parent::_alloc::allocate(n, oldcontent);
			while (i < _parent::_size)
			{
				 _parent::_alloc::construct(&(_content[i]), oldcontent[i]);
				 _parent::_alloc::destroy(&(oldcontent[i]));
				++i;
			}
			if (oldcontent)
				_parent::_alloc::deallocate(oldcontent, _capacity);
			_capacity = n;
			//_update(...);
		}

		reference		operator[](size_type n)
		{
			return (_content[n]);
		}

		const_reference	operator[](size_type n) const
		{
			return (content[n]);
		}

		reference		at(size_type n)
		{
			if (n < 0 || n >= size())
				throw new std::out_of_range("n");

			return (_content[n]);
		} 

		const_reference	at(size_type n) const
		{
			if (n < 0 || n >= size())
				throw new std::out_of_range("n");

			return (_content[n]);
		} 

		reference		front(void)
		{
			return (**_parent::_front);
		}

		const_reference	front(void) const
		{
			return (**_parent::_front);
		}

		reference		back(void)
		{
			return (**_parent::_back);
		}

		const_reference	back(void) const
		{
			return (**_parent::_back);
		}

		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last)
		{
			clear();
			while (first != last)
				push_back(*(first++));
		}

		void	assign(size_type n, const value_type &val)
		{
			clear();
			insert(*_parent::_end, n, val);
		}

		void	push_back(const value_type &val)
		{
			insert(_parent::_end, val);
		}

		void	pop_back(void)
		{
			erase(_parent::_end); 
		}

		iterator	insert(iterator position, const value_type &val)
		{
			insert(position, 1, val);

			return (position);
		}

		void		insert(iterator position,
						size_type n, const value_type &val)
		{
			_preextend_size(n);

			// magic here, may use memmove
			//_content[size()] = val;
			++_parent::_size;
			_update_back(...);
		}

		template <class InputIterator>
		void		insert(iterator position,
						InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(position, *(first++));
				position += 2;
			}
			_update(...);
		}

		iterator	erase(iterator position)
		{
			// magic here, may use memmove
			--_parent::_size;
			if (size() + 110 < _capacity)
				reserve(size() + 10);
		}

		iterator	erase(iterator first, iterator last)
		{
			while (last != first)
				erase(--last);
		}

		void		swap(list &x)
		{
			_swap_pointer(&_parent::_begin, &x._begin);
			_swap_pointer(&_parent::_end, &x._end);
			_swap_pointer(&_parent::_rbegin, &x._rbegin);
			_swap_pointer(&_parent::_rend, &x._rend);
			_swap_pointer(&_parent::_front, &x._front);
			_swap_pointer(&_parent::_back, &x._back);
			_swap_pointer(&_parent::_size, &x._size);
			_swap_pointer(&_parent::_capacity, &x._capacity);
			_swap_pointer(&_parent::_content, &x._content);
		}

		void		clear(void)
		{
			_parent::_size = 0;
			reserve(10);
			//_update(NULL, NULL);  // reserve should do the update
		}

		allocator_type	get_allocator(void) const
		{
			// may review that and usage of allocator in all code
			allocator_type	allocator;

			return (allocator);
		}

		// relational operators
		// swap
		// vector<bool>
};
