/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:03:56 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 19:17:55 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_SET_CPP
# define TESTS_SET_CPP

#include "tests.hpp"
#include "set/ultrabasic.hpp"
#include "set/members.hpp"
#include "set/access.hpp"
#include "set/iterator.hpp"
#include "set/capacity.hpp"
#include "set/modifiers.hpp"
#include "set/observers.hpp"
#include "set/operations.hpp"


void	set_ultrabasic(std::string selection)
{
	test(
		set_ub_insert< std::set<std::string> >,
		set_ub_insert< ft::set<std::string> >,
		"set_ub_insert",
		selection
	);
}

void	set_members(std::string selection)
{
	test(
		set_memberstypes_1< std::set<std::string> >,
		set_memberstypes_1< ft::set<std::string> >,
		"set_memberstypes_1",
		selection
	);

	test(
		set_contructors_1< std::set<std::string> >,
		set_contructors_1< ft::set<std::string> >,
		"set_contructors_1",
		selection
	);

	test(
		set_contructors_2< std::set<std::string, cmpByStringLength> >,
		set_contructors_2< ft::set<std::string, cmpByStringLength> >,
		"set_contructors_2",
		selection
	);

	test(
		set_equal< std::set<std::string> >,
		set_equal< ft::set<std::string> >,
		"set_equal",
		selection
	);
}

void	set_access(std::string selection)
{
	test(
		set_access_1< std::set<std::string> >,
		set_access_1< ft::set<std::string> >,
		"set_access_1",
		selection
	);

	test(
		set_access_2< std::set<std::string> >,
		set_access_2< ft::set<std::string> >,
		"set_access_2",
		selection
	);

	test(
		set_access_3< std::set<std::string> >,
		set_access_3< ft::set<std::string> >,
		"set_access_3",
		selection
	);

	test(
		set_access_4< std::set<std::string> >,
		set_access_4< ft::set<std::string> >,
		"set_access_4",
		selection
	);
}

void	set_iterator(std::string selection)
{
	test(
		set_iterator_1< std::set<std::string>, std::set<std::string>::iterator >,
		set_iterator_1< ft::set<std::string>, ft::set<std::string>::iterator >,
		"set_iterator_1",
		selection
	);

	test(
		set_iterator_1< std::set<std::string>, std::set<std::string>::const_iterator >,
		set_iterator_1< ft::set<std::string>, ft::set<std::string>::const_iterator >,
		"set_iterator_1_const",
		selection
	);

	test(
		set_iterator_2< std::set<std::string>, std::set<std::string>::iterator >,
		set_iterator_2< ft::set<std::string>, ft::set<std::string>::iterator >,
		"set_iterator_2",
		selection
	);

	test(
		set_iterator_2< std::set<std::string>, std::set<std::string>::const_iterator >,
		set_iterator_2< ft::set<std::string>, ft::set<std::string>::const_iterator >,
		"set_iterator_2_const",
		selection
	);

	test(
		set_reverse_iterator_1< std::set<std::string>, std::set<std::string>::reverse_iterator >,
		set_reverse_iterator_1< ft::set<std::string>, ft::set<std::string>::reverse_iterator >,
		"set_reverse_iterator_1",
		selection
	);

	test(
		set_reverse_iterator_1< std::set<std::string>, std::set<std::string>::const_reverse_iterator >,
		set_reverse_iterator_1< ft::set<std::string>, ft::set<std::string>::const_reverse_iterator >,
		"set_reverse_iterator_1_const",
		selection
	);

	test(
		set_reverse_iterator_2< std::set<std::string>, std::set<std::string>::reverse_iterator >,
		set_reverse_iterator_2< ft::set<std::string>, ft::set<std::string>::reverse_iterator >,
		"set_reverse_iterator_2",
		selection
	);

	test(
		set_reverse_iterator_2< std::set<std::string>, std::set<std::string>::const_reverse_iterator >,
		set_reverse_iterator_2< ft::set<std::string>, ft::set<std::string>::const_reverse_iterator >,
		"set_reverse_iterator_2_const",
		selection
	);

	test(
		set_iterator_contructor_eq_deref< std::set<std::string>, std::set<std::string>::iterator , std::set<std::string>::iterator , std::set<std::string>::const_iterator >,
		set_iterator_contructor_eq_deref< ft::set<std::string>, ft::set<std::string>::iterator , ft::set<std::string>::iterator , ft::set<std::string>::const_iterator >,
		"set_iterator_contructor_eq_deref",
		selection
	);

	test(
		set_iterator_contructor_eq_deref_reverse< std::set<std::string>, std::set<std::string>::reverse_iterator , std::set<std::string>::reverse_iterator , std::set<std::string>::const_reverse_iterator >,
		set_iterator_contructor_eq_deref_reverse< ft::set<std::string>, ft::set<std::string>::reverse_iterator , ft::set<std::string>::reverse_iterator , ft::set<std::string>::const_reverse_iterator >,
		"set_iterator_contructor_eq_deref_reverse",
		selection
	);

	test(
		set_reverse_iterator_operator_equal_with_iterator< std::set<std::string>, std::set<std::string>::reverse_iterator, std::set<std::string>::iterator >,
		set_reverse_iterator_operator_equal_with_iterator< ft::set<std::string>, ft::set<std::string>::reverse_iterator, ft::set<std::string>::iterator >,
		"set_reverse_iterator_operator_equal_with_iterator",
		selection
	);
}

/*
** empty() and size() members are both
** tested along other tests
*/
void	set_capacity(std::string selection)
{
	test(
		set_capacity< std::set<std::string> >,
		set_capacity< ft::set<std::string> >,
		"set_capacity",
		selection
	);
}

