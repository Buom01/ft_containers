/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommonIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:07:46 by badam             #+#    #+#             */
/*   Updated: 2021/04/06 06:39:11 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACOMMONITERATOR_HPP
# define ACOMMONITERATOR_HPP

# include "ACommon.hpp"
# include "Iterator.hpp"


template< class Category, class T, class Alloc>
class	ACommonIterator: public ACommon<Category, T, Alloc>
{
	typedef	ACommon<Category, T, Alloc>	_parent;

	using typename _parent::reference;
	using typename _parent::const_reference;


	public:
		typedef	Iterator<Category, T, Alloc>	iterator;
		//typedef	Iterator<Category, T>	const_iterator;
		//typedef	Iterator<Category, T>	reverse_iterator;  // May set a child of itertor which set _reversed = true automatically
		//typedef	Iterator<Category, T>	const_reverse_iterator;

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
			return (*_parent::_front);
		}

		const_reference	back(void) const
		{
			return (*_parent::_front);
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

#endif
