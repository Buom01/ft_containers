/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:07:57 by user              #+#    #+#             */
/*   Updated: 2021/08/30 15:33:06 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.cpp"

bool	maydo(std::string testname, std::string selection)
{
	return true;
	return (selection.compare(testname) <= 0);
}

int	main(int argc, char **argv)
{
	std::string	selection;

	if (argc >= 2)
		selection = *(argv + 1);
	else
		selection = "";

	do_tests(selection);

	return (0);
}