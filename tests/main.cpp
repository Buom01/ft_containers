/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:07:57 by user              #+#    #+#             */
/*   Updated: 2021/12/20 17:59:15 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "vector.cpp"
#include "stack.cpp"
#include "map.cpp"
#include "set.cpp"

bool	maydo(std::string testname, std::string selection)
{
	return (testname.rfind(selection, 0) == 0);
}

int	main(int argc, char **argv)
{
	std::string	selection;

	if (argc >= 2)
		selection = *(argv + 1);
	else
		selection = "";

	vector_tests(selection);
	stack_tests(selection);
	map_tests(selection);
	set_tests(selection);

	return (0);
}