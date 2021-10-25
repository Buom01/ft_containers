/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   members.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/10/25 12:03:31 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_STACK_MEMBERS_HPP
# define TESTS_STACK_MEMBERS_HPP

template <class container>
int	stack_memberstypes_1(container &stack)
{
	static_cast<void>(stack);

	typename container::value_type				T;
	typename container::container_type			ContainerType;
	typename container::size_type				SizeType;

	static_cast<void>(T);
	static_cast<void>(ContainerType);
	static_cast<void>(SizeType);

	return (0);
}

template <class container>
int	stack_memberstypes_2(container &stack)
{
	static_cast<void>(stack);

	typename container::size_type				SizeType		= 0;

	if (--SizeType < 0)
		return (1);

	return (0);
}

template <class container, class vector>
int	stack_contructors(container &stack)
{
	vector		vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	container	new_stack(vec);

	stack.push(new_stack.top());

	return (0);
}

#endif

