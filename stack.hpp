/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:49:40 by badam             #+#    #+#             */
/*   Updated: 2021/10/22 16:12:12 by badam            ###   ########.fr       */
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
	typedef stack< T, Container >	_self;

	public:
		typedef				Container					container_type;
		typedef typename	Container::value_type		value_type;
		typedef typename	Container::size_type		size_type;
		typedef typename	Container::reference		reference;
		typedef typename	Container::const_reference	const_reference;

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


		friend bool	operator==(const _self &lhs, const _self &rhs)
		{
			return (lhs.c == rhs.c);
		}
		
		friend bool	operator!=(const _self &lhs, const _self &rhs)
		{
			return (lhs.c != rhs.c);
		}
		
		friend bool	operator<(const _self &lhs, const _self &rhs)
		{
			return (lhs.c < rhs.c);
		}
		
		friend bool	operator<=(const _self &lhs, const _self &rhs)
		{
			return (lhs.c <= rhs.c);
		}
		
		friend bool	operator>(const _self &lhs, const _self &rhs)
		{
			return (lhs.c > rhs.c);
		}
		
		friend bool	operator>=(const _self &lhs, const _self &rhs)
		{
			return (lhs.c >= rhs.c);
		}
};

}

#endif