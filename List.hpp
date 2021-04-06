/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:21:10 by badam             #+#    #+#             */
/*   Updated: 2021/04/06 06:37:37 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "ACommonIterator.hpp"


template < class T, class Alloc = std::allocator<T> >
class	List: public ACommonIterator<std::bidirectional_iterator_tag, T, Alloc> 
{
	typedef	ACommon<std::bidirectional_iterator_tag, T, Alloc>	_parent;
	typedef	Iterator<std::bidirectional_iterator_tag, T, Alloc>	_iterator;

	using typename _parent::reference;
	using typename _parent::const_reference;
	using typename _parent::size_type;


	public:
		size_type		max_size(void) const
		{
			return (_parent::_max_size());
		}

		// assign

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
			_parent::_insert(position, val);
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
			_parent::_erase(position);
		}

		_iterator		erase(_iterator first, _iterator last)
		{
			_parent::_erase(first, last);
		}

		// parent::swap

		// resize

		void			clear(void)
		{
			_parent::clear();
		}

		// all operator
		// reverse (may be easier to do at parent level ?)
};

#endif
