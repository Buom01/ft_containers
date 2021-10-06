/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:49:40 by badam             #+#    #+#             */
/*   Updated: 2021/10/05 13:15:10 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"


namespace ft
{

template< class T, class Container = ft::vector<T> >
class stack
{
	typedef stack		_self;
	typedef Container	_parent;

	public:
		typedef	container_type	Container;
		using typename _parent::value_type;
		using typename _parent::size_type;
		using typename _parent::reference;
		using typename _parent::const_reference;

	protected:
		Container	c;

	public:
		explicit	stack(const Container& cont = Container()): c(cont)
		{};

		virtual		~stack(void)
		{};

		_self	&operator=(const _self &other)
		{
			c = other.c;
		};

		reference		top(void)
		{
			return (c.back());
		};

		const_reference	top(void) const
		{
			return (c.back());
		};

		bool			empty() const
		{
			return (c.empty());
		};

		size_type		size() const
		{
			return (c.size());
		};

		void			push(const value_type& value)
		{
			c.push_back(value);
		};

		void			pop(void)
		{
			c.pop_back();
		};
};


template< class T, class Container >
bool	operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs.c == rhs.c);
}

template< class T, class Container >
bool	operator!=(const ft::core<T, Alloc, Item, Iterator, ConstIterator> &lhs, const ft::core<T, Alloc, Item, Iterator, ConstIterator> &rhs)
{
	return (lhs.c != rhs.c);
}

template< class T, class Container >
bool	operator<(const ft::core<T, Alloc, Item, Iterator, ConstIterator> &lhs, const ft::core<T, Alloc, Item, Iterator, ConstIterator> &rhs)
{
	return (lhs.c < rhs.c);
}

template< class T, class Container >
bool	operator<=(const ft::core<T, Alloc, Item, Iterator, ConstIterator> &lhs, const ft::core<T, Alloc, Item, Iterator, ConstIterator> &rhs)
{
	return (lhs.c <= rhs.c);
}

template< class T, class Container >
bool	operator>(const ft::core<T, Alloc, Item, Iterator, ConstIterator> &lhs, const ft::core<T, Alloc, Item, Iterator, ConstIterator> &rhs)
{
	return (lhs.c > rhs.c);
}

template< class T, class Container >
bool	operator>=(const ft::core<T, Alloc, Item, Iterator, ConstIterator> &lhs, const ft::core<T, Alloc, Item, Iterator, ConstIterator> &rhs)
{
	return (lhs.c >= rhs.c);
}

}

#endif
