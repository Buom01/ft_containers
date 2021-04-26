/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:21:10 by badam             #+#    #+#             */
/*   Updated: 2021/04/26 10:32:33 by bastien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "common_iterator.hpp"


namespace ft
{

template < class T, class Alloc = std::allocator<T> >
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
		size_type		max_size(void) const
		{
			return (_parent::_max_size());
		}

		template <class InputIterator>
		void			assign(InputIterator first, InputIterator last)
		{
			_parent::_clear();
			_parent::_insert(_parent::_begin, first, last);
		}

		void			assign(size_type n, const T &val)
		{
			_parent::_clear();
			_parent::_insert(_parent::_begin, n, val);
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
			_iterator	it	= _parent::_begin;

			while (n-- && it != _parent::_end)
					++it;
			if (n)
				_parent::_insert(_parent::_end, n, val);
			else
				_parent::_erase(it, _parent::_end);
		}

		void			clear(void)
		{
			_parent::clear();
		}

		void	splice(_iterator position, list &x)
		{
			splice(position, x, x._begin, x._end);
		}

		void	splice(_iterator position, list &x, _iterator i)
		{
			_iterator	end(i);

			++end;
			splice(position, x, i, end);
		}

		void	splice(_iterator position, list &x, _iterator first, _iterator last)
		{
			size_type	movelength	= 0;
			_iterator	incLast		= last;
			_item		next		= position.getElem();
			_item		prev		= next->prev;

			--incLast;

			if (!_parent::_front || position.getElem() == _parent::_front.getElem())
				_parent::_update_front(first.getElem());
			if (!_parent::_back || !position.getElem())
				_parent::_update_back(incLast.getElem());

			if (x._front == first.getElem() && x._back == incLast.getElem())
				x._update(NULL, NULL);
			else if (x._front == first.getElem())
				x._update_front(last.getElem());
			else if (x._back == incLast.getElem())
				x._update_back(first.getElem()->prev);

			if (!first.getElem()->prev != incLast.getElem())
			{
				incLast.getElem()->next->prev = first.getElem()->prev;
				first.getElem()->prev->next = incLast.getElem()->next;
			}

			prev->next = first.getElem();
			next->prev = incLast.getElem();
			first.getElem()->prev = prev;
			incLast.getElem()->next = next;

			while (first++ != last)
				++movelength;
			x._size -= movelength;
			_parent::_size += movelength;
		}

		void	remove(const T &val)
		{
			static struct s_is_val
			{
				const T *refval;
  				bool	operator() (const T& value)
				{
					return (value == *refval);
				}
				void	set_refval(const T *val)
				{
					refval = val;
				}
			} is_val;

			is_val.set_refval(val);
			remove_if(is_val);
		}

		template <class Predicate>
		void	remove_if(Predicate pred)
		{
			_iterator	it	= _parent::_begin;

			while (it != _parent::_end)
			{
				if (pred(*it))
					it = _parent::_erase(it);
				else
					++it;
			}
		}

		void	unique(void)
		{
			static struct s_binary_pred
			{
				bool	operator() (const T first, const T second)
				{
					return (first == second);
				}
			} binary_pred;

			unique(binary_pred);
		}

		template <class BinaryPredicate>
		void	unique(BinaryPredicate binary_pred)
		{
			_iterator	prev	= _parent::_begin;
			_iterator	it		= prev;

			if (prev == _parent::_end)
				return ;
			++it;
			while (it != _parent::_end)
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

		void	merge(list &x)
		{
			static struct s_comp
			{
				bool	operator() (const T first, const T second)
				{
					return (first < second);
				}
			} comp;

			merge(x, comp);
		}

		template <class Compare>
		void	merge (list &x, Compare comp)
		{
			_iterator	it	=	_parent::_begin;
			_iterator	itx	=	x._begin;

			while (itx != _parent::_end)
			{
				if (it == _parent::_end || comp(*itx, *it))
					splice(it, x, itx++);
				else
					++it;
			}
		}

		void	sort(void)
		{
			static struct s_comp
			{
				bool	operator() (const T first, const T second)
				{
					return (first < second);
				}
			} comp;

			sort(comp);
		}

		template <class Compare>
		void	sort(Compare comp)
		{
			if (!_parent::_begin)
				return ;

			_update_front(_sort(comp, _parent::_begin, _parent::getSize()).getElem());
			_update_back(_parent::_front->prev);
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
		template <class Compare>
		_iterator 	_sort(Compare comp, _iterator items, size_type size, size_type begin)
		{
			while (begin--)
				++items;

			if (size > 1)
			{
				size_type	size_A				= size / 2;
				size_type	size_B				= (size + 1) / 2;
				_iterator	prev_last_sorted	= items;

				_iterator	A		= _sort(comp, items, size_A, 0);
				_iterator	B		= _sort(comp, items, size_B, size_A);

				--prev_last_sorted;
				while (size_A || size_B)
				{
					if (size_A && comp(*A, *B))
					{
						splice((++prev_last_sorted)--, this, A++);
						--size_A;
					}
					else
					{
						splice((++prev_last_sorted)--, this, B++);
						--size_B;
					}
				}
				while (--size)
					--prev_last_sorted;
				return (prev_last_sorted);
			}
			else
				return (items);
		}
};

}

#endif
