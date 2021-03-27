/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:23:55 by badam             #+#    #+#             */
/*   Updated: 2021/03/28 00:24:10 by badam            ###   ########.fr       */
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
		typedef	ACommon<Category, T, Alloc>	_container;
		typedef	struct s_commonItem<T>		_item;

		_container	*_content;
		_item 		*_elem;

	public:
		Iterator(void)
		{
			_content = NULL;
			_elem = NULL;
		};
		Iterator(const Iterator &src);
		Iterator(_container *content, _item *elem)
		{
			_content = content;
			_elem = elem;
		};
		virtual	~Iterator(void)
		{
		};

		Iterator	&operator=(const Iterator &ref);
		Iterator	&operator++(void);
		Iterator	operator++(int);
		Iterator	&operator--(void);
		Iterator	operator--(int);
		bool		operator==(const Iterator &ref);
		bool		operator!=(const Iterator &ref);
		T			&operator*(void);
		const T		&operator*(void) const;
		T			&operator->(void);
		const T		&operator->(void) const;
};

#endif
