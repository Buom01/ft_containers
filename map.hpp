/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:49:40 by badam             #+#    #+#             */
/*   Updated: 2021/12/18 21:56:56 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "utils.hpp"
# include "rbt.hpp"

namespace ft
{

template< class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
class map: public rbt<Key, T, pair<const Key, T>, pair<const Key, T>, Compare, Alloc>
{
	typedef map												_self;
	typedef	rbt<Key, T, pair<const Key, T>, pair<const Key, T>, Compare, Alloc>	_parent;

	public:
		typedef typename	_parent::key_type				key_type;
		typedef typename	_parent::mapped_type			mapped_type;
		typedef typename	_parent::value_type				value_type;
		typedef typename	_parent::key_compare			key_compare;
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
		map(): _parent()
		{};

		explicit map(const Compare &comp, const Alloc &alloc = allocator_type()): _parent(comp, alloc)
		{};

		template <class InputIt>
		map(InputIt first, InputIt last, const Compare& comp = key_compare(), const Alloc& alloc = allocator_type()):
			_parent(first, last, comp, alloc)
		{};

		map(const map &x): _parent(x)
		{};

		virtual	~map(void)
		{};

		mapped_type			&operator[](const key_type& key)
		{
			return (_parent::insert(ft::make_pair(key, T())).first->second);
		}

		mapped_type			&at(const Key& key)
		{
			iterator	it	= _parent::find(key);

			if (it == _parent::end())
				throw std::out_of_range("key");

			return (it->second);
		} 

		const mapped_type	&at(const Key& key) const
		{
			const_iterator	it	= _parent::find(key);

			if (it == _parent::end())
				throw std::out_of_range("key");

			return (it->second);
		} 
};

}

#endif
