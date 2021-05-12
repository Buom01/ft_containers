/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:07:57 by user              #+#    #+#             */
/*   Updated: 2021/05/12 15:14:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "list/easy.hpp"

namespace ft
{
namespace tests
{


inline bool	maydo(std::string testname, std::string selection)
{
	return (selection.compare(testname) <= 0);
}

void	do_tests(std::string selection)
{
	test(
		list_push_frontback< std::list<T> >,
		list_push_frontback< ft::list<T> >,
		"list_push_frontback",
		selection
	);

	test(
		list_pushpop_frontback< std::list<T> >,
		list_pushpop_frontback< ft::list<T> >,
		"list_pushpop_frontback",
		selection
	);

	test(
		list_clear< std::list<T> >,
		list_clear< ft::list<T> >,
		"list_clear",
		selection
	);
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
