/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:21:10 by badam             #+#    #+#             */
/*   Updated: 2021/03/31 18:34:20 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "ACommonIterator.hpp"


template < class T, class Alloc = std::allocator<T> >
class	List: public ACommonIterator<std::bidirectional_iterator_tag, T, Alloc> 
{
	typedef	ACommon<std::bidirectional_iterator_tag, T, Alloc>	_parent;

	using typename _parent::reference;
	using typename _parent::const_reference;
	using typename _parent::size_type;


	public:
		size_type		max_size(void) const
		{
			return (_parent::_max_size());
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

		// assign

		void	push_front(const_reference val)
		{
			_parent::_push_front(val);
		}

		void	push_back(const_reference val)
		{
			_parent::_push_back(val);
		}

		void	pop_front(void)
		{
			_parent::_pop_front();
		}

		void	pop_back(void)
		{
			_parent::_pop_back();
		}

		// resize
};

#endif
