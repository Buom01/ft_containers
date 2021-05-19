/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:07:57 by user              #+#    #+#             */
/*   Updated: 2021/05/19 15:28:42 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "list/modifiers.hpp"

namespace ft
{
namespace tests
{


inline bool	maydo(std::string testname, std::string selection)
{
	return (selection.compare(testname) <= 0);
}

void	modifiers(std::string selection)
{
	test(
		list_push_frontback< std::list<E> >,
		list_push_frontback< ft::list<E> >,
		"list_push_frontback",
		selection
	);

	test(
		list_pop_frontback< std::list<E> >,
		list_pop_frontback< ft::list<E> >,
		"list_pop_frontback",
		selection
	);

	test(
		list_clear< std::list<E> >,
		list_clear< ft::list<E> >,
		"list_clear",
		selection
	);

	test(
		list_swap< std::list<E> >,
		list_swap< ft::list<E> >,
		"list_swap",
		selection
	);

	test(
		list_erase< std::list<E> >,
		list_erase< ft::list<E> >,
		"list_erase",
		selection
	);

	test(
		list_insert_1< std::list<E> >,
		list_insert_1< ft::list<E> >,
		"list_insert_1",
		selection
	);

	test(
		list_insert_3< std::list<E> >,
		list_insert_3< ft::list<E> >,
		"list_insert_3",
		selection
	);

	test(
		list_insert_4< std::list<E> >,
		list_insert_4< ft::list<E> >,
		"list_insert_4",
		selection
	);

	test(
		list_resize< std::list<E> >,
		list_resize< ft::list<E> >,
		"list_resize",
		selection
	);
}

void	do_tests(std::string selection)
{
	modifiers(selection);
}


}
}


int	main(int argc, char **argv)
{
	std::string	selection;

	if (argc >= 2)
		selection = *(argv + 1);
	else
		selection = "";

	ft::tests::do_tests(selection);

	return (0);
}
