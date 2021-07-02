/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:07:46 by badam             #+#    #+#             */
/*   Updated: 2021/06/27 09:40:22 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_ITERATOR_HPP
# define COMMON_ITERATOR_HPP

# include "common.hpp"
# include "iterator.hpp"


namespace ft
{

template< class Category, class T, class Alloc>
class	common_iterator: public ft::common<Category, T, Alloc>
{
	typedef	common<Category, T, Alloc>	_parent;

	using typename _parent::reference;
	using typename _parent::const_reference;


	public:
		typedef	ft::iterator<Category, T, Alloc>	iterator;
		typedef	ft::iterator<Category, T, Alloc>	const_iterator; // TMP
		typedef	ft::iterator<Category, T, Alloc>	reverse_iterator;  // May set a child of itertor which set _reversed = true automatically
		typedef	ft::iterator<Category, T, Alloc>	const_reverse_iterator;

		reference		front(void)
		{
			return (*(_parent::_front->content));
		}

		const_reference	front(void) const
		{
			return (*(_parent::_front->content));
		}

		reference		back(void)
		{
			return (*(_parent::_back->content));
		}

		const_reference	back(void) const
		{
			return (*(_parent::_back->content));
		}

		iterator		begin(void) const
		{
			return (*_parent::_begin);
		};

		iterator		end(void) const
		{
			return (*_parent::_end);
		}

		iterator		rbegin(void) const
		{
			return (*_parent::_rbegin);
		};

		iterator		rend(void) const
		{
			return (*_parent::_rend);
		}
};

}

#endif
