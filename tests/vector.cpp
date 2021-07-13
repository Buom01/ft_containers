/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:03:56 by badam             #+#    #+#             */
/*   Updated: 2021/07/13 14:13:09 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VECTOR_CPP
# define TESTS_VECTOR_CPP

#include "tests.hpp"
#include "vector/access.hpp"
#include "vector/modifiers.hpp"
#include "vector/capacity.hpp"
#include "vector/operations.hpp"

namespace ft
{
namespace tests
{
namespace vector
{


void	access(std::string selection)
{
	test(
		vector_access_1< std::vector<E> >,
		vector_access_1< ft::vector<E> >,
		"vector_access_1",
		selection
	);
}

void	modifiers(std::string selection)
{
}

void	operations(std::string selection)
{
}

void	do_tests(std::string selection)
{
	access(selection);
	modifiers(selection);
	operations(selection);
}


}
}
}

#endif
