/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:07:57 by user              #+#    #+#             */
/*   Updated: 2021/06/23 10:24:16 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "list/modifiers.hpp"
#include "list/capacity.hpp"
#include "list/operations.hpp"

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
		list_capacity< std::list<E> >,
		list_capacity< ft::list<E> >,
		"list_capacity",
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
		list_insert_2< std::list<E> >,
		list_insert_2< ft::list<E> >,
		"list_insert_2",
		selection
	);

	test(
		list_insert_3< std::list<E> >,
		list_insert_3< ft::list<E> >,
		"list_insert_3",
		selection
	);

	test(
		list_resize< std::list<E> >,
		list_resize< ft::list<E> >,
		"list_resize",
		selection
	);

	test(
		list_assign_1< std::list<E> >,
		list_assign_1< ft::list<E> >,
		"list_assign_1",
		selection
	);

	test(
		list_assign_2< std::list<E> >,
		list_assign_2< ft::list<E> >,
		"list_assign_2",
		selection
	);

	test(
		list_assign_3< std::list<E> >,
		list_assign_3< ft::list<E> >,
		"list_assign_3",
		selection
	);

	test(
		list_assign_4< std::list<E> >,
		list_assign_4< ft::list<E> >,
		"list_assign_4",
		selection
	);

	test(
		list_assign_5< std::list<E> >,
		list_assign_5< ft::list<E> >,
		"list_assign_5",
		selection
	);

	test(
		list_assign_6< std::list<E> >,
		list_assign_6< ft::list<E> >,
		"list_assign_6",
		selection
	);

	test(
		list_remove< std::list<E> >,
		list_remove< ft::list<E> >,
		"list_remove",
		selection
	);

	test(
		list_remove_if< std::list<E> >,
		list_remove_if< ft::list<E> >,
		"list_remove_if",
		selection
	);

	test(
		list_reverse< std::list<E> >,
		list_reverse< ft::list<E> >,
		"list_reverse",
		selection
	);

	test(
		list_unique< std::list<E> >,
		list_unique< ft::list<E> >,
		"list_unique",
		selection
	);

	test(
		list_unique_1< std::list<E> >,
		list_unique_1< ft::list<E> >,
		"list_unique_1",
		selection
	);

	test(
		list_splice_3_1< std::list<E> >,
		list_splice_3_1< ft::list<E> >,
		"list_splice_3_1",
		selection
	);

	test(
		list_splice_3_2< std::list<E> >,
		list_splice_3_2< ft::list<E> >,
		"list_splice_3_2",
		selection
	);

	test(
		list_splice_3_3< std::list<E> >,
		list_splice_3_3< ft::list<E> >,
		"list_splice_3_3",
		selection
	);

	test(
		list_splice_3_4< std::list<E> >,
		list_splice_3_4< ft::list<E> >,
		"list_splice_3_4",
		selection
	);

	test(
		list_splice_3_5< std::list<E> >,
		list_splice_3_5< ft::list<E> >,
		"list_splice_3_5",
		selection
	);

	test(
		list_splice_3_6< std::list<E> >,
		list_splice_3_6< ft::list<E> >,
		"list_splice_3_6",
		selection
	);

	test(
		list_splice_3_7< std::list<E> >,
		list_splice_3_7< ft::list<E> >,
		"list_splice_3_7",
		selection
	);

	test(
		list_splice_3_8< std::list<E> >,
		list_splice_3_8< ft::list<E> >,
		"list_splice_3_8",
		selection
	);

	test(
		list_splice_2< std::list<E> >,
		list_splice_2< ft::list<E> >,
		"list_splice_2",
		selection
	);

	test(
		list_splice_1< std::list<E> >,
		list_splice_1< ft::list<E> >,
		"list_splice_1",
		selection
	);

/*
	test(
		list_sort_1< std::list<E> >,
		list_sort_1< ft::list<E> >,
		"list_sort_1",
		selection
	);

	test(
		list_sort_2< std::list<E> >,
		list_sort_2< ft::list<E> >,
		"list_sort_2",
		selection
	);

	test(
		list_sort_3< std::list<E> >,
		list_sort_3< ft::list<E> >,
		"list_sort_3",
		selection
	);

	test(
		list_sort_4< std::list<E> >,
		list_sort_4< ft::list<E> >,
		"list_sort_4",
		selection
	);
*/
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
