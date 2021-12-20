/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:03:56 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 17:17:31 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_CPP
# define TESTS_MAP_CPP

struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

#include <utility>
#include "tests.hpp"
#include "map/ultrabasic.hpp"
#include "map/members.hpp"
#include "map/access.hpp"
#include "map/iterator.hpp"
#include "map/capacity.hpp"
#include "map/modifiers.hpp"
#include "map/observers.hpp"
#include "map/operations.hpp"


void	map_ultrabasic(std::string selection)
{
	test(
		map_ub_insert< std::map<std::string, E> >,
		map_ub_insert< ft::map<std::string, E> >,
		"map_ub_insert",
		selection
	);

	test(
		map_ub_std_insert1< std::map<std::string, E> >,
		map_ub_ft_insert1< ft::map<std::string, E> >,
		"map_ub_insert1",
		selection
	);
}

void	map_members(std::string selection)
{
	test(
		map_memberstypes_1< std::map<std::string, E> >,
		map_memberstypes_1< ft::map<std::string, E> >,
		"map_memberstypes_1",
		selection
	);

	test(
		map_contructors_1< std::map<std::string, E>, std::pair<std::string, E> >,
		map_contructors_1< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_contructors_1",
		selection
	);

	test(
		map_contructors_2< std::map<std::string, E, cmpByStringLength>, std::pair<std::string, E> >,
		map_contructors_2< ft::map<std::string, E, cmpByStringLength>, ft::pair<std::string, E> >,
		"map_contructors_2",
		selection
	);

	test(
		map_equal< std::map<std::string, E>, std::pair<std::string, E> >,
		map_equal< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_equal",
		selection
	);
}

void	map_access(std::string selection)
{
	test(
		map_access_1< std::map<std::string, E> >,
		map_access_1< ft::map<std::string, E> >,
		"map_access_1",
		selection
	);

	test(
		map_access_2< std::map<std::string, E> >,
		map_access_2< ft::map<std::string, E> >,
		"map_access_2",
		selection
	);

	test(
		map_access_3< std::map<std::string, E>, std::pair<std::string, E> >,
		map_access_3< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_access_3",
		selection
	);

	test(
		map_access_4< std::map<std::string, E>, std::pair<std::string, E> >,
		map_access_4< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_access_4",
		selection
	);
}

void	map_iterator(std::string selection)
{
	test(
		map_iterator_1< std::map<std::string, E>, std::pair<std::string, E>, std::map<std::string, E>::iterator >,
		map_iterator_1< ft::map<std::string, E>, ft::pair<std::string, E>, ft::map<std::string, E>::iterator >,
		"map_iterator_1",
		selection
	);

	test(
		map_iterator_1< std::map<std::string, E>, std::pair<std::string, E>, std::map<std::string, E>::const_iterator >,
		map_iterator_1< ft::map<std::string, E>, ft::pair<std::string, E>, ft::map<std::string, E>::const_iterator >,
		"map_iterator_1_const",
		selection
	);

	test(
		map_iterator_2< std::map<std::string, E>, std::pair<std::string, E>, std::map<std::string, E>::iterator >,
		map_iterator_2< ft::map<std::string, E>, ft::pair<std::string, E>, ft::map<std::string, E>::iterator >,
		"map_iterator_2",
		selection
	);

	test(
		map_iterator_2< std::map<std::string, E>, std::pair<std::string, E>, std::map<std::string, E>::const_iterator >,
		map_iterator_2< ft::map<std::string, E>, ft::pair<std::string, E>, ft::map<std::string, E>::const_iterator >,
		"map_iterator_2_const",
		selection
	);

	test(
		map_reverse_iterator_1< std::map<std::string, E>, std::pair<std::string, E>, std::map<std::string, E>::reverse_iterator >,
		map_reverse_iterator_1< ft::map<std::string, E>, ft::pair<std::string, E>, ft::map<std::string, E>::reverse_iterator >,
		"map_reverse_iterator_1",
		selection
	);

	test(
		map_reverse_iterator_1< std::map<std::string, E>, std::pair<std::string, E>, std::map<std::string, E>::const_reverse_iterator >,
		map_reverse_iterator_1< ft::map<std::string, E>, ft::pair<std::string, E>, ft::map<std::string, E>::const_reverse_iterator >,
		"map_reverse_iterator_1_const",
		selection
	);

	test(
		map_reverse_iterator_2< std::map<std::string, E>, std::pair<std::string, E>, std::map<std::string, E>::reverse_iterator >,
		map_reverse_iterator_2< ft::map<std::string, E>, ft::pair<std::string, E>, ft::map<std::string, E>::reverse_iterator >,
		"map_reverse_iterator_2",
		selection
	);

	test(
		map_reverse_iterator_2< std::map<std::string, E>, std::pair<std::string, E>, std::map<std::string, E>::const_reverse_iterator >,
		map_reverse_iterator_2< ft::map<std::string, E>, ft::pair<std::string, E>, ft::map<std::string, E>::const_reverse_iterator >,
		"map_reverse_iterator_2_const",
		selection
	);

	test(
		map_iterator_contructor_eq_deref< std::map<std::string, E>, std::pair<std::string, E>, std::map<std::string, E>::iterator , std::map<std::string, E>::iterator , std::map<std::string, E>::const_iterator >,
		map_iterator_contructor_eq_deref< ft::map<std::string, E>, ft::pair<std::string, E>, ft::map<std::string, E>::iterator , ft::map<std::string, E>::iterator , ft::map<std::string, E>::const_iterator >,
		"map_iterator_contructor_eq_deref",
		selection
	);

	test(
		map_iterator_contructor_eq_deref_reverse< std::map<std::string, E>, std::pair<std::string, E>, std::map<std::string, E>::reverse_iterator , std::map<std::string, E>::reverse_iterator , std::map<std::string, E>::const_reverse_iterator >,
		map_iterator_contructor_eq_deref_reverse< ft::map<std::string, E>, ft::pair<std::string, E>, ft::map<std::string, E>::reverse_iterator , ft::map<std::string, E>::reverse_iterator , ft::map<std::string, E>::const_reverse_iterator >,
		"map_iterator_contructor_eq_deref_reverse",
		selection
	);

	test(
		map_reverse_iterator_operator_equal_with_iterator< std::map<std::string, E>, std::pair<std::string, E>, std::map<std::string, E>::reverse_iterator, std::map<std::string, E>::iterator >,
		map_reverse_iterator_operator_equal_with_iterator< ft::map<std::string, E>, ft::pair<std::string, E>, ft::map<std::string, E>::reverse_iterator, ft::map<std::string, E>::iterator >,
		"map_reverse_iterator_operator_equal_with_iterator",
		selection
	);
}

