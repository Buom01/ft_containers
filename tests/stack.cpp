/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:03:56 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 19:18:02 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_STACK_CPP
# define TESTS_STACK_CPP

#include "tests.hpp"
#include "stack/members.hpp"
#include "stack/access.hpp"
#include "stack/modifiers.hpp"
#include "stack/nonmember.hpp"

void	stack_members(std::string selection)
{
	stack_test(
		stack_memberstypes_1< std::stack<E> >,
		stack_memberstypes_1< ft::stack<E> >,
		"stack_memberstypes_1",
		selection
	);

	stack_test(
		stack_memberstypes_2< std::stack<E> >,
		stack_memberstypes_2< ft::stack<E> >,
		"stack_memberstypes_2",
		selection
	);

	stack_test(
		stack_contructors< std::stack< E, std::vector<E> >, std::vector<E> >,
		stack_contructors< ft::stack< E, ft::vector<E> >, ft::vector<E> >,
		"stack_contructors",
		selection
	);
}
void	stack_access(std::string selection)
{
	stack_test(
		stack_access< std::stack<E> >,
		stack_access< ft::stack<E> >,
		"stack_access",
		selection
	);
}

void	stack_modifiers(std::string selection)
{
	stack_test(
		stack_push< std::stack<E> >,
		stack_push< ft::stack<E> >,
		"stack_push",
		selection
	);
	
	stack_test(
		stack_pop< std::stack<E> >,
		stack_pop< ft::stack<E> >,
		"stack_pop",
		selection
	);
}

void	stack_nonmemeber(std::string selection)
{
	stack_test(
		stack_nm_equal_not_equal< std::stack<E> >,
		stack_nm_equal_not_equal< ft::stack<E> >,
		"stack_nm_equal_not_equal",
		selection
	);

	stack_test(
		stack_nm_compare< std::stack<E> >,
		stack_nm_compare< ft::stack<E> >,
		"stack_nm_compare",
		selection
	);
}

/*
** empty() and size() members are both
** tested along other tests
*/
void	stack_tests(std::string selection)
{
	stack_members(selection);
	stack_access(selection); 
	stack_modifiers(selection);
	stack_nonmemeber(selection);
}

#endif
