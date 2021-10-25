/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonmember.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/10/25 13:50:56 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_STACK_NONMEMBER_HPP
# define TESTS_STACK_NONMEMBER_HPP

template <class container>
int	stack_nm_equal_not_equal(container &stack)
{
	container	stack1;

	if (!(stack == stack1))
		return (1);
	if (stack != stack1)
		return (2);

	stack.push(1);

	if (stack == stack1)
		return (3);
	if (!(stack != stack1))
		return (4);

	stack1.push(1);

	if (!(stack == stack1))
		return (5);
	if (stack != stack1)
		return (6);

	stack1.push(2);

	if (stack == stack1)
		return (7);
	if (!(stack != stack1))
		return (8);

	stack.push(2);

	if (!(stack == stack1))
		return (9);
	if (stack != stack1)
		return (10);



	stack1.push(3);

	if (stack == stack1)
		return (11);
	if (!(stack != stack1))
		return (12);

	stack.push(3);

	if (!(stack == stack1))
		return (13);
	if (stack != stack1)
		return (14);

	stack.push(4);

	if (stack == stack1)
		return (15);
	if (!(stack != stack1))
		return (16);

	stack1.push(4);

	if (!(stack == stack1))
		return (17);
	if (stack != stack1)
		return (18);

	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack1.pop();
	stack1.pop();
	stack1.pop();
	stack1.pop();

	if (!(stack == stack1))
		return (19);
	if (stack != stack1)
		return (20);

	return (0);
}
template <class container>
void	_stack_nm_dump_compare(container &out, container first, container second)
{
	out.push(first == second);
	out.push(first >= second);
	out.push(first <= second);
	out.push(first != second);
	out.push(first > second);
	out.push(first < second);
	out.push(2);
}

template <class container>
int	stack_nm_compare(container &stack)
{
	{
		container first;
		container second;
		
		_stack_nm_dump_compare(stack, first, second);

		first.push(1);
		_stack_nm_dump_compare(stack, first, second);
		
		second.push(2);
		_stack_nm_dump_compare(stack, first, second);
		
		first.push(3);
		_stack_nm_dump_compare(stack, first, second);
		
		second.push(4);
		_stack_nm_dump_compare(stack, first, second);
		
		second.push(5);
		_stack_nm_dump_compare(stack, first, second);
	}

	{
		container first;
		container second;
		
		_stack_nm_dump_compare(stack, second, first);

		first.push(1);
		_stack_nm_dump_compare(stack, second, first);
		
		second.push(2);
		_stack_nm_dump_compare(stack, second, first);
		
		first.push(3);
		_stack_nm_dump_compare(stack, second, first);
		
		second.push(4);
		_stack_nm_dump_compare(stack, second, first);
		
		second.push(5);
		_stack_nm_dump_compare(stack, second, first);
	}

	return (0);
}

#endif