/*
** empty() and size() members are both
** tested along other tests
*/
void	map_capacity(std::string selection)
{
	test(
		map_capacity< std::map<std::string, E>, std::pair<std::string, E> >,
		map_capacity< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_capacity",
		selection
	);
}

void	map_modifiers(std::string selection)
{
	test(
		map_tricky_insert_1< std::map<std::string, E>, std::pair<std::string, E> >,
		map_tricky_insert_1< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_tricky_insert_1",
		selection
	);
	
	test(
		map_tricky_insert_2< std::map<std::string, E>, std::pair<std::string, E> >,
		map_tricky_insert_2< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_tricky_insert_2",
		selection
	);

	test(
		map_tricky_insert_3< std::map<std::string, E>, std::pair<std::string, E> >,
		map_tricky_insert_3< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_tricky_insert_3",
		selection
	);

	test(
		map_tricky_insert_4< std::map<std::string, E>, std::pair<std::string, E> >,
		map_tricky_insert_4< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_tricky_insert_4",
		selection
	);

	test(
		map_tricky_insert_5< std::map<std::string, E>, std::pair<std::string, E> >,
		map_tricky_insert_5< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_tricky_insert_5",
		selection
	);

	test(
		map_tricky_insert_6< std::map<std::string, E>, std::pair<std::string, E> >,
		map_tricky_insert_6< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_tricky_insert_6",
		selection
	);

	test(
		map_epic_insert_1< std::map<std::string, E>, std::pair<std::string, E> >,
		map_epic_insert_1< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_epic_insert_1",
		selection
	);
	
	test(
		map_clear< std::map<std::string, E>, std::pair<std::string, E> >,
		map_clear< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_clear",
		selection
	);
	
	test(
		map_swap< std::map<std::string, E>, std::pair<std::string, E> >,
		map_swap< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_swap",
		selection
	);
	
	test(
		map_erase_1< std::map<std::string, E>, std::pair<std::string, E> >,
		map_erase_1< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_erase_1",
		selection
	);
	
	test(
		map_erase_2< std::map<std::string, E>, std::pair<std::string, E> >,
		map_erase_2< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_erase_2",
		selection
	);
	
	test(
		map_erase_3< std::map<std::string, E>, std::pair<std::string, E> >,
		map_erase_3< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_erase_3",
		selection
	);
	
	test(
		map_erase_4< std::map<std::string, E>, std::pair<std::string, E> >,
		map_erase_4< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_erase_4",
		selection
	);
	
	test(
		map_erase_5< std::map<std::string, E>, std::pair<std::string, E> >,
		map_erase_5< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_erase_5",
		selection
	);
	
	test(
		map_erase_6< std::map<std::string, E>, std::pair<std::string, E> >,
		map_erase_6< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_erase_6",
		selection
	);
	
	test(
		map_erase_7< std::map<std::string, E>, std::pair<std::string, E> >,
		map_erase_7< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_erase_7",
		selection
	);
	
	test(
		map_erase_8< std::map<std::string, E>, std::pair<std::string, E> >,
		map_erase_8< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_erase_8",
		selection
	);
	
	test(
		map_erase_9< std::map<std::string, E>, std::pair<std::string, E> >,
		map_erase_9< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_erase_9",
		selection
	);
}

