/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:23:55 by badam             #+#    #+#             */
/*   Updated: 2021/04/26 10:38:16 by bastien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>

# include "common.hpp"


namespace ft
{

template< class Category, class T, class Alloc>
class	common;

template< class Category, class T, class Alloc >
class	iterator: public std::iterator<Category, T>
{
	protected:
		typedef iterator<Category, T, Alloc>	_self;
		typedef	ft::common<Category, T, Alloc>	_container;
		typedef	struct s_common_item<T>			_item;

		_item	**_back;
		_item 	*_elem;
		bool	_reversed;

	public:
		iterator(void)
		{
			_back = NULL;
			_elem = NULL;
			_reversed = false;
		};

		iterator(const iterator &src)
		{
			*this = src;
		};

		iterator(_item **back, _item *elem, bool reversed = false)
		{
			_back = back;
			_elem = elem;
			_reversed = reversed;
		};

		virtual	~iterator(void)
		{
		};


		iterator	&operator=(const iterator &ref)
		{
			if (this != &ref)
			{
				_back = ref.getBack();
				_elem = ref.getElem();
				_reversed = ref.getReversed();
			}

			return (*this);
		};

		iterator	&operator++(void)
		{
			if (_elem == *_back)
				_elem = NULL;
			else
				_elem = _elem->next;

			return (*this);
		};

		iterator	operator++(int)
		{
			_self	tmp(*this);

			++(*this);
			return (tmp);
		};

		iterator	&operator--(void);
		iterator	operator--(int);
		bool		operator==(const iterator &ref);
		bool		operator!=(const iterator &ref)
		{
			return (ref.getElem() != _elem);
		};

		T			&operator*(void)
		{
			return (*(_elem->content));
		};

		const T		&operator*(void) const
		{
			return (*(_elem->content));
		};

		T			&operator->(void)
		{
			return (*(_elem->content));
		};

		const T		&operator->(void) const
		{
			return (*(_elem->content));
		};


		// May want to get rid of following
		_item	*getElem(void) const
		{
			return (_elem);
		};

		_item	**getElemPtr(void)
		{
			return (&_elem);
		};

		_item	**getBack(void) const
		{
			return (_back);
		};

		bool	getReversed(void) const
		{
			return (_reversed);
		};
};

}

#endif
