/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/10/22 18:07:02 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_STACK_ACCESS_HPP
# define TESTS_STACK_ACCESS_HPP

template <class container>
int	stack_access(container &stack)
{
	if (stack.size() != 0 || !stack.empty())
		return (1);

	stack.push(1);
	if (stack.top() != 1)
		return (2);
	
	if (stack.size() != 1 || stack.empty())
		return (3);

	stack.push(2);
	if (stack.top() != 2)
		return (4);
	
	if (stack.size() != 2 || stack.empty())
		return (5);

	return (0);
}

#endif