void	map_observers(std::string selection)
{
	test(
		map_keycomp_a< std::map< std::string, E >, std::pair<std::string, E> >,
		map_keycomp_a< ft::map< std::string, E >, ft::pair<std::string, E> >,
		"map_keycomp_1",
		selection
	);
	test(
		map_keycomp_b< std::map< std::string, E >, std::pair<std::string, E> >,
		map_keycomp_b< ft::map< std::string, E >, ft::pair<std::string, E> >,
		"map_keycomp_2",
		selection
	);

	test(
		map_keycomp_a< std::map< std::string, E, cmpByStringLength >, std::pair<std::string, E> >,
		map_keycomp_a< ft::map< std::string, E, cmpByStringLength >, ft::pair<std::string, E> >,
		"map_keycomp_3",
		selection
	);

	test(
		map_keycomp_b< std::map< std::string, E, cmpByStringLength >, std::pair<std::string, E> >,
		map_keycomp_b< ft::map< std::string, E, cmpByStringLength >, ft::pair<std::string, E> >,
		"map_keycomp_4",
		selection
	);

	test(
		map_valuecomp_a< std::map< std::string, std::string >, std::pair<std::string, std::string> >,
		map_valuecomp_a< ft::map< std::string, std::string >, ft::pair<std::string, std::string> >,
		"map_valuecomp_1",
		selection
	);
	test(
		map_valuecomp_b< std::map< std::string, std::string >, std::pair<std::string, std::string> >,
		map_valuecomp_b< ft::map< std::string, std::string >, ft::pair<std::string, std::string> >,
		"map_valuecomp_2",
		selection
	);

	test(
		map_valuecomp_a< std::map< std::string, std::string, cmpByStringLength >, std::pair<std::string, std::string> >,
		map_valuecomp_a< ft::map< std::string, std::string, cmpByStringLength >, ft::pair<std::string, std::string> >,
		"map_valuecomp_3",
		selection
	);

	test(
		map_valuecomp_b< std::map< std::string, std::string, cmpByStringLength >, std::pair<std::string, std::string> >,
		map_valuecomp_b< ft::map< std::string, std::string, cmpByStringLength >, ft::pair<std::string, std::string> >,
		"map_valuecomp_4",
		selection
	);
}

void	map_operations(std::string selection)
{
	test(
		map_find< std::map< std::string, E >, std::pair<std::string, E> >,
		map_find< ft::map< std::string, E >, ft::pair<std::string, E> >,
		"map_find",
		selection
	);

	test(
		map_count< std::map< std::string, E >, std::pair<std::string, E> >,
		map_count< ft::map< std::string, E >, ft::pair<std::string, E> >,
		"map_count",
		selection
	);

	test(
		map_lowerbound< std::map< std::string, E >, std::pair<std::string, E> >,
		map_lowerbound< ft::map< std::string, E >, ft::pair<std::string, E> >,
		"map_lowerbound",
		selection
	);

	test(
		map_upperbound< std::map< std::string, E >, std::pair<std::string, E> >,
		map_upperbound< ft::map< std::string, E >, ft::pair<std::string, E> >,
		"map_upperbound",
		selection
	);

	test(
		map_equalrange< std::map< std::string, E >, std::pair<std::string, E> >,
		map_equalrange< ft::map< std::string, E >, ft::pair<std::string, E> >,
		"map_equalrange",
		selection
	);
}

void	map_tests(std::string selection)
{
	// SHOULD TEST TIME !

	map_ultrabasic(selection);

	map_members(selection);
	map_access(selection); 
	map_iterator(selection);
	map_capacity(selection);
	map_modifiers(selection);
	map_observers(selection);
	map_operations(selection);
}

#endif
