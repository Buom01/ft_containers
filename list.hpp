/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:21:10 by badam             #+#    #+#             */
/*   Updated: 2021/06/25 16:09:41 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "common_iterator.hpp"


namespace ft
{

template< class T, class Alloc = std::allocator<T> >
class	list: public ft::common_iterator<std::bidirectional_iterator_tag, T, Alloc> 
{
	typedef	ft::common<std::bidirectional_iterator_tag, T, Alloc>	_parent;
	using typename _parent::_iterator;
	using typename _parent::_item;

	using typename _parent::allocator_type;
	using typename _parent::reference;
	using typename _parent::const_reference;
	using typename _parent::size_type;


	public:
		explicit list(const allocator_type &alloc = allocator_type())
		{
			_parent::_init(alloc);
		}

		explicit list(size_type n, const T &val = T(),
				const allocator_type &alloc = allocator_type())
		{
			_parent::_init(alloc);
			assign(n, val);
		}

/*
		list(x, y) with int use this instead of the right one

		template <class InputIterator>
		list (InputIterator first, InputIterator last,
				const allocator_type &alloc = allocator_type())
		{
			_parent::_init(alloc);
			assign<InputIterator>(first, last);
		}
*/

		list (const list &x)
		{
			*this = x;
		}

		size_type		max_size(void) const
		{
			return (_parent::_max_size());
		}

		template <class InputIterator>
		void			assign(InputIterator first, InputIterator last)
		{
			_parent::_clear();
			_parent::template _insert<InputIterator>(*_parent::_begin, first, last);
		}

		void			assign(size_type n, const T &val)
		{
			_parent::_clear();
			_parent::_insert(*_parent::_begin, n, val);
		}

		void			push_front(const_reference val)
		{
			_parent::_push_front(val);
		}

		void			push_back(const_reference val)
		{
			_parent::_push_back(val);
		}

		void			pop_front(void)
		{
			_parent::_pop_front();
		}

		void			pop_back(void)
		{
			_parent::_pop_back();
		}

		_iterator		insert(_iterator position, const T &val)
		{
			return (_parent::_insert(position, val));
		}

		void			insert(_iterator position, size_type n, const T &val)
		{
			_parent::_insert(position, n, val);
		}

		template <class InputIterator>
		void			insert(_iterator position, InputIterator first, InputIterator last)
		{
			_parent::template _insert<InputIterator>(position, first, last);
		}

		_iterator		erase(_iterator position)
		{
			return (_parent::_erase(position));
		}

		_iterator		erase(_iterator first, _iterator last)
		{
			return (_parent::_erase(first, last));
		}

		void			swap(list &x)
		{
			_parent::_swap(x);
		}

		void			resize(size_type n, T val = T())
		{
			_iterator	it	= *_parent::_begin;

			while (n && it != *_parent::_end)
			{
				--n;
				++it;
			}
			if (n)
				_parent::_insert(*_parent::_end, n, val);
			else
				_parent::_erase(it, *_parent::_end);
		}

		void			clear(void)
		{
			_parent::_clear();
		}

		void	splice(_iterator position, list &x)
		{
			splice(position, x, *(x._begin), *(x._end));
		}

		void	splice(_iterator position, list &x, _iterator i)
		{
			_iterator	end(i);

			++end;
			splice(position, x, i, end);
		}

		void	splice(_iterator position, list &x, _iterator first, _iterator last)  // had to use const_iterator
		{
			size_type	movelength	= 0;
			_iterator	i;
			_item		*ifirst;
			_item		*ilast;
			_item		*prev;
			_item		*next;
			_item		*xprev;
			_item		*xnext;


			if (!x.size() || !(first.getElem()) || first == position)
				return ;

			i = first;
			while (i++ != last)
				++movelength;

			--last;
			i = position;
			--i;

			ifirst = first.getElem();
			ilast = last.getElem();
			xprev = ifirst->prev;
			xnext = ilast->next;
			prev = i.getElem();
			next = position.getElem();

			if (ifirst->prev == ilast && &x != this)
				x._update(NULL, NULL);
			else
			{
				xprev->next = xnext;
				xnext->prev = xprev;
				if (ilast == x._back)
					x._update_back(xprev);
				else if (ifirst == x._front)
					x._update_front(xnext);
			}

			if (!prev && !next)
			{
				ifirst->prev = ilast;
				ilast->next = ifirst;					
				_parent::_update(ifirst, ilast);
			}
			else
			{
				if (!next)
				{
					_parent::_update_back(ilast);
					next = prev->next;
				}
				else if (!prev)
				{
					_parent::_update_front(ifirst);
					prev = next->prev;
				}

				{
					prev->next = ifirst;
					ifirst->prev = prev;
					next->prev = ilast;
					ilast->next = next;
				}
			}

			x._size -= movelength;
			_parent::_size += movelength;
		}

	private:
		struct s_is_val
		{
			const T *refval;
  			bool	operator() (const T& value)
			{
				return (value == *refval);
			}
			void	set_refval(const T &val)
			{
				refval = &val;
			}
		} is_val;
		
	public:
		void	remove(const T &val)
		{
			is_val.set_refval(val);
			remove_if(is_val);
		}

		template <class Predicate>
		void	remove_if(Predicate pred)
		{
			_iterator	it	= *_parent::_begin;

			while (it != *_parent::_end)
			{
				if (pred(*it))
					it = _parent::_erase(it);
				else
					++it;
			}
		}

	private:
	struct s_binary_pred
	{
		bool	operator() (const T first, const T second)
		{
			return (first == second);
		}
	} binary_pred;

	public:
		void	unique(void)
		{
			unique(binary_pred);
		}

		template <class BinaryPredicate>
		void	unique(BinaryPredicate binary_pred)
		{
			_iterator	prev	= *_parent::_begin;
			_iterator	it		= prev;

			if (prev == *_parent::_end)
				return ;
			++it;
			while (it != *_parent::_end)
			{
				if (binary_pred(*it, *prev))
					it = _parent::_erase(it);
				else
				{
					++it;
					++prev;
				}
			}
		}

	private:
	struct s_comp_pred
	{
		bool	operator() (const T first, const T second)
		{
			return (first < second);
		}
	} comp_pred;

	public:
		void	merge(list &x)
		{
			merge(x, comp_pred);
		}

		template <class Compare>
		void	merge (list &x, Compare comp)
		{
			_iterator	it	=	*_parent::_begin;
			_iterator	itx	=	*(x._begin);

			if (&x == this)
				return ;
			while (itx != *_parent::_end)
			{
				if (it == *_parent::_end || comp(*itx, *it))
					splice(it, x, itx++);
				else
					++it;
			}
		}

	private:
		struct s_sort_comp
		{
			bool	operator() (const T first, const T second)
			{
				return (first < second);
			}
		} sort_comp;

	public:
		void	sort(void)
		{
			sort(sort_comp);
		}

		template <class Compare>
		void	sort(Compare comp)
		{
			if (!_parent::_begin)  // Must review this two lines
				return ;

			_parent::_update_front(
				_sort(
					comp,
					*_parent::_begin,
					_parent::_size
				).getElem()
			);
			_parent::_update_back(_parent::_front->prev);
		}

		void	reverse(void)
		{
			_item	*front	= _parent::_front;
			_item	*back	= _parent::_back;
			_item	*i		= front;
			_item	*tmp	= NULL;

			if (!front)
				return ;
			while (tmp != front)
			{
				tmp = i->next;
				i->next = i->prev;
				i->prev = tmp;
				i = tmp;
			}
			_parent::_update(back, front);
		}

		allocator_type	get_allocator(void) const
		{
			return (_parent::_get_allocator());
		}

	private:
		_iterator	_advance(_iterator it, size_type n)
		{
			while (n--)
				++it;
			return (it);
		}

		template <class Compare>
		_iterator 	_sort(Compare &comp, _iterator items, size_type size)
		{
			if (size > 1)
			{
				size_type	size_A	= size / 2;
				size_type	size_B	= (size + 1) / 2;
				_iterator	A		= items;
				_iterator	B		= _advance(items, size_A);
				_iterator	begin	= items;
				_iterator	sorted;

				--begin;
				A = _sort(comp, A, size_A);
				++begin;
				B = _sort(comp, B, size_B);
				--begin;

				sorted = begin;
				while (size_A || size_B)
				{
					if (size_B && (!size_A || comp(*B, *A)))
					{
						splice((++sorted)--, *this, B++);
						++sorted;
						--size_B;
					}
					else
					{
						splice((++sorted)--, *this, A++);
						++sorted;
						--size_A;
					}
				}
				++begin;
				return (begin);
			}
			else
				return (items);
		}
};

}

#endif
