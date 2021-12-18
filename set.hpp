/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:49:40 by badam             #+#    #+#             */
/*   Updated: 2021/12/18 16:48:36 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "utils.hpp"
# include "rbt.hpp"

namespace ft
{

template< class T, class Compare = less<T>, class Alloc = std::allocator<T> >
class set: public rbt<T, T, T, Compare, Alloc>
{
	typedef set< T, Compare, Alloc >		_self;
	typedef rbt< T, T, T, Compare, Alloc >	_parent;

	public:
		typedef typename	_parent::key_type				key_type;
		typedef typename	_parent::value_type				value_type;
		typedef typename	_parent::key_compare			key_compare;
		typedef typename	_parent::value_compare			value_compare;
		typedef typename	_parent::allocator_type			allocator_type;
		typedef typename	_parent::reference				reference;
		typedef typename	_parent::const_reference		const_reference;
		typedef typename	_parent::pointer				pointer;
		typedef typename	_parent::const_pointer			const_pointer;
		typedef typename	_parent::iterator				iterator;
		typedef typename	_parent::const_iterator			const_iterator;
		typedef typename	_parent::reverse_iterator		reverse_iterator;
		typedef typename	_parent::const_reverse_iterator	const_reverse_iterator;
		typedef typename	_parent::difference_type		difference_type;
		typedef typename	_parent::size_type				size_type;

	public:
		set(): _parent()
		{};

		explicit set( const Compare& comp, const Alloc& alloc = Alloc() ): _parent(comp, alloc)
		{};

		template< class InputIt >
		set( InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc() ):
			_parent(first, last, comp, alloc)
		{};

		set( const set& other ): _parent(other)
		{}

		virtual		~set(void)
		{};
};

}

#endif
