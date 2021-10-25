/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/10/22 18:07:10 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_STACK_MODIFIERS_HPP
# define TESTS_STACK_MODIFIERS_HPP

template <class container>
int	stack_push(container &stack)
{
	stack.push(1);
	stack.push(2);

	if (stack.size() != 2 || stack.empty())
		return (1);
	
	return (0);
}

template <class container>
int	stack_pop(container &stack)
{
	stack.push(1);
	stack.push(2);
	stack.push(3);

	stack.pop();
	stack.pop();
	stack.pop();

	stack.push(7);
	stack.push(8);
	stack.push(9);

	stack.pop();

	if (stack.size() != 2 || stack.empty())
		return (1);
	
	return (0);
}

#endif

