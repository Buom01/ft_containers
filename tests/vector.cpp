/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:03:56 by badam             #+#    #+#             */
/*   Updated: 2021/09/09 14:57:47 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VECTOR_CPP
# define TESTS_VECTOR_CPP

#include "tests.hpp"
#include "vector/access.hpp"
#include "vector/modifiers.hpp"
//#include "vector/capacity.hpp"
//#include "vector/operations.hpp"

void	access(std::string selection)
{
	test(
		vector_access_1< std::vector<E> >,
		vector_access_1< ft::vector<E> >,
		"vector_access_1",
		selection
	);

	test(
		vector_access_2< std::vector<E> >,
		vector_access_2< ft::vector<E> >,
		"vector_access_2",
		selection
	);

	test(
		vector_access_3< std::vector<E> >,
		vector_access_3< ft::vector<E> >,
		"vector_access_3",
		selection
	);

	test(
		vector_access_4< std::vector<E> >,
		vector_access_4< ft::vector<E> >,
		"vector_access_4",
		selection
	);

	// test(
	// 	vector_access_5< std::vector<E> >,
	// 	vector_access_5< ft::vector<E> >,
	// 	"vector_access_5",
	// 	selection
	// );
}

void	modifiers(std::string selection)
{
	test(
		vector_push_back< std::vector<E> >,
		vector_push_back< ft::vector<E> >,
		"vector_push_back",
		selection
	);
	
	test(
		vector_pop_back< std::vector<E> >,
		vector_pop_back< ft::vector<E> >,
		"vector_pop_back",
		selection
	);
	
	test(
		vector_clear< std::vector<E> >,
		vector_clear< ft::vector<E> >,
		"vector_clear",
		selection
	);
	
	test(
		vector_swap< std::vector<E> >,
		vector_swap< ft::vector<E> >,
		"vector_swap",
		selection
	);
	
	test(
		vector_erase< std::vector<E> >,
		vector_erase< ft::vector<E> >,
		"vector_erase",
		selection
	);
	
	test(
		vector_insert_1< std::vector<E> >,
		vector_insert_1< ft::vector<E> >,
		"vector_insert_1",
		selection
	);
}

void	operations(std::string selection)
{
	static_cast<void>(selection);
}

void	do_tests(std::string selection)
{
	access(selection);
	// iterator
	modifiers(selection);
	operations(selection);
}

#endif