void	set_modifiers(std::string selection)
{
	test(
		set_tricky_insert_1< std::set<std::string> >,
		set_tricky_insert_1< ft::set<std::string> >,
		"set_tricky_insert_1",
		selection
	);
	
	test(
		set_tricky_insert_2< std::set<std::string> >,
		set_tricky_insert_2< ft::set<std::string> >,
		"set_tricky_insert_2",
		selection
	);

	test(
		set_tricky_insert_3< std::set<std::string> >,
		set_tricky_insert_3< ft::set<std::string> >,
		"set_tricky_insert_3",
		selection
	);

	test(
		set_tricky_insert_4< std::set<std::string> >,
		set_tricky_insert_4< ft::set<std::string> >,
		"set_tricky_insert_4",
		selection
	);

	test(
		set_tricky_insert_5< std::set<std::string> >,
		set_tricky_insert_5< ft::set<std::string> >,
		"set_tricky_insert_5",
		selection
	);

	test(
		set_tricky_insert_6< std::set<std::string> >,
		set_tricky_insert_6< ft::set<std::string> >,
		"set_tricky_insert_6",
		selection
	);

	test(
		set_epic_insert_1< std::set<std::string> >,
		set_epic_insert_1< ft::set<std::string> >,
		"set_epic_insert_1",
		selection
	);
	
	test(
		set_clear< std::set<std::string> >,
		set_clear< ft::set<std::string> >,
		"set_clear",
		selection
	);
	
	test(
		set_swap< std::set<std::string> >,
		set_swap< ft::set<std::string> >,
		"set_swap",
		selection
	);
	
	test(
		set_erase_1< std::set<std::string> >,
		set_erase_1< ft::set<std::string> >,
		"set_erase_1",
		selection
	);
	
	test(
		set_erase_2< std::set<std::string> >,
		set_erase_2< ft::set<std::string> >,
		"set_erase_2",
		selection
	);
	
	test(
		set_erase_3< std::set<std::string> >,
		set_erase_3< ft::set<std::string> >,
		"set_erase_3",
		selection
	);
	
	test(
		set_erase_4< std::set<std::string> >,
		set_erase_4< ft::set<std::string> >,
		"set_erase_4",
		selection
	);
	
	test(
		set_erase_5< std::set<std::string> >,
		set_erase_5< ft::set<std::string> >,
		"set_erase_5",
		selection
	);
	
	test(
		set_erase_6< std::set<std::string> >,
		set_erase_6< ft::set<std::string> >,
		"set_erase_6",
		selection
	);
	
	test(
		set_erase_7< std::set<std::string> >,
		set_erase_7< ft::set<std::string> >,
		"set_erase_7",
		selection
	);
	
	test(
		set_erase_8< std::set<std::string> >,
		set_erase_8< ft::set<std::string> >,
		"set_erase_8",
		selection
	);
	
	test(
		set_erase_9< std::set<std::string> >,
		set_erase_9< ft::set<std::string> >,
		"set_erase_9",
		selection
	);
}

void	set_observers(std::string selection)
{
	test(
		set_keycomp_a< std::set< std::string > >,
		set_keycomp_a< ft::set< std::string > >,
		"set_keycomp_1",
		selection
	);
	test(
		set_keycomp_b< std::set< std::string > >,
		set_keycomp_b< ft::set< std::string > >,
		"set_keycomp_2",
		selection
	);

	test(
		set_keycomp_a< std::set< std::string, cmpByStringLength > >,
		set_keycomp_a< ft::set< std::string, cmpByStringLength > >,
		"set_keycomp_3",
		selection
	);

	test(
		set_keycomp_b< std::set< std::string, cmpByStringLength > >,
		set_keycomp_b< ft::set< std::string, cmpByStringLength > >,
		"set_keycomp_4",
		selection
	);

	test(
		set_valuecomp_a< std::set< std::string > >,
		set_valuecomp_a< ft::set< std::string > >,
		"set_valuecomp_1",
		selection
	);
	test(
		set_valuecomp_b< std::set< std::string > >,
		set_valuecomp_b< ft::set< std::string > >,
		"set_valuecomp_2",
		selection
	);

	test(
		set_valuecomp_a< std::set< std::string, cmpByStringLength > >,
		set_valuecomp_a< ft::set< std::string, cmpByStringLength > >,
		"set_valuecomp_3",
		selection
	);

	test(
		set_valuecomp_b< std::set< std::string, cmpByStringLength > >,
		set_valuecomp_b< ft::set< std::string, cmpByStringLength > >,
		"set_valuecomp_4",
		selection
	);
}

void	set_operations(std::string selection)
{
	test(
		set_find< std::set< std::string > >,
		set_find< ft::set< std::string > >,
		"set_find",
		selection
	);

	test(
		set_count< std::set< std::string > >,
		set_count< ft::set< std::string > >,
		"set_count",
		selection
	);

	test(
		set_lowerbound< std::set< std::string > >,
		set_lowerbound< ft::set< std::string > >,
		"set_lowerbound",
		selection
	);

	test(
		set_upperbound< std::set< std::string > >,
		set_upperbound< ft::set< std::string > >,
		"set_upperbound",
		selection
	);

	test(
		set_equalrange< std::set< std::string > >,
		set_equalrange< ft::set< std::string > >,
		"set_equalrange",
		selection
	);
}

void	set_tests(std::string selection)
{
	set_ultrabasic(selection);

	set_members(selection);
	set_access(selection); 
	set_iterator(selection);
	set_capacity(selection);
	set_modifiers(selection);
	set_observers(selection);
	set_operations(selection);
}

#endif
