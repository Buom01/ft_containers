/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:23:55 by badam             #+#    #+#             */
/*   Updated: 2021/03/31 01:57:09 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>

# include "ACommon.hpp"


template< class Category, class T, class Alloc>
class	ACommon;

template< class Category, class T, class Alloc >
class	Iterator: public std::iterator<Category, T>
{
	protected:
		typedef Iterator<Category, T, Alloc>	_self;
		typedef	ACommon<Category, T, Alloc>		_container;
		typedef	struct s_commonItem<T>			_item;

		_item	**_back;
		_item 	*_elem;
		bool	_reversed;

	public:
		Iterator(void)
		{
			_back = NULL;
			_elem = NULL;
			_reversed = false;
		};

		Iterator(const Iterator &src)
		{
			*this = src;
		};

		Iterator(_item **back, _item *elem, bool reversed = false)
		{
			_back = back;
			_elem = elem;
			_reversed = reversed;
		};

		virtual	~Iterator(void)
		{
		};


		Iterator	&operator=(const Iterator &ref)
		{
			if (this != &ref)
			{
				_back = ref.getBack();
				_elem = ref.getElem();
				_reversed = ref.getReversed();
			}

			return (*this);
		};

		Iterator	&operator++(void)
		{
			if (_elem == *_back)
				_elem = NULL;
			else
				_elem = _elem->next;

			return (*this);
		};

		Iterator	operator++(int)
		{
			_self	tmp(*this);

			++(*this);
			return (tmp);
		};

		Iterator	&operator--(void);
		Iterator	operator--(int);
		bool		operator==(const Iterator &ref);
		bool		operator!=(const Iterator &ref)
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

		_item	**getBack(void) const
		{
			return (_back);
		};

		bool	getReversed(void) const
		{
			return (_reversed);
		};
};

#endif
